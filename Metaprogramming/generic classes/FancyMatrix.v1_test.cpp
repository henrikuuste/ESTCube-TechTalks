#include "FancyMatrix.hpp"
#include <iostream>

using namespace std;

using RotMatrixF = StaticMatrix<float, 3, 3>;
using TrMatrixF = StaticMatrix<float, 4, 4>;

static constexpr RotMatrixF I3{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
static constexpr RotMatrixF LTM = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};


template<typename T, size_t M, size_t N>
constexpr auto make_identity() {
  StaticMatrix<T, M, N> ret{};
  for(size_t i = 0; i < std::min(M, N); i++) {
    ret(i, i) =1;
  }
  return ret;
}

template<typename T, size_t M>
static constexpr auto Eye = make_identity<T, M, M>();

int main() {
  RotMatrixF A(7);
  StaticMatrix<int, 2, 3> B{{1, 2, 3}, {4, 5, 6}};
  StaticMatrix<double, 2, 2> C{{1, -5.5}, {5.5, 1}};

  cout << A << "\n";
  cout << B << "\n";
  cout << C << "\n";
  cout << I3 << "\n";
  cout << LTM << "\n";

  cout << Eye<double, 4> << "\n";

  auto D = Eye<float, 3> * 2.2 + 0.1;
  cout << D << "\n";

  C = {{1e-6, 1e-5}, {1e2, 1e3}};
  cout << C << "\n";
}