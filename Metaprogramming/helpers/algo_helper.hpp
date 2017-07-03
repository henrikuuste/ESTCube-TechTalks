#pragma once
#include <algorithm>

namespace algo {
// Namespace algo
//
template <typename T> using Iterator = typename T::iterator;

template <class ForwardIt, class T>
constexpr void fill(ForwardIt first, ForwardIt last, const T &value) {
  for (; first != last; ++first) {
    *first = value;
  }
}

template <typename Container, typename T>
constexpr void fill(Container &c, const T &value) {
  fill(std::begin(c), std::end(c), value);
}

template <class InputIt, class OutputIt>
constexpr OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
  while (first != last) {
    *d_first++ = *first++;
  }
  return d_first;
}

template <typename SrcContainer, typename DestContainer>
constexpr Iterator<DestContainer> copy(SrcContainer &src,
                                       const DestContainer &dest) {
  return copy(std::begin(src), std::end(src), std::begin(dest));
}

//
// Namespace algo
}