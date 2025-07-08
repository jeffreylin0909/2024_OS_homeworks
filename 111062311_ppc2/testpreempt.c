/*
 * file: testpreempt.c
 */
#include <8051.h>
#include "preemptive.h"

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
__data __at (0x2E) char in_counter;
__data __at (0x30) char buffer[16];
extern char tmp0,tmp1,tmp2;
/* [TODO for this function]
 * the producer in this test program generates one characters at a
 * time from 'A' to 'Z' and starts from 'A' again. The shared buffer
 * must be empty in order for the Producer to write.
 */
void Producer(void)
{
    /*
     * [TODO]
     * initialize producer data structure, and then enter
     * an infinite loop (does not return)
     */
    while (1)
    {
        /* [TODO]
         * wait for the buffer to be available,
         * and then write the new data into the buffer */
		tmp0 = b_end+1;
        if (tmp0==16)tmp0=0;
        while (tmp0 == b_start){
        	;//wait preempt
		}
		EA = 0;
			buffer[b_end] = 'A'+in_counter;
			b_end++;
			if (b_end==16)b_end=0;
			in_counter++;
			if (in_counter==26)in_counter=0;
		EA = 1;
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
        /*
         * [TODO]
         * wait for new data from producer
         */
		while (b_start == b_end){
			;//wait preempt
		}
		EA = 0;
	        /*
	         * [TODO]
	         * write data to serial port Tx,
	         * poll for Tx to finish writing (TI),
	         * then clear the flag
	         */
	        SBUF = buffer[b_start];
		    while (TI == 0);
		    TI = 0; 
		    
		    b_start++;
		    if (b_start==16)b_start=0;
		EA = 1;
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
    b_start = b_end = 0;
    in_counter = 0;
    /*
     * [TODO]
     * set up Producer and Consumer.
     * Because both are infinite loops, there is no loop
     * in this function and no return.
     */
    ThreadCreate(Producer);
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

