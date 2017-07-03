#include <iostream>
#include "mymatrix.v2.hpp"

using namespace std;

int main() {
  MyMatrix<float> m1{
    {
      {1.0, 5.5},
      {-5.5, 1.0}
    }
  };
  cout << m1 << "\n";
  MyMatrix<int> m2{
    {
      {1, 5},
      {-5, 1}
    }
  };
  cout << m2 << "\n";
}