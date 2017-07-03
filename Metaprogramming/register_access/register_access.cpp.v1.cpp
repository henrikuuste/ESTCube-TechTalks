#include "../helpers/port.h"
#include <climits>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

using regsize_t = uint32_t;

namespace reg {
  INLINE_CONSTEXPR regsize_t nbits(regsize_t width) {
    return static_cast<regsize_t>(-(width != 0)) &
           (static_cast<regsize_t>(-1) >>
            ((sizeof(regsize_t) * CHAR_BIT) - width));
  }

  INLINE_CONSTEXPR regsize_t bitmask(regsize_t offset, regsize_t width) {
    return nbits(width) << offset;
  }

  namespace access {
    struct ro {
      INLINE_STATIC regsize_t
      read(volatile regsize_t *device, regsize_t offset, regsize_t mask) {
        return (*device & mask) >> offset;
      }
    };

    struct wo {
      INLINE_STATIC void write(
          volatile regsize_t *device, regsize_t offset, regsize_t mask,
          regsize_t value) {
        *device = ((value << offset) & mask);
      }

      INLINE_STATIC void set(volatile regsize_t *device, regsize_t mask) {
        *device = mask;
      }
    };

    struct rw : ro {
      INLINE_STATIC void write(
          volatile regsize_t *device, regsize_t offset, regsize_t mask,
          regsize_t value) {
        *device = (*device & ~mask) | ((value << offset) & mask);
      }

      INLINE_STATIC void set(volatile regsize_t *device, regsize_t mask) {
        *device |= mask;
      }

      INLINE_STATIC void clear(volatile regsize_t *device, regsize_t mask) {
        *device &= ~mask;
      }
    };
  }

  template <
      typename access_policy_t, regsize_t address, regsize_t offset,
      regsize_t width, regsize_t clearOnOne = 0x0>
  struct reg_t {

    static_assert(width > 0, "invalid field of zero width");
    static_assert(
        width + offset <= std::numeric_limits<regsize_t>::digits,
        "register width overflow");

    using type = volatile regsize_t *;
    [[gnu::always_inline]] inline static type ptr() {
      return reinterpret_cast<type>(address);
    }
    static constexpr auto bits = bitmask(0, width);
    static constexpr auto mask = bitmask(offset, width);

    INLINE_STATIC regsize_t read() {
      return access_policy_t::read(ptr(), offset, mask);
    }

    INLINE_STATIC void write(regsize_t value) {
      access_policy_t::write(ptr(), offset, mask | clearOnOne, value);
    }

    INLINE_STATIC bool test(regsize_t value = bits) { return read() == value; }

    INLINE_STATIC void set() {
      if (!clearOnOne) {
        access_policy_t::set(ptr(), mask);
      } else {
        access_policy_t::write(ptr(), offset, mask | clearOnOne, bits);
      }
    }

    INLINE_STATIC void clear() {
      if (!clearOnOne) {
        access_policy_t::clear(ptr(), mask);
      } else {
        access_policy_t::write(ptr(), offset, mask | clearOnOne, 0);
      }
    }
  };
}
/**
 * @DATASHEET
 * PWR registers 0x4000 7000 - 0x4000 73FF
 * PWR_CSR offset 0x04
 * | 31-20    | 19-18        | 17         | 16       |
 * | reserved | UDRDY[rc_w1] | ODSWRDY[r] | ODRDY[r] |
 *
 * | 15       | 14        | 13-10    | 9        | 8        |
 * | reserved | VOSRDY[r] | reserved | BRE[rw]  | EWUP[rw] |
 *
 * | 7-4      | 3      | 2       | 1      | 0      |
 * | reserved | BRR[r] | PVDO[r] | SBF[r] | WUF[r] |
 *
 * Reserved, must be kept at reset value.
 */

static constexpr regsize_t PERIPH_BASE = 0x40000000U;
static constexpr regsize_t APB1PERIPH_BASE = PERIPH_BASE;
static constexpr regsize_t PWR_BASE = APB1PERIPH_BASE + 0x7000U;

namespace Pwr {
  using namespace reg;
  static constexpr auto clearOnOne = bitmask(18, 2);
  using EnableWakeup = reg_t<access::rw, PWR_BASE + 0x04, 8, 1, clearOnOne>;
  INLINE_STATIC void enableWakeupPin() { EnableWakeup::set(); };
  using BackupRegulatorEnable = reg_t<access::rw, PWR_BASE + 0x04, 9, 1, clearOnOne>;
  INLINE_STATIC void enableBackupRegulator() { BackupRegulatorEnable::set(); };
  using StandByFlag = reg_t<access::ro, PWR_BASE + 0x04, 1, 1>;
  INLINE_STATIC bool checkStandBy() { return StandByFlag::test(); }
  using UnderDriveReady = reg_t<access::rw, PWR_BASE + 0x04, 18, 2>;
  INLINE_STATIC bool checkUnderDrive() {
    if (UnderDriveReady::test()) {
      UnderDriveReady::set();
      return true;
    }
    return false;
  }
}
//! [user code]
int main() {
  // Enable wake-up pin by writing 1 to [EWUP]
  Pwr::enableWakeupPin();
  // Check standby with [SBF]
  if (Pwr::checkStandBy()) {
    TWIDDLE_THUMBS; // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if (Pwr::checkUnderDrive()) {
    TWIDDLE_THUMBS; // do something else useful
  }
}
//! [user code]
