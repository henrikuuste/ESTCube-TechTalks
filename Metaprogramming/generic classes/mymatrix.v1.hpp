#pragma once
#include <iostream>

struct MyMatrix {
  float data[2][2];

  MyMatrix operator+(const float &rhs) {
    MyMatrix out{*this};
    out.data[0][0] += rhs;
    out.data[0][1] += rhs;
    out.data[1][0] += rhs;
    out.data[1][1] += rhs;
    return out;
  }
};

std::ostream &operator<<(std::ostream &os, const MyMatrix &rhs) {
  os << "[ " << rhs.data[0][0] << ", " << rhs.data[0][1];
  os << "; " << rhs.data[1][0] << ", " << rhs.data[1][1];
  os << "]";
  return os;
}
