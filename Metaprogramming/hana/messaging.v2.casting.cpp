#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#define PACKED __attribute__((packed))

//! [message structure]
enum class MessageType : uint8_t;

struct MessageBase {
  MessageType id;
};

template <MessageType idTag> struct Message : MessageBase {
  static constexpr auto const_id = idTag;

  constexpr Message() : MessageBase{idTag} {}
};
//! [message structure]

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

void print_output(std::string str) { std::cout << bin2hex11(str) << std::endl; }
//! [utilities]

namespace registrar { //! [registrar]
template <size_t index> void handler(const void *) {
  std::cout << "..[" << index << "]\n";
}

template <std::size_t... Indices>
constexpr auto make_registrar_helper(std::index_sequence<Indices...>)
    -> std::array<decltype(&handler<0>), sizeof...(Indices)> {
  return {{handler<Indices>...}};
}

template <int N> constexpr auto make_registrar() {
  return make_registrar_helper(std::make_index_sequence<N>{});
}

void handle(MessageType idx, const void *data);
} //! [registrar]

#define INIT_MESSAGING()                                                       \
  namespace registrar {                                                        \
  constexpr auto cmd_lookup =                                                  \
      make_registrar<to_underlying(MessageType::COUNT)>();                     \
  void handle(MessageType idx, const void *data) {                             \
    if (idx >= MessageType::COUNT) {                                           \
      throw std::out_of_range("Crap");                                         \
    }                                                                          \
    cmd_lookup[to_underlying(idx)](data);                                      \
  }                                                                            \
  }

#define REGISTER_MESSAGE(MSG_TYPE)                                             \
  namespace registrar {                                                        \
  template <>                                                                  \
  void handler<to_underlying(MSG_TYPE::const_id)>(const void *data) {          \
    const MSG_TYPE *msg = reinterpret_cast<const MSG_TYPE *>(data);            \
    msg->handle();                                                             \
  }                                                                            \
  }

//! [serialization]
template <typename MessageT> std::string serialize(MessageT &&msg) {
  std::string msg_data(reinterpret_cast<const char *>(&msg), sizeof(MessageT));
  print_output(msg_data);
  return msg_data;
}

void deserialize(std::string str) {
  const void *data = reinterpret_cast<const void *>(str.data());
  const MessageBase *m = reinterpret_cast<const MessageBase *>(data);
  registrar::handle(m->id, data);
}
//! [serialization]

//! [user code]
enum class MessageType : uint8_t { NONE, PING, VER, COUNT };

struct Ping : Message<MessageType::PING> {
  uint32_t time;
  explicit constexpr Ping() : time(0) {}
  explicit constexpr Ping(uint32_t in_time) : time(in_time) {}
  void handle() const { std::cout << ">>> PONG " << time << "\n"; }
};
REGISTER_MESSAGE(Ping);

struct Version : Message<MessageType::VER> {
  void handle() const { std::cout << ">>> VERSION 0.1-alpha\n"; }
};
REGISTER_MESSAGE(Version);

INIT_MESSAGING();

int main() {
  std::string msg_data = serialize(Ping(100));
  deserialize(msg_data);

  msg_data = serialize(Version());
  deserialize(msg_data);
}
//! [user code]