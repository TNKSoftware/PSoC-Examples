#include "project.h"

int main(void)
{
    CyGlobalIntEnable;
    
    CyDelay(1000);  // wait 1000ms

    UART_1_Start();
    UART_1_UartPutString("Hello World!\n");

    for(;;)
    {
    }
}
