#include <limits.h>
#include <stdint.h>

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

/***********************************************************
* FROM MCU HEADER
***********************************************************/
#define PERIPH_BASE 0x40000000U /*!< Peripheral base address */
#define APB1PERIPH_BASE PERIPH_BASE
#define PWR_BASE (APB1PERIPH_BASE + 0x7000U)

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

// [Portability]
typedef uint32_t regsize_t;

// [Utilities]
#define NBITS(WIDTH)                                                           \
  ((regsize_t)(-(WIDTH != 0)) &                                                \
   ((regsize_t)(-1) >> ((sizeof(regsize_t) * CHAR_BIT) - WIDTH)))
#define BITMASK(OFFSET, WIDTH) (NBITS(WIDTH) << (OFFSET))
#define AS_REG(REG) (*((volatile regsize_t *)(REG)))

// [Register]
#define MAKE_REG_BASE(NAME, ADDR, WRITE_MASK, CLEARONE_MASK)                   \
  const ptrdiff_t NAME##_ADDR = (ADDR);                                        \
  const regsize_t NAME##_CO_MASK = (CLEARONE_MASK);                            \
  const regsize_t NAME##_WMASK = (WRITE_MASK);

#define MAKE_REG(REG, BASE, OFFSET, WIDTH)                                     \
  const ptrdiff_t REG##_ADDR = BASE##_ADDR;                                    \
  const regsize_t REG##_OFFSET = (OFFSET);                                     \
  const regsize_t REG##_WIDTH = (WIDTH);                                       \
  const regsize_t REG##_CO_MASK = ~(BASE##_CO_MASK);                           \
  const regsize_t REG##_MASK = (BITMASK(REG##_OFFSET, REG##_WIDTH));

#define REG_MASK(REG) REG##_MASK
#define REG_OFFSET(REG) REG##_OFFSET
#define REG_WIDTH(REG) REG##_WIDTH
#define REG_BITS(REG) BITMASK(0, REG##_WIDTH)
#define REG_ACCESS(REG) AS_REG(REG##_ADDR)
#define REG_WITH_CO(REG) (REG_ACCESS(REG) & (REG##_CO_MASK))

// [Operators]
#define REG_SET(REG) REG_ACCESS(REG) = REG_WITH_CO(REG) | REG_MASK(REG);
#define REG_CLEAR(REG) REG_ACCESS(REG) = REG_WITH_CO(REG) & ~REG_MASK(REG);
#define REG_WRITE(REG, DATA)                                                   \
  REG_ACCESS(REG) = (REG_WITH_CO(REG) & ~REG_MASK(REG)) |                      \
                    ((DATA << REG_OFFSET(REG)) & REG_MASK(REG));
#define REG_READ(REG) ((REG_ACCESS(REG) & REG_MASK(REG)) >> REG_OFFSET(REG))
#define REG_COMPARE(REG, DATA) (REG_READ(REG) == (DATA))
// Could be optimized on ARM by calling ASM TEST directly
#define REG_TEST(REG) REG_COMPARE(REG, REG_BITS(REG))

#define REG_CLOBBER(REG_BASE, DATA)                                            \
  REG_ACCESS(REG_BASE) = (DATA) & (REG_BASE##_WMASK);

#define ATOMIC_OP(OP) IT_DISABLE(); OP; IT_ENABLE();

#define START_REG_ACCESS(REG_BASE)                                             \
  regsize_t REG_BASE##_val = 0;                                                \
  regsize_t REG_BASE##_mask = 0;

#define REG_SET_LAZY(REG, BASE)                                                \
  BASE##_val |= REG_MASK(REG);                                                 \
  BASE##_mask |= REG_MASK(REG);

#define END_REG_ACCESS(REG_BASE)                                               \
  REG_ACCESS(REG_BASE) =                                                       \
      (REG_WITH_CO(REG_BASE) & ~(REG_BASE##_mask)) | (REG_BASE##_val);

//! [HAL MCU registers]
MAKE_REG_BASE(
    PWR_CSR, PWR_BASE + 0x04, 0x000f430f, BITMASK(PWR_CSR_UDRDY_Pos, 2))
MAKE_REG(WKUP_ENABLE, PWR_CSR, PWR_CSR_EWUP_Pos, 1)
MAKE_REG(WKUP_FLAG, PWR_CSR, PWR_CSR_WUF_Pos, 1)
MAKE_REG(STDBY_FLAG, PWR_CSR, PWR_CSR_SBF_Pos, 1)
MAKE_REG(UNDER_DRIVE_READY, PWR_CSR, PWR_CSR_UDRDY_Pos, 2)
//! [HAL MCU registers]

//! [user code]
int main() {
  // Enable wake-up pin by writing 1 to [EWUP]
  REG_SET(WKUP_ENABLE);

  START_REG_ACCESS(PWR_CSR);
  REG_SET_LAZY(WKUP_ENABLE, PWR_CSR);
  REG_SET_LAZY(WKUP_FLAG, PWR_CSR);
  END_REG_ACCESS(PWR_CSR);
  REG_CLOBBER(PWR_CSR, 0xFFFF);
  // Check standby with [SBF]
  if (REG_TEST(STDBY_FLAG)) {
    asm volatile("nop"); // do something useful
  }

  // Check and clear under-drive ready flag [UDRDY]
  if (REG_TEST(UNDER_DRIVE_READY)) {
    REG_SET(UNDER_DRIVE_READY);
    // REG_WRITE(UNDER_DRIVE_READY, 0xf);
    asm volatile("nop"); // do something else useful
  }
}
//! [user code]
