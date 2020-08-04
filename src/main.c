#include "main.h"
#include "rcu.h"
#include "port.h"

static volatile int flag = 0;

static void
delay(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 108000; ++j) {
            flag = 0;
        }
    }
}

int
main()
{
    rcu_setup();
    port_setup();

    for (;;) {
        delay(300);
        GPIO_BOP(GPIOA) = 1 << 1;
        delay(300);
        GPIO_BC(GPIOA) = 1 << 1;
    }

    return 0;
}
