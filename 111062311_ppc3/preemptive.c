#include <8051.h>

#include "preemptive.h"

/*
 * [TODO]
 * declare the static globals here using
 *        __data __at (address) type name; syntax
 * manually allocate the addresses of these variables, for
 * - saved stack pointers (MAXTHREADS)
 * - current thread ID
 * - a bitmap for which thread ID is a valid thread;
 *   maybe also a count, but strictly speaking not necessary
 * - plus any temporaries that you need.
 */
__data __at (0x20) char T_SP[4];
__data __at (0x24) char current_T;
__data __at (0x25) char tmp0;
__data __at (0x26) char tmp1;
__data __at (0x27) char tmp2;
__data __at (0x28) char bitmap;


/*
 * [TODO]
 * define a macro for saving the context of the current thread by
 * 1) push ACC, B register, Data pointer registers (DPL, DPH), PSW
 * 2) save SP into the saved Stack Pointers array
 *   as indexed by the current thread ID.
 * Note that 1) should be written in assembly,
 *     while 2) can be written in either assembly or C
 */
#define SAVESTATE               \
    {                           \
        __asm                   \
        PUSH A					\
        PUSH B					\
        PUSH DPL				\
        PUSH DPH				\
        PUSH PSW				\
        __endasm;               \
        						\
        T_SP[current_T] = SP;	\
    }

/*
 * [TODO]
 * define a macro for restoring the context of the current thread by
 * essentially doing the reverse of SAVESTATE:
 * 1) assign SP to the saved SP from the saved stack pointer array
 * 2) pop the registers PSW, data pointer registers, B reg, and ACC
 * Again, popping must be done in assembly but restoring SP can be
 * done in either C or assembly.
 */
#define RESTORESTATE            \
    {                           \
    	SP = T_SP[current_T];	\
    							\
        __asm					\
        POP PSW					\
        POP DPH					\
        POP DPL					\
        POP B					\
        POP A					\
        __endasm;				\
    }

/*
 * we declare main() as an extern so we can reference its symbol
 * when creating a thread for it.
 */

extern void main(void);

/*
 * Bootstrap is jumped to by the startup code to make the thread for
 * main, and restore its context so the thread can run.
 */

void Bootstrap(void)
{
    /*
     * [TODO]
     * initialize data structures for threads (e.g., mask)
     *
     * optional: move the stack pointer to some known location
     * only during bootstrapping. by default, SP is 0x07.
     *
     * [TODO]
     *     create a thread for main; be sure current thread is
     *     set to this thread ID, and restore its context,
     *     so that it starts running main().
     */
    T_SP[0] = 0x3F;
    T_SP[1] = 0x4F;
    T_SP[2] = 0x5F;
    T_SP[3] = 0x6F;
    bitmap = 0b0000;
    
    TMOD = 0;
    IE = 0x82;//10000010
    //EA = 1;ET0 = 1;
    TR0 = 1;
    
    current_T = ThreadCreate(main);
    RESTORESTATE;
    return;
}

/*
 * ThreadCreate() creates a thread data structure so it is ready
 * to be restored (context switched in).
 * The function pointer itself should take no argument and should
 * return no argument.
 */
ThreadID ThreadCreate(FunctionPtr fp)
{
	EA = 0;
		/*
	     * [TODO]
	     * check to see we have not reached the max #threads.
	     * if so, return -1, which is not a valid thread ID.
	     */
	    tmp2 = 0;
	    do
	    {
	        if (tmp2==4){
	        	break;
			}
			if (!(bitmap&(1<<tmp2))){
				break;
			}
			tmp2++;
	    } while (1);
	    
	    if (tmp2 == 4){
	    	;
	    	//return tmp2;
		}else {
			/*
		     * [TODO]
		     *     otherwise, find a thread ID that is not in use,
		     *     and grab it. (can check the bit mask for threads), [done above]
		     *
		     * [TODO] below
		     * a. update the bit mask
		         (and increment thread count, if you use a thread count,
		          but it is optional)
		       b. calculate the starting stack location for new thread [done in Bootstrap]
		       c. save the current SP in a temporary
		          set SP to the starting location for the new thread [done in Bootstrap]
		       d. push the return address fp (2-byte parameter to
		          ThreadCreate) onto stack so it can be the return
		          address to resume the thread. Note that in SDCC
		          convention, 2-byte ptr is passed in DPTR.  but
		          push instruction can only push it as two separate
		          registers, DPL and DPH.
		       e. we want to initialize the registers to 0, so we
		          assign a register to 0 and push it four times
		          for ACC, B, DPL, DPH.  Note: push #0 will not work
		          because push takes only direct address as its operand,
		          but it does not take an immediate (literal) operand.
		       f. finally, we need to push PSW (processor status word)
		          register, which consist of bits
		           CY AC F0 RS1 RS0 OV UD P
		          all bits can be initialized to zero, except <RS1:RS0>
		          which selects the register bank.
		          Thread 0 uses bank 0, Thread 1 uses bank 1, etc.
		          Setting the bits to 00B, 01B, 10B, 11B will select
		          the register bank so no need to push/pop registers
		          R0-R7.  So, set PSW to
		          00000000B for thread 0, 00001000B for thread 1,
		          00010000B for thread 2, 00011000B for thread 3.
		       g. write the current stack pointer to the saved stack
		          pointer array for this newly created thread ID
		       h. set SP to the saved SP in step c.
		       i. finally, return the newly created thread ID.
		     */
		    bitmap = bitmap|(1<<tmp2);
		    tmp0 = SP;
		    SP = T_SP[tmp2];
			__asm
		        PUSH DPL
		        PUSH DPH
		    __endasm;
		    
		    ACC = 0;
		    __asm
		        PUSH ACC
		        PUSH ACC
		        PUSH ACC
		        PUSH ACC
		    __endasm;
		    
		    tmp1 = tmp2<<3;
		    __asm
		        PUSH 0x26;
		    __endasm;
		    
		    T_SP[tmp2] = SP;
		    SP = tmp0;
		    
		    //return tmp2;
		}
	EA = 1;
	return tmp2;
}

/*
 * this is called by a running thread to yield control to another
 * thread.  ThreadYield() saves the context of the current
 * running thread, picks another thread (and set the current thread
 * ID to it), if any, and then restores its state.
 */

void ThreadYield(void)
{
	EA = 0;
	    SAVESTATE;
	    tmp0 = 1<<current_T;
	    do
	    {
	        /*
	         * [TODO]
	         * do round-robin policy for now.
	         * find the next thread that can run and
	         * set the current thread ID to it,
	         * so that it can be restored (by the last line of
	         * this function).
	         * there should be at least one thread, so this loop
	         * will always terminate.
	         */
	        current_T++;
	        tmp0 <<= 1;
	        if (current_T==4){
	        	current_T = 0;
	        	tmp0 = 1;
			}
			if (bitmap&tmp0){
				break;
			}
	    } while (1);
	    RESTORESTATE;
	EA = 1;
}

/*
 * ThreadExit() is called by the thread's own code to terminate
 * itself.  It will never return; instead, it switches context
 * to another thread.
 */
void ThreadExit(void)
{
	EA = 0;
	    /*
	     * clear the bit for the current thread from the
	     * bit mask, decrement thread count (if any),
	     * and set current thread to another valid ID.
	     * Q: What happens if there are no more valid threads? A: inf loop
	     */
	    
	    bitmap = bitmap&(~(1<<current_T));
	    tmp0 = 1<<current_T;
	    do
	    {
	        current_T++;
	        tmp0 <<= 1;
	        if (current_T==4){
	        	current_T = 0;
	        	tmp0 = 1;
			}
			if (bitmap&tmp0){
				break;
			}
	    } while (1);
	    RESTORESTATE;
	EA = 1;
}

void myTimer0Handler(void)
{
	EA = 0;
	    SAVESTATE;
	    tmp0 = 1<<current_T;
	    do
	    {
	        /*
	         * [TODO]
	         * do round-robin policy for now.
	         * find the next thread that can run and
	         * set the current thread ID to it,
	         * so that it can be restored (by the last line of
	         * this function).
	         * there should be at least one thread, so this loop
	         * will always terminate.
	         */
	        current_T++;
	        tmp0 <<= 1;
	        if (current_T==4){
	        	current_T = 0;
	        	tmp0 = 1;
			}
			if (bitmap&tmp0){
				break;
			}
	    } while (1);
	    RESTORESTATE;
    EA = 1;
    __asm
            RETI
    __endasm;
}
