/*

 *  Simple and accurate tick counter on AVR microcontrollers

 *  https://github.com/malcom/AVR-Tick-Counter

 *

 *  Copyright (C) 2017 Marcin 'Malcom' Malich <me@malcom.pl>

 *  Released under the MIT License.

 */



#ifndef AVR_TICK_COUNTER_H

#define AVR_TICK_COUNTER_H





#ifdef AVR_TICK_COUNTER_USE_32BIT

    typedef uint32_t ticks_t;

#else

    typedef uint16_t ticks_t;

#endif





extern void ResetTickCounter(void);

extern void StartTickCounter(void);

extern void StopTickCounter(void);

extern ticks_t GetTicks(void);



#endif /* AVR_TICK_COUNTER_H */