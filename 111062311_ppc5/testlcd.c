/*
 * file: testpreempt.c
 */
#include <8051.h>
#include "preemptive.h"
#include "buttonlib.h"
#include "keylib.h"
#include "lcdlib.h"
#define BUFFER_SIZE 3

/*
 * [TODO]
 * declare your global variables here, for the shared buffer
 * between the producer and consumer.
 * Hint: you may want to manually designate the location for the
 * variable.  you can use
 *        __data __at (0x30) type var;
 * to declare a variable var of the type
 */
__data __at (0x2C) char b_start;
__data __at (0x2D) char b_end;
__data __at (0x30) char buffer[BUFFER_SIZE];
extern char tmp0,tmp1,tmp2;

__data __at (0x29) char mutex;
__data __at (0x2A) char full;
__data __at (0x2B) char empty;
/* [TODO for this function]
 * the producer in this test program generates one characters at a
 * time from 'A' to 'Z' and starts from 'A' again. The shared buffer
 * must be empty in order for the Producer to write.
 */
void Producer1(void)
{
    /*
     * [TODO]
     * initialize producer data structure, and then enter
     * an infinite loop (does not return)
     */
    while (1)
    {
    	if (empty==0)ThreadYield();
    	SemaphoreWait(empty);
    	if (mutex==0)ThreadYield();
	   	SemaphoreWait(mutex);
	   	EA = 0;
	   	// add the new char to the buffer
		if (AnyButtonPressed()){
			tmp0 = ButtonToChar();
			if (tmp0){
				buffer[b_end] = tmp0;
				b_end++;
				if (b_end==BUFFER_SIZE)b_end=0;
				EA = 1;
				SemaphoreSignal(mutex);
			   	SemaphoreSignal(full);
			   	while(AnyButtonPressed());
			}else {
				EA = 1;
				SemaphoreSignal(mutex);
			   	SemaphoreSignal(empty);
			}
		}else {
			EA = 1;
			SemaphoreSignal(mutex);
		   	SemaphoreSignal(empty);
		}
        /* [TODO]
         * wait for the buffer to be available,
         * and then write the new data into the buffer */
    }
}

void Producer2(void)
{
    /*
     * [TODO]
     * initialize producer data structure, and then enter
     * an infinite loop (does not return)
     */
    while (1)
    {
	   	// add the new char to the buffer
	   	if (empty==0)ThreadYield();
    	SemaphoreWait(empty);
    	if (mutex==0)ThreadYield();
	   	SemaphoreWait(mutex);
		EA = 0;
		if (AnyKeyPressed()){
			tmp0 = KeyToChar();
			if (tmp0){
				buffer[b_end] = tmp0;
				b_end++;
				if (b_end==BUFFER_SIZE)b_end=0;
				EA = 1;
				SemaphoreSignal(mutex);
			   	SemaphoreSignal(full);
			   	while(AnyKeyPressed());
			}else {
				EA = 1;
				SemaphoreSignal(mutex);
			   	SemaphoreSignal(empty);
			}
		}else {
			EA = 1;
			SemaphoreSignal(mutex);
		   	SemaphoreSignal(empty);
		}
        /* [TODO]
         * wait for the buffer to be available,
         * and then write the new data into the buffer */
    }
}

/* [TODO for this function]
 * the consumer in this test program gets the next item from
 * the queue and consume it and writes it to the serial port.
 * The Consumer also does not return.
 */
void Consumer(void)
{	
    while (1)
    {
    	if (full==0)ThreadYield();
	   	SemaphoreWait(full);
	   	if (mutex==0)ThreadYield();
	   	SemaphoreWait(mutex);
	   	// remove the next char from the buffer
	   	EA = 0;
		    LCD_write_char(buffer[b_start]);
		    while (!LCD_ready());
		    
		    b_start++;
		    if (b_start==BUFFER_SIZE)b_start=0;
		EA = 1;
	   	SemaphoreSignal(mutex);
	   	SemaphoreSignal(empty);
    }
}

/* [TODO for this function]
 * main() is started by the thread bootstrapper as thread-0.
 * It can create more thread(s) as needed:
 * one thread can act as producer and another as consumer.
 */
void main(void)
{
    /*
     * [TODO]
     * initialize globals
     */
    Init_Keypad();
    LCD_Init();
    
    
    SemaphoreCreate(mutex,1);
    SemaphoreCreate(full,0);
    SemaphoreCreate(empty,BUFFER_SIZE);
    
    
    b_start = b_end = 0;
    /*
     * [TODO]
     * set up Producer and Consumer.
     * Because both are infinite loops, there is no loop
     * in this function and no return.
     */
    ThreadCreate(Producer1);
    ThreadCreate(Producer2);
    ThreadCreate(Consumer);
    ThreadExit();
}

void _sdcc_gsinit_startup(void)
{
    __asm
        LJMP _Bootstrap
    __endasm;
}

void _mcs51_genRAMCLEAR(void) {}
void _mcs51_genXINIT(void) {}
void _mcs51_genXRAMCLEAR(void) {}

void timer0_ISR(void) __interrupt(1) {
        __asm
                ljmp _myTimer0Handler
        __endasm;
}

