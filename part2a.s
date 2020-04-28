.global _start
_start: 	

/* For every key (0-5):

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
		// Before anything, load the address
		BL LOAD_ADDRESS

		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 0
		CMP R1, #0
		// If it is, we can branch to display it right away 
		BEQ DISPLAY_ZERO
		// Otherwise, branch to next key 
		BNE FIRST_KEY
		
// For displaying 1		
FIRST_KEY:	
		// Before anything, load the address
		BL LOAD_ADDRESS
		
		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 1
		CMP R1, #1
		BEQ DISPLAY_ONE
		// Otherwise, branch to next key
		BNE SECOND_KEY	
		
// For displaying 2
SECOND_KEY:	
		// Before anything, load the address
		BL LOAD_ADDRESS
		
		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 2
		CMP R1, #2
		// If it is, we can branch to display it right away
		BEQ DISPLAY_TWO
		// Otherwise, branch to next key
		BNE THIRD_KEY
		
// For displaying 3
THIRD_KEY:	
		// Before anything, load the address
		BL LOAD_ADDRESS
		
		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 3
		CMP R1, #3
		// If it is, we can branch to display it right away
		BEQ DISPLAY_THREE
		// Otherwise, branch to next key
		BNE FOURTH_KEY		
		
// For displaying 4
FOURTH_KEY:	
		// Before anything, load the address
		BL LOAD_ADDRESS

		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 4
		CMP R1, #4
		// If it is, we can branch to display it right away
		BEQ DISPLAY_FOUR
		// Otherwise, branch to next key
		BNE FIFTH_KEY
		
// For displaying 5
FIFTH_KEY:	
		// Before anything, load the address
		BL LOAD_ADDRESS
		
		// AND the contents of R1 and the address #0xf
		AND R1, #0xf
		// Check if this is = to 5
		CMP R1, #5
		// If it is, we can branch to display it right away
		BEQ DISPLAY_FIVE
		// Otherwise, branch to next key
		BNE ZEROTH_KEY
		
LOAD_ADDRESS:
		LDR R1, =0xff200040
		LDR R1, [R1]
		MOV PC, LR 
		
// --------------------- DISPLAYING SECTION --------------------

DISPLAY_ZERO:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #FIRST_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0xffffff00
			ORR R8, #0x3f
			STR R8, [R9]
			B FIRST_KEY	

DISPLAY_ONE:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #FIRST_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0xffff00ff
			ORR R8, #0x0600
			STR R8, [R9]
			B SECOND_KEY	
			
DISPLAY_TWO:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #FIRST_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0xff00ffff
			ORR R8, #0x5b0000
			STR R8, [R9]
			B THIRD_KEY	
			
DISPLAY_THREE:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #FIRST_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0x00ffffff
			ORR R8, #0x4f000000
			STR R8, [R9]
			B FOURTH_KEY
			
DISPLAY_FOUR:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #SECOND_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0xffffff00
			ORR R8, #0x66
			STR R8, [R9]
			B FIFTH_KEY
			
DISPLAY_FIVE:	
			// Check: is key 2 is released 
			// Get address from table 
			MOV R9, #SECOND_ADDRESS 
			// Load the value of the address
			LDR R9, [R9, #8] 
			// Load contents that we wish to display 
			LDR R8, [R9] 
			// Get the according hex and store it then 
			AND R8, #0xffff00ff
			ORR R8, #0x6d00
			STR R8, [R9]
			B ZEROTH_KEY

FIRST_ADDRESS: .word 0xFF200020, 0xFF200030, 0xFF200020
SECOND_ADDRESS: .word 0xFF200020, 0xFF200030, 0xFF200030
