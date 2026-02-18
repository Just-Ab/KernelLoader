#include "Drivers/VgaDriver.h"
#include "Drivers/KeyboardDriver.h"


void main(){
    const char entryText[65] = "--Kernel entry-- | Keyboard test [scan|ascii]|[  : ] exit:Q+Esc ";
    vgaSet(entryText,sizeof(entryText),VGA_MODE_NOBLINK_BLACK_HIGH_WHITE);
    unsigned char running = 1;
    unsigned char prevKey=0x00,currentKey=0x00;
    while (running)
    {
        currentKey = keyboardReadRaw();

        vgaSetHexWordAt(currentKey,47,0,VGA_MODE_NOBLINK_BLACK_HIGH_WHITE);
        vgaSetCharAt(keyboardReadAscii(),50,0,VGA_MODE_NOBLINK_BLACK_HIGH_WHITE);

        if (currentKey==0x01 && prevKey==0x10) running = 0;

        prevKey = currentKey;
    }
    vgaClear(' ',VGA_MODE_NOBLINK_BLACK_HIGH_WHITE);
    const char exitText[60] = "--Kernel entry--  | Test-Ends, Please shutdown the machine.";
    vgaSet(exitText,sizeof(exitText),VGA_MODE_NOBLINK_BLACK_HIGH_WHITE);

}