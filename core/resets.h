#ifndef __RESET_H
#define __RESET_H

// #ifdef __cplusplus
// extern "C" {
// #endif

#include "rp2040.h"

#define RESET_ADC         (1 << 0)
#define RESET_BUSCTRL     (1 << 1)
#define RESET_DMA         (1 << 2)
#define RESET_I2C0        (1 << 3)
#define RESET_I2C1        (1 << 4)
#define RESET_IO_BANK0    (1 << 5)
#define RESET_IO_QSPI     (1 << 6)
#define RESET_JTAG        (1 << 7)
#define RESET_PADS_BANK0  (1 << 8)
#define RESET_PADS_QSPI   (1 << 9)
#define RESET_PIO0        (1 << 10)
#define RESET_PIO1        (1 << 11)
#define RESET_PLL_SYS     (1 << 12)
#define RESET_PLL_USB     (1 << 13)
#define RESET_PWM         (1 << 14)
#define RESET_RTC         (1 << 15)
#define RESET_SPI0        (1 << 16)
#define RESET_SPI1        (1 << 17)
#define RESET_SYSCFG      (1 << 18)
#define RESET_SYSINFO     (1 << 19)
#define RESET_TBMAN       (1 << 20)
#define RESET_TIMER       (1 << 21)
#define RESET_UART0       (1 << 22)
#define RESET_UART1       (1 << 23)
#define RESET_USBCTRL     (1 << 24)

struct resets_hw {
	uint32_t reset;
	uint32_t wdsel;
	uint32_t reset_done;
};

#define RESETS_CLR	((volatile struct resets_hw*)RESETS_BASE)

void reset_set(uint32_t hw);
void reset_release(uint32_t hw);
void reset_release_wait(uint32_t hw);


// #ifdef __cplusplus
// }; /** END: __cplusplus */
// #endif

#endif /** END: __RESET_H */