#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>
#include <type_traits>

//**Implementation********************************************************************************
/*!\name Implementation */
//@{

template <size_t index>
void fun() { std::cout << "Handler[" << index << "]"; }

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

template<>
void fun<2>() { cout << "HELLOOOO!"; }

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