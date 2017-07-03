#pragma once
#include <cmath>
#include <limits>
#include <type_traits>

namespace smath {

  /**
     * @brief Exponential function.
     */
  template <typename Float>
  constexpr auto exp(Float x) -> decltype(std::exp(x));

  /**
   * @brief Power function
   *
   * @warning This functions is only available for the integer
   * @warning exponent right now.
   */
  template <typename Number, typename Integer>
  constexpr auto pow(Number x, Integer exponent)
      -> std::common_type_t<Number, Integer>;

  namespace detail {
    ////////////////////////////////////////////////////////////
    // Factorial function

    template <typename Integer> constexpr auto factorial(Integer n) -> Integer {
      Integer res = 1;
      for (Integer i = 2; i <= n; ++i) {
        res *= i;
      }
      return res;
    }

    template <typename Integer, Integer N>
    constexpr auto factorial(std::integral_constant<Integer, N>)
        -> std::integral_constant<Integer, factorial(N)> {
      return {};
    }

    // x^n / n!
    template <typename T> constexpr auto xn_nfac(T x, int n) -> T {
      return smath::pow(x, n) / detail::factorial<T>(n);
    }

    ////////////////////////////////////////////////////////////
    // pow

    template <typename T, typename Unsigned>
    constexpr auto pow_helper(T x, Unsigned exponent)
        -> std::common_type_t<T, Unsigned> {
      // Exponentiation by squaring
      return (exponent == 0) ? 1
                             : (exponent % 2 == 0)
                                   ? pow_helper(x * x, exponent / 2)
                                   : x * pow_helper(x * x, (exponent - 1) / 2);
    }

    ////////////////////////////////////////////////////////////
    // exp (contributed by theLOLflashlight)

    constexpr std::size_t exp_max_depth = 50;

    template <std::size_t N> struct exponential {
      exponential() = delete;

      static_assert(N < exp_max_depth, "exceeded maximum recursion depth");

      template <typename T> static constexpr auto compute(T x) -> T {
        const auto epsilon = std::numeric_limits<T>::epsilon() * x;
        const T term = xn_nfac(x, N);

        if (term < epsilon) {
          return term;
        } else {
          return term + exponential<N + 1>::compute(x);
        }
      }
    };

    template <> struct exponential<exp_max_depth> {
      exponential() = delete;
      template <typename T> static constexpr auto compute(T) -> T {
        return T();
      }
    };

    template <std::size_t N, typename T> constexpr auto exp_helper(T x) -> T {
      return exponential<N>::compute(x);
    }
  }

  template <typename Float>
  constexpr auto exp(Float x) -> decltype(std::exp(x)) {
    return 1 + x + detail::exp_helper<2>(x);
  }

  template <typename Number, typename Integer>
  constexpr auto pow(Number x, Integer exponent)
      -> std::common_type_t<Number, Integer> {
    static_assert(
        std::is_integral<Integer>::value, "pow only accepts integer exponents");

    return (exponent == 0)
               ? 1
               : (exponent > 0) ? detail::pow_helper(x, exponent)
                                : 1 / detail::pow_helper(x, -exponent);
  }

  template <typename Integer, Integer N, Integer M>
  constexpr auto
  pow(std::integral_constant<Integer, N>, std::integral_constant<Integer, M>)
      -> std::integral_constant<Integer, smath::pow(N, M)> {
    return {};
  }
}
