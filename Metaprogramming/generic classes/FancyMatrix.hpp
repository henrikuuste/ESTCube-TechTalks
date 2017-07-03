#pragma once
#include "../helpers/algo_helper.hpp"
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <type_traits>

template <class T> concept bool Scalar = std::is_arithmetic<T>::value;

template <typename Type, size_t M, size_t N> class StaticMatrix {
public:
  typedef Type &Reference; //!< Reference to a non-constant matrix value.
  typedef const Type &ConstReference; //!< Reference to a constant matrix value.
  typedef Type *Pointer;            //!< Pointer to a non-constant matrix value.
  typedef const Type *ConstPointer; //!< Pointer to a constant matrix value.

  inline constexpr StaticMatrix();
  inline constexpr StaticMatrix(const Type &init);
  inline constexpr StaticMatrix(
      std::initializer_list<std::initializer_list<Type>> list);
  template <typename Other>
  inline constexpr StaticMatrix(
      size_t m, size_t n, const Other *array);
  template <typename Other>
  inline constexpr StaticMatrix(const Other (&array)[M][N]);
  inline constexpr StaticMatrix(const StaticMatrix &m);

  inline constexpr StaticMatrix &operator=(const StaticMatrix &rhs);

  inline constexpr Reference operator()(size_t i, size_t j) noexcept;
  inline constexpr ConstReference operator()(size_t i, size_t j) const noexcept;

  inline constexpr size_t rows() const noexcept;
  inline constexpr size_t columns() const noexcept;

  inline constexpr StaticMatrix &
  operator=(std::initializer_list<std::initializer_list<Type>> list);
  // template <typename Type2, size_t M2, size_t N2>
  // inline StaticMatrix &operator*=(const StaticMatrix<Type2, M2, N2> &rhs);

  inline constexpr StaticMatrix &operator*=(Scalar rhs);
  inline constexpr StaticMatrix &operator+=(Scalar rhs);
  // inline StaticMatrix &transpose();

private:
  Type v_[N * M];
};

template <typename T, size_t M, size_t N>
std::ostream &operator<<(std::ostream &os, const StaticMatrix<T, M, N> &rhs) {
  for (size_t i = 0UL; i < rhs.rows(); ++i) {
    os << "( ";
    for (size_t j = 0UL; j < rhs.columns(); ++j) {
      os << std::setw(6) << rhs(i, j) << " ";
    }
    os << ")\n";
  }

  return os;
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix() : v_() {
  for (auto &e : v_)
    e = Type();
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix(const Type &init)
    : v_() {
  for (auto &e : v_)
    e = init;
  // algo::fill(v_, init);
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix(
    std::initializer_list<std::initializer_list<Type>> list)
    : v_() {
  size_t i(0UL);
  for (const auto &rowList : list) {
    for (const auto &e : rowList) {
      v_[i++] = e;
    }
  }
}

template <typename Type, size_t M, size_t N>
template <typename Other> // Data type of the initialization array
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix(
    size_t m, size_t n, const Other *array)
    : v_() {

  for (size_t i = 0UL; i < m; ++i) {
    for (size_t j = 0UL; j < n; ++j)
      v_[i * N + j] = array[i * n + j];
  }
}

template <typename Type, size_t M, size_t N>
template <typename Other> // Data type of the initialization array
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix(
    const Other (&array)[M][N])
    : v_() {

  for (size_t i = 0UL; i < M; ++i) {
    for (size_t j = 0UL; j < N; ++j)
      v_[i * N + j] = array[i][j];
  }
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N>::StaticMatrix(const StaticMatrix &m)
    : v_() {
  for (size_t i = 0UL; i < M * N; ++i)
    v_[i] = m.v_[i];
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N> &StaticMatrix<Type, M, N>::
operator=(const StaticMatrix &rhs) {
  for (size_t i = 0; i < (M * N); i++) {
    v_[i] = rhs.v_[i];
  }
  return *this;
}

template <typename Type, size_t M, size_t N>
inline constexpr typename StaticMatrix<Type, M, N>::Reference
StaticMatrix<Type, M, N>::operator()(size_t i, size_t j) noexcept {
  return v_[i * N + j];
}

template <typename Type, size_t M, size_t N>
inline constexpr typename StaticMatrix<Type, M, N>::ConstReference
StaticMatrix<Type, M, N>::operator()(size_t i, size_t j) const noexcept {
  return v_[i * N + j];
}

template <typename Type, size_t M, size_t N>
inline constexpr size_t StaticMatrix<Type, M, N>::rows() const noexcept {
  return M;
}

template <typename Type, size_t M, size_t N>
inline constexpr size_t StaticMatrix<Type, M, N>::columns() const noexcept {
  return N;
}

template <typename Type, size_t M, size_t N>
inline constexpr StaticMatrix<Type, M, N> &StaticMatrix<Type, M, N>::
operator=(std::initializer_list<std::initializer_list<Type>> list) {
  size_t i(0UL);
  for (const auto &rowList : list) {
    for (const auto &e : rowList) {
      v_[i++] = e;
    }
  }
  return *this;
}

template <typename Type, size_t M, size_t N>
constexpr StaticMatrix<Type, M, N> &StaticMatrix<Type, M, N>::
operator*=(Scalar rhs) {
  for (auto &e : v_) {
    e *= static_cast<Type>(rhs);
  }
  return *this;
}

template <typename Type, size_t M, size_t N>
constexpr auto
operator*(const StaticMatrix<Type, M, N> &lhs, const Scalar &rhs) {
  StaticMatrix<Type, M, N> ret(lhs);
  ret *= rhs;
  return ret;
}

template <typename Type, size_t M, size_t N>
constexpr auto
operator*(const Scalar &lhs, const StaticMatrix<Type, M, N> &rhs) {
  StaticMatrix<Type, M, N> ret(rhs);
  ret *= lhs;
  return ret;
}

template <typename Type, size_t M, size_t N>
constexpr StaticMatrix<Type, M, N> &StaticMatrix<Type, M, N>::
operator+=(Scalar rhs) {
  for (auto &e : v_) {
    e += static_cast<Type>(rhs);
  }
  return *this;
}

template <typename Type, size_t M, size_t N>
constexpr auto
operator+(const StaticMatrix<Type, M, N> &lhs, const Scalar &rhs) {
  StaticMatrix<Type, M, N> ret(lhs);
  ret += rhs;
  return ret;
}

template <typename Type, size_t M, size_t N>
constexpr auto
operator+(const Scalar &lhs, const StaticMatrix<Type, M, N> &rhs) {
  StaticMatrix<Type, M, N> ret(rhs);
  ret += lhs;
  return ret;
}
