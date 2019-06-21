#include "project.h"
#include <stdio.h>

/* Defines for pa_in_dma */
#define pa_in_dma_BYTES_PER_BURST 1
#define pa_in_dma_REQUEST_PER_BURST 1
#define pa_in_dma_SRC_BASE (CYDEV_PERIPH_BASE)
#define pa_in_dma_DST_BASE (CYDEV_SRAM_BASE)

/* Variable declarations for pa_in_dma */
/* Move these variable declarations to the top of the function */
uint8 pa_in_dma_Chan;
uint8 pa_in_dma_TD[1];

uint8 res_buffer[32];

void InitDma()
{
    /* DMA Configuration for pa_in_dma */
    pa_in_dma_Chan = pa_in_dma_DmaInitialize(pa_in_dma_BYTES_PER_BURST, pa_in_dma_REQUEST_PER_BURST, 
        HI16(pa_in_dma_SRC_BASE), HI16(pa_in_dma_DST_BASE));
    pa_in_dma_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(pa_in_dma_TD[0], 32, pa_in_dma_TD[0], pa_in_dma__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(pa_in_dma_TD[0], LO16((uint32)pa_in_DMA_PTR), LO16((uint32)res_buffer));
    CyDmaChSetInitialTd(pa_in_dma_Chan, pa_in_dma_TD[0]);
    CyDmaChEnable(pa_in_dma_Chan, 1);
}

CY_ISR(OnInterruptPaInDma)
{
    char str[10];
    for(int n = 0; n < 32; n++){
        sprintf(str, "%x ", res_buffer[n]);
        UART_PutString(str);
    }
}

int main(void)
{
    CyGlobalIntEnable;

    isr_dma_StartEx(OnInterruptPaInDma);
    InitDma();
    
    UART_Start();

    for(;;)
    {
    }
}
