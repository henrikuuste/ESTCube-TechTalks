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

//! [user code]
int main() {
  // Enable wake-up pin by writing 1 to [EWUP]
  *((volatile uint32_t *)0x40007004) |= (0x1 << 8);
  // Check standby with [SBF]
  if (*((volatile uint32_t *)0x40007004) & (0x1 << 1)) {
    asm volatile("nop"); // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if ((*((volatile uint32_t *)0x40007004) & (0x3 << 18)) == (0x3 << 18)) {
    *((volatile uint32_t *)0x40007004) |= (0x3 << 18);
    asm volatile("nop"); // do something else useful
  }
}
//! [user code]
