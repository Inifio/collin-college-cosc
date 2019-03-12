;/*--------------------------*\
;|| Name: LAWSON ZEUGIN		||
;|| Class: COSC - 2325.S01	||
;|| Project: LAB EIGHT		||
;\*--------------------------*/

.386
.model flat

public _Average

.data

.code

_Average proc
		PUSH	EBP							; PUSHING EBP TO THE STACK
		MOV		EBP, ESP					; SETTING EBP EQUAL TO ESP
		XOR		EAX, EAX					; SETTING EAX TO 0
		XOR		ECX, ECX					; SETTING ECX TO 0
		MOV		EDX, [EBP + 8]				; GETTING NUMBER OF ELEMENTS IN THE ARRAY
		MOV		EBX, [EBP + 12]				; GETTING THE ADDRESS OF THE 1ST ELEMTNT OF THE ARRAY
	LOOP1:
		ADD		EAX, [EBX + (ECX * 4)]		; ADD EAX TO ECX * 4
		INC		ECX							
		CMP		ECX, EDX					; IF THEY ARE EQUAL WE HAVE READ ALL ELEMENTS
		JL		LOOP1

		CDQ
		IDIV	ECX							; DEVIDE EAX BY THE TOTAL ELEMENTS IN THE ARRAY
		XOR		EDX, EDX					; SETTING EDX TO 0
		SHL		EDX, 1						; EDX *= 2
		CMP		EDX, ECX					; COMPARING TO SEE IF ROUNDING UP IS NEEDED.
		JG		DONE						; NO ROUND UP? JUMP TO DONE
		ADD		EAX, 1						; NEEDS TO ROUND UP -> ADD ONE
	DONE:
		POP		EBP							; POP EBP OFF THE STACK
		ret									; RETURN THE RESULT IN EAX
_Average endp

end