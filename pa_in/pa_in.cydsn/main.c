#include "project.h"

CY_ISR(OnIntrupptPaIn)
{
    uint8_t v = pa_in_GetValue();
    for(int i = 0; i < 8; i++){
        UART_PutChar((v & 0x80) ? '1' : '0');
        v <<= 1;
    }
}

int main(void)
{
    CyGlobalIntEnable;
    
    isr_pa_in_StartEx(OnIntrupptPaIn);
    UART_Start();

    for(;;)
    {
    }
}
