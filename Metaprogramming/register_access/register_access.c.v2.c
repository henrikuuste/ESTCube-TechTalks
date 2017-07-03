#include <stdint.h>
#include <stdio.h>

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

#define PACKED __attribute__((packed))

typedef union {
  uint32_t d32;
  struct PACKED {
    uint_fast8_t wuf : 1;
    uint_fast8_t sbf : 1;
    uint_fast8_t pvdo : 1;
    uint_fast8_t brr : 1;
    uint_fast8_t reserved7_4 : 4;
    uint_fast8_t ewup : 1;
    uint_fast8_t bre : 1;
    uint_fast8_t reserved13_10 : 4;
    uint_fast8_t vosrdy : 1;
    uint_fast8_t rserved15 : 1;
    uint_fast8_t odrdy : 1;
    uint_fast8_t odswrdy : 1;
    uint_fast8_t udrdy : 2;
    uint_fast16_t reserved31_20 : 12;
  } v;
} PWR_Reg_t;

#define PERIPH_BASE 0x40000000U /*!< Peripheral base address */
#define APB1PERIPH_BASE PERIPH_BASE
#define PWR_BASE (APB1PERIPH_BASE + 0x7000U)
#define PWR ((volatile PWR_Reg_t *)(PWR_BASE + 0x04))

//! [user code]
int main() {
  // Enable wake-up pin by writing 1 to [EWUP]
  PWR->v.ewup = 1;
  // Check standby with [SBF]
  if (PWR->v.sbf) {
    asm volatile("nop"); // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if ((PWR->v.udrdy) == 3) {
    PWR->v.udrdy = 3;
    asm volatile("nop"); // do something else useful
  }
}
//! [user code]
