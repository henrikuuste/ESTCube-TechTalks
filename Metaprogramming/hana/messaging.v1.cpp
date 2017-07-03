#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/string.hpp"

#include "boost/hana.hpp"

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
namespace hana = boost::hana;
using namespace std::literals;

template <class T> concept bool HanaStruct = hana::Struct<T>::value;

//! [message structure]
enum class MessageType : uint8_t;

struct Header {
  MessageType id;
};
BOOST_HANA_ADAPT_STRUCT(Header, id);

template <MessageType idTag> struct Message {
  Header header;
  static constexpr auto id = idTag;

  constexpr Message() : header{idTag} {}
};
//! [message structure]

//! [cereal + hana]
namespace cereal {
constexpr auto &member_name = hana::first;
constexpr auto &member_val = hana::second;
template <typename Member> constexpr auto member_name_str(Member m) {
  return hana::to<char const *>(member_name(m));
}

template <typename Archive> void save(Archive &archive, const HanaStruct &src) {
  hana::for_each(src, [&archive](const auto &m) {
    archive(make_nvp(member_name_str(m), member_val(m)));
  });
}

template <typename Archive> void load(Archive &archive, HanaStruct &src) {
  hana::for_each(src, [&archive, &src](auto &&m) {
    archive(make_nvp(member_name_str(m), member_val(m)));
    hana::at_key(src, member_name(m)) = member_val(m);
  });
}
}
//! [cereal + hana]

//! [utilities]
template <typename E> constexpr auto to_underlying(E e) {
  return static_cast<typename std::underlying_type<E>::type>(e);
}

std::string bin2hex11(const std::string bin) {
  std::ostringstream oss;
  oss << std::setfill('0');
  std::for_each(bin.begin(), bin.end(), [&oss](unsigned char ch) {
    oss << std::hex << std::setw(2) << static_cast<int>(ch) << " ";
  });
  return oss.str();
}
//! [utilities]

//! [registrar]
template <typename ArchiveType, size_t index> void handler(ArchiveType &) {
  std::cout << "..[" << index << "]\n";
}

template <typename ArchiveType, std::size_t... Indices>
constexpr auto make_registrar_helper(std::index_sequence<Indices...>)
    -> std::array<decltype(&handler<ArchiveType, 0>), sizeof...(Indices)> {
  return {{handler<ArchiveType, Indices>...}};
}

template <typename ArchiveType, int N> constexpr auto make_registrar() {
  return make_registrar_helper<ArchiveType>(std::make_index_sequence<N>{});
}

template <typename ArchiveType> void handle(size_t idx, ArchiveType &archive);

#define INIT_LOOKUP(ArchiveType)                                               \
  template <>                                                                  \
  constexpr auto cmd_lookup<ArchiveType> =                                     \
      make_registrar<ArchiveType, to_underlying(MessageType::COUNT)>();

#define INIT_MESSAGING()                                                       \
  \
template<typename ArchiveType> constexpr auto cmd_lookup = 0;                  \
  INIT_LOOKUP(cereal::JSONInputArchive);                                       \
  INIT_LOOKUP(cereal::XMLInputArchive);                                        \
  INIT_LOOKUP(cereal::BinaryInputArchive);                                     \
  template <typename ArchiveType>                                              \
  void handle(MessageType idx, ArchiveType &archive) {                         \
    if (idx >= MessageType::COUNT) {                                           \
      throw std::out_of_range("Crap");                                         \
    }                                                                          \
    cmd_lookup<ArchiveType>[to_underlying(idx)](archive);                      \
  }

#define REGISTER_MSG_HELPER(MSG_TYPE, ArchiveType)                             \
  template <>                                                                  \
  void handler<ArchiveType, to_underlying(MSG_TYPE::id)>(ArchiveType &         \
                                                         archive) {            \
    MSG_TYPE cmd;                                                              \
    archive(cmd);                                                              \
    cmd.handle();                                                              \
  }

#define REGISTER_MESSAGE(MSG_TYPE, ...)                                        \
  \
BOOST_HANA_ADAPT_STRUCT(MSG_TYPE, ##__VA_ARGS__);                              \
  \
REGISTER_MSG_HELPER(MSG_TYPE, cereal::JSONInputArchive);                       \
  \
REGISTER_MSG_HELPER(MSG_TYPE, cereal::XMLInputArchive);                        \
  \
REGISTER_MSG_HELPER(MSG_TYPE, cereal::BinaryInputArchive);
//! [registrar]

//! [serialization]
template <typename ArchiveType>
void serialize(const HanaStruct &src, std::ostream &dst) {
  ArchiveType archive(dst);
  archive(cereal::make_nvp("Header", src.header));
  archive(cereal::make_nvp("Message", src));
}

template <typename ArchiveType> void deserialize(std::string in_data) {
  std::stringstream ss_in;
  ss_in << in_data;
  ArchiveType archive(ss_in);

  Header message_header;
  archive(message_header);
  handle(message_header.id, archive);
}
//! [serialization]

//! [demo helpers]
using namespace cereal;
#define SELECT_SERIALIZER(TYPE)                                                \
  using ArchiveOut = TYPE##OutputArchive;                                      \
  using ArchiveIn = TYPE##InputArchive;

template <typename ArchiveOut> void print_output(std::string str) {
  std::cout << str << std::endl;
}

template <> void print_output<BinaryOutputArchive>(std::string str) {
  std::cout << bin2hex11(str) << std::endl;
}
//! [demo helpers]

//! [user code]
enum class MessageType : uint8_t { NONE, PING, VER, COUNT };

struct Ping : Message<MessageType::PING> {
  uint32_t time;
  explicit constexpr Ping() : time(0) {}
  explicit constexpr Ping(uint32_t in_time) : time(in_time) {}
  void handle() { std::cout << ">>> PONG " << time << "\n"; }
};
REGISTER_MESSAGE(Ping, time);

struct Version : Message<MessageType::VER> {
  void handle() { std::cout << ">>> VERSION 0.1-alpha\n"; }
};
REGISTER_MESSAGE(Version);

INIT_MESSAGING();
SELECT_SERIALIZER(Binary);

//! [demo helpers]
template <typename T> std::string demo_serialize(T &&t) {
  std::ostringstream ss_out;
  serialize<ArchiveOut>(t, ss_out);
  print_output<ArchiveOut>(ss_out.str());
  return ss_out.str();
}

void demo_deserialize(std::string str) { deserialize<ArchiveIn>(str); }
//! [demo helpers]

int main() {
  std::string msg_data = demo_serialize(Ping(100));
  demo_deserialize(msg_data);

  msg_data = demo_serialize(Version());
  demo_deserialize(msg_data);
}
//! [user code]