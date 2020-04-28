// libraries included to use bool
#include <stdio.h>
#include <stdbool.h>

const int get_index(const int index)
{
    return index % 15;
}

int main(void) {

    volatile int* SEG_ptr1 = 0xFF200020;
    volatile int* SEG_ptr2 = 0xFF200030;
    volatile int* KEY_ptr = 0xFF20005C;
    volatile int* timer_base = 0xFF202000;

    const char Seg7_Data[] = {0b0111110, // U
                              0b0000000,
                              0b1011100, // o
                              0b1110001, // f
                              0b0000000,
                              0b1111000, // t
                              0b0000000,
                              0b1111001, // E
                              0b0111001, // C
                              0b1111001, // E
                              0b1000000, // -
                              0b1011011, // 2
                              0b1100110, // 4
                              0b1001111, // 3
                              0b0000000};

    int index = 0;

    // initializes count to show where to display the led
    bool run = true;

    while (1) {

        if (run)
        {	
            *SEG_ptr1 = 0;
            *SEG_ptr2 = 0;
            
            for (int seg_no = 0; seg_no < 6; seg_no++)
            {
                int actual_index = get_index(index + 5 - seg_no);

                if (seg_no < 4)
                {
                    *SEG_ptr1 = Seg7_Data[actual_index] << 8*seg_no | *SEG_ptr1;
                }
                else
                {
                    *SEG_ptr2 = Seg7_Data[actual_index] << 8*(seg_no - 4) | *SEG_ptr2;
                }
            }
            
            index++;
            *(timer_base) = 0; // Reset TimeOut
            *(timer_base + 2) = 0xF080;
            *(timer_base + 3) = 0x2FA;
            *(timer_base + 1) = 0b0100; // Start Timer

            while (1)
            {
                if (*timer_base & 0b1 == 0b1) // Prevent Compiler Optimization
                {
                    break;
                }
            }
        }
        
        if (*KEY_ptr != 0b0000)
        {
            run = !run;
            *KEY_ptr = *KEY_ptr;
        }
    }
}
