#pragma once
#include "Register/Utility.hpp"

namespace Kvasir {
  using namespace Register;

  using access_rw = ReadWriteAccess;
  using access_ro = ReadOnlyAccess;
  template <
      typename TAddress, unsigned Mask, typename Access = access_rw,
      typename TFieldType = unsigned>
  using field = FieldLocation<TAddress, Mask, Access, TFieldType>;

  // Power control
  namespace PwrCr { ///<power control register
    using Addr = Address<0x40007000, 0xfffffc00, 0x00000000, unsigned>;
    constexpr field<Addr, maskFromRange(9, 9)> fpds{};
    constexpr field<Addr, maskFromRange(8, 8)> dbp{};
    constexpr field<Addr, maskFromRange(7, 5)> pls{};
    constexpr field<Addr, maskFromRange(4, 4)> pvde{};
    constexpr field<Addr, maskFromRange(3, 3)> csbf{};
    constexpr field<Addr, maskFromRange(2, 2)> cwuf{};
    constexpr field<Addr, maskFromRange(1, 1)> pdds{};
    constexpr field<Addr, maskFromRange(0, 0)> lpds{};
  }
  namespace PwrCsr { ///<power control/status register
    using Addr = Address<0x40007004, 0xffffbcf0, 0x000c0000, unsigned>;
    constexpr field<Addr, maskFromRange(0, 0), access_ro, unsigned> wuf{};
    constexpr field<Addr, maskFromRange(1, 1), access_ro, unsigned> sbf{};
    constexpr field<Addr, maskFromRange(2, 2), access_ro, unsigned> pvdo{};
    constexpr field<Addr, maskFromRange(3, 3), access_ro, unsigned> brr{};
    constexpr field<Addr, maskFromRange(8, 8)> ewup{};
    constexpr field<Addr, maskFromRange(9, 9)> bre{};
    constexpr field<Addr, maskFromRange(14, 14)> vosrdy{};
    enum class UDVal { UDDisabled = 0b00, UDReady = 0b11 };
    constexpr field<Addr, maskFromRange(19, 18), ROneToClearAccess, UDVal>
        udrdy{};
  }
}

namespace Kvasir {
  // General-purpose I/Os
  namespace GpiodModer { ///<GPIO port mode register
    using Addr =
        Register::Address<0x40020c00, 0x00000000, 0x00000000, unsigned>;
    enum class ModeVal {
      input = 0b00,
      output = 0b01,
      af = 0b10,
      analog = 0b11
    };
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 30), Register::ReadWriteAccess,
        unsigned>
        moder15{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 28), Register::ReadWriteAccess,
        unsigned>
        moder14{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 26), Register::ReadWriteAccess,
        unsigned>
        moder13{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 24), Register::ReadWriteAccess,
        unsigned>
        moder12{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 22), Register::ReadWriteAccess,
        unsigned>
        moder11{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 20), Register::ReadWriteAccess,
        unsigned>
        moder10{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 18), Register::ReadWriteAccess,
        unsigned>
        moder9{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 16), Register::ReadWriteAccess,
        unsigned>
        moder8{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 14), Register::ReadWriteAccess,
        unsigned>
        moder7{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 12), Register::ReadWriteAccess,
        unsigned>
        moder6{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 10), Register::ReadWriteAccess,
        unsigned>
        moder5{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 8), Register::ReadWriteAccess,
        unsigned>
        moder4{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 6), Register::ReadWriteAccess,
        unsigned>
        moder3{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 4), Register::ReadWriteAccess,
        unsigned>
        moder2{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 2), Register::ReadWriteAccess,
        unsigned>
        moder1{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 0), Register::ReadWriteAccess,
        unsigned>
        moder0{};
  }
  namespace GpiodOtyper { ///<GPIO port output type register
    using Addr =
        Register::Address<0x40020c04, 0xffff0000, 0x00000000, unsigned>;
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        ot15{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        ot14{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        ot13{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        ot12{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        ot11{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        ot10{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        ot9{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        ot8{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        ot7{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        ot6{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        ot5{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        ot4{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        ot3{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        ot2{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        ot1{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        ot0{};
  }
  namespace GpiodOspeedr { ///<GPIO port output speed          register
    using Addr =
        Register::Address<0x40020c08, 0x00000000, 0x00000000, unsigned>;
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 30), Register::ReadWriteAccess,
        unsigned>
        ospeedr15{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 28), Register::ReadWriteAccess,
        unsigned>
        ospeedr14{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 26), Register::ReadWriteAccess,
        unsigned>
        ospeedr13{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 24), Register::ReadWriteAccess,
        unsigned>
        ospeedr12{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 22), Register::ReadWriteAccess,
        unsigned>
        ospeedr11{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 20), Register::ReadWriteAccess,
        unsigned>
        ospeedr10{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 18), Register::ReadWriteAccess,
        unsigned>
        ospeedr9{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 16), Register::ReadWriteAccess,
        unsigned>
        ospeedr8{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 14), Register::ReadWriteAccess,
        unsigned>
        ospeedr7{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 12), Register::ReadWriteAccess,
        unsigned>
        ospeedr6{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 10), Register::ReadWriteAccess,
        unsigned>
        ospeedr5{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 8), Register::ReadWriteAccess,
        unsigned>
        ospeedr4{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 6), Register::ReadWriteAccess,
        unsigned>
        ospeedr3{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 4), Register::ReadWriteAccess,
        unsigned>
        ospeedr2{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 2), Register::ReadWriteAccess,
        unsigned>
        ospeedr1{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 0), Register::ReadWriteAccess,
        unsigned>
        ospeedr0{};
  }
  namespace GpiodPupdr { ///<GPIO port pull-up/pull-down          register
    using Addr =
        Register::Address<0x40020c0c, 0x00000000, 0x00000000, unsigned>;
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 30), Register::ReadWriteAccess,
        unsigned>
        pupdr15{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 28), Register::ReadWriteAccess,
        unsigned>
        pupdr14{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 26), Register::ReadWriteAccess,
        unsigned>
        pupdr13{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 24), Register::ReadWriteAccess,
        unsigned>
        pupdr12{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 22), Register::ReadWriteAccess,
        unsigned>
        pupdr11{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 20), Register::ReadWriteAccess,
        unsigned>
        pupdr10{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 18), Register::ReadWriteAccess,
        unsigned>
        pupdr9{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 16), Register::ReadWriteAccess,
        unsigned>
        pupdr8{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 14), Register::ReadWriteAccess,
        unsigned>
        pupdr7{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 12), Register::ReadWriteAccess,
        unsigned>
        pupdr6{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 10), Register::ReadWriteAccess,
        unsigned>
        pupdr5{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 8), Register::ReadWriteAccess,
        unsigned>
        pupdr4{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 6), Register::ReadWriteAccess,
        unsigned>
        pupdr3{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 4), Register::ReadWriteAccess,
        unsigned>
        pupdr2{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 2), Register::ReadWriteAccess,
        unsigned>
        pupdr1{};
    /// Port x configuration bits (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 0), Register::ReadWriteAccess,
        unsigned>
        pupdr0{};
  }
  namespace GpiodIdr { ///<GPIO port input data register
    using Addr =
        Register::Address<0x40020c10, 0xffff0000, 0x00000000, unsigned>;
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        idr15{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        idr14{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        idr13{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        idr12{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        idr11{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        idr10{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        idr9{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        idr8{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        idr7{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        idr6{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        idr5{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        idr4{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        idr3{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        idr2{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        idr1{};
    /// Port input data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        idr0{};
  }
  namespace GpiodOdr { ///<GPIO port output data register
    using Addr =
        Register::Address<0x40020c14, 0xffff0000, 0x00000000, unsigned>;
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        odr15{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        odr14{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        odr13{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        odr12{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        odr11{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        odr10{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        odr9{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        odr8{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        odr7{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        odr6{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        odr5{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        odr4{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        odr3{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        odr2{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        odr1{};
    /// Port output data (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        odr0{};
  }
  namespace GpiodBsrr { ///<GPIO port bit set/reset          register
    using Addr =
        Register::Address<0x40020c18, 0x00000000, 0x00000000, unsigned>;
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 31), Register::ReadWriteAccess,
        unsigned>
        br15{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 30), Register::ReadWriteAccess,
        unsigned>
        br14{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        br13{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        br12{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 27), Register::ReadWriteAccess,
        unsigned>
        br11{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        br10{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        br9{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(24, 24), Register::ReadWriteAccess,
        unsigned>
        br8{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23), Register::ReadWriteAccess,
        unsigned>
        br7{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        br6{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        br5{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 20), Register::ReadWriteAccess,
        unsigned>
        br4{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19), Register::ReadWriteAccess,
        unsigned>
        br3{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        br2{};
    /// Port x reset bit y (y =              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        br1{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        br0{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        bs15{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        bs14{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        bs13{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        bs12{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        bs11{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        bs10{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        bs9{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        bs8{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        bs7{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        bs6{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        bs5{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        bs4{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        bs3{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        bs2{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        bs1{};
    /// Port x set bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        bs0{};
  }
  namespace GpiodLckr { ///<GPIO port configuration lock          register
    using Addr =
        Register::Address<0x40020c1c, 0xfffe0000, 0x00000000, unsigned>;
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        lckk{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        lck15{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        lck14{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        lck13{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        lck12{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        lck11{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        lck10{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        lck9{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        lck8{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        lck7{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        lck6{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        lck5{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        lck4{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        lck3{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        lck2{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        lck1{};
    /// Port x lock bit y (y=              0..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        lck0{};
  }
  namespace GpiodAfrl { ///<GPIO alternate function low          register
    using Addr =
        Register::Address<0x40020c20, 0x00000000, 0x00000000, unsigned>;
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 28), Register::ReadWriteAccess,
        unsigned>
        afrl7{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 24), Register::ReadWriteAccess,
        unsigned>
        afrl6{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 20), Register::ReadWriteAccess,
        unsigned>
        afrl5{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 16), Register::ReadWriteAccess,
        unsigned>
        afrl4{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 12), Register::ReadWriteAccess,
        unsigned>
        afrl3{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 8), Register::ReadWriteAccess,
        unsigned>
        afrl2{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 4), Register::ReadWriteAccess,
        unsigned>
        afrl1{};
    /// Alternate function selection for port x              bit y (y = 0..7)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 0), Register::ReadWriteAccess,
        unsigned>
        afrl0{};
  }
  namespace GpiodAfrh { ///<GPIO alternate function high          register
    using Addr =
        Register::Address<0x40020c24, 0x00000000, 0x00000000, unsigned>;
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 28), Register::ReadWriteAccess,
        unsigned>
        afrh15{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 24), Register::ReadWriteAccess,
        unsigned>
        afrh14{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 20), Register::ReadWriteAccess,
        unsigned>
        afrh13{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 16), Register::ReadWriteAccess,
        unsigned>
        afrh12{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 12), Register::ReadWriteAccess,
        unsigned>
        afrh11{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 8), Register::ReadWriteAccess,
        unsigned>
        afrh10{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 4), Register::ReadWriteAccess,
        unsigned>
        afrh9{};
    /// Alternate function selection for port x              bit y (y = 8..15)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 0), Register::ReadWriteAccess,
        unsigned>
        afrh8{};
  }
}
namespace Kvasir {
  // Reset and clock control
  namespace RccCr { ///<clock control register
    using Addr =
        Register::Address<0x40023800, 0xf0f00004, 0x00000000, unsigned>;
    enum class RegVal { resetVal = 0x00000083 };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 0), Register::ReadWriteAccess, RegVal>
        reg{};
    namespace RegValC {
      constexpr Register::FieldValue<decltype(reg)::Type, RegVal::resetVal>
          resetVal{};
    }
    /// PLLI2S clock ready flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 27),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        plli2srdy{};
    /// PLLI2S enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        plli2son{};
    /// Main PLL (PLL) clock ready              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        pllrdy{};
    /// Main PLL (PLL) enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(24, 24), Register::ReadWriteAccess,
        unsigned>
        pllon{};
    /// Clock security system              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19), Register::ReadWriteAccess,
        unsigned>
        csson{};
    /// HSE clock bypass
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        hsebyp{};
    /// HSE clock ready flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hserdy{};
    /// HSE clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        hseon{};
    /// Internal high-speed clock              calibration
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 8),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hsical{};
    /// Internal high-speed clock              trimming
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 3), Register::ReadWriteAccess,
        unsigned>
        hsitrim{};
    /// Internal high-speed clock ready              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hsirdy{};
    /// Internal high-speed clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        hsion{};
  }
  namespace RccPllcfgr { ///<PLL configuration register
    using Addr =
        Register::Address<0x40023804, 0xf0bc8000, 0x00000000, unsigned>;
    enum class RegVal { resetVal = 0x24003010 };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 0), Register::ReadWriteAccess, RegVal>
        reg{};
    namespace RegValC {
      constexpr Register::FieldValue<decltype(reg)::Type, RegVal::resetVal>
          resetVal{};
    }
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 0), Register::ReadWriteAccess,
        unsigned>
        ureg{};
    /// Main PLL (PLL) division factor for USB              OTG FS, SDIO and
    /// random number generator              clocks
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 24), Register::ReadWriteAccess,
        unsigned>
        pllq{};
    /// Main PLL(PLL) and audio PLL (PLLI2S)              entry clock source
    enum class SrcVal { hsi = 0x0, hse = 0x1 };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        SrcVal>
        pllsrc{};
    namespace SrcValC {
      constexpr Register::FieldValue<decltype(pllsrc)::Type, SrcVal::hsi> hsi{};
      constexpr Register::FieldValue<decltype(pllsrc)::Type, SrcVal::hse> hse{};
    }
    /// Main PLL (PLL) division factor for main              system clock
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 16), Register::ReadWriteAccess,
        unsigned>
        pllp{};
    /// Main PLL (PLL) multiplication factor for              VCO
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 6), Register::ReadWriteAccess,
        unsigned>
        plln{};
    /// Division factor for the main PLL (PLL)              and audio PLL
    /// (PLLI2S) input clock
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 0), Register::ReadWriteAccess,
        unsigned>
        pllm{};
  }
  namespace RccCfgr { ///<clock configuration register
    using Addr =
        Register::Address<0x40023808, 0x00000300, 0x00000000, unsigned>;
    enum class RegVal { resetVal = 0x00000000 };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 0), Register::ReadWriteAccess, RegVal>
        reg{};
    namespace RegValC {
      constexpr Register::FieldValue<decltype(reg)::Type, RegVal::resetVal>
          resetVal{};
    }
    /// Microcontroller clock output              2
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 30), Register::ReadWriteAccess,
        unsigned>
        mco2{};
    /// MCO2 prescaler
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 27), Register::ReadWriteAccess,
        unsigned>
        mco2pre{};
    /// MCO1 prescaler
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 24), Register::ReadWriteAccess,
        unsigned>
        mco1pre{};
    /// I2S clock selection
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23), Register::ReadWriteAccess,
        unsigned>
        i2ssrc{};
    /// Microcontroller clock output              1
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 21), Register::ReadWriteAccess,
        unsigned>
        mco1{};
    /// HSE division factor for RTC              clock
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 16), Register::ReadWriteAccess,
        unsigned>
        rtcpre{};
    /// APB high-speed prescaler              (APB2)
    enum class Ppre2Val {
      div1 = 0b000,
      div2 = 0b100,
      div4 = 0b101,
      div8 = 0b110,
      div16 = 0b111
    };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 13), Register::ReadWriteAccess,
        Ppre2Val>
        ppre2{};
    namespace Ppre2ValC {
      constexpr Register::FieldValue<decltype(ppre2)::Type, Ppre2Val::div1>
          div1{};
      constexpr Register::FieldValue<decltype(ppre2)::Type, Ppre2Val::div2>
          div2{};
      constexpr Register::FieldValue<decltype(ppre2)::Type, Ppre2Val::div4>
          div4{};
      constexpr Register::FieldValue<decltype(ppre2)::Type, Ppre2Val::div8>
          div8{};
    }
    /// APB Low speed prescaler              (APB1)
    enum class Ppre1Val {
      div1 = 0b000,
      div2 = 0b100,
      div4 = 0b101,
      div8 = 0b110,
      div16 = 0b111
    };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 10), Register::ReadWriteAccess,
        Ppre1Val>
        ppre1{};
    namespace Ppre1ValC {
      constexpr Register::FieldValue<decltype(ppre1)::Type, Ppre1Val::div1>
          div1{};
      constexpr Register::FieldValue<decltype(ppre1)::Type, Ppre1Val::div2>
          div2{};
      constexpr Register::FieldValue<decltype(ppre1)::Type, Ppre1Val::div4>
          div4{};
      constexpr Register::FieldValue<decltype(ppre1)::Type, Ppre1Val::div8>
          div8{};
    }
    /// AHB prescaler
    enum class HpreVal {
      div1 = 0b0000,
      div2 = 0b1000,
      div4 = 0b1001,
      div8 = 0b1010
      // TODO
    };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 4), Register::ReadWriteAccess, HpreVal>
        hpre{};
    namespace HpreValC {
      constexpr Register::FieldValue<decltype(hpre)::Type, HpreVal::div1>
          div1{};
    }
    /// System clock switch status
    enum class SwVal {
      hsi = 0b00,
      hse = 0b01,
      pll = 0b10,
    };
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 2),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        SwVal>
        sws{};
    namespace SwsValC {
      constexpr Register::FieldValue<decltype(sws)::Type, SwVal::hsi> hsi{};
      constexpr Register::FieldValue<decltype(sws)::Type, SwVal::hse> hse{};
      constexpr Register::FieldValue<decltype(sws)::Type, SwVal::pll> pll{};
    }
    /// System clock switch
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 0), Register::ReadWriteAccess, SwVal>
        sw{};
    namespace SwValC {
      constexpr Register::FieldValue<decltype(sw)::Type, SwVal::hsi> hsi{};
      constexpr Register::FieldValue<decltype(sw)::Type, SwVal::hse> hse{};
      constexpr Register::FieldValue<decltype(sw)::Type, SwVal::pll> pll{};
    }
  }
  namespace RccCir { ///<clock interrupt register
    using Addr =
        Register::Address<0x4002380c, 0xff40c040, 0x00000000, unsigned>;
    /// Clock security system interrupt              clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        cssc{};
    /// PLLI2S ready interrupt              clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        plli2srdyc{};
    /// Main PLL(PLL) ready interrupt              clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 20),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        pllrdyc{};
    /// HSE ready interrupt clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hserdyc{};
    /// HSI ready interrupt clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hsirdyc{};
    /// LSE ready interrupt clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lserdyc{};
    /// LSI ready interrupt clear
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16),
        Register::Access<
            Register::AccessType::writeOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lsirdyc{};
    /// PLLI2S ready interrupt              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(13, 13), Register::ReadWriteAccess,
        unsigned>
        plli2srdyie{};
    /// Main PLL (PLL) ready interrupt              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        pllrdyie{};
    /// HSE ready interrupt enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        hserdyie{};
    /// HSI ready interrupt enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        hsirdyie{};
    /// LSE ready interrupt enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        lserdyie{};
    /// LSI ready interrupt enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        lsirdyie{};
    /// Clock security system interrupt              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        cssf{};
    /// PLLI2S ready interrupt              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        plli2srdyf{};
    /// Main PLL (PLL) ready interrupt              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        pllrdyf{};
    /// HSE ready interrupt flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hserdyf{};
    /// HSI ready interrupt flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        hsirdyf{};
    /// LSE ready interrupt flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lserdyf{};
    /// LSI ready interrupt flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lsirdyf{};
  }
  namespace RccAhb1rstr { ///<AHB1 peripheral reset register
    using Addr =
        Register::Address<0x40023810, 0xdd9fee00, 0x00000000, unsigned>;
    /// USB OTG HS module reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        otghsrst{};
    /// Ethernet MAC reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        ethmacrst{};
    /// DMA2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        dma2rst{};
    /// DMA2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        dma1rst{};
    /// CRC reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        crcrst{};
    /// IO port I reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        gpioirst{};
    /// IO port H reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        gpiohrst{};
    /// IO port G reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        gpiogrst{};
    /// IO port F reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        gpiofrst{};
    /// IO port E reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        gpioerst{};
    /// IO port D reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        gpiodrst{};
    /// IO port C reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        gpiocrst{};
    /// IO port B reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        gpiobrst{};
    /// IO port A reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        gpioarst{};
  }
  namespace RccAhb2rstr { ///<AHB2 peripheral reset register
    using Addr =
        Register::Address<0x40023814, 0xffffff3e, 0x00000000, unsigned>;
    /// USB OTG FS module reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        otgfsrst{};
    /// Random number generator module              reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        rngrst{};
    /// Camera interface reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        dcmirst{};
  }
  namespace RccAhb3rstr { ///<AHB3 peripheral reset register
    using Addr =
        Register::Address<0x40023818, 0xfffffffe, 0x00000000, unsigned>;
    /// Flexible static memory controller module              reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        fsmcrst{};
  }
  namespace RccApb1rstr { ///<APB1 peripheral reset register
    using Addr =
        Register::Address<0x40023820, 0xc9013600, 0x00000000, unsigned>;
    /// DAC reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        dacrst{};
    /// Power interface reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        pwrrst{};
    /// CAN2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        can2rst{};
    /// CAN1 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        can1rst{};
    /// I2C3 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23), Register::ReadWriteAccess,
        unsigned>
        i2c3rst{};
    /// I2C 2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        i2c2rst{};
    /// I2C 1 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        i2c1rst{};
    /// USART 5 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 20), Register::ReadWriteAccess,
        unsigned>
        uart5rst{};
    /// USART 4 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19), Register::ReadWriteAccess,
        unsigned>
        uart4rst{};
    /// USART 3 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        uart3rst{};
    /// USART 2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        uart2rst{};
    /// SPI 3 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        spi3rst{};
    /// SPI 2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        spi2rst{};
    /// Window watchdog reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        wwdgrst{};
    /// TIM14 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        tim14rst{};
    /// TIM13 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        tim13rst{};
    /// TIM12 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        tim12rst{};
    /// TIM7 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        tim7rst{};
    /// TIM6 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        tim6rst{};
    /// TIM5 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        tim5rst{};
    /// TIM4 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        tim4rst{};
    /// TIM3 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim3rst{};
    /// TIM2 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim2rst{};
  }
  namespace RccApb2rstr { ///<APB2 peripheral reset register
    using Addr =
        Register::Address<0x40023824, 0xfff8a6cc, 0x00000000, unsigned>;
    /// TIM11 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        tim11rst{};
    /// TIM10 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        tim10rst{};
    /// TIM9 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        tim9rst{};
    /// System configuration controller              reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        syscfgrst{};
    /// SPI 1 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        spi1rst{};
    /// SDIO reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        sdiorst{};
    /// ADC interface reset (common to all              ADCs)
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        adcrst{};
    /// USART6 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        usart6rst{};
    /// USART1 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        usart1rst{};
    /// TIM8 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim8rst{};
    /// TIM1 reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim1rst{};
  }
  namespace RccAhb1enr { ///<AHB1 peripheral clock register
    using Addr =
        Register::Address<0x40023830, 0x819bee00, 0x00000000, unsigned>;
    /// USB OTG HSULPI clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 30), Register::ReadWriteAccess,
        unsigned>
        otghsulpien{};
    /// USB OTG HS clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        otghsen{};
    /// Ethernet PTP clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        ethmacptpen{};
    /// Ethernet Reception clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 27), Register::ReadWriteAccess,
        unsigned>
        ethmacrxen{};
    /// Ethernet Transmission clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        ethmactxen{};
    /// Ethernet MAC clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        ethmacen{};
    /// DMA2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        dma2en{};
    /// DMA1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        dma1en{};
    /// Backup SRAM interface clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        bkpsramen{};
    /// CRC clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        crcen{};
    /// IO port I clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        gpioien{};
    /// IO port H clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        gpiohen{};
    /// IO port G clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        gpiogen{};
    /// IO port F clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        gpiofen{};
    /// IO port E clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        gpioeen{};
    /// IO port D clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        gpioden{};
    /// IO port C clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        gpiocen{};
    /// IO port B clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        gpioben{};
    /// IO port A clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        gpioaen{};
  }
  namespace RccAhb2enr { ///<AHB2 peripheral clock enable          register
    using Addr =
        Register::Address<0x40023834, 0xffffff3e, 0x00000000, unsigned>;
    /// USB OTG FS clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        otgfsen{};
    /// Random number generator clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        rngen{};
    /// Camera interface enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        dcmien{};
  }
  namespace RccAhb3enr { ///<AHB3 peripheral clock enable          register
    using Addr =
        Register::Address<0x40023838, 0xfffffffe, 0x00000000, unsigned>;
    /// Flexible static memory controller module              clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        fsmcen{};
  }
  namespace RccApb1enr { ///<APB1 peripheral clock enable          register
    using Addr =
        Register::Address<0x40023840, 0xc9013600, 0x00000000, unsigned>;
    /// DAC interface clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        dacen{};
    /// Power interface clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        pwren{};
    /// CAN 2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        can2en{};
    /// CAN 1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        can1en{};
    /// I2C3 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23), Register::ReadWriteAccess,
        unsigned>
        i2c3en{};
    /// I2C2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        i2c2en{};
    /// I2C1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        i2c1en{};
    /// UART5 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 20), Register::ReadWriteAccess,
        unsigned>
        uart5en{};
    /// UART4 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19), Register::ReadWriteAccess,
        unsigned>
        uart4en{};
    /// USART3 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        usart3en{};
    /// USART 2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        usart2en{};
    /// SPI3 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        spi3en{};
    /// SPI2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        spi2en{};
    /// Window watchdog clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        wwdgen{};
    /// TIM14 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        tim14en{};
    /// TIM13 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        tim13en{};
    /// TIM12 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        tim12en{};
    /// TIM7 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        tim7en{};
    /// TIM6 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        tim6en{};
    /// TIM5 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        tim5en{};
    /// TIM4 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        tim4en{};
    /// TIM3 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim3en{};
    /// TIM2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim2en{};
  }
  namespace RccApb2enr { ///<APB2 peripheral clock enable          register
    using Addr =
        Register::Address<0x40023844, 0xfff8a0cc, 0x00000000, unsigned>;
    /// TIM11 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        tim11en{};
    /// TIM10 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        tim10en{};
    /// TIM9 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        tim9en{};
    /// System configuration controller clock              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        syscfgen{};
    /// SPI1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        spi1en{};
    /// SDIO clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        sdioen{};
    /// ADC3 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        adc3en{};
    /// ADC2 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        adc2en{};
    /// ADC1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        adc1en{};
    /// USART6 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        usart6en{};
    /// USART1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        usart1en{};
    /// TIM8 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim8en{};
    /// TIM1 clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim1en{};
  }
  namespace RccAhb1lpenr { ///<AHB1 peripheral clock enable in low power
                           ///mode register
    using Addr =
        Register::Address<0x40023850, 0x81986e00, 0x00000000, unsigned>;
    /// USB OTG HS ULPI clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 30), Register::ReadWriteAccess,
        unsigned>
        otghsulpilpen{};
    /// USB OTG HS clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        otghslpen{};
    /// Ethernet PTP clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        ethmacptplpen{};
    /// Ethernet reception clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 27), Register::ReadWriteAccess,
        unsigned>
        ethmacrxlpen{};
    /// Ethernet transmission clock enable              during Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        ethmactxlpen{};
    /// Ethernet MAC clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        ethmaclpen{};
    /// DMA2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        dma2lpen{};
    /// DMA1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        dma1lpen{};
    /// Backup SRAM interface clock enable              during Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        bkpsramlpen{};
    /// SRAM 2 interface clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        sram2lpen{};
    /// SRAM 1interface clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        sram1lpen{};
    /// Flash interface clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        flitflpen{};
    /// CRC clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        crclpen{};
    /// IO port I clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        gpioilpen{};
    /// IO port H clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        gpiohlpen{};
    /// IO port G clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        gpioglpen{};
    /// IO port F clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        gpioflpen{};
    /// IO port E clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        gpioelpen{};
    /// IO port D clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        gpiodlpen{};
    /// IO port C clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        gpioclpen{};
    /// IO port B clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        gpioblpen{};
    /// IO port A clock enable during sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        gpioalpen{};
  }
  namespace RccAhb2lpenr { ///<AHB2 peripheral clock enable in low power
                           ///mode register
    using Addr =
        Register::Address<0x40023854, 0xffffff3e, 0x00000000, unsigned>;
    /// USB OTG FS clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        otgfslpen{};
    /// Random number generator clock enable              during Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        rnglpen{};
    /// Camera interface enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        dcmilpen{};
  }
  namespace RccAhb3lpenr { ///<AHB3 peripheral clock enable in low power
                           ///mode register
    using Addr =
        Register::Address<0x40023858, 0xfffffffe, 0x00000000, unsigned>;
    /// Flexible static memory controller module              clock enable
    /// during Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        fsmclpen{};
  }
  namespace RccApb1lpenr { ///<APB1 peripheral clock enable in low power
                           ///mode register
    using Addr =
        Register::Address<0x40023860, 0xc9013600, 0x00000000, unsigned>;
    /// DAC interface clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        daclpen{};
    /// Power interface clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        pwrlpen{};
    /// CAN 2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        can2lpen{};
    /// CAN 1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        can1lpen{};
    /// I2C3 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(23, 23), Register::ReadWriteAccess,
        unsigned>
        i2c3lpen{};
    /// I2C2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(22, 22), Register::ReadWriteAccess,
        unsigned>
        i2c2lpen{};
    /// I2C1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(21, 21), Register::ReadWriteAccess,
        unsigned>
        i2c1lpen{};
    /// UART5 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(20, 20), Register::ReadWriteAccess,
        unsigned>
        uart5lpen{};
    /// UART4 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(19, 19), Register::ReadWriteAccess,
        unsigned>
        uart4lpen{};
    /// USART3 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        usart3lpen{};
    /// USART2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        usart2lpen{};
    /// SPI3 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        spi3lpen{};
    /// SPI2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        spi2lpen{};
    /// Window watchdog clock enable during              Sleep mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        wwdglpen{};
    /// TIM14 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        tim14lpen{};
    /// TIM13 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(7, 7), Register::ReadWriteAccess,
        unsigned>
        tim13lpen{};
    /// TIM12 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(6, 6), Register::ReadWriteAccess,
        unsigned>
        tim12lpen{};
    /// TIM7 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        tim7lpen{};
    /// TIM6 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        tim6lpen{};
    /// TIM5 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(3, 3), Register::ReadWriteAccess,
        unsigned>
        tim5lpen{};
    /// TIM4 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        tim4lpen{};
    /// TIM3 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim3lpen{};
    /// TIM2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim2lpen{};
  }
  namespace RccApb2lpenr { ///<APB2 peripheral clock enabled in low power
                           ///mode register
    using Addr =
        Register::Address<0x40023864, 0xfff8a0cc, 0x00000000, unsigned>;
    /// TIM11 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(18, 18), Register::ReadWriteAccess,
        unsigned>
        tim11lpen{};
    /// TIM10 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(17, 17), Register::ReadWriteAccess,
        unsigned>
        tim10lpen{};
    /// TIM9 clock enable during sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        tim9lpen{};
    /// System configuration controller clock              enable during Sleep
    /// mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 14), Register::ReadWriteAccess,
        unsigned>
        syscfglpen{};
    /// SPI 1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 12), Register::ReadWriteAccess,
        unsigned>
        spi1lpen{};
    /// SDIO clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(11, 11), Register::ReadWriteAccess,
        unsigned>
        sdiolpen{};
    /// ADC 3 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(10, 10), Register::ReadWriteAccess,
        unsigned>
        adc3lpen{};
    /// ADC2 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        adc2lpen{};
    /// ADC1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        adc1lpen{};
    /// USART6 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(5, 5), Register::ReadWriteAccess,
        unsigned>
        usart6lpen{};
    /// USART1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(4, 4), Register::ReadWriteAccess,
        unsigned>
        usart1lpen{};
    /// TIM8 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1), Register::ReadWriteAccess,
        unsigned>
        tim8lpen{};
    /// TIM1 clock enable during Sleep              mode
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        tim1lpen{};
  }
  namespace RccBdcr { ///<Backup domain control register
    using Addr =
        Register::Address<0x40023870, 0xfffe7cf8, 0x00000000, unsigned>;
    /// Backup domain software              reset
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(16, 16), Register::ReadWriteAccess,
        unsigned>
        bdrst{};
    /// RTC clock enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(15, 15), Register::ReadWriteAccess,
        unsigned>
        rtcen{};
    /// RTC clock source selection
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(9, 9), Register::ReadWriteAccess,
        unsigned>
        rtcsel1{};
    /// RTC clock source selection
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(8, 8), Register::ReadWriteAccess,
        unsigned>
        rtcsel0{};
    /// External low-speed oscillator              bypass
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(2, 2), Register::ReadWriteAccess,
        unsigned>
        lsebyp{};
    /// External low-speed oscillator              ready
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lserdy{};
    /// External low-speed oscillator              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        lseon{};
  }
  namespace RccCsr { ///<clock control & status          register
    using Addr =
        Register::Address<0x40023874, 0x00fffffc, 0x00000000, unsigned>;
    /// Low-power reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 31), Register::ReadWriteAccess,
        unsigned>
        lpwrrstf{};
    /// Window watchdog reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 30), Register::ReadWriteAccess,
        unsigned>
        wwdgrstf{};
    /// Independent watchdog reset              flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(29, 29), Register::ReadWriteAccess,
        unsigned>
        wdgrstf{};
    /// Software reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(28, 28), Register::ReadWriteAccess,
        unsigned>
        sftrstf{};
    /// POR/PDR reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 27), Register::ReadWriteAccess,
        unsigned>
        porrstf{};
    /// PIN reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(26, 26), Register::ReadWriteAccess,
        unsigned>
        padrstf{};
    /// BOR reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(25, 25), Register::ReadWriteAccess,
        unsigned>
        borrstf{};
    /// Remove reset flag
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(24, 24), Register::ReadWriteAccess,
        unsigned>
        rmvf{};
    /// Internal low-speed oscillator              ready
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(1, 1),
        Register::Access<
            Register::AccessType::readOnly, Register::ReadActionType::normal,
            Register::ModifiedWriteValueType::normal>,
        unsigned>
        lsirdy{};
    /// Internal low-speed oscillator              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(0, 0), Register::ReadWriteAccess,
        unsigned>
        lsion{};
  }
  namespace RccSscgr { ///<spread spectrum clock generation          register
    using Addr =
        Register::Address<0x40023880, 0x30000000, 0x00000000, unsigned>;
    /// Spread spectrum modulation              enable
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(31, 31), Register::ReadWriteAccess,
        unsigned>
        sscgen{};
    /// Spread Select
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 30), Register::ReadWriteAccess,
        unsigned>
        spreadsel{};
    /// Incrementation step
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(27, 13), Register::ReadWriteAccess,
        unsigned>
        incstep{};
    /// Modulation period
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(12, 0), Register::ReadWriteAccess,
        unsigned>
        modper{};
  }
  namespace RccPlli2scfgr { ///<PLLI2S configuration register
    using Addr =
        Register::Address<0x40023884, 0x8fff803f, 0x00000000, unsigned>;
    /// PLLI2S division factor for I2S              clocks
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(30, 28), Register::ReadWriteAccess,
        unsigned>
        plli2srx{};
    /// PLLI2S multiplication factor for              VCO
    constexpr Register::FieldLocation<
        Addr, Register::maskFromRange(14, 6), Register::ReadWriteAccess,
        unsigned>
        plli2snx{};
  }
}

namespace Kvasir {
  namespace Io {
    template <int Port, int Pin>
    struct MakeAction<Action::Output, Register::PinLocation<Port, Pin>>
        : Register::Action<
              Register::FieldLocation<
                  Register::Address<
                      0x40020000 + (0x400 * Port), 0x00000000, 0x00000000,
                      unsigned>,
                  (1 << (Pin * 2))>,
              Register::WriteLiteralAction<(1 << (Pin * 2))>> {};

    template <int Port, int Pin>
    struct MakeAction<Action::Set, Register::PinLocation<Port, Pin>>
        : Register::Detail::Set<Register::FieldLocation<
              Register::Address<
                  0x40020014 + (0x400 * Port), 0xffff0000, 0x00000000,
                  unsigned>,
              (1 << Pin)>> {};

    template <int Port, int Pin>
    struct MakeAction<Action::Toggle, Register::PinLocation<Port, Pin>>
        : Register::Action<
              Register::FieldLocation<
                  Register::Address<
                      0x40020014 + (0x400 * Port), 0xffff0000, 0x00000000,
                      unsigned>,
                  (1 << Pin)>,
              Register::XorLiteralAction<(1 << Pin)>> {};
  }
}
