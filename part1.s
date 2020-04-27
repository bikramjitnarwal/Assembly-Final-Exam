.global _start
_start:
	
// Question 1(a)
WAIT_FOR_VSYNC:
	PUSH {R0-R3, LR}
	LDR R12, =0xFF203020
	MOV R0, #1
	LDR R1, =0xFF20302C
	STR R0, [R12]
	
LOOP:
	LDR R1,=0xFF20302C
	CMP R1, #0
	BEQ LOOP
	
	POP {R0-R3, LR}
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
	STR R2, [R3]
	MOV PC, LR


// Question 1(c)

// We want to start from 0,0
MOV R0, #0 
MOV R1, #0 
MOV R3, LR 

X:
	Y: 
		BL PLOT_PIXEL

		// Check if you hit the pixel 240 
		CMP R1, #240
		// If you dont hit pixel 240, move 1 
		ADD R1, #1
		// And keep looping
		BLT Y
	
	// Check if x hits pixel 320 
	CMP R0, #320
	// If you dont hit pixel 320, move 1 
	ADD R0, #1
	// And keep looping
	BLT X

MOV PC, LR 
	
