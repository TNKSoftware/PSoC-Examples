#include "project.h"
#include <stdio.h>

CY_ISR(OnIntrupptShiftReg)
{
    uint32_t v = shift_reg_GetValue();
    for(int n = 0; n < 32; n++){
        UART_PutChar(((v >> (31 - n)) & 0x1) ? '1' : '0');
    }
    UART_PutChar(' ');
}

int main(void)
{
    CyGlobalIntEnable;

    shift_reg_isr_StartEx(OnIntrupptShiftReg);
    
    UART_Start();

    for(;;)
    {
    }
}
