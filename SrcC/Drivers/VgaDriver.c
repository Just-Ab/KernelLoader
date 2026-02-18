#include "Drivers/VgaDriver.h"

void vgaClear(const unsigned char character , const unsigned char mode){
    
    volatile const unsigned char * VGA_MEMORY=(volatile const unsigned char*)VGA_MEMSTART;
    
    char *memoryPointer = (unsigned char*)VGA_MEMORY;

    for(int i=0;i<VGA_WIDTH*VGA_HEIGHT;i++){
        *(memoryPointer+i*VGA_UNIT)=character;
        *(memoryPointer+i*VGA_UNIT+1)=mode;

        
    }
}


void vgaSet(const unsigned char *string,const int size,const unsigned char mode){
    volatile const unsigned short * VGA_MEMORY_START=(volatile const unsigned short*)VGA_MEMSTART;
    volatile const unsigned short * VGA_MEMORY_END=(volatile const unsigned short*)(VGA_MEMEND);

    unsigned short *memoryPointer = (unsigned short*)VGA_MEMORY_START;
    for(int i=0;i<size;i++){
        if(memoryPointer>(unsigned short*)VGA_MEMORY_END){break;}
        *(memoryPointer)=(mode<<8)|string[i];
        memoryPointer++;
    }
}


void vgaSetCharAt(const unsigned char character, const int col, const int row, const unsigned char mode) {
    if (row >= VGA_HEIGHT || row < 0 || col >= VGA_WIDTH || col < 0) return;
    unsigned short* memoryPointer = (unsigned short*)(VGA_MEMSTART + (row * VGA_WIDTH + col) * VGA_UNIT);
    *memoryPointer = ((unsigned short)mode << 8) | character;
}



void vgaSetHexWordAt(const unsigned short hex,const int col,const int row,const unsigned char mode){
    for (int offset = 0; offset < 2; offset++) {
        unsigned char nibble = (hex >> ((1 - offset) * 4)) & 0xF;
        unsigned char ascii  = nibble < 10 ? '0' + nibble : 'A' + (nibble - 10);
        vgaSetCharAt(ascii, col + offset, row, mode);
    }
}

void vgaSetHexDDdAt(unsigned long long hex, int col, int row, unsigned char mode) {
    for (int offset = 0; offset < 16; offset++) {
        unsigned char nibble = (hex >> ((15 - offset) * 4)) & 0xF;
        unsigned char ascii  = nibble < 10 ? '0' + nibble : 'A' + (nibble - 10);
        vgaSetCharAt(ascii, col + offset, row, mode);
    }
}
