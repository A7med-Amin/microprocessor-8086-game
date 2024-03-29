
;//GAME TEXT MODE INTIAL MODE
GAME_WIND MACRO GAMELEVEL
LOCAL CHECK1,L1,L2,ITSLEVEL1
    LEA SI,GAMELEVEL
    CHECK1:
	MOV AH,1
	INT 16H
	JZ CHECK1                             ;7ATETHA HENA 3SHAN COMPARE CHECK LAZEM YEKON BA3D INTRUPT 
	
	;CHECK KEY IS VALID KEY
	CMP AL,'1'
	JZ L1          
	
	CMP AL,'2'
	JZ L2
	mov ah,0                             ;CONSUME BUFFER
    int 16h
	JMP CHECK1
	
	L1:
	MOV AH,0                            ;CONSUME BUFFER
	INT 16H
	MOV [SI],1                          ;INTIALIZE LEVEL BY 1
	JMP ITSLEVEL1                       ;JMP TO LEVEL 1 
	
	
	L2:
	MOV AH,0                              ;CONSUME BUFFER
	INT 16H
	MOV [SI],2                            ;INTIALIZE LEVEL BY 2
	
	ITSLEVEL1:
	
ENDM GAME_WIND

;//FORRBIDEN CHAR TEXT
FORBIDDEN_CHAR MACRO CHAR1
LOCAL CHECK0,CHECK,L1,L2,L3,L4,L5,NUMBER,ALFA,CONT,CAP_ALFA

    MOV DI,OFFSET CHAR1
 
    JMP CHECK
    
	CHECK0:
    mov ah,0                             ;CONSUME BUFFER
    int 16h    
 
    CHECK:
	MOV AH,1
	INT 16H  
	JZ CHECK 
	                     ;7ATETHA HENA 3SHAN COMPARE CHECK LAZEM YEKON BA3D INTRUPT 
	
	;CHECK KEY IS RIGHT
	;-------------------------
	CMP AL,30H
	JZ NUMBER
	JA L1 
	JMP CHECK0 
	
	 L1:
    CMP AL,39H
    JBE NUMBER
    JMP  L2
    
    L2:
    CMP AL,41H 
    JB CHECK0
    JMP L3
    
    L3:
    CMP AL,5AH
    JBE CAP_ALFA
	JMP L4
	
	L4:
	CMP AL,61H 
    JB CHECK0
    JMP L5
	
	L5:
	CMP AL,7AH
    JBE ALFA
	JMP CHECK0
	
	;------------------------- 
	CAP_ALFA:
	ADD AL,20H
	JMP ALFA
	
    NUMBER:
    MOV [DI],AL
    JMP CONT
     
    ALFA:
    MOV [DI],AL
	JMP CONT
  CONT:

ENDM FORBIDDEN_CHAR

;//SWAP REGISTERS REG1=REG2
;//REG1=REG TEMP  REG2=REG PLAYER

MIRROR MACRO REG1,REG2
;LEA DI,REG1
MOV DX,0H
MOV DX,REG2
MOV REG1,DX
ENDM MIRROR

;//RESRET COMMANDS BY PUTTING  $

RESET_COM MACRO COMM
LOCAL L1
LEA SI,COMM
MOV CX,13
L1:
MOV [SI],'$'
INC SI
LOOP L1
ENDM RESET_COM


;//HANSHOOF ELDOOR W 3ALA ASASO HA5OD INST GENERAL

GENERAL_INST MACRO COMMG,COMMP,ACT_SIZE
LOCAL HOTAHA
LEA BX,ACT_SIZE
MOV CX,[BX]
LEA SI,COMMP
LEA DI,COMMG
HOTAHA:
MOV AL,[SI]
MOV [DI],AL
INC SI
INC DI
LOOP HOTAHA

ENDM GENERAL_INST