#include "project.h"

int ppos = 0;

const uint32_t patterns[] = {
    0b11111111000000001111111100000000,
    0b11110000111100001111000011110000,
    0b11001100110011001100110011001100,
    0b10101010101010101010101010101010,
    0b11001100110011001100110011001100,
    0b11110000111100001111000011110000,
};

CY_ISR(OnInterruptSO)
{
    sreg_out_SetValue(patterns[ppos]);
    ppos++;
    if(ppos == 6) ppos = 0;
}

int main(void)
{
    CyGlobalIntEnable;

    so_isr_StartEx(OnInterruptSO);

    for(;;)
    {
    }
}
