#include <array>
#include <array>
#include <cstdint>
#include <iostream>

constexpr char my_fun(size_t i) { return 'a' + i; }

//**Implementation********************************************************************************
/*!\name Implementation */
//@{
template <size_t N, size_t I = N - 1> // General
class CompileTable : public CompileTable<N, I - 1> {
public:
  static const int dummy;
};

template <size_t N> class CompileTable<N, 0> { // Stop condition
public:
  static const int dummy;
  static char value[N];
};

template <size_t N, size_t I> // General
const int CompileTable<N, I>::dummy = CompileTable<N, 0>::value[I] =
    my_fun(I) + 0 * CompileTable<N, I - 1>::dummy;

template <size_t N> // Stop condition
const int CompileTable<N, 0>::dummy = CompileTable<N, 0>::value[0] = my_fun(0);

template <size_t N> char CompileTable<N, 0>::value[N]; // value definition
//@}
//**********************************************************************************************

constexpr auto MY_COUNT = 10;

template class CompileTable<MY_COUNT>;
constexpr auto &my_data = CompileTable<MY_COUNT>::value;

int main() {
  for (auto &e : my_data) {
    std::cout << e << ", ";
  }
}