#include <iostream>

using namespace std;

void main() {
	const unsigned char c1(0x11);
	const unsigned char c2(0x22);
	const unsigned char c3(0x33);
	const unsigned char c4(0x44);
	unsigned long il(0);

	_asm {
		mov		ah, c1		;// Puts c1 into ah
		mov		al, c2		;// Puts c2 into al
		shl		eax, 16		;// Moves contents of ah & al to right side of eax
		mov		ah, c3		;// Puts c3 into ah
		mov		al, c4		;// Puts c4 into al
		mov		il, eax		;// Set entire contents of eax to il
	}

	cout << "Result is " << hex << il << endl;

}