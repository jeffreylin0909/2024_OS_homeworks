                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module test3threads
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
                                     20 	.globl _ThreadExit
                                     21 	.globl _ThreadCreate
                                     22 	.globl _CY
                                     23 	.globl _AC
                                     24 	.globl _F0
                                     25 	.globl _RS1
                                     26 	.globl _RS0
                                     27 	.globl _OV
                                     28 	.globl _F1
                                     29 	.globl _P
                                     30 	.globl _PS
                                     31 	.globl _PT1
                                     32 	.globl _PX1
                                     33 	.globl _PT0
                                     34 	.globl _PX0
                                     35 	.globl _RD
                                     36 	.globl _WR
                                     37 	.globl _T1
                                     38 	.globl _T0
                                     39 	.globl _INT1
                                     40 	.globl _INT0
                                     41 	.globl _TXD
                                     42 	.globl _RXD
                                     43 	.globl _P3_7
                                     44 	.globl _P3_6
                                     45 	.globl _P3_5
                                     46 	.globl _P3_4
                                     47 	.globl _P3_3
                                     48 	.globl _P3_2
                                     49 	.globl _P3_1
                                     50 	.globl _P3_0
                                     51 	.globl _EA
                                     52 	.globl _ES
                                     53 	.globl _ET1
                                     54 	.globl _EX1
                                     55 	.globl _ET0
                                     56 	.globl _EX0
                                     57 	.globl _P2_7
                                     58 	.globl _P2_6
                                     59 	.globl _P2_5
                                     60 	.globl _P2_4
                                     61 	.globl _P2_3
                                     62 	.globl _P2_2
                                     63 	.globl _P2_1
                                     64 	.globl _P2_0
                                     65 	.globl _SM0
                                     66 	.globl _SM1
                                     67 	.globl _SM2
                                     68 	.globl _REN
                                     69 	.globl _TB8
                                     70 	.globl _RB8
                                     71 	.globl _TI
                                     72 	.globl _RI
                                     73 	.globl _P1_7
                                     74 	.globl _P1_6
                                     75 	.globl _P1_5
                                     76 	.globl _P1_4
                                     77 	.globl _P1_3
                                     78 	.globl _P1_2
                                     79 	.globl _P1_1
                                     80 	.globl _P1_0
                                     81 	.globl _TF1
                                     82 	.globl _TR1
                                     83 	.globl _TF0
                                     84 	.globl _TR0
                                     85 	.globl _IE1
                                     86 	.globl _IT1
                                     87 	.globl _IE0
                                     88 	.globl _IT0
                                     89 	.globl _P0_7
                                     90 	.globl _P0_6
                                     91 	.globl _P0_5
                                     92 	.globl _P0_4
                                     93 	.globl _P0_3
                                     94 	.globl _P0_2
                                     95 	.globl _P0_1
                                     96 	.globl _P0_0
                                     97 	.globl _B
                                     98 	.globl _ACC
                                     99 	.globl _PSW
                                    100 	.globl _IP
                                    101 	.globl _P3
                                    102 	.globl _IE
                                    103 	.globl _P2
                                    104 	.globl _SBUF
                                    105 	.globl _SCON
                                    106 	.globl _P1
                                    107 	.globl _TH1
                                    108 	.globl _TH0
                                    109 	.globl _TL1
                                    110 	.globl _TL0
                                    111 	.globl _TMOD
                                    112 	.globl _TCON
                                    113 	.globl _PCON
                                    114 	.globl _DPH
                                    115 	.globl _DPL
                                    116 	.globl _SP
                                    117 	.globl _P0
                                    118 	.globl __2_turn
                                    119 	.globl __1_turn
                                    120 	.globl _empty
                                    121 	.globl _full
                                    122 	.globl _mutex
                                    123 	.globl _buffer
                                    124 	.globl _in_counter_2
                                    125 	.globl _in_counter_1
                                    126 	.globl _b_end
                                    127 	.globl _b_start
                                    128 ;--------------------------------------------------------
                                    129 ; special function registers
                                    130 ;--------------------------------------------------------
                                    131 	.area RSEG    (ABS,DATA)
      000000                        132 	.org 0x0000
                           000080   133 _P0	=	0x0080
                           000081   134 _SP	=	0x0081
                           000082   135 _DPL	=	0x0082
                           000083   136 _DPH	=	0x0083
                           000087   137 _PCON	=	0x0087
                           000088   138 _TCON	=	0x0088
                           000089   139 _TMOD	=	0x0089
                           00008A   140 _TL0	=	0x008a
                           00008B   141 _TL1	=	0x008b
                           00008C   142 _TH0	=	0x008c
                           00008D   143 _TH1	=	0x008d
                           000090   144 _P1	=	0x0090
                           000098   145 _SCON	=	0x0098
                           000099   146 _SBUF	=	0x0099
                           0000A0   147 _P2	=	0x00a0
                           0000A8   148 _IE	=	0x00a8
                           0000B0   149 _P3	=	0x00b0
                           0000B8   150 _IP	=	0x00b8
                           0000D0   151 _PSW	=	0x00d0
                           0000E0   152 _ACC	=	0x00e0
                           0000F0   153 _B	=	0x00f0
                                    154 ;--------------------------------------------------------
                                    155 ; special function bits
                                    156 ;--------------------------------------------------------
                                    157 	.area RSEG    (ABS,DATA)
      000000                        158 	.org 0x0000
                           000080   159 _P0_0	=	0x0080
                           000081   160 _P0_1	=	0x0081
                           000082   161 _P0_2	=	0x0082
                           000083   162 _P0_3	=	0x0083
                           000084   163 _P0_4	=	0x0084
                           000085   164 _P0_5	=	0x0085
                           000086   165 _P0_6	=	0x0086
                           000087   166 _P0_7	=	0x0087
                           000088   167 _IT0	=	0x0088
                           000089   168 _IE0	=	0x0089
                           00008A   169 _IT1	=	0x008a
                           00008B   170 _IE1	=	0x008b
                           00008C   171 _TR0	=	0x008c
                           00008D   172 _TF0	=	0x008d
                           00008E   173 _TR1	=	0x008e
                           00008F   174 _TF1	=	0x008f
                           000090   175 _P1_0	=	0x0090
                           000091   176 _P1_1	=	0x0091
                           000092   177 _P1_2	=	0x0092
                           000093   178 _P1_3	=	0x0093
                           000094   179 _P1_4	=	0x0094
                           000095   180 _P1_5	=	0x0095
                           000096   181 _P1_6	=	0x0096
                           000097   182 _P1_7	=	0x0097
                           000098   183 _RI	=	0x0098
                           000099   184 _TI	=	0x0099
                           00009A   185 _RB8	=	0x009a
                           00009B   186 _TB8	=	0x009b
                           00009C   187 _REN	=	0x009c
                           00009D   188 _SM2	=	0x009d
                           00009E   189 _SM1	=	0x009e
                           00009F   190 _SM0	=	0x009f
                           0000A0   191 _P2_0	=	0x00a0
                           0000A1   192 _P2_1	=	0x00a1
                           0000A2   193 _P2_2	=	0x00a2
                           0000A3   194 _P2_3	=	0x00a3
                           0000A4   195 _P2_4	=	0x00a4
                           0000A5   196 _P2_5	=	0x00a5
                           0000A6   197 _P2_6	=	0x00a6
                           0000A7   198 _P2_7	=	0x00a7
                           0000A8   199 _EX0	=	0x00a8
                           0000A9   200 _ET0	=	0x00a9
                           0000AA   201 _EX1	=	0x00aa
                           0000AB   202 _ET1	=	0x00ab
                           0000AC   203 _ES	=	0x00ac
                           0000AF   204 _EA	=	0x00af
                           0000B0   205 _P3_0	=	0x00b0
                           0000B1   206 _P3_1	=	0x00b1
                           0000B2   207 _P3_2	=	0x00b2
                           0000B3   208 _P3_3	=	0x00b3
                           0000B4   209 _P3_4	=	0x00b4
                           0000B5   210 _P3_5	=	0x00b5
                           0000B6   211 _P3_6	=	0x00b6
                           0000B7   212 _P3_7	=	0x00b7
                           0000B0   213 _RXD	=	0x00b0
                           0000B1   214 _TXD	=	0x00b1
                           0000B2   215 _INT0	=	0x00b2
                           0000B3   216 _INT1	=	0x00b3
                           0000B4   217 _T0	=	0x00b4
                           0000B5   218 _T1	=	0x00b5
                           0000B6   219 _WR	=	0x00b6
                           0000B7   220 _RD	=	0x00b7
                           0000B8   221 _PX0	=	0x00b8
                           0000B9   222 _PT0	=	0x00b9
                           0000BA   223 _PX1	=	0x00ba
                           0000BB   224 _PT1	=	0x00bb
                           0000BC   225 _PS	=	0x00bc
                           0000D0   226 _P	=	0x00d0
                           0000D1   227 _F1	=	0x00d1
                           0000D2   228 _OV	=	0x00d2
                           0000D3   229 _RS0	=	0x00d3
                           0000D4   230 _RS1	=	0x00d4
                           0000D5   231 _F0	=	0x00d5
                           0000D6   232 _AC	=	0x00d6
                           0000D7   233 _CY	=	0x00d7
                                    234 ;--------------------------------------------------------
                                    235 ; overlayable register banks
                                    236 ;--------------------------------------------------------
                                    237 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        238 	.ds 8
                                    239 ;--------------------------------------------------------
                                    240 ; internal ram data
                                    241 ;--------------------------------------------------------
                                    242 	.area DSEG    (DATA)
                           00002C   243 _b_start	=	0x002c
                           00002D   244 _b_end	=	0x002d
                           00002E   245 _in_counter_1	=	0x002e
                           00002F   246 _in_counter_2	=	0x002f
                           000030   247 _buffer	=	0x0030
                           000029   248 _mutex	=	0x0029
                           00002A   249 _full	=	0x002a
                           00002B   250 _empty	=	0x002b
                           000033   251 __1_turn	=	0x0033
                           000034   252 __2_turn	=	0x0034
                                    253 ;--------------------------------------------------------
                                    254 ; overlayable items in internal ram 
                                    255 ;--------------------------------------------------------
                                    256 ;--------------------------------------------------------
                                    257 ; Stack segment in internal ram 
                                    258 ;--------------------------------------------------------
                                    259 	.area	SSEG
      000008                        260 __start__stack:
      000008                        261 	.ds	1
                                    262 
                                    263 ;--------------------------------------------------------
                                    264 ; indirectly addressable internal ram data
                                    265 ;--------------------------------------------------------
                                    266 	.area ISEG    (DATA)
                                    267 ;--------------------------------------------------------
                                    268 ; absolute internal ram data
                                    269 ;--------------------------------------------------------
                                    270 	.area IABS    (ABS,DATA)
                                    271 	.area IABS    (ABS,DATA)
                                    272 ;--------------------------------------------------------
                                    273 ; bit data
                                    274 ;--------------------------------------------------------
                                    275 	.area BSEG    (BIT)
                                    276 ;--------------------------------------------------------
                                    277 ; paged external ram data
                                    278 ;--------------------------------------------------------
                                    279 	.area PSEG    (PAG,XDATA)
                                    280 ;--------------------------------------------------------
                                    281 ; external ram data
                                    282 ;--------------------------------------------------------
                                    283 	.area XSEG    (XDATA)
                                    284 ;--------------------------------------------------------
                                    285 ; absolute external ram data
                                    286 ;--------------------------------------------------------
                                    287 	.area XABS    (ABS,XDATA)
                                    288 ;--------------------------------------------------------
                                    289 ; external initialized ram data
                                    290 ;--------------------------------------------------------
                                    291 	.area XISEG   (XDATA)
                                    292 	.area HOME    (CODE)
                                    293 	.area GSINIT0 (CODE)
                                    294 	.area GSINIT1 (CODE)
                                    295 	.area GSINIT2 (CODE)
                                    296 	.area GSINIT3 (CODE)
                                    297 	.area GSINIT4 (CODE)
                                    298 	.area GSINIT5 (CODE)
                                    299 	.area GSINIT  (CODE)
                                    300 	.area GSFINAL (CODE)
                                    301 	.area CSEG    (CODE)
                                    302 ;--------------------------------------------------------
                                    303 ; interrupt vector 
                                    304 ;--------------------------------------------------------
                                    305 	.area HOME    (CODE)
      000000                        306 __interrupt_vect:
      000000 02 01 24         [24]  307 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  308 	reti
      000004                        309 	.ds	7
      00000B 02 01 2B         [24]  310 	ljmp	_timer0_ISR
                                    311 ;--------------------------------------------------------
                                    312 ; global & static initialisations
                                    313 ;--------------------------------------------------------
                                    314 	.area HOME    (CODE)
                                    315 	.area GSINIT  (CODE)
                                    316 	.area GSFINAL (CODE)
                                    317 	.area GSINIT  (CODE)
                                    318 	.globl __sdcc_gsinit_startup
                                    319 	.globl __sdcc_program_startup
                                    320 	.globl __start__stack
                                    321 	.globl __mcs51_genXINIT
                                    322 	.globl __mcs51_genXRAMCLEAR
                                    323 	.globl __mcs51_genRAMCLEAR
                                    324 	.area GSFINAL (CODE)
      000011 02 00 0E         [24]  325 	ljmp	__sdcc_program_startup
                                    326 ;--------------------------------------------------------
                                    327 ; Home
                                    328 ;--------------------------------------------------------
                                    329 	.area HOME    (CODE)
                                    330 	.area HOME    (CODE)
      00000E                        331 __sdcc_program_startup:
      00000E 02 00 F4         [24]  332 	ljmp	_main
                                    333 ;	return from main will return to caller
                                    334 ;--------------------------------------------------------
                                    335 ; code
                                    336 ;--------------------------------------------------------
                                    337 	.area CSEG    (CODE)
                                    338 ;------------------------------------------------------------
                                    339 ;Allocation info for local variables in function 'Producer1'
                                    340 ;------------------------------------------------------------
                                    341 ;	test3threads.c:34: void Producer1(void)
                                    342 ;	-----------------------------------------
                                    343 ;	 function Producer1
                                    344 ;	-----------------------------------------
      000014                        345 _Producer1:
                           000007   346 	ar7 = 0x07
                           000006   347 	ar6 = 0x06
                           000005   348 	ar5 = 0x05
                           000004   349 	ar4 = 0x04
                           000003   350 	ar3 = 0x03
                           000002   351 	ar2 = 0x02
                           000001   352 	ar1 = 0x01
                           000000   353 	ar0 = 0x00
                                    354 ;	test3threads.c:41: while (1)
      000014                        355 00106$:
                                    356 ;	test3threads.c:44: SemaphoreWait(_1_turn);
      000014                        357 		0$:
      000014 85 33 E0         [24]  358 	MOV ACC, __1_turn 
      000017 60 FB            [24]  359 	JZ 0$ 
      000019 20 E7 F8         [24]  360 	JB ACC.7, 0$ 
      00001C 15 33            [12]  361 	dec __1_turn 
                                    362 ;	test3threads.c:45: SemaphoreWait(empty);
      00001E                        363 		1$:
      00001E 85 2B E0         [24]  364 	MOV ACC, _empty 
      000021 60 FB            [24]  365 	JZ 1$ 
      000023 20 E7 F8         [24]  366 	JB ACC.7, 1$ 
      000026 15 2B            [12]  367 	dec _empty 
                                    368 ;	test3threads.c:46: SemaphoreWait(mutex);
      000028                        369 		2$:
      000028 85 29 E0         [24]  370 	MOV ACC, _mutex 
      00002B 60 FB            [24]  371 	JZ 2$ 
      00002D 20 E7 F8         [24]  372 	JB ACC.7, 2$ 
      000030 15 29            [12]  373 	dec _mutex 
                                    374 ;	test3threads.c:48: EA = 0;
                                    375 ;	assignBit
      000032 C2 AF            [12]  376 	clr	_EA
                                    377 ;	test3threads.c:49: buffer[b_end] = 'A'+in_counter_1;
      000034 E5 2D            [12]  378 	mov	a,_b_end
      000036 24 30            [12]  379 	add	a,#_buffer
      000038 F9               [12]  380 	mov	r1,a
      000039 AF 2E            [24]  381 	mov	r7,_in_counter_1
      00003B 74 41            [12]  382 	mov	a,#0x41
      00003D 2F               [12]  383 	add	a,r7
      00003E F7               [12]  384 	mov	@r1,a
                                    385 ;	test3threads.c:50: b_end++;
      00003F E5 2D            [12]  386 	mov	a,_b_end
      000041 04               [12]  387 	inc	a
      000042 F5 2D            [12]  388 	mov	_b_end,a
                                    389 ;	test3threads.c:51: if (b_end==BUFFER_SIZE)b_end=0;
      000044 74 03            [12]  390 	mov	a,#0x03
      000046 B5 2D 03         [24]  391 	cjne	a,_b_end,00102$
      000049 75 2D 00         [24]  392 	mov	_b_end,#0x00
      00004C                        393 00102$:
                                    394 ;	test3threads.c:52: in_counter_1++;
      00004C E5 2E            [12]  395 	mov	a,_in_counter_1
      00004E 04               [12]  396 	inc	a
      00004F F5 2E            [12]  397 	mov	_in_counter_1,a
                                    398 ;	test3threads.c:53: if (in_counter_1==26)in_counter_1=0;
      000051 74 1A            [12]  399 	mov	a,#0x1a
      000053 B5 2E 03         [24]  400 	cjne	a,_in_counter_1,00104$
      000056 75 2E 00         [24]  401 	mov	_in_counter_1,#0x00
      000059                        402 00104$:
                                    403 ;	test3threads.c:54: EA = 1;
                                    404 ;	assignBit
      000059 D2 AF            [12]  405 	setb	_EA
                                    406 ;	test3threads.c:55: SemaphoreSignal(mutex);
      00005B 05 29            [12]  407 	INC _mutex 
                                    408 ;	test3threads.c:56: SemaphoreSignal(full);
      00005D 05 2A            [12]  409 	INC _full 
                                    410 ;	test3threads.c:57: SemaphoreSignal(_2_turn);
      00005F 05 34            [12]  411 	INC __2_turn 
                                    412 ;	test3threads.c:62: }
      000061 80 B1            [24]  413 	sjmp	00106$
                                    414 ;------------------------------------------------------------
                                    415 ;Allocation info for local variables in function 'Producer2'
                                    416 ;------------------------------------------------------------
                                    417 ;	test3threads.c:64: void Producer2(void)
                                    418 ;	-----------------------------------------
                                    419 ;	 function Producer2
                                    420 ;	-----------------------------------------
      000063                        421 _Producer2:
                                    422 ;	test3threads.c:71: while (1)
      000063                        423 00106$:
                                    424 ;	test3threads.c:74: SemaphoreWait(_2_turn);
      000063                        425 		3$:
      000063 85 34 E0         [24]  426 	MOV ACC, __2_turn 
      000066 60 FB            [24]  427 	JZ 3$ 
      000068 20 E7 F8         [24]  428 	JB ACC.7, 3$ 
      00006B 15 34            [12]  429 	dec __2_turn 
                                    430 ;	test3threads.c:75: SemaphoreWait(empty);
      00006D                        431 		4$:
      00006D 85 2B E0         [24]  432 	MOV ACC, _empty 
      000070 60 FB            [24]  433 	JZ 4$ 
      000072 20 E7 F8         [24]  434 	JB ACC.7, 4$ 
      000075 15 2B            [12]  435 	dec _empty 
                                    436 ;	test3threads.c:76: SemaphoreWait(mutex);
      000077                        437 		5$:
      000077 85 29 E0         [24]  438 	MOV ACC, _mutex 
      00007A 60 FB            [24]  439 	JZ 5$ 
      00007C 20 E7 F8         [24]  440 	JB ACC.7, 5$ 
      00007F 15 29            [12]  441 	dec _mutex 
                                    442 ;	test3threads.c:78: EA = 0;
                                    443 ;	assignBit
      000081 C2 AF            [12]  444 	clr	_EA
                                    445 ;	test3threads.c:79: buffer[b_end] = '0'+in_counter_2;
      000083 E5 2D            [12]  446 	mov	a,_b_end
      000085 24 30            [12]  447 	add	a,#_buffer
      000087 F9               [12]  448 	mov	r1,a
      000088 AF 2F            [24]  449 	mov	r7,_in_counter_2
      00008A 74 30            [12]  450 	mov	a,#0x30
      00008C 2F               [12]  451 	add	a,r7
      00008D F7               [12]  452 	mov	@r1,a
                                    453 ;	test3threads.c:80: b_end++;
      00008E E5 2D            [12]  454 	mov	a,_b_end
      000090 04               [12]  455 	inc	a
      000091 F5 2D            [12]  456 	mov	_b_end,a
                                    457 ;	test3threads.c:81: if (b_end==BUFFER_SIZE)b_end=0;
      000093 74 03            [12]  458 	mov	a,#0x03
      000095 B5 2D 03         [24]  459 	cjne	a,_b_end,00102$
      000098 75 2D 00         [24]  460 	mov	_b_end,#0x00
      00009B                        461 00102$:
                                    462 ;	test3threads.c:82: in_counter_2++;
      00009B E5 2F            [12]  463 	mov	a,_in_counter_2
      00009D 04               [12]  464 	inc	a
      00009E F5 2F            [12]  465 	mov	_in_counter_2,a
                                    466 ;	test3threads.c:83: if (in_counter_2==10)in_counter_2=0;
      0000A0 74 0A            [12]  467 	mov	a,#0x0a
      0000A2 B5 2F 03         [24]  468 	cjne	a,_in_counter_2,00104$
      0000A5 75 2F 00         [24]  469 	mov	_in_counter_2,#0x00
      0000A8                        470 00104$:
                                    471 ;	test3threads.c:84: EA = 1;
                                    472 ;	assignBit
      0000A8 D2 AF            [12]  473 	setb	_EA
                                    474 ;	test3threads.c:85: SemaphoreSignal(mutex);
      0000AA 05 29            [12]  475 	INC _mutex 
                                    476 ;	test3threads.c:86: SemaphoreSignal(full);
      0000AC 05 2A            [12]  477 	INC _full 
                                    478 ;	test3threads.c:87: SemaphoreSignal(_1_turn);
      0000AE 05 33            [12]  479 	INC __1_turn 
                                    480 ;	test3threads.c:92: }
      0000B0 80 B1            [24]  481 	sjmp	00106$
                                    482 ;------------------------------------------------------------
                                    483 ;Allocation info for local variables in function 'Consumer'
                                    484 ;------------------------------------------------------------
                                    485 ;	test3threads.c:99: void Consumer(void)
                                    486 ;	-----------------------------------------
                                    487 ;	 function Consumer
                                    488 ;	-----------------------------------------
      0000B2                        489 _Consumer:
                                    490 ;	test3threads.c:105: TMOD |= 0x20;
      0000B2 43 89 20         [24]  491 	orl	_TMOD,#0x20
                                    492 ;	test3threads.c:106: TH1 = -6;//for buad (frequency)
      0000B5 75 8D FA         [24]  493 	mov	_TH1,#0xfa
                                    494 ;	test3threads.c:107: SCON = 0x50;//for serial port
      0000B8 75 98 50         [24]  495 	mov	_SCON,#0x50
                                    496 ;	test3threads.c:108: TR1 = 1;//start
                                    497 ;	assignBit
      0000BB D2 8E            [12]  498 	setb	_TR1
                                    499 ;	test3threads.c:110: while (1)
      0000BD                        500 00107$:
                                    501 ;	test3threads.c:112: SemaphoreWait(full);
      0000BD                        502 		6$:
      0000BD 85 2A E0         [24]  503 	MOV ACC, _full 
      0000C0 60 FB            [24]  504 	JZ 6$ 
      0000C2 20 E7 F8         [24]  505 	JB ACC.7, 6$ 
      0000C5 15 2A            [12]  506 	dec _full 
                                    507 ;	test3threads.c:113: SemaphoreWait(mutex);
      0000C7                        508 		7$:
      0000C7 85 29 E0         [24]  509 	MOV ACC, _mutex 
      0000CA 60 FB            [24]  510 	JZ 7$ 
      0000CC 20 E7 F8         [24]  511 	JB ACC.7, 7$ 
      0000CF 15 29            [12]  512 	dec _mutex 
                                    513 ;	test3threads.c:115: EA = 0;
                                    514 ;	assignBit
      0000D1 C2 AF            [12]  515 	clr	_EA
                                    516 ;	test3threads.c:116: SBUF = buffer[b_start];
      0000D3 E5 2C            [12]  517 	mov	a,_b_start
      0000D5 24 30            [12]  518 	add	a,#_buffer
      0000D7 F9               [12]  519 	mov	r1,a
      0000D8 87 99            [24]  520 	mov	_SBUF,@r1
                                    521 ;	test3threads.c:117: while (TI == 0);
      0000DA                        522 00101$:
                                    523 ;	test3threads.c:118: TI = 0; 
                                    524 ;	assignBit
      0000DA 10 99 02         [24]  525 	jbc	_TI,00127$
      0000DD 80 FB            [24]  526 	sjmp	00101$
      0000DF                        527 00127$:
                                    528 ;	test3threads.c:120: b_start++;
      0000DF E5 2C            [12]  529 	mov	a,_b_start
      0000E1 04               [12]  530 	inc	a
      0000E2 F5 2C            [12]  531 	mov	_b_start,a
                                    532 ;	test3threads.c:121: if (b_start==BUFFER_SIZE)b_start=0;
      0000E4 74 03            [12]  533 	mov	a,#0x03
      0000E6 B5 2C 03         [24]  534 	cjne	a,_b_start,00105$
      0000E9 75 2C 00         [24]  535 	mov	_b_start,#0x00
      0000EC                        536 00105$:
                                    537 ;	test3threads.c:122: EA = 1;
                                    538 ;	assignBit
      0000EC D2 AF            [12]  539 	setb	_EA
                                    540 ;	test3threads.c:123: SemaphoreSignal(mutex);
      0000EE 05 29            [12]  541 	INC _mutex 
                                    542 ;	test3threads.c:124: SemaphoreSignal(empty);
      0000F0 05 2B            [12]  543 	INC _empty 
                                    544 ;	test3threads.c:126: }
      0000F2 80 C9            [24]  545 	sjmp	00107$
                                    546 ;------------------------------------------------------------
                                    547 ;Allocation info for local variables in function 'main'
                                    548 ;------------------------------------------------------------
                                    549 ;	test3threads.c:133: void main(void)
                                    550 ;	-----------------------------------------
                                    551 ;	 function main
                                    552 ;	-----------------------------------------
      0000F4                        553 _main:
                                    554 ;	test3threads.c:139: SemaphoreCreate(mutex,1);
      0000F4 75 29 01         [24]  555 	mov	_mutex,#0x01
                                    556 ;	test3threads.c:140: SemaphoreCreate(full,0);
      0000F7 75 2A 00         [24]  557 	mov	_full,#0x00
                                    558 ;	test3threads.c:141: SemaphoreCreate(empty,BUFFER_SIZE);
      0000FA 75 2B 03         [24]  559 	mov	_empty,#0x03
                                    560 ;	test3threads.c:143: SemaphoreCreate(_1_turn,1);
      0000FD 75 33 01         [24]  561 	mov	__1_turn,#0x01
                                    562 ;	test3threads.c:144: SemaphoreCreate(_2_turn,0);
      000100 75 34 00         [24]  563 	mov	__2_turn,#0x00
                                    564 ;	test3threads.c:146: b_start = b_end = 0;
      000103 75 2D 00         [24]  565 	mov	_b_end,#0x00
      000106 75 2C 00         [24]  566 	mov	_b_start,#0x00
                                    567 ;	test3threads.c:147: in_counter_1 = 0;
      000109 75 2E 00         [24]  568 	mov	_in_counter_1,#0x00
                                    569 ;	test3threads.c:148: in_counter_2 = 0;
      00010C 75 2F 00         [24]  570 	mov	_in_counter_2,#0x00
                                    571 ;	test3threads.c:155: ThreadCreate(Producer1);
      00010F 90 00 14         [24]  572 	mov	dptr,#_Producer1
      000112 12 01 61         [24]  573 	lcall	_ThreadCreate
                                    574 ;	test3threads.c:156: ThreadCreate(Producer2);
      000115 90 00 63         [24]  575 	mov	dptr,#_Producer2
      000118 12 01 61         [24]  576 	lcall	_ThreadCreate
                                    577 ;	test3threads.c:157: ThreadCreate(Consumer);
      00011B 90 00 B2         [24]  578 	mov	dptr,#_Consumer
      00011E 12 01 61         [24]  579 	lcall	_ThreadCreate
                                    580 ;	test3threads.c:158: ThreadExit();
                                    581 ;	test3threads.c:159: }
      000121 02 02 3C         [24]  582 	ljmp	_ThreadExit
                                    583 ;------------------------------------------------------------
                                    584 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                    585 ;------------------------------------------------------------
                                    586 ;	test3threads.c:161: void _sdcc_gsinit_startup(void)
                                    587 ;	-----------------------------------------
                                    588 ;	 function _sdcc_gsinit_startup
                                    589 ;	-----------------------------------------
      000124                        590 __sdcc_gsinit_startup:
                                    591 ;	test3threads.c:165: __endasm;
      000124 02 01 2F         [24]  592 	LJMP	_Bootstrap
                                    593 ;	test3threads.c:166: }
      000127 22               [24]  594 	ret
                                    595 ;------------------------------------------------------------
                                    596 ;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
                                    597 ;------------------------------------------------------------
                                    598 ;	test3threads.c:168: void _mcs51_genRAMCLEAR(void) {}
                                    599 ;	-----------------------------------------
                                    600 ;	 function _mcs51_genRAMCLEAR
                                    601 ;	-----------------------------------------
      000128                        602 __mcs51_genRAMCLEAR:
      000128 22               [24]  603 	ret
                                    604 ;------------------------------------------------------------
                                    605 ;Allocation info for local variables in function '_mcs51_genXINIT'
                                    606 ;------------------------------------------------------------
                                    607 ;	test3threads.c:169: void _mcs51_genXINIT(void) {}
                                    608 ;	-----------------------------------------
                                    609 ;	 function _mcs51_genXINIT
                                    610 ;	-----------------------------------------
      000129                        611 __mcs51_genXINIT:
      000129 22               [24]  612 	ret
                                    613 ;------------------------------------------------------------
                                    614 ;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
                                    615 ;------------------------------------------------------------
                                    616 ;	test3threads.c:170: void _mcs51_genXRAMCLEAR(void) {}
                                    617 ;	-----------------------------------------
                                    618 ;	 function _mcs51_genXRAMCLEAR
                                    619 ;	-----------------------------------------
      00012A                        620 __mcs51_genXRAMCLEAR:
      00012A 22               [24]  621 	ret
                                    622 ;------------------------------------------------------------
                                    623 ;Allocation info for local variables in function 'timer0_ISR'
                                    624 ;------------------------------------------------------------
                                    625 ;	test3threads.c:172: void timer0_ISR(void) __interrupt(1) {
                                    626 ;	-----------------------------------------
                                    627 ;	 function timer0_ISR
                                    628 ;	-----------------------------------------
      00012B                        629 _timer0_ISR:
                                    630 ;	test3threads.c:175: __endasm;
      00012B 02 02 95         [24]  631 	ljmp	_myTimer0Handler
                                    632 ;	test3threads.c:176: }
      00012E 32               [24]  633 	reti
                                    634 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    635 ;	eliminated unneeded push/pop psw
                                    636 ;	eliminated unneeded push/pop dpl
                                    637 ;	eliminated unneeded push/pop dph
                                    638 ;	eliminated unneeded push/pop b
                                    639 ;	eliminated unneeded push/pop acc
                                    640 	.area CSEG    (CODE)
                                    641 	.area CONST   (CODE)
                                    642 	.area XINIT   (CODE)
                                    643 	.area CABS    (ABS,CODE)
