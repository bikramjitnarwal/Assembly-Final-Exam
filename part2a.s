.global _start

//Display a decimal digit on the HEX0 display

_start: 	


//load the value of key0 into the memory @ the address 0xFF200050
KEY0:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #0
		BEQ DISPLAY_ZERO
		BNE KEY1
		
KEY1:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #1
		BEQ DISPLAY_ONE
		BNE KEY2	
		
KEY2:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #2
		BEQ DISPLAY_TWO
		BNE KEY3
		
KEY3:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #3
		BEQ DISPLAY_THREE
		BNE KEY4		
		
KEY4:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #4
		BEQ DISPLAY_FOUR
		BNE KEY5
		
KEY5:	LDR R1, =0xff200040
		LDR R1, [R1]
		
//check the state of KEY0 by extracting the first bit (LSB)
		AND R1, #0xf
		CMP R1, #5
		BEQ DISPLAY_FIVE
		BNE KEY0
		

DISPLAY_ZERO:	
			MOV R9, #ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffffff00
			ORR R8, #0x3f
			STR R8, [R9]
			B KEY1	


DISPLAY_ONE:	
			MOV R9, #ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffff00ff
			ORR R8, #0x0600
			STR R8, [R9]
			B KEY2	
			
DISPLAY_TWO:	
			MOV R9, #ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xff00ffff
			ORR R8, #0x5b0000
			STR R8, [R9]
			B KEY3	
			
DISPLAY_THREE:	
			MOV R9, #ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0x00ffffff
			ORR R8, #0x4f000000
			STR R8, [R9]
			B KEY4
			
DISPLAY_FOUR:	
			MOV R9, #ADDR2 //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffffff00
			ORR R8, #0x66
			STR R8, [R9]
			B KEY5
			
DISPLAY_FIVE:	
			MOV R9, #ADDR2 //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffff00ff
			ORR R8, #0x6d00
			STR R8, [R9]
			B KEY0

//HEX0 - 3 0xFF200020
//HEX4 - 5 0xFF200030
//KEY0 - 3 0xFF200050

ADDRESS: .word 0xFF200020, 0xFF200030, 0xFF200020
ADDR2: .word 0xFF200020, 0xFF200030, 0xFF200030
//6 - 0   HEX0
//14 - 8  HEX1
//22 - 16 HEX2
//30 - 24 HEX3
