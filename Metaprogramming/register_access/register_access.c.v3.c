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

#define __IO volatile

typedef struct {
  __IO uint32_t CR;  /*!< PWR power control register, offset: 0x00 */
  __IO uint32_t CSR; /*!< PWR power control/status register, offset: 0x04 */
} PWR_TypeDef;

#define PERIPH_BASE 0x40000000U /*!< Peripheral base address */
#define APB1PERIPH_BASE PERIPH_BASE
#define PWR_BASE (APB1PERIPH_BASE + 0x7000U)
#define PWR ((PWR_TypeDef *)PWR_BASE)

/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF_Pos (0U)
#define PWR_CSR_WUF_Msk (0x1U << PWR_CSR_WUF_Pos)
#define PWR_CSR_WUF PWR_CSR_WUF_Msk
#define PWR_CSR_SBF_Pos (1U)
#define PWR_CSR_SBF_Msk (0x1U << PWR_CSR_SBF_Pos)
#define PWR_CSR_SBF PWR_CSR_SBF_Msk
#define PWR_CSR_PVDO_Pos (2U)
#define PWR_CSR_PVDO_Msk (0x1U << PWR_CSR_PVDO_Pos)
#define PWR_CSR_PVDO PWR_CSR_PVDO_Msk
#define PWR_CSR_BRR_Pos (3U)
#define PWR_CSR_BRR_Msk (0x1U << PWR_CSR_BRR_Pos)
#define PWR_CSR_BRR PWR_CSR_BRR_Msk
#define PWR_CSR_EWUP_Pos (8U)
#define PWR_CSR_EWUP_Msk (0x1U << PWR_CSR_EWUP_Pos)
#define PWR_CSR_EWUP PWR_CSR_EWUP_Msk
#define PWR_CSR_BRE_Pos (9U)
#define PWR_CSR_BRE_Msk (0x1U << PWR_CSR_BRE_Pos)
#define PWR_CSR_BRE PWR_CSR_BRE_Msk
#define PWR_CSR_VOSRDY_Pos (14U)
#define PWR_CSR_VOSRDY_Msk (0x1U << PWR_CSR_VOSRDY_Pos)
#define PWR_CSR_VOSRDY PWR_CSR_VOSRDY_Msk
#define PWR_CSR_ODRDY_Pos (16U)
#define PWR_CSR_ODRDY_Msk (0x1U << PWR_CSR_ODRDY_Pos)
#define PWR_CSR_ODRDY PWR_CSR_ODRDY_Msk
#define PWR_CSR_ODSWRDY_Pos (17U)
#define PWR_CSR_ODSWRDY_Msk (0x1U << PWR_CSR_ODSWRDY_Pos)
#define PWR_CSR_ODSWRDY PWR_CSR_ODSWRDY_Msk
#define PWR_CSR_UDRDY_Pos (18U)
#define PWR_CSR_UDRDY_Msk (0x3U << PWR_CSR_UDRDY_Pos)
#define PWR_CSR_UDRDY PWR_CSR_UDRDY_Msk

/* Legacy define */
#define PWR_CSR_REGRDY PWR_CSR_VOSRDY


//! [user code]
int main() {
  // Enable wake-up pin by writing 1 to [EWUP]
  PWR->CSR |=  PWR_CSR_EWUP;
  // Check standby with [SBF]
  if (PWR->CSR & PWR_CSR_SBF) {
    asm volatile("nop"); // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if ((PWR->CSR & PWR_CSR_UDRDY) == PWR_CSR_UDRDY) {
    PWR->CSR |= PWR_CSR_UDRDY;
    asm volatile("nop"); // do something else useful
  }
}
//! [user code]
