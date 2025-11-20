                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module testlcd
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _timer0_ISR
                                     12 	.globl __mcs51_genXRAMCLEAR
                                     13 	.globl __mcs51_genXINIT
                                     14 	.globl __mcs51_genRAMCLEAR
                                     15 	.globl __sdcc_gsinit_startup
                                     16 	.globl _main
                                     17 	.globl _Consumer
                                     18 	.globl _Producer2
                                     19 	.globl _Producer1
                                     20 	.globl _LCD_ready
                                     21 	.globl _LCD_write_char
                                     22 	.globl _LCD_Init
                                     23 	.globl _AnyKeyPressed
                                     24 	.globl _KeyToChar
                                     25 	.globl _Init_Keypad
                                     26 	.globl _ButtonToChar
                                     27 	.globl _AnyButtonPressed
                                     28 	.globl _ThreadExit
                                     29 	.globl _ThreadYield
                                     30 	.globl _ThreadCreate
                                     31 	.globl _CY
                                     32 	.globl _AC
                                     33 	.globl _F0
                                     34 	.globl _RS1
                                     35 	.globl _RS0
                                     36 	.globl _OV
                                     37 	.globl _F1
                                     38 	.globl _P
                                     39 	.globl _PS
                                     40 	.globl _PT1
                                     41 	.globl _PX1
                                     42 	.globl _PT0
                                     43 	.globl _PX0
                                     44 	.globl _RD
                                     45 	.globl _WR
                                     46 	.globl _T1
                                     47 	.globl _T0
                                     48 	.globl _INT1
                                     49 	.globl _INT0
                                     50 	.globl _TXD
                                     51 	.globl _RXD
                                     52 	.globl _P3_7
                                     53 	.globl _P3_6
                                     54 	.globl _P3_5
                                     55 	.globl _P3_4
                                     56 	.globl _P3_3
                                     57 	.globl _P3_2
                                     58 	.globl _P3_1
                                     59 	.globl _P3_0
                                     60 	.globl _EA
                                     61 	.globl _ES
                                     62 	.globl _ET1
                                     63 	.globl _EX1
                                     64 	.globl _ET0
                                     65 	.globl _EX0
                                     66 	.globl _P2_7
                                     67 	.globl _P2_6
                                     68 	.globl _P2_5
                                     69 	.globl _P2_4
                                     70 	.globl _P2_3
                                     71 	.globl _P2_2
                                     72 	.globl _P2_1
                                     73 	.globl _P2_0
                                     74 	.globl _SM0
                                     75 	.globl _SM1
                                     76 	.globl _SM2
                                     77 	.globl _REN
                                     78 	.globl _TB8
                                     79 	.globl _RB8
                                     80 	.globl _TI
                                     81 	.globl _RI
                                     82 	.globl _P1_7
                                     83 	.globl _P1_6
                                     84 	.globl _P1_5
                                     85 	.globl _P1_4
                                     86 	.globl _P1_3
                                     87 	.globl _P1_2
                                     88 	.globl _P1_1
                                     89 	.globl _P1_0
                                     90 	.globl _TF1
                                     91 	.globl _TR1
                                     92 	.globl _TF0
                                     93 	.globl _TR0
                                     94 	.globl _IE1
                                     95 	.globl _IT1
                                     96 	.globl _IE0
                                     97 	.globl _IT0
                                     98 	.globl _P0_7
                                     99 	.globl _P0_6
                                    100 	.globl _P0_5
                                    101 	.globl _P0_4
                                    102 	.globl _P0_3
                                    103 	.globl _P0_2
                                    104 	.globl _P0_1
                                    105 	.globl _P0_0
                                    106 	.globl _B
                                    107 	.globl _ACC
                                    108 	.globl _PSW
                                    109 	.globl _IP
                                    110 	.globl _P3
                                    111 	.globl _IE
                                    112 	.globl _P2
                                    113 	.globl _SBUF
                                    114 	.globl _SCON
                                    115 	.globl _P1
                                    116 	.globl _TH1
                                    117 	.globl _TH0
                                    118 	.globl _TL1
                                    119 	.globl _TL0
                                    120 	.globl _TMOD
                                    121 	.globl _TCON
                                    122 	.globl _PCON
                                    123 	.globl _DPH
                                    124 	.globl _DPL
                                    125 	.globl _SP
                                    126 	.globl _P0
                                    127 	.globl _empty
                                    128 	.globl _full
                                    129 	.globl _mutex
                                    130 	.globl _buffer
                                    131 	.globl _b_end
                                    132 	.globl _b_start
                                    133 ;--------------------------------------------------------
                                    134 ; special function registers
                                    135 ;--------------------------------------------------------
                                    136 	.area RSEG    (ABS,DATA)
      000000                        137 	.org 0x0000
                           000080   138 _P0	=	0x0080
                           000081   139 _SP	=	0x0081
                           000082   140 _DPL	=	0x0082
                           000083   141 _DPH	=	0x0083
                           000087   142 _PCON	=	0x0087
                           000088   143 _TCON	=	0x0088
                           000089   144 _TMOD	=	0x0089
                           00008A   145 _TL0	=	0x008a
                           00008B   146 _TL1	=	0x008b
                           00008C   147 _TH0	=	0x008c
                           00008D   148 _TH1	=	0x008d
                           000090   149 _P1	=	0x0090
                           000098   150 _SCON	=	0x0098
                           000099   151 _SBUF	=	0x0099
                           0000A0   152 _P2	=	0x00a0
                           0000A8   153 _IE	=	0x00a8
                           0000B0   154 _P3	=	0x00b0
                           0000B8   155 _IP	=	0x00b8
                           0000D0   156 _PSW	=	0x00d0
                           0000E0   157 _ACC	=	0x00e0
                           0000F0   158 _B	=	0x00f0
                                    159 ;--------------------------------------------------------
                                    160 ; special function bits
                                    161 ;--------------------------------------------------------
                                    162 	.area RSEG    (ABS,DATA)
      000000                        163 	.org 0x0000
                           000080   164 _P0_0	=	0x0080
                           000081   165 _P0_1	=	0x0081
                           000082   166 _P0_2	=	0x0082
                           000083   167 _P0_3	=	0x0083
                           000084   168 _P0_4	=	0x0084
                           000085   169 _P0_5	=	0x0085
                           000086   170 _P0_6	=	0x0086
                           000087   171 _P0_7	=	0x0087
                           000088   172 _IT0	=	0x0088
                           000089   173 _IE0	=	0x0089
                           00008A   174 _IT1	=	0x008a
                           00008B   175 _IE1	=	0x008b
                           00008C   176 _TR0	=	0x008c
                           00008D   177 _TF0	=	0x008d
                           00008E   178 _TR1	=	0x008e
                           00008F   179 _TF1	=	0x008f
                           000090   180 _P1_0	=	0x0090
                           000091   181 _P1_1	=	0x0091
                           000092   182 _P1_2	=	0x0092
                           000093   183 _P1_3	=	0x0093
                           000094   184 _P1_4	=	0x0094
                           000095   185 _P1_5	=	0x0095
                           000096   186 _P1_6	=	0x0096
                           000097   187 _P1_7	=	0x0097
                           000098   188 _RI	=	0x0098
                           000099   189 _TI	=	0x0099
                           00009A   190 _RB8	=	0x009a
                           00009B   191 _TB8	=	0x009b
                           00009C   192 _REN	=	0x009c
                           00009D   193 _SM2	=	0x009d
                           00009E   194 _SM1	=	0x009e
                           00009F   195 _SM0	=	0x009f
                           0000A0   196 _P2_0	=	0x00a0
                           0000A1   197 _P2_1	=	0x00a1
                           0000A2   198 _P2_2	=	0x00a2
                           0000A3   199 _P2_3	=	0x00a3
                           0000A4   200 _P2_4	=	0x00a4
                           0000A5   201 _P2_5	=	0x00a5
                           0000A6   202 _P2_6	=	0x00a6
                           0000A7   203 _P2_7	=	0x00a7
                           0000A8   204 _EX0	=	0x00a8
                           0000A9   205 _ET0	=	0x00a9
                           0000AA   206 _EX1	=	0x00aa
                           0000AB   207 _ET1	=	0x00ab
                           0000AC   208 _ES	=	0x00ac
                           0000AF   209 _EA	=	0x00af
                           0000B0   210 _P3_0	=	0x00b0
                           0000B1   211 _P3_1	=	0x00b1
                           0000B2   212 _P3_2	=	0x00b2
                           0000B3   213 _P3_3	=	0x00b3
                           0000B4   214 _P3_4	=	0x00b4
                           0000B5   215 _P3_5	=	0x00b5
                           0000B6   216 _P3_6	=	0x00b6
                           0000B7   217 _P3_7	=	0x00b7
                           0000B0   218 _RXD	=	0x00b0
                           0000B1   219 _TXD	=	0x00b1
                           0000B2   220 _INT0	=	0x00b2
                           0000B3   221 _INT1	=	0x00b3
                           0000B4   222 _T0	=	0x00b4
                           0000B5   223 _T1	=	0x00b5
                           0000B6   224 _WR	=	0x00b6
                           0000B7   225 _RD	=	0x00b7
                           0000B8   226 _PX0	=	0x00b8
                           0000B9   227 _PT0	=	0x00b9
                           0000BA   228 _PX1	=	0x00ba
                           0000BB   229 _PT1	=	0x00bb
                           0000BC   230 _PS	=	0x00bc
                           0000D0   231 _P	=	0x00d0
                           0000D1   232 _F1	=	0x00d1
                           0000D2   233 _OV	=	0x00d2
                           0000D3   234 _RS0	=	0x00d3
                           0000D4   235 _RS1	=	0x00d4
                           0000D5   236 _F0	=	0x00d5
                           0000D6   237 _AC	=	0x00d6
                           0000D7   238 _CY	=	0x00d7
                                    239 ;--------------------------------------------------------
                                    240 ; overlayable register banks
                                    241 ;--------------------------------------------------------
                                    242 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        243 	.ds 8
                                    244 ;--------------------------------------------------------
                                    245 ; internal ram data
                                    246 ;--------------------------------------------------------
                                    247 	.area DSEG    (DATA)
                           00002C   248 _b_start	=	0x002c
                           00002D   249 _b_end	=	0x002d
                           000030   250 _buffer	=	0x0030
                           000029   251 _mutex	=	0x0029
                           00002A   252 _full	=	0x002a
                           00002B   253 _empty	=	0x002b
                                    254 ;--------------------------------------------------------
                                    255 ; overlayable items in internal ram 
                                    256 ;--------------------------------------------------------
                                    257 ;--------------------------------------------------------
                                    258 ; Stack segment in internal ram 
                                    259 ;--------------------------------------------------------
                                    260 	.area	SSEG
      000008                        261 __start__stack:
      000008                        262 	.ds	1
                                    263 
                                    264 ;--------------------------------------------------------
                                    265 ; indirectly addressable internal ram data
                                    266 ;--------------------------------------------------------
                                    267 	.area ISEG    (DATA)
                                    268 ;--------------------------------------------------------
                                    269 ; absolute internal ram data
                                    270 ;--------------------------------------------------------
                                    271 	.area IABS    (ABS,DATA)
                                    272 	.area IABS    (ABS,DATA)
                                    273 ;--------------------------------------------------------
                                    274 ; bit data
                                    275 ;--------------------------------------------------------
                                    276 	.area BSEG    (BIT)
                                    277 ;--------------------------------------------------------
                                    278 ; paged external ram data
                                    279 ;--------------------------------------------------------
                                    280 	.area PSEG    (PAG,XDATA)
                                    281 ;--------------------------------------------------------
                                    282 ; external ram data
                                    283 ;--------------------------------------------------------
                                    284 	.area XSEG    (XDATA)
                                    285 ;--------------------------------------------------------
                                    286 ; absolute external ram data
                                    287 ;--------------------------------------------------------
                                    288 	.area XABS    (ABS,XDATA)
                                    289 ;--------------------------------------------------------
                                    290 ; external initialized ram data
                                    291 ;--------------------------------------------------------
                                    292 	.area XISEG   (XDATA)
                                    293 	.area HOME    (CODE)
                                    294 	.area GSINIT0 (CODE)
                                    295 	.area GSINIT1 (CODE)
                                    296 	.area GSINIT2 (CODE)
                                    297 	.area GSINIT3 (CODE)
                                    298 	.area GSINIT4 (CODE)
                                    299 	.area GSINIT5 (CODE)
                                    300 	.area GSINIT  (CODE)
                                    301 	.area GSFINAL (CODE)
                                    302 	.area CSEG    (CODE)
                                    303 ;--------------------------------------------------------
                                    304 ; interrupt vector 
                                    305 ;--------------------------------------------------------
                                    306 	.area HOME    (CODE)
      000000                        307 __interrupt_vect:
      000000 02 01 56         [24]  308 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  309 	reti
      000004                        310 	.ds	7
      00000B 02 01 5D         [24]  311 	ljmp	_timer0_ISR
                                    312 ;--------------------------------------------------------
                                    313 ; global & static initialisations
                                    314 ;--------------------------------------------------------
                                    315 	.area HOME    (CODE)
                                    316 	.area GSINIT  (CODE)
                                    317 	.area GSFINAL (CODE)
                                    318 	.area GSINIT  (CODE)
                                    319 	.globl __sdcc_gsinit_startup
                                    320 	.globl __sdcc_program_startup
                                    321 	.globl __start__stack
                                    322 	.globl __mcs51_genXINIT
                                    323 	.globl __mcs51_genXRAMCLEAR
                                    324 	.globl __mcs51_genRAMCLEAR
                                    325 	.area GSFINAL (CODE)
      000011 02 00 0E         [24]  326 	ljmp	__sdcc_program_startup
                                    327 ;--------------------------------------------------------
                                    328 ; Home
                                    329 ;--------------------------------------------------------
                                    330 	.area HOME    (CODE)
                                    331 	.area HOME    (CODE)
      00000E                        332 __sdcc_program_startup:
      00000E 02 01 2C         [24]  333 	ljmp	_main
                                    334 ;	return from main will return to caller
                                    335 ;--------------------------------------------------------
                                    336 ; code
                                    337 ;--------------------------------------------------------
                                    338 	.area CSEG    (CODE)
                                    339 ;------------------------------------------------------------
                                    340 ;Allocation info for local variables in function 'Producer1'
                                    341 ;------------------------------------------------------------
                                    342 ;	testlcd.c:33: void Producer1(void)
                                    343 ;	-----------------------------------------
                                    344 ;	 function Producer1
                                    345 ;	-----------------------------------------
      000014                        346 _Producer1:
                           000007   347 	ar7 = 0x07
                           000006   348 	ar6 = 0x06
                           000005   349 	ar5 = 0x05
                           000004   350 	ar4 = 0x04
                           000003   351 	ar3 = 0x03
                           000002   352 	ar2 = 0x02
                           000001   353 	ar1 = 0x01
                           000000   354 	ar0 = 0x00
                                    355 ;	testlcd.c:40: while (1)
      000014                        356 00117$:
                                    357 ;	testlcd.c:42: if (empty==0)ThreadYield();
      000014 E5 2B            [12]  358 	mov	a,_empty
      000016 70 03            [24]  359 	jnz	00102$
      000018 12 02 19         [24]  360 	lcall	_ThreadYield
      00001B                        361 00102$:
                                    362 ;	testlcd.c:43: SemaphoreWait(empty);
      00001B                        363 		0$:
      00001B 85 2B E0         [24]  364 	MOV ACC, _empty 
      00001E 60 FB            [24]  365 	JZ 0$ 
      000020 20 E7 F8         [24]  366 	JB ACC.7, 0$ 
      000023 15 2B            [12]  367 	dec _empty 
                                    368 ;	testlcd.c:44: if (mutex==0)ThreadYield();
      000025 E5 29            [12]  369 	mov	a,_mutex
      000027 70 03            [24]  370 	jnz	00104$
      000029 12 02 19         [24]  371 	lcall	_ThreadYield
      00002C                        372 00104$:
                                    373 ;	testlcd.c:45: SemaphoreWait(mutex);
      00002C                        374 		1$:
      00002C 85 29 E0         [24]  375 	MOV ACC, _mutex 
      00002F 60 FB            [24]  376 	JZ 1$ 
      000031 20 E7 F8         [24]  377 	JB ACC.7, 1$ 
      000034 15 29            [12]  378 	dec _mutex 
                                    379 ;	testlcd.c:46: EA = 0;
                                    380 ;	assignBit
      000036 C2 AF            [12]  381 	clr	_EA
                                    382 ;	testlcd.c:48: if (AnyButtonPressed()){
      000038 12 03 E3         [24]  383 	lcall	_AnyButtonPressed
      00003B E5 82            [12]  384 	mov	a,dpl
      00003D 60 34            [24]  385 	jz	00114$
                                    386 ;	testlcd.c:49: tmp0 = ButtonToChar();
      00003F 12 03 F5         [24]  387 	lcall	_ButtonToChar
                                    388 ;	testlcd.c:50: if (tmp0){
      000042 E5 82            [12]  389 	mov	a,dpl
      000044 F5 25            [12]  390 	mov	_tmp0,a
      000046 60 23            [24]  391 	jz	00111$
                                    392 ;	testlcd.c:51: buffer[b_end] = tmp0;
      000048 E5 2D            [12]  393 	mov	a,_b_end
      00004A 24 30            [12]  394 	add	a,#_buffer
      00004C F8               [12]  395 	mov	r0,a
      00004D A6 25            [24]  396 	mov	@r0,_tmp0
                                    397 ;	testlcd.c:52: b_end++;
      00004F E5 2D            [12]  398 	mov	a,_b_end
      000051 04               [12]  399 	inc	a
      000052 F5 2D            [12]  400 	mov	_b_end,a
                                    401 ;	testlcd.c:53: if (b_end==BUFFER_SIZE)b_end=0;
      000054 74 03            [12]  402 	mov	a,#0x03
      000056 B5 2D 03         [24]  403 	cjne	a,_b_end,00106$
      000059 75 2D 00         [24]  404 	mov	_b_end,#0x00
      00005C                        405 00106$:
                                    406 ;	testlcd.c:54: EA = 1;
                                    407 ;	assignBit
      00005C D2 AF            [12]  408 	setb	_EA
                                    409 ;	testlcd.c:55: SemaphoreSignal(mutex);
      00005E 05 29            [12]  410 	INC _mutex 
                                    411 ;	testlcd.c:56: SemaphoreSignal(full);
      000060 05 2A            [12]  412 	INC _full 
                                    413 ;	testlcd.c:57: while(AnyButtonPressed());
      000062                        414 00107$:
      000062 12 03 E3         [24]  415 	lcall	_AnyButtonPressed
      000065 E5 82            [12]  416 	mov	a,dpl
      000067 60 AB            [24]  417 	jz	00117$
      000069 80 F7            [24]  418 	sjmp	00107$
      00006B                        419 00111$:
                                    420 ;	testlcd.c:59: EA = 1;
                                    421 ;	assignBit
      00006B D2 AF            [12]  422 	setb	_EA
                                    423 ;	testlcd.c:60: SemaphoreSignal(mutex);
      00006D 05 29            [12]  424 	INC _mutex 
                                    425 ;	testlcd.c:61: SemaphoreSignal(empty);
      00006F 05 2B            [12]  426 	INC _empty 
      000071 80 A1            [24]  427 	sjmp	00117$
      000073                        428 00114$:
                                    429 ;	testlcd.c:64: EA = 1;
                                    430 ;	assignBit
      000073 D2 AF            [12]  431 	setb	_EA
                                    432 ;	testlcd.c:65: SemaphoreSignal(mutex);
      000075 05 29            [12]  433 	INC _mutex 
                                    434 ;	testlcd.c:66: SemaphoreSignal(empty);
      000077 05 2B            [12]  435 	INC _empty 
                                    436 ;	testlcd.c:72: }
      000079 80 99            [24]  437 	sjmp	00117$
                                    438 ;------------------------------------------------------------
                                    439 ;Allocation info for local variables in function 'Producer2'
                                    440 ;------------------------------------------------------------
                                    441 ;	testlcd.c:74: void Producer2(void)
                                    442 ;	-----------------------------------------
                                    443 ;	 function Producer2
                                    444 ;	-----------------------------------------
      00007B                        445 _Producer2:
                                    446 ;	testlcd.c:81: while (1)
      00007B                        447 00117$:
                                    448 ;	testlcd.c:84: if (empty==0)ThreadYield();
      00007B E5 2B            [12]  449 	mov	a,_empty
      00007D 70 03            [24]  450 	jnz	00102$
      00007F 12 02 19         [24]  451 	lcall	_ThreadYield
      000082                        452 00102$:
                                    453 ;	testlcd.c:85: SemaphoreWait(empty);
      000082                        454 		2$:
      000082 85 2B E0         [24]  455 	MOV ACC, _empty 
      000085 60 FB            [24]  456 	JZ 2$ 
      000087 20 E7 F8         [24]  457 	JB ACC.7, 2$ 
      00008A 15 2B            [12]  458 	dec _empty 
                                    459 ;	testlcd.c:86: if (mutex==0)ThreadYield();
      00008C E5 29            [12]  460 	mov	a,_mutex
      00008E 70 03            [24]  461 	jnz	00104$
      000090 12 02 19         [24]  462 	lcall	_ThreadYield
      000093                        463 00104$:
                                    464 ;	testlcd.c:87: SemaphoreWait(mutex);
      000093                        465 		3$:
      000093 85 29 E0         [24]  466 	MOV ACC, _mutex 
      000096 60 FB            [24]  467 	JZ 3$ 
      000098 20 E7 F8         [24]  468 	JB ACC.7, 3$ 
      00009B 15 29            [12]  469 	dec _mutex 
                                    470 ;	testlcd.c:88: EA = 0;
                                    471 ;	assignBit
      00009D C2 AF            [12]  472 	clr	_EA
                                    473 ;	testlcd.c:89: if (AnyKeyPressed()){
      00009F 12 04 87         [24]  474 	lcall	_AnyKeyPressed
      0000A2 E5 82            [12]  475 	mov	a,dpl
      0000A4 60 34            [24]  476 	jz	00114$
                                    477 ;	testlcd.c:90: tmp0 = KeyToChar();
      0000A6 12 04 92         [24]  478 	lcall	_KeyToChar
                                    479 ;	testlcd.c:91: if (tmp0){
      0000A9 E5 82            [12]  480 	mov	a,dpl
      0000AB F5 25            [12]  481 	mov	_tmp0,a
      0000AD 60 23            [24]  482 	jz	00111$
                                    483 ;	testlcd.c:92: buffer[b_end] = tmp0;
      0000AF E5 2D            [12]  484 	mov	a,_b_end
      0000B1 24 30            [12]  485 	add	a,#_buffer
      0000B3 F8               [12]  486 	mov	r0,a
      0000B4 A6 25            [24]  487 	mov	@r0,_tmp0
                                    488 ;	testlcd.c:93: b_end++;
      0000B6 E5 2D            [12]  489 	mov	a,_b_end
      0000B8 04               [12]  490 	inc	a
      0000B9 F5 2D            [12]  491 	mov	_b_end,a
                                    492 ;	testlcd.c:94: if (b_end==BUFFER_SIZE)b_end=0;
      0000BB 74 03            [12]  493 	mov	a,#0x03
      0000BD B5 2D 03         [24]  494 	cjne	a,_b_end,00106$
      0000C0 75 2D 00         [24]  495 	mov	_b_end,#0x00
      0000C3                        496 00106$:
                                    497 ;	testlcd.c:95: EA = 1;
                                    498 ;	assignBit
      0000C3 D2 AF            [12]  499 	setb	_EA
                                    500 ;	testlcd.c:96: SemaphoreSignal(mutex);
      0000C5 05 29            [12]  501 	INC _mutex 
                                    502 ;	testlcd.c:97: SemaphoreSignal(full);
      0000C7 05 2A            [12]  503 	INC _full 
                                    504 ;	testlcd.c:98: while(AnyKeyPressed());
      0000C9                        505 00107$:
      0000C9 12 04 87         [24]  506 	lcall	_AnyKeyPressed
      0000CC E5 82            [12]  507 	mov	a,dpl
      0000CE 60 AB            [24]  508 	jz	00117$
      0000D0 80 F7            [24]  509 	sjmp	00107$
      0000D2                        510 00111$:
                                    511 ;	testlcd.c:100: EA = 1;
                                    512 ;	assignBit
      0000D2 D2 AF            [12]  513 	setb	_EA
                                    514 ;	testlcd.c:101: SemaphoreSignal(mutex);
      0000D4 05 29            [12]  515 	INC _mutex 
                                    516 ;	testlcd.c:102: SemaphoreSignal(empty);
      0000D6 05 2B            [12]  517 	INC _empty 
      0000D8 80 A1            [24]  518 	sjmp	00117$
      0000DA                        519 00114$:
                                    520 ;	testlcd.c:105: EA = 1;
                                    521 ;	assignBit
      0000DA D2 AF            [12]  522 	setb	_EA
                                    523 ;	testlcd.c:106: SemaphoreSignal(mutex);
      0000DC 05 29            [12]  524 	INC _mutex 
                                    525 ;	testlcd.c:107: SemaphoreSignal(empty);
      0000DE 05 2B            [12]  526 	INC _empty 
                                    527 ;	testlcd.c:113: }
      0000E0 80 99            [24]  528 	sjmp	00117$
                                    529 ;------------------------------------------------------------
                                    530 ;Allocation info for local variables in function 'Consumer'
                                    531 ;------------------------------------------------------------
                                    532 ;	testlcd.c:120: void Consumer(void)
                                    533 ;	-----------------------------------------
                                    534 ;	 function Consumer
                                    535 ;	-----------------------------------------
      0000E2                        536 _Consumer:
                                    537 ;	testlcd.c:122: while (1)
      0000E2                        538 00111$:
                                    539 ;	testlcd.c:124: if (full==0)ThreadYield();
      0000E2 E5 2A            [12]  540 	mov	a,_full
      0000E4 70 03            [24]  541 	jnz	00102$
      0000E6 12 02 19         [24]  542 	lcall	_ThreadYield
      0000E9                        543 00102$:
                                    544 ;	testlcd.c:125: SemaphoreWait(full);
      0000E9                        545 		4$:
      0000E9 85 2A E0         [24]  546 	MOV ACC, _full 
      0000EC 60 FB            [24]  547 	JZ 4$ 
      0000EE 20 E7 F8         [24]  548 	JB ACC.7, 4$ 
      0000F1 15 2A            [12]  549 	dec _full 
                                    550 ;	testlcd.c:126: if (mutex==0)ThreadYield();
      0000F3 E5 29            [12]  551 	mov	a,_mutex
      0000F5 70 03            [24]  552 	jnz	00104$
      0000F7 12 02 19         [24]  553 	lcall	_ThreadYield
      0000FA                        554 00104$:
                                    555 ;	testlcd.c:127: SemaphoreWait(mutex);
      0000FA                        556 		5$:
      0000FA 85 29 E0         [24]  557 	MOV ACC, _mutex 
      0000FD 60 FB            [24]  558 	JZ 5$ 
      0000FF 20 E7 F8         [24]  559 	JB ACC.7, 5$ 
      000102 15 29            [12]  560 	dec _mutex 
                                    561 ;	testlcd.c:129: EA = 0;
                                    562 ;	assignBit
      000104 C2 AF            [12]  563 	clr	_EA
                                    564 ;	testlcd.c:130: LCD_write_char(buffer[b_start]);
      000106 E5 2C            [12]  565 	mov	a,_b_start
      000108 24 30            [12]  566 	add	a,#_buffer
      00010A F9               [12]  567 	mov	r1,a
      00010B 87 82            [24]  568 	mov	dpl,@r1
      00010D 12 03 80         [24]  569 	lcall	_LCD_write_char
                                    570 ;	testlcd.c:131: while (!LCD_ready());
      000110                        571 00105$:
      000110 12 03 1D         [24]  572 	lcall	_LCD_ready
      000113 E5 82            [12]  573 	mov	a,dpl
      000115 60 F9            [24]  574 	jz	00105$
                                    575 ;	testlcd.c:133: b_start++;
      000117 E5 2C            [12]  576 	mov	a,_b_start
      000119 04               [12]  577 	inc	a
      00011A F5 2C            [12]  578 	mov	_b_start,a
                                    579 ;	testlcd.c:134: if (b_start==BUFFER_SIZE)b_start=0;
      00011C 74 03            [12]  580 	mov	a,#0x03
      00011E B5 2C 03         [24]  581 	cjne	a,_b_start,00109$
      000121 75 2C 00         [24]  582 	mov	_b_start,#0x00
      000124                        583 00109$:
                                    584 ;	testlcd.c:135: EA = 1;
                                    585 ;	assignBit
      000124 D2 AF            [12]  586 	setb	_EA
                                    587 ;	testlcd.c:136: SemaphoreSignal(mutex);
      000126 05 29            [12]  588 	INC _mutex 
                                    589 ;	testlcd.c:137: SemaphoreSignal(empty);
      000128 05 2B            [12]  590 	INC _empty 
                                    591 ;	testlcd.c:139: }
      00012A 80 B6            [24]  592 	sjmp	00111$
                                    593 ;------------------------------------------------------------
                                    594 ;Allocation info for local variables in function 'main'
                                    595 ;------------------------------------------------------------
                                    596 ;	testlcd.c:146: void main(void)
                                    597 ;	-----------------------------------------
                                    598 ;	 function main
                                    599 ;	-----------------------------------------
      00012C                        600 _main:
                                    601 ;	testlcd.c:152: Init_Keypad();
      00012C 12 04 81         [24]  602 	lcall	_Init_Keypad
                                    603 ;	testlcd.c:153: LCD_Init();
      00012F 12 03 21         [24]  604 	lcall	_LCD_Init
                                    605 ;	testlcd.c:156: SemaphoreCreate(mutex,1);
      000132 75 29 01         [24]  606 	mov	_mutex,#0x01
                                    607 ;	testlcd.c:157: SemaphoreCreate(full,0);
      000135 75 2A 00         [24]  608 	mov	_full,#0x00
                                    609 ;	testlcd.c:158: SemaphoreCreate(empty,BUFFER_SIZE);
      000138 75 2B 03         [24]  610 	mov	_empty,#0x03
                                    611 ;	testlcd.c:161: b_start = b_end = 0;
      00013B 75 2D 00         [24]  612 	mov	_b_end,#0x00
      00013E 75 2C 00         [24]  613 	mov	_b_start,#0x00
                                    614 ;	testlcd.c:168: ThreadCreate(Producer1);
      000141 90 00 14         [24]  615 	mov	dptr,#_Producer1
      000144 12 01 93         [24]  616 	lcall	_ThreadCreate
                                    617 ;	testlcd.c:169: ThreadCreate(Producer2);
      000147 90 00 7B         [24]  618 	mov	dptr,#_Producer2
      00014A 12 01 93         [24]  619 	lcall	_ThreadCreate
                                    620 ;	testlcd.c:170: ThreadCreate(Consumer);
      00014D 90 00 E2         [24]  621 	mov	dptr,#_Consumer
      000150 12 01 93         [24]  622 	lcall	_ThreadCreate
                                    623 ;	testlcd.c:171: ThreadExit();
                                    624 ;	testlcd.c:172: }
      000153 02 02 6E         [24]  625 	ljmp	_ThreadExit
                                    626 ;------------------------------------------------------------
                                    627 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                    628 ;------------------------------------------------------------
                                    629 ;	testlcd.c:174: void _sdcc_gsinit_startup(void)
                                    630 ;	-----------------------------------------
                                    631 ;	 function _sdcc_gsinit_startup
                                    632 ;	-----------------------------------------
      000156                        633 __sdcc_gsinit_startup:
                                    634 ;	testlcd.c:178: __endasm;
      000156 02 01 61         [24]  635 	LJMP	_Bootstrap
                                    636 ;	testlcd.c:179: }
      000159 22               [24]  637 	ret
                                    638 ;------------------------------------------------------------
                                    639 ;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
                                    640 ;------------------------------------------------------------
                                    641 ;	testlcd.c:181: void _mcs51_genRAMCLEAR(void) {}
                                    642 ;	-----------------------------------------
                                    643 ;	 function _mcs51_genRAMCLEAR
                                    644 ;	-----------------------------------------
      00015A                        645 __mcs51_genRAMCLEAR:
      00015A 22               [24]  646 	ret
                                    647 ;------------------------------------------------------------
                                    648 ;Allocation info for local variables in function '_mcs51_genXINIT'
                                    649 ;------------------------------------------------------------
                                    650 ;	testlcd.c:182: void _mcs51_genXINIT(void) {}
                                    651 ;	-----------------------------------------
                                    652 ;	 function _mcs51_genXINIT
                                    653 ;	-----------------------------------------
      00015B                        654 __mcs51_genXINIT:
      00015B 22               [24]  655 	ret
                                    656 ;------------------------------------------------------------
                                    657 ;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
                                    658 ;------------------------------------------------------------
                                    659 ;	testlcd.c:183: void _mcs51_genXRAMCLEAR(void) {}
                                    660 ;	-----------------------------------------
                                    661 ;	 function _mcs51_genXRAMCLEAR
                                    662 ;	-----------------------------------------
      00015C                        663 __mcs51_genXRAMCLEAR:
      00015C 22               [24]  664 	ret
                                    665 ;------------------------------------------------------------
                                    666 ;Allocation info for local variables in function 'timer0_ISR'
                                    667 ;------------------------------------------------------------
                                    668 ;	testlcd.c:185: void timer0_ISR(void) __interrupt(1) {
                                    669 ;	-----------------------------------------
                                    670 ;	 function timer0_ISR
                                    671 ;	-----------------------------------------
      00015D                        672 _timer0_ISR:
                                    673 ;	testlcd.c:188: __endasm;
      00015D 02 02 C7         [24]  674 	ljmp	_myTimer0Handler
                                    675 ;	testlcd.c:189: }
      000160 32               [24]  676 	reti
                                    677 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    678 ;	eliminated unneeded push/pop psw
                                    679 ;	eliminated unneeded push/pop dpl
                                    680 ;	eliminated unneeded push/pop dph
                                    681 ;	eliminated unneeded push/pop b
                                    682 ;	eliminated unneeded push/pop acc
                                    683 	.area CSEG    (CODE)
                                    684 	.area CONST   (CODE)
                                    685 	.area XINIT   (CODE)
                                    686 	.area CABS    (ABS,CODE)
