#include "main.h"
#include <gd32vf103_gpio.h>

#define S0(n, mode) GPIO_MODE_SET(n, mode)
#define S1(n, mode) GPIO_MODE_SET((n-8), mode)
#define M0(n) (GPIO_MODE_MASK(n))
#define M1(n) (GPIO_MODE_MASK(n-8))

void
port_setup()
{
    // CTL[1:0]:MD[1:0]

    // port A
    // port A0-A1 output
    GPIO_CTL0(GPIOA) &= ~(M0(0) | M0(1));
    GPIO_CTL0(GPIOA) |= 0u
        | S0(0, 0x3) // A0 as output
        | S0(1, 0x3) // A1 as output
    ;
}