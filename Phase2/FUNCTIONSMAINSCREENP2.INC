;//FUNCTIONS OF MAIN SCREEN PLAYER 2
FUNCTIONS_MAINSCREENP2 MACRO CHOICE,CHOICE1

    LOCAL CHECK,F1,F2,ESC  

 	
	LEA DI,CHOICE1
	CMP [DI],'C'
	JNZ GAMING 
	DISPLAY_MESS NAMEMESS+2
	MOV AH,3H
	MOV BH,0
	INT 10H
	MOVE_CURSOR DH,NAMEMESS+1	
	DISPLAY_MESS CHATMESSR 
	PRINT_NEWLINE
	JMP CHECK
	
	GAMING:
	CMP [DI],'G'
	JNZ CHECK
	DISPLAY_MESS NAMEMESS+2     ;PRINT PLAYER 1 NAME
	MOV AH,3H                   ;MOVE CURSORE TO PRINT REST OF MESSAGE
	MOV BH,0
	INT 10H
	MOVE_CURSOR DH,NAMEMESS+1	
	DISPLAY_MESS GAMEINVR
	PRINT_NEWLINE
	
	
    CHECK:
	MOV AH,1
	INT 16H
	JZ CHECK                         ;7ATETHA HENA 3SHAN COMPARE CHECKS LAZEM YEKON BA3D INTRUPT 
	
	;CHECKKEY IS RIGHT
	CMP AH,3BH
	JZ F1
	CMP AH,3CH
	JZ F2
	CMP AL,1BH
	JZ ESC
	mov ah,0                             ;CONSUME BUFFER
    int 16h
	JMP CHECK
	
	F1:
	LEA SI,CHOICE
	MOV [SI],'C'
	MOV AH,0                              ;CONSUME BUFFER
	INT 16H
	DISPLAY_MESS CHATMESS
	JMP CHECK_VALID_MODE                              ;JMP TO CHECK MODES SELECTED BY 2 PLAYERS
	
	
	ESC:
	LEA SI,CHOICE
	MOV [SI],'E'
	MOV AH,0                              ;CONSUME BUFFER
	INT 16H
	JMP CHECK_VALID_MODE                          ;JMP TO CHECK MODES SELECTED BY 2 PLAYERS
	
	
	F2:
	LEA SI,CHOICE
	MOV [SI],'G'
	MOV AH,0                              ;CONSUME BUFFER
	INT 16H 
	JMP CHECK_VALID_MODE                              ;JMP TO CHECK MODES SELECTED BY 2 PLAYERS
	
		
ENDM FUNCTIONS_MAINSCREENP2