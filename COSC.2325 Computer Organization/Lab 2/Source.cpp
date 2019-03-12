#include <iostream>

using namespace std;

void main() {
	unsigned char c1 = 'x';
	unsigned char c2 = 'x';
	unsigned char c3;
	unsigned char c4;
	unsigned long il(0xaabbccee);

	_asm {
		mov eax, il
		mov c3, ah
		mov c4, al
		shr eax, 16
		mov c1, ah
		mov c2, al
	}

	cout.flags(ios::hex);

	cout << "Results are "	<< (unsigned int)c1 << ", "
							<< (unsigned int)c2 << ", "
							<< (unsigned int)c3 << ", "
							<< (unsigned int)c4 << endl;
}