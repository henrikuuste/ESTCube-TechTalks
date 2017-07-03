#pragma once
#include <iostream>

template <typename elem_t> struct MyMatrix {
  elem_t data[2][2];

  MyMatrix operator+(const elem_t &rhs) {
    MyMatrix out{*this};
    out.data[0][0] += rhs;
    out.data[0][1] += rhs;
    out.data[1][0] += rhs;
    out.data[1][1] += rhs;
    return out;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyMatrix<T> &rhs) {
  os << "[ " << rhs.data[0][0] << ", " << rhs.data[0][1];
  os << "; " << rhs.data[1][0] << ", " << rhs.data[1][1];
  os << "]";
  return os;
}
