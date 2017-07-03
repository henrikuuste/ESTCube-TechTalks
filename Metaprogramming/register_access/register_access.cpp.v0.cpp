#include "../helpers/port.h"
#include <cstddef>
#include <cstdint>

class Register {
public:
  Register(std::ptrdiff_t address, uint32_t mask = 0xFFFF'FFFF)
      : reg(reinterpret_cast<volatile uint32_t *>(address)), writeMask(mask),
        clearOnWriteOne(0) {}

protected:
  FORCED_INLINE void write(uint32_t pos, uint32_t value) {
    uint32_t data = ((value << pos) & writeMask);
    if (data & clearOnWriteOne) {
      *reg |= data;
    } else {
      *reg = (*reg & ~clearOnWriteOne) | data;
    }
  }
  FORCED_INLINE uint32_t read(uint32_t pos, uint32_t bits) {
    return (*reg & (bits << pos)) >> pos;
  }
  FORCED_INLINE bool test(uint32_t pos, uint32_t bits) {
    return this->read(pos, bits) == bits;
  }

  volatile uint32_t *reg;
  uint32_t writeMask;
  uint32_t clearOnWriteOne;
};

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

#define PERIPH_BASE 0x40000000U /*!< Peripheral base address */
#define APB1PERIPH_BASE PERIPH_BASE
#define PWR_BASE (APB1PERIPH_BASE + 0x7000U)

class PwrCsr : public Register {
public:
  PwrCsr() : Register(PWR_BASE + 0x04, 0x000F'430F) {
    clearOnWriteOne = 0x000C'0000;
  }
  FORCED_INLINE void enableWakeup() { write(8, 1); }
  FORCED_INLINE bool wasInStandby() { return test(1, 1); }
  FORCED_INLINE bool isUnderDriveReady() { return test(18, 0b11); }
  FORCED_INLINE void clearUnderDriveFlag() { write(18, 0b11); }
};

//! [user code]
int main() {
  PwrCsr p;
  // Enable wake-up pin by writing 1 to [EWUP]
  p.enableWakeup();
  // Check standby with [SBF]
  if (p.wasInStandby()) {
    TWIDDLE_THUMBS; // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if (p.isUnderDriveReady()) {
    p.clearUnderDriveFlag();
    TWIDDLE_THUMBS; // do something else useful
  }
}
//! [user code]
