.global _start
_start:
	
// Question 1(a)
WAIT_FOR_VSYNC:
	// Push onto stack to prevent clobbered registers 
	PUSH {R0-R3, LR}
	// Get address of VGA controller 
	LDR R12, =0xFF203020
	MOV R0, #1
	// Get address of status register 
	LDR R1, =0xFF20302C
	// Set a 1 into the register containing the controller 
	STR R0, [R12]
	
LOOP:
	// Load status register 
	LDR R1,=0xFF20302C
	// Check is R1 = 0, is so keep looping until it isnt 
	CMP R1, #0
	BEQ LOOP
	
	// We can finally pop since we are done this subroutine 
	POP {R0-R3, LR}
	// Return 
	MOV PC, LR
	
END: 
	B END

// Question 1(b)
PLOT_PIXEL:
	// We want the back buffer, so add 4 
	// R3 = BACK BUFFER
	LDR R3, [R12, #4]
	// Shift y coordinate: (y << 10) & x coordinate: (x << 1)
	LSL R1, #10
	LSL R0, #1
	// Now add the shifted y and x coodinates then store it in back buffer
	ADD R3, R1
	ADD R3, R0
	// Store it 
	STR R2, [R3]
	// Return 
	MOV PC, LR
END:
	B END

// Question 1(c)

CLEAR_SCREEN:
	// Push onto stack to prevent clobbered registers 
	PUSH {R0-R3, LR}
	// We want to start from 0,0
	MOV R0, #0 
	MOV R1, #0 
	MOV R2, #0

	// Double loop to iterate all pixels over the screen 
	/*
	for(int .....){
		for(int ....){
		
	This is the general technique still in assembly but using 
	subroutines basically 
	*/
	
	X:
		Y: 
			// Plot pixel to help clear screen at that coordinate
			BL PLOT_PIXEL
			
			// Move 1 pixel (iterate over screen) 
			ADD R1, #1
			// Check if you hit the pixel 240 
			CMP R1, #240
			// If you dont hit it, keep looping 
			BLT Y
		
		MOV R1, #1
		// Move 1 pixel (iterate over screen)
		ADD R0, #1
		// Check if x hits pixel 320 
		CMP R0, #320
		// If you dont hit it, keep looping 
		BLT X

	// We can finally pop since we are done this subroutine 
	POP {R0-R3, LR}
	MOV PC, LR 

	

// Question 1(e)

// Combination of all parts 
MAIN: 	
	
	MOV R0, #0
	MOV R1, #0
	LDR R2, =0x0000
	BL CLEAR_SCREEN	
	B END
	
PLOT_PIXEL:
	// We want the back buffer, so add 4 
	// R3 = BACK BUFFER
	LDR R3, [R12, #4]
	// Shift y coordinate: (y << 10) & x coordinate: (x << 1)
	LSL R1, #10
	LSL R0, #1
	// Now add the shifted y and x coodinates then store it in back buffer
	ADD R3, R1
	ADD R3, R0
	STR R2, [R3]
	MOV PC, LR
END:
	B END
	
CLEAR_SCREEN:
	PUSH {R0-R3, LR}
	// We want to start from 0,0
	MOV R0, #0 
	MOV R1, #0 
	MOV R2, #0

	// Double loop to iterate all pixels over the screen 
	X:
		Y: 
			BL PLOT_PIXEL
			
			// Move 1 pixel (iterate over screen) 
			ADD R1, #1
			// Check if you hit the pixel 240 
			CMP R1, #240
			// If you dont hit it, keep looping 
			BLT Y
		
		MOV R1, #1
		// Move 1 pixel (iterate over screen)
		ADD R0, #1
		// Check if x hits pixel 320 
		CMP R0, #320
		// If you dont hit it, keep looping 
		BLT X

	POP {R0-R3, LR}
	MOV PC, LR 
