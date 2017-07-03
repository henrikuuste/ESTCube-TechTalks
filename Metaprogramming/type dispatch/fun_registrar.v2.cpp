#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>

//**Implementation********************************************************************************
/*!\name Implementation */
//@{

template <size_t index> void fun() { std::cout << "..[" << index << "]"; }

template <std::size_t... Indices>
constexpr auto make_registrar_helper(std::index_sequence<Indices...>)
    -> std::array<decltype(&fun<0>), sizeof...(Indices)> {
  return {{fun<Indices>...}};
}

template <int N> constexpr auto make_registrar() {
  return make_registrar_helper(std::make_index_sequence<N>{});
}
//@}
//**********************************************************************************************

using namespace std;

void other_fun() { cout << "HELLOOOO!!!"; }

template <> void fun<2>() { other_fun(); }

#define REGISTER_FUN(id, function)                                             \
  template <> void fun<id>() { function(); }

void ping_fun() { cout << "PING"; }
REGISTER_FUN(0, ping_fun);

REGISTER_FUN(9, [] { cout << "LAMBDA"; });

constexpr auto N = 10;
constexpr auto registrar = make_registrar<N>();

int main() {
  // test code begin
  for (auto f : registrar) {
    f();
    cout << ", ";
  }
  cout << "\n";
  registrar[2]();
  // test code end
}