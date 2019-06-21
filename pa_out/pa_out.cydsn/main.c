#include "project.h"

// LED number -> Pin's position
#define SEG_LA   0b00000001
#define SEG_LB   0b00000010
#define SEG_LC   0b00000100
#define SEG_LP   0b00001000
#define SEG_LD   0b00010000
#define SEG_LE   0b00100000
#define SEG_LF   0b10000000
#define SEG_LG   0b01000000

const uint8_t seg_pos[] =
{
    SEG_0, SEG_1, SEG_2, SEG_3, SEG_4,
    SEG_5, SEG_6, SEG_7, SEG_8, SEG_9
};

int main(void)
{
    CyGlobalIntEnable;

    int count = 0;
    uint8_t n = 0, pt = 0;

    for(;;)
    {
        count++;
        if(count == 5000000){
            count = 0;
            pa_out_1_SetValue(seg_pos[n] | pt);
            n++;
            if(n >= 10){
                n = 0;
                pt = (pt) ? 0x00 : SEG_LP;
            }
        }
    }
}
