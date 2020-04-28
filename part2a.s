.global _start
_start: 	

	
/* For all keys:

- check their state by getting the first bit (which is the least
signigicant bit) 
- then call a seperate sub routine which displays this number
- this display subroutine will: 
     - check if key 2 is released
	 - then get the value of the address
	 - receive what to display and then store it in the memory of the hex 
	 */
// Once u get one key working you can just repeat code for other keys 
// ------------------- CHECK STATES & Get first bit ---------------

// For displaying 0

ZEROTH_KEY:	
		BL LOAD_ADDRESS

		AND R1, #0xf
		CMP R1, #0
		
		BEQ DISPLAY_ZERO
		
		BNE FIRST_KEY
		
		
// For displaying 1		
FIRST_KEY:	
		BL LOAD_ADDRESS
		
		AND R1, #0xf
		CMP R1, #1
		BEQ DISPLAY_ONE
		BNE SECOND_KEY	
		
// For displaying 2
SECOND_KEY:	
		BL LOAD_ADDRESS
		
		AND R1, #0xf
		CMP R1, #2
		BEQ DISPLAY_TWO
		BNE THIRD_KEY
		
// For displaying 3
THIRD_KEY:	
		BL LOAD_ADDRESS
		
		AND R1, #0xf
		CMP R1, #3
		BEQ DISPLAY_THREE
		BNE FOURTH_KEY		
		
// For displaying 4
FOURTH_KEY:	
		BL LOAD_ADDRESS

		AND R1, #0xf
		CMP R1, #4
		BEQ DISPLAY_FOUR
		BNE FIFTH_KEY
		
// For displaying 5
FIFTH_KEY:	
		BL LOAD_ADDRESS
		
		AND R1, #0xf
		CMP R1, #5
		BEQ DISPLAY_FIVE
		BNE ZEROTH_KEY
		
LOAD_ADDRESS:
		LDR R1, =0xff200040
		LDR R1, [R1]
		MOV PC, LR 
		
// --------------------- DISPLAYING SECTION --------------------

DISPLAY_ZERO:	
			MOV R9, #FIRST_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffffff00
			ORR R8, #0x3f
			STR R8, [R9]
			B FIRST_KEY	


DISPLAY_ONE:	
			MOV R9, #FIRST_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffff00ff
			ORR R8, #0x0600
			STR R8, [R9]
			B SECOND_KEY	
			
DISPLAY_TWO:	
			MOV R9, #FIRST_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xff00ffff
			ORR R8, #0x5b0000
			STR R8, [R9]
			B THIRD_KEY	
			
DISPLAY_THREE:	
			MOV R9, #FIRST_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0x00ffffff
			ORR R8, #0x4f000000
			STR R8, [R9]
			B FOURTH_KEY
			
DISPLAY_FOUR:	
			MOV R9, #SECOND_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffffff00
			ORR R8, #0x66
			STR R8, [R9]
			B FIFTH_KEY
			
DISPLAY_FIVE:	
			MOV R9, #SECOND_ADDRESS //check if key 2 is released
			LDR R9, [R9, #8] //we have the value of the address
			LDR R8, [R9] //we have the contents of the display
			AND R8, #0xffff00ff
			ORR R8, #0x6d00
			STR R8, [R9]
			B ZEROTH_KEY

FIRST_ADDRESS: .word 0xFF200020, 0xFF200030, 0xFF200020
SECOND_ADDRESS: .word 0xFF200020, 0xFF200030, 0xFF200030
