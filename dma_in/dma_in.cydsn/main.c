#include "project.h"

uint8_t send_buffer_pos;
uint8_t send_buffer[2][24];
const uint8_t send_buffer_data[] = {
    0b11111111, 0b00000000, 0b11111111, 0b00000000,
    0b11110000, 0b11110000, 0b11110000, 0b11110000,
    0b11001100, 0b11001100, 0b11001100, 0b11001100,
    0b10101010, 0b10101010, 0b10101010, 0b10101010,
    0b11001100, 0b11001100, 0b11001100, 0b11001100,
    0b11110000, 0b11110000, 0b11110000, 0b11110000,
};

/* Defines for led_dma */
#define led_dma_BYTES_PER_BURST 1
#define led_dma_REQUEST_PER_BURST 1
#define led_dma_SRC_BASE (CYDEV_SRAM_BASE)
#define led_dma_DST_BASE (CYDEV_PERIPH_BASE)

/* Variable declarations for led_dma */
/* Move these variable declarations to the top of the function */
uint8 led_dma_Chan;
uint8 led_dma_TD[2];

void InitDma()
{
    /* DMA Configuration for led_dma */
    led_dma_Chan = led_dma_DmaInitialize(led_dma_BYTES_PER_BURST, led_dma_REQUEST_PER_BURST, 
        HI16(led_dma_SRC_BASE), HI16(led_dma_DST_BASE));
    led_dma_TD[0] = CyDmaTdAllocate();
    led_dma_TD[1] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(led_dma_TD[0], 24, led_dma_TD[1], led_dma__TD_TERMOUT_EN | CY_DMA_TD_INC_SRC_ADR);
    CyDmaTdSetConfiguration(led_dma_TD[1], 24, led_dma_TD[0], led_dma__TD_TERMOUT_EN | CY_DMA_TD_INC_SRC_ADR);
    CyDmaTdSetAddress(led_dma_TD[0], LO16((uint32)send_buffer[0]), LO16((uint32)led_out_dma_ptr));
    CyDmaTdSetAddress(led_dma_TD[1], LO16((uint32)send_buffer[1]), LO16((uint32)led_out_dma_ptr));
    CyDmaChSetInitialTd(led_dma_Chan, led_dma_TD[0]);
    CyDmaChEnable(led_dma_Chan, 1);   
}

void CopyDmaBuffer()
{
    uint8_t cid;
    CyDmaChStatus(led_dma_Chan, &cid, NULL);
    
    uint8_t bpos = (cid == led_dma_TD[1]) ? 0 : 1; 
    memcpy(send_buffer[bpos], send_buffer_data, 24);
}

CY_ISR(OnInterruptLed)
{
    CopyDmaBuffer();
}

int main(void)
{
    CyGlobalIntEnable;
    
    memcpy(send_buffer[0], send_buffer_data, 24);
    memcpy(send_buffer[1], send_buffer_data, 24);
   
    InitDma();
    led_dma_isr_StartEx(OnInterruptLed);

    for(;;)
    {
    }
}
