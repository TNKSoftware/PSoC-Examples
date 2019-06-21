#include "project.h"
#include <stdio.h>

CY_ISR(OnIntrupptPaIn)
{
    char str[10];
    sprintf(str, "%x ", pa_in_fifo_GetValue());
    UART_PutString(str);
}

int main(void)
{
    CyGlobalIntEnable;

    isr_dma_StartEx(OnIntrupptPaIn);
    
    UART_Start();

    for(;;)
    {
    }
}
