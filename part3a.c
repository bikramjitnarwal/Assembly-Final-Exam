#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// HEX display for the score
volatile int *HEX_ptr = (int *) (0xFF200020); 
volatile int *HEX_ptr1 = (int *) (0xFF200030);

// Variables to be used
bool isItON = true;
// We will use 1000000 to help set a delay, Looping from 0 to delayNum
int delayNum = 1000000;

// Each digit from total hex: 101243
int hex_0 = 3;
int hex_1 = 4;
int hex_2 = 2;
int hex_3 = 1;
int hex_4 = 0;
int hex_5 = 1;

// Create character arrays for HEX3-0 and HEX5-4 display
unsigned char HEX_segs[] = {0, 0, 0};
unsigned char HEX_segs1[] = {0, 0};

unsigned char newHEX[] = {0x00, 0x00, 0x00, 0x00};
unsigned char newHEX1[] = {0x00, 0x00};

void display_3(){
	if(hex_0 == 0){
		HEX_segs[0] = 0x39;
	} else if(hex_0 == 1) {
		HEX_segs[0] = 0x79;
	} else if(hex_0 == 2) { 
		HEX_segs[0] = 0x5B; 
	} else if(hex_0 == 3) { 
		HEX_segs[0] = 0x4F; 
	} else if(hex_0 == 4) {
		HEX_segs[0] = 0x66; 
	}
}

void display_4(){
	if(hex_1 == 0)
		HEX_segs[1] = 0x39;
	else if(hex_1 == 1)
		HEX_segs[1] = 0x79;
	else if(hex_1 == 2)
		HEX_segs[1] = 0x5B; 
	else if(hex_1 == 3)
		HEX_segs[1] = 0x4F; 
	else if(hex_1 == 4)
		HEX_segs[1] = 0x66;
}

void display_2(){
	if(hex_2 == 0)
		HEX_segs[2] = 0x39;
	else if(hex_2 == 1)
		HEX_segs[2] = 0x79;
	else if(hex_2 == 2)
		HEX_segs[2] = 0x5B; 
	else if(hex_2 == 3)
		HEX_segs[2] = 0x4F; 
	else if(hex_2 == 4)
		HEX_segs[2] = 0x66;
}

void display_secondE(){
	if(hex_3 == 0)
		HEX_segs[3] = 0x39;
	else if(hex_3 == 1)
		HEX_segs[3] = 0x79;
	else if(hex_3 == 2)
		HEX_segs[3] = 0x5B; 
	else if(hex_3 == 3)
		HEX_segs[3] = 0x4F; 
	else if(hex_3 == 4)
		HEX_segs[3] = 0x66;
}

void display_C(){
	if(hex_4 == 0)
		HEX_segs1[0] = 0x39;
	else if(hex_4 == 1)
		HEX_segs1[0] = 0x79;
	else if(hex_4 == 2)
		HEX_segs1[0] = 0x5B; 
	else if(hex_4 == 3)
		HEX_segs1[0] = 0x4F; 
	else if(hex_4 == 4)
		HEX_segs1[0] = 0x66;
}

void display_firstE(){
	if(hex_5 == 0)
		HEX_segs1[1] = 0x39;
	else if(hex_5 == 1)
		HEX_segs1[1] = 0x79;
	else if(hex_5 == 2)
		HEX_segs1[1] = 0x5B; 
	else if(hex_5 == 3)
		HEX_segs1[1] = 0x4F; 
	else if(hex_5 == 4)
		HEX_segs1[1] = 0x66;
}

void turn_ON(){
	// assign the values for HEX display
	
	display_3();

	display_4();

	display_2();
	
	display_secondE();
	
	display_C();
	
	display_firstE();

	*HEX_ptr =  *(int *)(HEX_segs);
	*HEX_ptr1 = *(int *)(HEX_segs1);

	for (int i = 0; i < delayNum; i++) {
	}

	isItON = false;
}


void turn_OFF(){
	*HEX_ptr =  *(int *)(newHEX);
	*HEX_ptr1 = *(int *)(newHEX1);
	for (int i = 0; i < delayNum; i++) {
	}
	isItON = true;
}

int main(void){
	while (1) {
		while (isItON) {
			turn_ON();
		}
	
		while (isItON == false) {
			turn_OFF();
		}
	}
	return 0;
}
