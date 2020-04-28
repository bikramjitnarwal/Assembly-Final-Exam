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
int counter = 0;
int i = 0;
int shift_index = 0;
int add_delay = 0x2FAF080;
bool start = true;
bool begin = true;
bool forward_direction = true;
 
// All address values allocated to variables 
volatile int* SEG_ptr_1 = 0xFF200020;
volatile int* SEG_ptr_2 = 0xFF200030;
volatile int* KEY_ptr = 0xFF20005C;
volatile int* timers_address_base = 0xFF202000;
volatile int* LED_ptr = 0xFF200000;

char uoftcharacters[] = {U, space, o, f, space, t, space, E, C, E, hypen, two, four, three, space}; 

// Reset the timer and then start it 
void timer_reset_start(){
	*(timers_address_base) = 0; 
	*(timers_address_base + 2) = add_delay & 0x0000FFFF;
	*(timers_address_base + 3) = (add_delay & 0xFFFF0000) >> 16;
	*(timers_address_base + 1) = 0b0100; 
}

void startProgram(){
	*SEG_ptr_1 = 0;
	*SEG_ptr_2 = 0;
	
	for (int k = 0; k < 6; k++){
		int j = (i + 5 - k) % 15;

		if (k < 4){
			*SEG_ptr_1 = uoftcharacters[j] << 8*k | *SEG_ptr_1;
		} else {
			*SEG_ptr_2 = uoftcharacters[j] << 8*(k - 4) | *SEG_ptr_2;
		}
	}

	if (forward_direction){
		i = i - shift_index;
	} else {
		i = i + shift_index;
	}
	
	if (shift_index > 0) {
		add_delay = add_delay << shift_index;
	} else if (shift_index < 0) {
		add_delay = add_delay >> abs(shift_index);
	}
	
	timer_reset_start();

	while (1) {
		if (*timers_address_base & 0b1 == 0b1) {
			break;
		}
	}
}

void additional_features(){
	if (*KEY_ptr == 0b1) {
		begin = !begin;
		*KEY_ptr = 0b1;
	}
	
	if (*KEY_ptr == 0b10) {
		if (shift_index > -16) {
			shift_index--;
		}
		*KEY_ptr = 0b10;
	}
	
	if (*KEY_ptr == 0b100) {
		if (shift_index < 16) {
			shift_index++;
		}
		*KEY_ptr = 0b100;
	}
	
	if (*KEY_ptr == 0b1000) {
		forward_direction = !forward_direction;
		*KEY_ptr = 0b1000;
	}
}

int main(void) {
	while (1) {
        if (begin){	
			startProgram();
        }
		
        *LED_ptr = *KEY_ptr;
        additional_features();
    }
}
