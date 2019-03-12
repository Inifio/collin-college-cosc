/*--------------------------*\
|| Name: Lawson Zeugin		||
|| Class: COSC - 2325.S01	||
|| Project: Lab Three		||
\*--------------------------*/
#include <iostream>

using namespace std;

void main() {
	long Var1 = 6;
	long Var2 = 10;
	long Var3 = 15;
	long Var4 = 21;
	long Var5 = 22;
	long Sum; 
	long Result; 
	long Remainder;
	
	_asm {
		;// -= Adding all the variables =-
		mov EAX, Var1		;// Moving 6 into EAX. EAX is now 6
		add EAX, Var2		;// Add 10 to EAX (6). EAX is now 16
		add EAX, Var3		;// Add 15 to EAX (16). EAX is now 31
		add EAX, Var4		;// Add 21 to EAX (31). EAX is now 52
		add EAX, Var5		;// Add 22 to EAX (52). EAX is now 74

		mov Sum, EAX		;// Move EAX into the Sum variable
		mov EAX, EAX		;// Clearing the register, probably not needed


		;// -= Completing the equation: (Var1+Var2)*(Var3–Var4)/(Var5+Var1) =-
		mov EAX, Var1		;// Moving 6 in EAX. EAX is now 6
		add EAX, Var2		;// Adding 10 to EAX (6). EAX is now 16
		mov EBX, Var3		;// Moving 15 into EBX. EBX is now 15
		sub EBX, Var4		;// Subtracting 21 from EBX (15). EBX is now -6
		mov ECX, Var5		;// Moving 22 into ECX. ECX is now 22
		add ECX, Var1		;// Adding 6 to ECX (22). ECX is now 16

		imul EBX			;// Multiplying EBX (-6) by EAX (16). EAX is now -96
		idiv ECX			;// Dividing EAX (-96) by ECX (16). EAX is now -3
		mov Result, EAX		;// Moving EAX (-3) into the result variable
		mov Remainder, EDX	;// Moving EDX (-12) to remainder variable
	}
	
	cout << "Sum is        " << Sum << endl; 
	cout << "Result is     " << Result << endl;
	cout << "Remainder is  " << Remainder << endl;
}