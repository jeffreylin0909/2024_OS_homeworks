/*
 * file: testpreempt.c
 */
#include <8051.h>
#include "preemptive.h"
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
__data __at (0x2E) char in_counter_1;
__data __at (0x2F) char in_counter_2;
__data __at (0x30) char buffer[BUFFER_SIZE];
extern char tmp0,tmp1,tmp2;

__data __at (0x29) char mutex;
__data __at (0x2A) char full;
__data __at (0x2B) char empty;
__data __at (0x33) char _1_turn;
__data __at (0x34) char _2_turn;
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
    	
    	SemaphoreWait(_1_turn);
    	SemaphoreWait(empty);
	   	SemaphoreWait(mutex);
	   	// add the new char to the buffer
	   	EA = 0;
			buffer[b_end] = 'A'+in_counter_1;
			b_end++;
			if (b_end==BUFFER_SIZE)b_end=0;
			in_counter_1++;
			if (in_counter_1==26)in_counter_1=0;
		EA = 1;
	   	SemaphoreSignal(mutex);
	   	SemaphoreSignal(full);
	   	SemaphoreSignal(_2_turn);
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
    	
    	SemaphoreWait(_2_turn);
    	SemaphoreWait(empty);
	   	SemaphoreWait(mutex);
	   	// add the new char to the buffer
	   	EA = 0;
			buffer[b_end] = '0'+in_counter_2;
			b_end++;
			if (b_end==BUFFER_SIZE)b_end=0;
			in_counter_2++;
			if (in_counter_2==10)in_counter_2=0;
		EA = 1;
	   	SemaphoreSignal(mutex);
	   	SemaphoreSignal(full);
	   	SemaphoreSignal(_1_turn);
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
    /*
     * [TODO]
     * initialize Tx for polling
     */
    TMOD |= 0x20;
	TH1 = -6;//for buad (frequency)
	SCON = 0x50;//for serial port
	TR1 = 1;//start
	
    while (1)
    {
	   	SemaphoreWait(full);
	   	SemaphoreWait(mutex);
	   	// remove the next char from the buffer
	   	EA = 0;
	        SBUF = buffer[b_start];
		    while (TI == 0);
		    TI = 0; 
		    
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
    SemaphoreCreate(mutex,1);
    SemaphoreCreate(full,0);
    SemaphoreCreate(empty,BUFFER_SIZE);
    
    SemaphoreCreate(_1_turn,1);
    SemaphoreCreate(_2_turn,0);
    
    b_start = b_end = 0;
    in_counter_1 = 0;
    in_counter_2 = 0;
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

