#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	
	// HEX display for the score
	volatile int *HEX_ptr = (int *) (0xFF200020); 
	volatile int *HEX_ptr1 = (int *) (0xFF200030);
	
	// Variables to be used
	bool turned_on = true;
	int HUGE_NUMBER = 1000000;
	
	// Set ECE243 on the display
	int final_display = 101243;
	
	while (1) {
		
		while (turned_on) {

			// Use modulos and division to get each digit from the final score
			int zeroHEX = final_display % 10;
			int firstHEX = final_display % 100 / 10;
			int secondHEX = final_display % 1000 / 100;
			int thirdHEX = final_display % 10000 / 1000;
			int fourthHEX = final_display % 100000 / 10000;
			int fifthHEX = final_display % 1000000 / 100000;

			// Create character arrays for HEX3-0 and HEX5-4 display
			unsigned char HEX_segs[] = {0, 0, 0};
			unsigned char HEX_segs1[] = {0, 0};

			// Use switch statements to assign the values for HEX display
			switch(zeroHEX){
				case 0 : HEX_segs[0] = 0x39; break;
				case 1 : HEX_segs[0] = 0x79; break;
				case 2 : HEX_segs[0] = 0x5B; break;
				case 3 : HEX_segs[0] = 0x4F; break;
				case 4 : HEX_segs[0] = 0x66; break;
			}

			switch(firstHEX){
				case 0 : HEX_segs[1] = 0x39; break;
				case 1 : HEX_segs[1] = 0x79; break;
				case 2 : HEX_segs[1] = 0x5B; break;
				case 3 : HEX_segs[1] = 0x4F; break;
				case 4 : HEX_segs[1] = 0x66; break;
			}

			switch(secondHEX){
				case 0 : HEX_segs[2] = 0x39; break;
				case 1 : HEX_segs[2] = 0x79; break;
				case 2 : HEX_segs[2] = 0x5B; break;
				case 3 : HEX_segs[2] = 0x4F; break;
				case 4 : HEX_segs[2] = 0x66; break;
			}

			switch(thirdHEX){
				case 0 : HEX_segs[3] = 0x39; break;
				case 1 : HEX_segs[3] = 0x79; break;
				case 2 : HEX_segs[3] = 0x5B; break;
				case 3 : HEX_segs[3] = 0x4F; break;
				case 4 : HEX_segs[3] = 0x66; break;
			}

			switch(fourthHEX){
				case 0 : HEX_segs1[0] = 0x39; break;
				case 1 : HEX_segs1[0] = 0x79; break;
				case 2 : HEX_segs1[0] = 0x5B; break;
				case 3 : HEX_segs1[0] = 0x4F; break;
				case 4 : HEX_segs1[0] = 0x66; break;
			}

			switch(fifthHEX){
				case 0 : HEX_segs1[1] = 0x39; break;
				case 1 : HEX_segs1[1] = 0x79; break;
				case 2 : HEX_segs1[1] = 0x5B; break;
				case 3 : HEX_segs1[1] = 0x4F; break;
				case 4 : HEX_segs1[1] = 0x66; break;
			}

			*HEX_ptr =  *(int *)(HEX_segs);
			*HEX_ptr1 = *(int *)(HEX_segs1);

			for (int i = 0; i < 1000000; i++) {
			}

			turned_on = false;
		}
	
		while (turned_on == false) {
			unsigned char newHEX[] = {0x00, 0x00, 0x00, 0x00};
			unsigned char newHEX1[] = {0x00, 0x00};

			*HEX_ptr =  *(int *)(newHEX);
			*HEX_ptr1 = *(int *)(newHEX1);
			for (int i = 0; i < 1000000; i++) {
			}
			turned_on = true;
		}
	}
	
	return 0;
}
