#include <stdio.h>
#include <stdbool.h>

// All binary values for "U of t ECE-243"
#define U 0b0111110
#define space 0b0000000
#define o 0b1011100
#define f 0b1110001
#define t 0b1111000
#define E 0b1111001
#define C 0b0111001
#define hypen 0b1000000
#define two 0b1011011
#define four 0b1100110
#define three 0b1001111

// Global variables
int i = 0;
bool start = true;
 
// All address values allocated to variables 
volatile int* SEG_ptr1 = 0xFF200020;
volatile int* SEG_ptr2 = 0xFF200030;
volatile int* KEY_ptr = 0xFF20005C;
volatile int* timers_address_base = 0xFF202000;

// Array with appropriate characters 
// I made the array like this because it was way easier to debug my code 
char uoftcharacters[] = {U, space, o, f, space, t, space, E, C, E, hypen, two, four, three, space}; 

void timer_reset_start(){
	// Reset TimeOut
	*(timers_address_base) = 0; 
	*(timers_address_base + 2) = 0xF080;
	*(timers_address_base + 3) = 0x2FA;
	// Being timer
	*(timers_address_base + 1) = 0b0100; 
}

void startProgram(){
	*SEG_ptr1 = 0;
	*SEG_ptr2 = 0;
	
	for (int k = 0; k < 6; k++){
		int j = (i + 5 - k) % 15;

		if (k < 4){
			*SEG_ptr1 = uoftcharacters[j] << 8*k | *SEG_ptr1;
		} else {
			*SEG_ptr2 = uoftcharacters[j] << 8*(k - 4) | *SEG_ptr2;
		}
	}
	
	i = i + 1;
	
	timer_reset_start();

	while (1){
		// Prevent Compiler Optimization
		if (*timers_address_base & 0b1 == 0b1){
			break;
		}
	}
}

int main(void) {
    while (1) {
        if (start){	
			startProgram();
        }
        
        if (*KEY_ptr != 0b0000){
            start = false;
        }
    }
}

