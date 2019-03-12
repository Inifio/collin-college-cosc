/*--------------------------*\
|| Name: Lawson Zeugin		||
|| Class: COSC - 2325.S01	||
|| Project: Lab Five		||
\*--------------------------*/
#include <iostream>
#include <stdlib.h>

using namespace std;

void main() {
	unsigned long i1;
	unsigned long i2;
	unsigned long i3;
	unsigned long i4;

	_asm {
		mov i1, 1
		mov i2, 1
		mov ecx, 1

		Loop1:
			inc ecx
			mov ebx, i1
			add ebx, 3
			mov i1, ebx
			mov eax, i2
			imul eax, 3
			mov i2, eax
			cmp ecx, 15
			jge Check2
			cmp ebx, 100
			jle Loop1

		Check2:
			cmp eax, 999999
			jl Loop1

		mov i3, ecx
		mov eax, ebx
		cdq
		idiv ecx
		mov i4, edx


	}

	cout << "Results are "	<< (unsigned long) i1 << ", "
							<< (unsigned long) i2 << ", "
							<< (unsigned long) i3 << ", "
							<< (unsigned long) i4 << endl;

	system("Pause");
}