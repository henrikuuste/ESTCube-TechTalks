#pragma GCC diagnostic ignored "-Wunused-variable"
#include "Io/Io.hpp"
#include "Register/Register.hpp"
#include "Register/Utility.hpp"
#include "chip_registers.hpp"

using namespace Kvasir;
using namespace Kvasir::Io;
using namespace Kvasir::Register;

constexpr auto orangeLed = makePinLocation(portD, pin13);
constexpr auto greenLed = makePinLocation(portD, pin12);
constexpr auto blueLed = makePinLocation(portD, pin15);
constexpr auto enableGPIOD = set(RccAhb1enr::gpioden);
constexpr auto enableGPIOB = set(RccAhb1enr::gpioben);
constexpr auto enableWakeupPin = set(PwrCsr::ewup);
constexpr FieldValue<decltype(PwrCsr::udrdy)::Type,PwrCsr::UDVal::UDReady> clearUnderDrive{};

int main() {
  apply(
      enableGPIOD,           //
      makeOutput(orangeLed), //
      makeOutput(blueLed),   //
      makeOutput(greenLed),  //
      enableGPIOB);
  // [later...]
  apply(
      toggle(orangeLed), //
      enableWakeupPin, //
      write(clearUnderDrive), //
      clear(PwrCsr::vosrdy), //
      set(PwrCr::dbp,  //
          PwrCsr::bre, //
          PwrCr::cwuf));
  auto val = apply(read(PwrCsr::sbf));

  return val;
}
