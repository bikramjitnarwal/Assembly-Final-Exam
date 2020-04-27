.global _start
_start:
	
// Question 1(a)
WAIT_FOR_VSYNC:
	PUSH {R0-R3, LR}
	LDR R12, ADDRESS_OF_VGA_CONTROLLER
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
	LDR R3, [R12, #4]
	// Shift y coordinate: (y << 10) & x coordinate: (x << 1)
	LSL R1, #10
	LSL R0, #1
	// Now add the shifted y and x coodinates then store it in back buffer
	ADD R3, R1
	ADD R3, R3
	STR R2, [R3]
	MOV PC, LR

ADDRESS_OF_VGA_CONTROLLER: 
	.word =0xFF203020
	
// Question 1(c)

CLEAR_SCREEN:
	PUSH {R0-R3}
	// We need to double loop to clear screen 
	MOVE R0, #0
	MOVE R1, #0
	MOVE R2, #0
	MOVE R3, LR
	
	X:
		Y:
			BL PLOT_PIXEL
			CMP R1, #0
			ADD R1, #1
			BLT Y
			
		CMP R0, #320
		ADD R0, #1
		BLT X
		
	PUSH {R0-R3}
	BX LR

END_LOOP: B END_LOOP
	
