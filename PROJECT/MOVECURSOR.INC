;//MOVE CURSOR
MOVE_CURSOR MACRO ROW,COL
    MOV AH,2
	MOV BH,0
    MOV DH,ROW
    MOV DL,COL
    INT 10H
ENDM MOVE_CURSOR