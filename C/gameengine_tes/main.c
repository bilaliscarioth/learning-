#include "stddef.h"
#include "stdint.h"


size_t* screenColumn;
size_t screenRow;
uint8_t terminalColor;
uint16_t* screenBuffer;


static const size_t widthVGA = 80;
static const size_t heightVGA = 25;

void setFrame(unsigned char uc){
	screenBuffer = (uint16_t*) 0xB8000;
	screenBuffer[0] = (uint16_t)uc;
}

int main(){
	setFrame(' ');
}
