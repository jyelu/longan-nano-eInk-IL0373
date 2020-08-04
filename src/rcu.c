#include <gd32vf103_rcu.h>

void
rcu_setup()
{
    // set peripheral
    RCU_APB2EN |= 0u
        // RCU_APB2EN_USART0EN | // enable usart 0
        | RCU_APB2EN_PAEN // enable port A
        // RCU_APB2EN_AFEN | // enable alt func IO
    ;
}