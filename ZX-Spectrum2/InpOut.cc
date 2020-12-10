
#include "InpOut.h"
#include <iostream>
#include <string>

void IO::write(unsigned address, uint8_t value) {
	_port_fe = value;

}

uint8_t IO::read(unsigned address) const {
	uint8_t a = (address >> 8);
	uint8_t p = (address & 0xff);

	if (p == 0xfe) {
		switch (a) {
	        case 0x7f: return _key_matrix[0];
	        case 0xbf: return _key_matrix[1];
	        case 0xdf: return _key_matrix[2];
	        case 0xef: return _key_matrix[3];
	        case 0xf7: return _key_matrix[4];
	        case 0xfb: return _key_matrix[5];
	        case 0xfd: return _key_matrix[6];
	        case 0xfe: return _key_matrix[7];
	        default:   return 0;
	     }
	}
	else return 0;
}

void IO::keydown(unsigned row, unsigned col)
{
	_key_matrix[row] &= ~(1 << col);
}

void IO::keyup(unsigned row, unsigned col)
{
	_key_matrix[row] |= (1 << col);
}
