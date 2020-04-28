#include <stdio.h>
#include <stdbool.h>

// Global variables: Because they will be used everywhere no matter which function it is 
// ADDRESS FOR KEY
volatile int *KEY = (int*)0xFF20005C;
// ADDRESS FOR LED
volatile int *LED = (int*)(0xFF200000);
// ADDRESS FOR timer status
volatile int *timerStatus = (int*)(0xFF202000);

// Count variable will help us go left or go right 
int count = 0;
// First just initialize left to true since we are going left first 
bool left = true;

void checkFlag(){
	while (1)
	{	
		// if the flag is set, leave the while loop
		if ((*timerStatus) & 0b1 == 1)
		{
			break;
		}
	}
}

void resetCount(){
	// resets the count flag, sets timer to 25M, starts counter
	*(timerStatus) = 0;
	*(timerStatus + 2) = 0x7840;
	*(timerStatus + 3) = 0x17D;
	*(timerStatus + 1) = 0b0100;
}

void resetEdgeCapture(){
	// to reset the edge capture, set 1 to the bit that was triggered by the key press
	if (*KEY == 0b0001) {
		*KEY = 1;
	}
	else if (*KEY == 0b0010) {
		*KEY = 1 << 1;
	}
	else if (*KEY == 0b0100) {
		*KEY = 1 << 2;
	}
	else if (*KEY == 0b1000) {
		*KEY = 1 << 3;
	}
}

void goingLeft(){
	// Light up LED which you start at 
	*LED = 1 << count;

	// Move left 
	count++;

	// if at the left end, start from the right
	if (count == 10) {
		count = 0;
	}
	
	resetCount();
		
	checkFlag();

	// reset flag for timer
	(*timerStatus) = 0;
	

	// checks for edge capture to see if key has been pressed
	// if key has been pressed, switch directions
	if (*KEY) {
		left = false;
	}

	resetEdgeCapture();
}

void goingRight(){
	// display the LED at the correct place
	*LED = 1 << count;

	// move to the left
	count--;

	// if at the left end, start from the right
	if (count == -1) {
		count = 10;
	}

	resetCount();
		
	checkFlag();

	// reset flag for timer
	(*timerStatus) = 0;

	// checks for edge capture to see if key has been pressed
	// if key has been pressed, switch directions
	if (*KEY) {
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
		
		while (!left) {
			goingRight();
		}
	}
}
