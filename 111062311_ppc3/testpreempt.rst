                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module testpreempt
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
                                     18 	.globl _Producer
                                     19 	.globl _ThreadExit
                                     20 	.globl _ThreadCreate
                                     21 	.globl _CY
                                     22 	.globl _AC
                                     23 	.globl _F0
                                     24 	.globl _RS1
                                     25 	.globl _RS0
                                     26 	.globl _OV
                                     27 	.globl _F1
                                     28 	.globl _P
                                     29 	.globl _PS
                                     30 	.globl _PT1
                                     31 	.globl _PX1
                                     32 	.globl _PT0
                                     33 	.globl _PX0
                                     34 	.globl _RD
                                     35 	.globl _WR
                                     36 	.globl _T1
                                     37 	.globl _T0
                                     38 	.globl _INT1
                                     39 	.globl _INT0
                                     40 	.globl _TXD
                                     41 	.globl _RXD
                                     42 	.globl _P3_7
                                     43 	.globl _P3_6
                                     44 	.globl _P3_5
                                     45 	.globl _P3_4
                                     46 	.globl _P3_3
                                     47 	.globl _P3_2
                                     48 	.globl _P3_1
                                     49 	.globl _P3_0
                                     50 	.globl _EA
                                     51 	.globl _ES
                                     52 	.globl _ET1
                                     53 	.globl _EX1
                                     54 	.globl _ET0
                                     55 	.globl _EX0
                                     56 	.globl _P2_7
                                     57 	.globl _P2_6
                                     58 	.globl _P2_5
                                     59 	.globl _P2_4
                                     60 	.globl _P2_3
                                     61 	.globl _P2_2
                                     62 	.globl _P2_1
                                     63 	.globl _P2_0
                                     64 	.globl _SM0
                                     65 	.globl _SM1
                                     66 	.globl _SM2
                                     67 	.globl _REN
                                     68 	.globl _TB8
                                     69 	.globl _RB8
                                     70 	.globl _TI
                                     71 	.globl _RI
                                     72 	.globl _P1_7
                                     73 	.globl _P1_6
                                     74 	.globl _P1_5
                                     75 	.globl _P1_4
                                     76 	.globl _P1_3
                                     77 	.globl _P1_2
                                     78 	.globl _P1_1
                                     79 	.globl _P1_0
                                     80 	.globl _TF1
                                     81 	.globl _TR1
                                     82 	.globl _TF0
                                     83 	.globl _TR0
                                     84 	.globl _IE1
                                     85 	.globl _IT1
                                     86 	.globl _IE0
                                     87 	.globl _IT0
                                     88 	.globl _P0_7
                                     89 	.globl _P0_6
                                     90 	.globl _P0_5
                                     91 	.globl _P0_4
                                     92 	.globl _P0_3
                                     93 	.globl _P0_2
                                     94 	.globl _P0_1
                                     95 	.globl _P0_0
                                     96 	.globl _B
                                     97 	.globl _ACC
                                     98 	.globl _PSW
                                     99 	.globl _IP
                                    100 	.globl _P3
                                    101 	.globl _IE
                                    102 	.globl _P2
                                    103 	.globl _SBUF
                                    104 	.globl _SCON
                                    105 	.globl _P1
                                    106 	.globl _TH1
                                    107 	.globl _TH0
                                    108 	.globl _TL1
                                    109 	.globl _TL0
                                    110 	.globl _TMOD
                                    111 	.globl _TCON
                                    112 	.globl _PCON
                                    113 	.globl _DPH
                                    114 	.globl _DPL
                                    115 	.globl _SP
                                    116 	.globl _P0
                                    117 	.globl _empty
                                    118 	.globl _full
                                    119 	.globl _mutex
                                    120 	.globl _buffer
                                    121 	.globl _in_counter
                                    122 	.globl _b_end
                                    123 	.globl _b_start
                                    124 ;--------------------------------------------------------
                                    125 ; special function registers
                                    126 ;--------------------------------------------------------
                                    127 	.area RSEG    (ABS,DATA)
      000000                        128 	.org 0x0000
                           000080   129 _P0	=	0x0080
                           000081   130 _SP	=	0x0081
                           000082   131 _DPL	=	0x0082
                           000083   132 _DPH	=	0x0083
                           000087   133 _PCON	=	0x0087
                           000088   134 _TCON	=	0x0088
                           000089   135 _TMOD	=	0x0089
                           00008A   136 _TL0	=	0x008a
                           00008B   137 _TL1	=	0x008b
                           00008C   138 _TH0	=	0x008c
                           00008D   139 _TH1	=	0x008d
                           000090   140 _P1	=	0x0090
                           000098   141 _SCON	=	0x0098
                           000099   142 _SBUF	=	0x0099
                           0000A0   143 _P2	=	0x00a0
                           0000A8   144 _IE	=	0x00a8
                           0000B0   145 _P3	=	0x00b0
                           0000B8   146 _IP	=	0x00b8
                           0000D0   147 _PSW	=	0x00d0
                           0000E0   148 _ACC	=	0x00e0
                           0000F0   149 _B	=	0x00f0
                                    150 ;--------------------------------------------------------
                                    151 ; special function bits
                                    152 ;--------------------------------------------------------
                                    153 	.area RSEG    (ABS,DATA)
      000000                        154 	.org 0x0000
                           000080   155 _P0_0	=	0x0080
                           000081   156 _P0_1	=	0x0081
                           000082   157 _P0_2	=	0x0082
                           000083   158 _P0_3	=	0x0083
                           000084   159 _P0_4	=	0x0084
                           000085   160 _P0_5	=	0x0085
                           000086   161 _P0_6	=	0x0086
                           000087   162 _P0_7	=	0x0087
                           000088   163 _IT0	=	0x0088
                           000089   164 _IE0	=	0x0089
                           00008A   165 _IT1	=	0x008a
                           00008B   166 _IE1	=	0x008b
                           00008C   167 _TR0	=	0x008c
                           00008D   168 _TF0	=	0x008d
                           00008E   169 _TR1	=	0x008e
                           00008F   170 _TF1	=	0x008f
                           000090   171 _P1_0	=	0x0090
                           000091   172 _P1_1	=	0x0091
                           000092   173 _P1_2	=	0x0092
                           000093   174 _P1_3	=	0x0093
                           000094   175 _P1_4	=	0x0094
                           000095   176 _P1_5	=	0x0095
                           000096   177 _P1_6	=	0x0096
                           000097   178 _P1_7	=	0x0097
                           000098   179 _RI	=	0x0098
                           000099   180 _TI	=	0x0099
                           00009A   181 _RB8	=	0x009a
                           00009B   182 _TB8	=	0x009b
                           00009C   183 _REN	=	0x009c
                           00009D   184 _SM2	=	0x009d
                           00009E   185 _SM1	=	0x009e
                           00009F   186 _SM0	=	0x009f
                           0000A0   187 _P2_0	=	0x00a0
                           0000A1   188 _P2_1	=	0x00a1
                           0000A2   189 _P2_2	=	0x00a2
                           0000A3   190 _P2_3	=	0x00a3
                           0000A4   191 _P2_4	=	0x00a4
                           0000A5   192 _P2_5	=	0x00a5
                           0000A6   193 _P2_6	=	0x00a6
                           0000A7   194 _P2_7	=	0x00a7
                           0000A8   195 _EX0	=	0x00a8
                           0000A9   196 _ET0	=	0x00a9
                           0000AA   197 _EX1	=	0x00aa
                           0000AB   198 _ET1	=	0x00ab
                           0000AC   199 _ES	=	0x00ac
                           0000AF   200 _EA	=	0x00af
                           0000B0   201 _P3_0	=	0x00b0
                           0000B1   202 _P3_1	=	0x00b1
                           0000B2   203 _P3_2	=	0x00b2
                           0000B3   204 _P3_3	=	0x00b3
                           0000B4   205 _P3_4	=	0x00b4
                           0000B5   206 _P3_5	=	0x00b5
                           0000B6   207 _P3_6	=	0x00b6
                           0000B7   208 _P3_7	=	0x00b7
                           0000B0   209 _RXD	=	0x00b0
                           0000B1   210 _TXD	=	0x00b1
                           0000B2   211 _INT0	=	0x00b2
                           0000B3   212 _INT1	=	0x00b3
                           0000B4   213 _T0	=	0x00b4
                           0000B5   214 _T1	=	0x00b5
                           0000B6   215 _WR	=	0x00b6
                           0000B7   216 _RD	=	0x00b7
                           0000B8   217 _PX0	=	0x00b8
                           0000B9   218 _PT0	=	0x00b9
                           0000BA   219 _PX1	=	0x00ba
                           0000BB   220 _PT1	=	0x00bb
                           0000BC   221 _PS	=	0x00bc
                           0000D0   222 _P	=	0x00d0
                           0000D1   223 _F1	=	0x00d1
                           0000D2   224 _OV	=	0x00d2
                           0000D3   225 _RS0	=	0x00d3
                           0000D4   226 _RS1	=	0x00d4
                           0000D5   227 _F0	=	0x00d5
                           0000D6   228 _AC	=	0x00d6
                           0000D7   229 _CY	=	0x00d7
                                    230 ;--------------------------------------------------------
                                    231 ; overlayable register banks
                                    232 ;--------------------------------------------------------
                                    233 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        234 	.ds 8
                                    235 ;--------------------------------------------------------
                                    236 ; internal ram data
                                    237 ;--------------------------------------------------------
                                    238 	.area DSEG    (DATA)
                           00002C   239 _b_start	=	0x002c
                           00002D   240 _b_end	=	0x002d
                           00002E   241 _in_counter	=	0x002e
                           000030   242 _buffer	=	0x0030
                           000029   243 _mutex	=	0x0029
                           00002A   244 _full	=	0x002a
                           00002B   245 _empty	=	0x002b
                                    246 ;--------------------------------------------------------
                                    247 ; overlayable items in internal ram 
                                    248 ;--------------------------------------------------------
                                    249 ;--------------------------------------------------------
                                    250 ; Stack segment in internal ram 
                                    251 ;--------------------------------------------------------
                                    252 	.area	SSEG
      000008                        253 __start__stack:
      000008                        254 	.ds	1
                                    255 
                                    256 ;--------------------------------------------------------
                                    257 ; indirectly addressable internal ram data
                                    258 ;--------------------------------------------------------
                                    259 	.area ISEG    (DATA)
                                    260 ;--------------------------------------------------------
                                    261 ; absolute internal ram data
                                    262 ;--------------------------------------------------------
                                    263 	.area IABS    (ABS,DATA)
                                    264 	.area IABS    (ABS,DATA)
                                    265 ;--------------------------------------------------------
                                    266 ; bit data
                                    267 ;--------------------------------------------------------
                                    268 	.area BSEG    (BIT)
                                    269 ;--------------------------------------------------------
                                    270 ; paged external ram data
                                    271 ;--------------------------------------------------------
                                    272 	.area PSEG    (PAG,XDATA)
                                    273 ;--------------------------------------------------------
                                    274 ; external ram data
                                    275 ;--------------------------------------------------------
                                    276 	.area XSEG    (XDATA)
                                    277 ;--------------------------------------------------------
                                    278 ; absolute external ram data
                                    279 ;--------------------------------------------------------
                                    280 	.area XABS    (ABS,XDATA)
                                    281 ;--------------------------------------------------------
                                    282 ; external initialized ram data
                                    283 ;--------------------------------------------------------
                                    284 	.area XISEG   (XDATA)
                                    285 	.area HOME    (CODE)
                                    286 	.area GSINIT0 (CODE)
                                    287 	.area GSINIT1 (CODE)
                                    288 	.area GSINIT2 (CODE)
                                    289 	.area GSINIT3 (CODE)
                                    290 	.area GSINIT4 (CODE)
                                    291 	.area GSINIT5 (CODE)
                                    292 	.area GSINIT  (CODE)
                                    293 	.area GSFINAL (CODE)
                                    294 	.area CSEG    (CODE)
                                    295 ;--------------------------------------------------------
                                    296 ; interrupt vector 
                                    297 ;--------------------------------------------------------
                                    298 	.area HOME    (CODE)
      000000                        299 __interrupt_vect:
      000000 02 00 BA         [24]  300 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  301 	reti
      000004                        302 	.ds	7
      00000B 02 00 C1         [24]  303 	ljmp	_timer0_ISR
                                    304 ;--------------------------------------------------------
                                    305 ; global & static initialisations
                                    306 ;--------------------------------------------------------
                                    307 	.area HOME    (CODE)
                                    308 	.area GSINIT  (CODE)
                                    309 	.area GSFINAL (CODE)
                                    310 	.area GSINIT  (CODE)
                                    311 	.globl __sdcc_gsinit_startup
                                    312 	.globl __sdcc_program_startup
                                    313 	.globl __start__stack
                                    314 	.globl __mcs51_genXINIT
                                    315 	.globl __mcs51_genXRAMCLEAR
                                    316 	.globl __mcs51_genRAMCLEAR
                                    317 	.area GSFINAL (CODE)
      000011 02 00 0E         [24]  318 	ljmp	__sdcc_program_startup
                                    319 ;--------------------------------------------------------
                                    320 ; Home
                                    321 ;--------------------------------------------------------
                                    322 	.area HOME    (CODE)
                                    323 	.area HOME    (CODE)
      00000E                        324 __sdcc_program_startup:
      00000E 02 00 99         [24]  325 	ljmp	_main
                                    326 ;	return from main will return to caller
                                    327 ;--------------------------------------------------------
                                    328 ; code
                                    329 ;--------------------------------------------------------
                                    330 	.area CSEG    (CODE)
                                    331 ;------------------------------------------------------------
                                    332 ;Allocation info for local variables in function 'Producer'
                                    333 ;------------------------------------------------------------
                                    334 ;	testpreempt.c:31: void Producer(void)
                                    335 ;	-----------------------------------------
                                    336 ;	 function Producer
                                    337 ;	-----------------------------------------
      000014                        338 _Producer:
                           000007   339 	ar7 = 0x07
                           000006   340 	ar6 = 0x06
                           000005   341 	ar5 = 0x05
                           000004   342 	ar4 = 0x04
                           000003   343 	ar3 = 0x03
                           000002   344 	ar2 = 0x02
                           000001   345 	ar1 = 0x01
                           000000   346 	ar0 = 0x00
                                    347 ;	testpreempt.c:38: while (1)
      000014                        348 00106$:
                                    349 ;	testpreempt.c:41: SemaphoreWait(empty);
      000014                        350 		0$:
      000014 85 2B E0         [24]  351 	MOV ACC, _empty 
      000017 60 FB            [24]  352 	JZ 0$ 
      000019 20 E7 F8         [24]  353 	JB ACC.7, 0$ 
      00001C 15 2B            [12]  354 	dec _empty 
                                    355 ;	testpreempt.c:42: SemaphoreWait(mutex);
      00001E                        356 		1$:
      00001E 85 29 E0         [24]  357 	MOV ACC, _mutex 
      000021 60 FB            [24]  358 	JZ 1$ 
      000023 20 E7 F8         [24]  359 	JB ACC.7, 1$ 
      000026 15 29            [12]  360 	dec _mutex 
                                    361 ;	testpreempt.c:44: EA = 0;
                                    362 ;	assignBit
      000028 C2 AF            [12]  363 	clr	_EA
                                    364 ;	testpreempt.c:45: buffer[b_end] = 'A'+in_counter;
      00002A E5 2D            [12]  365 	mov	a,_b_end
      00002C 24 30            [12]  366 	add	a,#_buffer
      00002E F9               [12]  367 	mov	r1,a
      00002F AF 2E            [24]  368 	mov	r7,_in_counter
      000031 74 41            [12]  369 	mov	a,#0x41
      000033 2F               [12]  370 	add	a,r7
      000034 F7               [12]  371 	mov	@r1,a
                                    372 ;	testpreempt.c:46: b_end++;
      000035 E5 2D            [12]  373 	mov	a,_b_end
      000037 04               [12]  374 	inc	a
      000038 F5 2D            [12]  375 	mov	_b_end,a
                                    376 ;	testpreempt.c:47: if (b_end==BUFFER_SIZE)b_end=0;
      00003A 74 03            [12]  377 	mov	a,#0x03
      00003C B5 2D 03         [24]  378 	cjne	a,_b_end,00102$
      00003F 75 2D 00         [24]  379 	mov	_b_end,#0x00
      000042                        380 00102$:
                                    381 ;	testpreempt.c:48: in_counter++;
      000042 E5 2E            [12]  382 	mov	a,_in_counter
      000044 04               [12]  383 	inc	a
      000045 F5 2E            [12]  384 	mov	_in_counter,a
                                    385 ;	testpreempt.c:49: if (in_counter==26)in_counter=0;
      000047 74 1A            [12]  386 	mov	a,#0x1a
      000049 B5 2E 03         [24]  387 	cjne	a,_in_counter,00104$
      00004C 75 2E 00         [24]  388 	mov	_in_counter,#0x00
      00004F                        389 00104$:
                                    390 ;	testpreempt.c:50: EA = 1;
                                    391 ;	assignBit
      00004F D2 AF            [12]  392 	setb	_EA
                                    393 ;	testpreempt.c:51: SemaphoreSignal(mutex);
      000051 05 29            [12]  394 	INC _mutex 
                                    395 ;	testpreempt.c:52: SemaphoreSignal(full);
      000053 05 2A            [12]  396 	INC _full 
                                    397 ;	testpreempt.c:57: }
      000055 80 BD            [24]  398 	sjmp	00106$
                                    399 ;------------------------------------------------------------
                                    400 ;Allocation info for local variables in function 'Consumer'
                                    401 ;------------------------------------------------------------
                                    402 ;	testpreempt.c:64: void Consumer(void)
                                    403 ;	-----------------------------------------
                                    404 ;	 function Consumer
                                    405 ;	-----------------------------------------
      000057                        406 _Consumer:
                                    407 ;	testpreempt.c:70: TMOD |= 0x20;
      000057 43 89 20         [24]  408 	orl	_TMOD,#0x20
                                    409 ;	testpreempt.c:71: TH1 = -6;//for buad (frequency)
      00005A 75 8D FA         [24]  410 	mov	_TH1,#0xfa
                                    411 ;	testpreempt.c:72: SCON = 0x50;//for serial port
      00005D 75 98 50         [24]  412 	mov	_SCON,#0x50
                                    413 ;	testpreempt.c:73: TR1 = 1;//start
                                    414 ;	assignBit
      000060 D2 8E            [12]  415 	setb	_TR1
                                    416 ;	testpreempt.c:75: while (1)
      000062                        417 00107$:
                                    418 ;	testpreempt.c:77: SemaphoreWait(full);
      000062                        419 		2$:
      000062 85 2A E0         [24]  420 	MOV ACC, _full 
      000065 60 FB            [24]  421 	JZ 2$ 
      000067 20 E7 F8         [24]  422 	JB ACC.7, 2$ 
      00006A 15 2A            [12]  423 	dec _full 
                                    424 ;	testpreempt.c:78: SemaphoreWait(mutex);
      00006C                        425 		3$:
      00006C 85 29 E0         [24]  426 	MOV ACC, _mutex 
      00006F 60 FB            [24]  427 	JZ 3$ 
      000071 20 E7 F8         [24]  428 	JB ACC.7, 3$ 
      000074 15 29            [12]  429 	dec _mutex 
                                    430 ;	testpreempt.c:80: EA = 0;
                                    431 ;	assignBit
      000076 C2 AF            [12]  432 	clr	_EA
                                    433 ;	testpreempt.c:81: SBUF = buffer[b_start];
      000078 E5 2C            [12]  434 	mov	a,_b_start
      00007A 24 30            [12]  435 	add	a,#_buffer
      00007C F9               [12]  436 	mov	r1,a
      00007D 87 99            [24]  437 	mov	_SBUF,@r1
                                    438 ;	testpreempt.c:82: while (TI == 0);
      00007F                        439 00101$:
                                    440 ;	testpreempt.c:83: TI = 0; 
                                    441 ;	assignBit
      00007F 10 99 02         [24]  442 	jbc	_TI,00127$
      000082 80 FB            [24]  443 	sjmp	00101$
      000084                        444 00127$:
                                    445 ;	testpreempt.c:85: b_start++;
      000084 E5 2C            [12]  446 	mov	a,_b_start
      000086 04               [12]  447 	inc	a
      000087 F5 2C            [12]  448 	mov	_b_start,a
                                    449 ;	testpreempt.c:86: if (b_start==BUFFER_SIZE)b_start=0;
      000089 74 03            [12]  450 	mov	a,#0x03
      00008B B5 2C 03         [24]  451 	cjne	a,_b_start,00105$
      00008E 75 2C 00         [24]  452 	mov	_b_start,#0x00
      000091                        453 00105$:
                                    454 ;	testpreempt.c:87: EA = 1;
                                    455 ;	assignBit
      000091 D2 AF            [12]  456 	setb	_EA
                                    457 ;	testpreempt.c:88: SemaphoreSignal(mutex);
      000093 05 29            [12]  458 	INC _mutex 
                                    459 ;	testpreempt.c:89: SemaphoreSignal(empty);
      000095 05 2B            [12]  460 	INC _empty 
                                    461 ;	testpreempt.c:91: }
      000097 80 C9            [24]  462 	sjmp	00107$
                                    463 ;------------------------------------------------------------
                                    464 ;Allocation info for local variables in function 'main'
                                    465 ;------------------------------------------------------------
                                    466 ;	testpreempt.c:98: void main(void)
                                    467 ;	-----------------------------------------
                                    468 ;	 function main
                                    469 ;	-----------------------------------------
      000099                        470 _main:
                                    471 ;	testpreempt.c:104: SemaphoreCreate(mutex,1);
      000099 75 29 01         [24]  472 	mov	_mutex,#0x01
                                    473 ;	testpreempt.c:105: SemaphoreCreate(full,0);
      00009C 75 2A 00         [24]  474 	mov	_full,#0x00
                                    475 ;	testpreempt.c:106: SemaphoreCreate(empty,BUFFER_SIZE);
      00009F 75 2B 03         [24]  476 	mov	_empty,#0x03
                                    477 ;	testpreempt.c:107: b_start = b_end = 0;
      0000A2 75 2D 00         [24]  478 	mov	_b_end,#0x00
      0000A5 75 2C 00         [24]  479 	mov	_b_start,#0x00
                                    480 ;	testpreempt.c:108: in_counter = 0;
      0000A8 75 2E 00         [24]  481 	mov	_in_counter,#0x00
                                    482 ;	testpreempt.c:115: ThreadCreate(Producer);
      0000AB 90 00 14         [24]  483 	mov	dptr,#_Producer
      0000AE 12 00 F7         [24]  484 	lcall	_ThreadCreate
                                    485 ;	testpreempt.c:116: ThreadCreate(Consumer);
      0000B1 90 00 57         [24]  486 	mov	dptr,#_Consumer
      0000B4 12 00 F7         [24]  487 	lcall	_ThreadCreate
                                    488 ;	testpreempt.c:117: ThreadExit();
                                    489 ;	testpreempt.c:118: }
      0000B7 02 01 D2         [24]  490 	ljmp	_ThreadExit
                                    491 ;------------------------------------------------------------
                                    492 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                    493 ;------------------------------------------------------------
                                    494 ;	testpreempt.c:120: void _sdcc_gsinit_startup(void)
                                    495 ;	-----------------------------------------
                                    496 ;	 function _sdcc_gsinit_startup
                                    497 ;	-----------------------------------------
      0000BA                        498 __sdcc_gsinit_startup:
                                    499 ;	testpreempt.c:124: __endasm;
      0000BA 02 00 C5         [24]  500 	LJMP	_Bootstrap
                                    501 ;	testpreempt.c:125: }
      0000BD 22               [24]  502 	ret
                                    503 ;------------------------------------------------------------
                                    504 ;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
                                    505 ;------------------------------------------------------------
                                    506 ;	testpreempt.c:127: void _mcs51_genRAMCLEAR(void) {}
                                    507 ;	-----------------------------------------
                                    508 ;	 function _mcs51_genRAMCLEAR
                                    509 ;	-----------------------------------------
      0000BE                        510 __mcs51_genRAMCLEAR:
      0000BE 22               [24]  511 	ret
                                    512 ;------------------------------------------------------------
                                    513 ;Allocation info for local variables in function '_mcs51_genXINIT'
                                    514 ;------------------------------------------------------------
                                    515 ;	testpreempt.c:128: void _mcs51_genXINIT(void) {}
                                    516 ;	-----------------------------------------
                                    517 ;	 function _mcs51_genXINIT
                                    518 ;	-----------------------------------------
      0000BF                        519 __mcs51_genXINIT:
      0000BF 22               [24]  520 	ret
                                    521 ;------------------------------------------------------------
                                    522 ;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
                                    523 ;------------------------------------------------------------
                                    524 ;	testpreempt.c:129: void _mcs51_genXRAMCLEAR(void) {}
                                    525 ;	-----------------------------------------
                                    526 ;	 function _mcs51_genXRAMCLEAR
                                    527 ;	-----------------------------------------
      0000C0                        528 __mcs51_genXRAMCLEAR:
      0000C0 22               [24]  529 	ret
                                    530 ;------------------------------------------------------------
                                    531 ;Allocation info for local variables in function 'timer0_ISR'
                                    532 ;------------------------------------------------------------
                                    533 ;	testpreempt.c:131: void timer0_ISR(void) __interrupt(1) {
                                    534 ;	-----------------------------------------
                                    535 ;	 function timer0_ISR
                                    536 ;	-----------------------------------------
      0000C1                        537 _timer0_ISR:
                                    538 ;	testpreempt.c:134: __endasm;
      0000C1 02 02 2B         [24]  539 	ljmp	_myTimer0Handler
                                    540 ;	testpreempt.c:135: }
      0000C4 32               [24]  541 	reti
                                    542 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    543 ;	eliminated unneeded push/pop psw
                                    544 ;	eliminated unneeded push/pop dpl
                                    545 ;	eliminated unneeded push/pop dph
                                    546 ;	eliminated unneeded push/pop b
                                    547 ;	eliminated unneeded push/pop acc
                                    548 	.area CSEG    (CODE)
                                    549 	.area CONST   (CODE)
                                    550 	.area XINIT   (CODE)
                                    551 	.area CABS    (ABS,CODE)
