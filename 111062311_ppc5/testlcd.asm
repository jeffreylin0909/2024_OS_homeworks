;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module testlcd
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _timer0_ISR
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genXINIT
	.globl __mcs51_genRAMCLEAR
	.globl __sdcc_gsinit_startup
	.globl _main
	.globl _Consumer
	.globl _Producer2
	.globl _Producer1
	.globl _LCD_ready
	.globl _LCD_write_char
	.globl _LCD_Init
	.globl _AnyKeyPressed
	.globl _KeyToChar
	.globl _Init_Keypad
	.globl _ButtonToChar
	.globl _AnyButtonPressed
	.globl _ThreadExit
	.globl _ThreadYield
	.globl _ThreadCreate
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _empty
	.globl _full
	.globl _mutex
	.globl _buffer
	.globl _b_end
	.globl _b_start
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_b_start	=	0x002c
_b_end	=	0x002d
_buffer	=	0x0030
_mutex	=	0x0029
_full	=	0x002a
_empty	=	0x002b
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	ljmp	_timer0_ISR
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Producer1'
;------------------------------------------------------------
;	testlcd.c:33: void Producer1(void)
;	-----------------------------------------
;	 function Producer1
;	-----------------------------------------
_Producer1:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	testlcd.c:40: while (1)
00117$:
;	testlcd.c:42: if (empty==0)ThreadYield();
	mov	a,_empty
	jnz	00102$
	lcall	_ThreadYield
00102$:
;	testlcd.c:43: SemaphoreWait(empty);
		0$:
	MOV ACC, _empty 
	JZ 0$ 
	JB ACC.7, 0$ 
	dec _empty 
;	testlcd.c:44: if (mutex==0)ThreadYield();
	mov	a,_mutex
	jnz	00104$
	lcall	_ThreadYield
00104$:
;	testlcd.c:45: SemaphoreWait(mutex);
		1$:
	MOV ACC, _mutex 
	JZ 1$ 
	JB ACC.7, 1$ 
	dec _mutex 
;	testlcd.c:46: EA = 0;
;	assignBit
	clr	_EA
;	testlcd.c:48: if (AnyButtonPressed()){
	lcall	_AnyButtonPressed
	mov	a,dpl
	jz	00114$
;	testlcd.c:49: tmp0 = ButtonToChar();
	lcall	_ButtonToChar
;	testlcd.c:50: if (tmp0){
	mov	a,dpl
	mov	_tmp0,a
	jz	00111$
;	testlcd.c:51: buffer[b_end] = tmp0;
	mov	a,_b_end
	add	a,#_buffer
	mov	r0,a
	mov	@r0,_tmp0
;	testlcd.c:52: b_end++;
	mov	a,_b_end
	inc	a
	mov	_b_end,a
;	testlcd.c:53: if (b_end==BUFFER_SIZE)b_end=0;
	mov	a,#0x03
	cjne	a,_b_end,00106$
	mov	_b_end,#0x00
00106$:
;	testlcd.c:54: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:55: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:56: SemaphoreSignal(full);
	INC _full 
;	testlcd.c:57: while(AnyButtonPressed());
00107$:
	lcall	_AnyButtonPressed
	mov	a,dpl
	jz	00117$
	sjmp	00107$
00111$:
;	testlcd.c:59: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:60: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:61: SemaphoreSignal(empty);
	INC _empty 
	sjmp	00117$
00114$:
;	testlcd.c:64: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:65: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:66: SemaphoreSignal(empty);
	INC _empty 
;	testlcd.c:72: }
	sjmp	00117$
;------------------------------------------------------------
;Allocation info for local variables in function 'Producer2'
;------------------------------------------------------------
;	testlcd.c:74: void Producer2(void)
;	-----------------------------------------
;	 function Producer2
;	-----------------------------------------
_Producer2:
;	testlcd.c:81: while (1)
00117$:
;	testlcd.c:84: if (empty==0)ThreadYield();
	mov	a,_empty
	jnz	00102$
	lcall	_ThreadYield
00102$:
;	testlcd.c:85: SemaphoreWait(empty);
		2$:
	MOV ACC, _empty 
	JZ 2$ 
	JB ACC.7, 2$ 
	dec _empty 
;	testlcd.c:86: if (mutex==0)ThreadYield();
	mov	a,_mutex
	jnz	00104$
	lcall	_ThreadYield
00104$:
;	testlcd.c:87: SemaphoreWait(mutex);
		3$:
	MOV ACC, _mutex 
	JZ 3$ 
	JB ACC.7, 3$ 
	dec _mutex 
;	testlcd.c:88: EA = 0;
;	assignBit
	clr	_EA
;	testlcd.c:89: if (AnyKeyPressed()){
	lcall	_AnyKeyPressed
	mov	a,dpl
	jz	00114$
;	testlcd.c:90: tmp0 = KeyToChar();
	lcall	_KeyToChar
;	testlcd.c:91: if (tmp0){
	mov	a,dpl
	mov	_tmp0,a
	jz	00111$
;	testlcd.c:92: buffer[b_end] = tmp0;
	mov	a,_b_end
	add	a,#_buffer
	mov	r0,a
	mov	@r0,_tmp0
;	testlcd.c:93: b_end++;
	mov	a,_b_end
	inc	a
	mov	_b_end,a
;	testlcd.c:94: if (b_end==BUFFER_SIZE)b_end=0;
	mov	a,#0x03
	cjne	a,_b_end,00106$
	mov	_b_end,#0x00
00106$:
;	testlcd.c:95: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:96: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:97: SemaphoreSignal(full);
	INC _full 
;	testlcd.c:98: while(AnyKeyPressed());
00107$:
	lcall	_AnyKeyPressed
	mov	a,dpl
	jz	00117$
	sjmp	00107$
00111$:
;	testlcd.c:100: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:101: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:102: SemaphoreSignal(empty);
	INC _empty 
	sjmp	00117$
00114$:
;	testlcd.c:105: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:106: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:107: SemaphoreSignal(empty);
	INC _empty 
;	testlcd.c:113: }
	sjmp	00117$
;------------------------------------------------------------
;Allocation info for local variables in function 'Consumer'
;------------------------------------------------------------
;	testlcd.c:120: void Consumer(void)
;	-----------------------------------------
;	 function Consumer
;	-----------------------------------------
_Consumer:
;	testlcd.c:122: while (1)
00111$:
;	testlcd.c:124: if (full==0)ThreadYield();
	mov	a,_full
	jnz	00102$
	lcall	_ThreadYield
00102$:
;	testlcd.c:125: SemaphoreWait(full);
		4$:
	MOV ACC, _full 
	JZ 4$ 
	JB ACC.7, 4$ 
	dec _full 
;	testlcd.c:126: if (mutex==0)ThreadYield();
	mov	a,_mutex
	jnz	00104$
	lcall	_ThreadYield
00104$:
;	testlcd.c:127: SemaphoreWait(mutex);
		5$:
	MOV ACC, _mutex 
	JZ 5$ 
	JB ACC.7, 5$ 
	dec _mutex 
;	testlcd.c:129: EA = 0;
;	assignBit
	clr	_EA
;	testlcd.c:130: LCD_write_char(buffer[b_start]);
	mov	a,_b_start
	add	a,#_buffer
	mov	r1,a
	mov	dpl,@r1
	lcall	_LCD_write_char
;	testlcd.c:131: while (!LCD_ready());
00105$:
	lcall	_LCD_ready
	mov	a,dpl
	jz	00105$
;	testlcd.c:133: b_start++;
	mov	a,_b_start
	inc	a
	mov	_b_start,a
;	testlcd.c:134: if (b_start==BUFFER_SIZE)b_start=0;
	mov	a,#0x03
	cjne	a,_b_start,00109$
	mov	_b_start,#0x00
00109$:
;	testlcd.c:135: EA = 1;
;	assignBit
	setb	_EA
;	testlcd.c:136: SemaphoreSignal(mutex);
	INC _mutex 
;	testlcd.c:137: SemaphoreSignal(empty);
	INC _empty 
;	testlcd.c:139: }
	sjmp	00111$
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	testlcd.c:146: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	testlcd.c:152: Init_Keypad();
	lcall	_Init_Keypad
;	testlcd.c:153: LCD_Init();
	lcall	_LCD_Init
;	testlcd.c:156: SemaphoreCreate(mutex,1);
	mov	_mutex,#0x01
;	testlcd.c:157: SemaphoreCreate(full,0);
	mov	_full,#0x00
;	testlcd.c:158: SemaphoreCreate(empty,BUFFER_SIZE);
	mov	_empty,#0x03
;	testlcd.c:161: b_start = b_end = 0;
	mov	_b_end,#0x00
	mov	_b_start,#0x00
;	testlcd.c:168: ThreadCreate(Producer1);
	mov	dptr,#_Producer1
	lcall	_ThreadCreate
;	testlcd.c:169: ThreadCreate(Producer2);
	mov	dptr,#_Producer2
	lcall	_ThreadCreate
;	testlcd.c:170: ThreadCreate(Consumer);
	mov	dptr,#_Consumer
	lcall	_ThreadCreate
;	testlcd.c:171: ThreadExit();
;	testlcd.c:172: }
	ljmp	_ThreadExit
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_gsinit_startup'
;------------------------------------------------------------
;	testlcd.c:174: void _sdcc_gsinit_startup(void)
;	-----------------------------------------
;	 function _sdcc_gsinit_startup
;	-----------------------------------------
__sdcc_gsinit_startup:
;	testlcd.c:178: __endasm;
	LJMP	_Bootstrap
;	testlcd.c:179: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
;------------------------------------------------------------
;	testlcd.c:181: void _mcs51_genRAMCLEAR(void) {}
;	-----------------------------------------
;	 function _mcs51_genRAMCLEAR
;	-----------------------------------------
__mcs51_genRAMCLEAR:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genXINIT'
;------------------------------------------------------------
;	testlcd.c:182: void _mcs51_genXINIT(void) {}
;	-----------------------------------------
;	 function _mcs51_genXINIT
;	-----------------------------------------
__mcs51_genXINIT:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
;------------------------------------------------------------
;	testlcd.c:183: void _mcs51_genXRAMCLEAR(void) {}
;	-----------------------------------------
;	 function _mcs51_genXRAMCLEAR
;	-----------------------------------------
__mcs51_genXRAMCLEAR:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_ISR'
;------------------------------------------------------------
;	testlcd.c:185: void timer0_ISR(void) __interrupt(1) {
;	-----------------------------------------
;	 function timer0_ISR
;	-----------------------------------------
_timer0_ISR:
;	testlcd.c:188: __endasm;
	ljmp	_myTimer0Handler
;	testlcd.c:189: }
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop psw
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;	eliminated unneeded push/pop acc
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
