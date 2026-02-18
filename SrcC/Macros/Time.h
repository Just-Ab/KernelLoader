#ifndef TIME_H
#define TIME_H

#include"Macros/Portio.h"

#define TIME_PIT_TIMER_REG_DATA 0x40
#define TIME_PIT_REG_CTRL 0x43
#define TIME_PIT_FREQUENCY 1193182


void delay(int ticks);

unsigned short pitDelta();
unsigned long long rdtscDelta();

#endif 