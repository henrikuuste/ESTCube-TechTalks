#include <iostream>
#include "mymatrix.v1.hpp"

using namespace std;

int main() {
  MyMatrix m1{
    {
      {1.0, 5.5},
      {-5.5, 1.0}
    }
  };
  cout << m1 << "\n";
}