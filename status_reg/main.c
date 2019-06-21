#include "project.h"
#include <stdio.h>

CY_ISR(OnSRegInterrupt)
{
    char str[32];
    sprintf(str, "%x ", Status_Reg_Read());
    UART_PutString(str);
}

int main(void)
{
    CyGlobalIntEnable;
    
    UART_Start();
    
    isr_sreg_StartEx(OnSRegInterrupt);   

    for(;;)
    {
    }
}
