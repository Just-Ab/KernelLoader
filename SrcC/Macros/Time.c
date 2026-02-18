#include "Macros/Time.h"



void delay(int ticks) {
    for (volatile int i = 0; i < ticks * 100000; i++);
}

unsigned short pitDelta(){
    portByteOut(TIME_PIT_REG_CTRL,0x00);
    unsigned char low = portByteIn(TIME_PIT_TIMER_REG_DATA);
    unsigned short timerStart = ((unsigned short)portByteIn(TIME_PIT_TIMER_REG_DATA)<<0x8)|((unsigned short)(low));
    portByteOut(TIME_PIT_REG_CTRL,0x00);
    low = portByteIn(TIME_PIT_TIMER_REG_DATA);
    unsigned short timerEnd = ((unsigned short)portByteIn(TIME_PIT_TIMER_REG_DATA)<<0x8)|((unsigned short)(low));

    return (timerStart-timerEnd)&0xffff;
}


unsigned long long rdtscDelta() {
    unsigned int low, high;
    __asm__  ("rdtsc" : "=a"(low), "=d"(high));
    return ((unsigned long long)high << 32) | low;
}
