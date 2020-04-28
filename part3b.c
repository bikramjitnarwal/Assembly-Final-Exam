#include <stdio.h>
#include <stdbool.h>

// ADDRESS FOR KEY
volatile int *KEY_ptr = (int*)0xFF20005C;
// ADDRESS FOR LED
volatile int *LED_ptr = (int*)(0xFF200000);
// ADDRESS FOR timer status
volatile int *timer_status = (int*)(0xFF202000);

// Count variable will help us go left or go right 
int direction_counter = 0;
// First just initialize left to true since we are going left first 
bool left = true;

void checkFlag(){
	while (1){	
		// We can only leave this while loop if the timer gets set 
		if ((*timer_status) & 0b1 == 1) {
			break;
		}
	}
}

void resetCount(){
	// resets the count flag, sets timer to 25M, starts counter
	*(timer_status) = 0;
	*(timer_status + 2) = 0x7840;
	*(timer_status + 3) = 0x17D;
	*(timer_status + 1) = 0b0100;
}

void resetEdgeCapture(){
	// Edge capture = reset when we set the value of 1 to the bit which was initiated by the press
	// of the key 
	if (*KEY_ptr == 0b0001) {
		*KEY_ptr = 1;
	} else if (*KEY_ptr == 0b0010) {
		*KEY_ptr = 1 << 1;
	} else if (*KEY_ptr == 0b0100) {
		*KEY_ptr = 1 << 2;
	} else if (*KEY_ptr == 0b1000) {
		*KEY_ptr = 1 << 3;
	}
}

void goingLeft(){
	// Light up LED which you start at 
	*LED_ptr = 1 << direction_counter;

	// Move right so increment counter  
	direction_counter++;

	// Switch directions if you are at one side 
	if (direction_counter == 10) 
		direction_counter = 0;
	
	// First we want to reset the count since we are at the end and then check flag 
	resetCount();
	checkFlag();

	// We also want to reset the timer back to 0
	(*timer_status) = 0;
	

	// Check if key is pressed, if it is then we switch directions to opposite direction
	if (*KEY_ptr) 
		left = false;

	resetEdgeCapture();
}

void goingRight(){
	// display the LED at the correct place
	*LED_ptr = 1 << direction_counter;

	// Move to the left so decrement counter 
	direction_counter--;

	// Switch directions if you are at one side 
	if (direction_counter == -1) {
		direction_counter = 10;
	}

	resetCount();
		
	checkFlag();

	// reset flag for timer
	(*timer_status) = 0;

	// checks for edge capture to see if key has been pressed
	// if key has been pressed, switch directions
	if (*KEY_ptr) {
		left = true;
	}

	resetEdgeCapture();
}

int main(void) {
	while (1) {
		// First we assume we go left 
		while (left) {
			goingLeft();
		}
		
		// If not left, that means we are going right 
		while (!left) {
			goingRight();
		}
	}
}
