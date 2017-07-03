#include <bitset>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>

#define BRIGAND_NO_BOOST_SUPPORT
#include "../libs/brigand/standalone/brigand.hpp"
namespace br = brigand;

#include <boost/hana.hpp>
namespace hana = boost::hana;
using namespace std::literals;
using namespace hana::literals;

namespace metal {
  //! [Data type]
  template <ptrdiff_t address, uint32_t mask> struct Register {
    static constexpr ptrdiff_t addr = address;
    static constexpr uint32_t m = mask;
  };

  //! [Data type]

  //! [Operator types]
  template <class R, uint32_t value> struct write_op {
    using reg = R;
    static constexpr uint32_t v = value;
  };
  //! [Operator types]

  //! [Operations]
  template <class R> constexpr auto set(R) { return write_op<R, R::m>{}; }
  //! [Operations]

  //! [Eval]
  template <class R, uint32_t value>
  constexpr auto getAddress(const write_op<R, value> &) {
    return R::addr;
  }

  template <class R, uint32_t value>
  constexpr auto getMask(const write_op<R, value> &) {
    return R::m;
  }

  template <typename... Args> void eval(Args... args) {
    constexpr auto regList =
        hana::sort(hana::make_tuple(args...), [](auto x, auto y) {
          return hana::bool_c<getAddress(x) == getAddress(y)>;
        });
    constexpr auto groupedRegs = hana::group(regList, [](auto x, auto y) {
      return hana::bool_c<getAddress(x) == getAddress(y)>;
    });
    hana::for_each(groupedRegs, [](auto group) {
      auto addr = getAddress(group[0_c]);
      uint32_t mask = hana::fold(group, 0U, [&](uint32_t init, auto op) {
        return init | getMask(op);
      });
      std::cout << reinterpret_cast<uint32_t *>(addr)
                << " |= " << std::bitset<16>(mask) << std::dec << "\n";
    });
  }

  //! [Eval]
}

//! [user code]
using namespace metal;

static constexpr Register<0x4000700, (1UL << 2)> myReg{};
static constexpr Register<0x4000700, (3UL << 10)> myReg2{};
static constexpr Register<0x4000704, (3UL << 8)> myReg3{};
static constexpr Register<0x4000700, (7UL << 13)> myReg4{};

int main(void) {
  eval(set(myReg));
  eval(set(myReg2));
  eval(set(myReg3));
  eval(set(myReg4));

  std::cout << "\nCombined\n";
  eval(            //
      set(myReg),  //
      set(myReg2), //
      set(myReg3), //
      set(myReg4)  //
      );
}
//! [user code]
