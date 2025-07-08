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
                                    117 	.globl _buffer
                                    118 	.globl _in_counter
                                    119 	.globl _b_end
                                    120 	.globl _b_start
                                    121 ;--------------------------------------------------------
                                    122 ; special function registers
                                    123 ;--------------------------------------------------------
                                    124 	.area RSEG    (ABS,DATA)
      000000                        125 	.org 0x0000
                           000080   126 _P0	=	0x0080
                           000081   127 _SP	=	0x0081
                           000082   128 _DPL	=	0x0082
                           000083   129 _DPH	=	0x0083
                           000087   130 _PCON	=	0x0087
                           000088   131 _TCON	=	0x0088
                           000089   132 _TMOD	=	0x0089
                           00008A   133 _TL0	=	0x008a
                           00008B   134 _TL1	=	0x008b
                           00008C   135 _TH0	=	0x008c
                           00008D   136 _TH1	=	0x008d
                           000090   137 _P1	=	0x0090
                           000098   138 _SCON	=	0x0098
                           000099   139 _SBUF	=	0x0099
                           0000A0   140 _P2	=	0x00a0
                           0000A8   141 _IE	=	0x00a8
                           0000B0   142 _P3	=	0x00b0
                           0000B8   143 _IP	=	0x00b8
                           0000D0   144 _PSW	=	0x00d0
                           0000E0   145 _ACC	=	0x00e0
                           0000F0   146 _B	=	0x00f0
                                    147 ;--------------------------------------------------------
                                    148 ; special function bits
                                    149 ;--------------------------------------------------------
                                    150 	.area RSEG    (ABS,DATA)
      000000                        151 	.org 0x0000
                           000080   152 _P0_0	=	0x0080
                           000081   153 _P0_1	=	0x0081
                           000082   154 _P0_2	=	0x0082
                           000083   155 _P0_3	=	0x0083
                           000084   156 _P0_4	=	0x0084
                           000085   157 _P0_5	=	0x0085
                           000086   158 _P0_6	=	0x0086
                           000087   159 _P0_7	=	0x0087
                           000088   160 _IT0	=	0x0088
                           000089   161 _IE0	=	0x0089
                           00008A   162 _IT1	=	0x008a
                           00008B   163 _IE1	=	0x008b
                           00008C   164 _TR0	=	0x008c
                           00008D   165 _TF0	=	0x008d
                           00008E   166 _TR1	=	0x008e
                           00008F   167 _TF1	=	0x008f
                           000090   168 _P1_0	=	0x0090
                           000091   169 _P1_1	=	0x0091
                           000092   170 _P1_2	=	0x0092
                           000093   171 _P1_3	=	0x0093
                           000094   172 _P1_4	=	0x0094
                           000095   173 _P1_5	=	0x0095
                           000096   174 _P1_6	=	0x0096
                           000097   175 _P1_7	=	0x0097
                           000098   176 _RI	=	0x0098
                           000099   177 _TI	=	0x0099
                           00009A   178 _RB8	=	0x009a
                           00009B   179 _TB8	=	0x009b
                           00009C   180 _REN	=	0x009c
                           00009D   181 _SM2	=	0x009d
                           00009E   182 _SM1	=	0x009e
                           00009F   183 _SM0	=	0x009f
                           0000A0   184 _P2_0	=	0x00a0
                           0000A1   185 _P2_1	=	0x00a1
                           0000A2   186 _P2_2	=	0x00a2
                           0000A3   187 _P2_3	=	0x00a3
                           0000A4   188 _P2_4	=	0x00a4
                           0000A5   189 _P2_5	=	0x00a5
                           0000A6   190 _P2_6	=	0x00a6
                           0000A7   191 _P2_7	=	0x00a7
                           0000A8   192 _EX0	=	0x00a8
                           0000A9   193 _ET0	=	0x00a9
                           0000AA   194 _EX1	=	0x00aa
                           0000AB   195 _ET1	=	0x00ab
                           0000AC   196 _ES	=	0x00ac
                           0000AF   197 _EA	=	0x00af
                           0000B0   198 _P3_0	=	0x00b0
                           0000B1   199 _P3_1	=	0x00b1
                           0000B2   200 _P3_2	=	0x00b2
                           0000B3   201 _P3_3	=	0x00b3
                           0000B4   202 _P3_4	=	0x00b4
                           0000B5   203 _P3_5	=	0x00b5
                           0000B6   204 _P3_6	=	0x00b6
                           0000B7   205 _P3_7	=	0x00b7
                           0000B0   206 _RXD	=	0x00b0
                           0000B1   207 _TXD	=	0x00b1
                           0000B2   208 _INT0	=	0x00b2
                           0000B3   209 _INT1	=	0x00b3
                           0000B4   210 _T0	=	0x00b4
                           0000B5   211 _T1	=	0x00b5
                           0000B6   212 _WR	=	0x00b6
                           0000B7   213 _RD	=	0x00b7
                           0000B8   214 _PX0	=	0x00b8
                           0000B9   215 _PT0	=	0x00b9
                           0000BA   216 _PX1	=	0x00ba
                           0000BB   217 _PT1	=	0x00bb
                           0000BC   218 _PS	=	0x00bc
                           0000D0   219 _P	=	0x00d0
                           0000D1   220 _F1	=	0x00d1
                           0000D2   221 _OV	=	0x00d2
                           0000D3   222 _RS0	=	0x00d3
                           0000D4   223 _RS1	=	0x00d4
                           0000D5   224 _F0	=	0x00d5
                           0000D6   225 _AC	=	0x00d6
                           0000D7   226 _CY	=	0x00d7
                                    227 ;--------------------------------------------------------
                                    228 ; overlayable register banks
                                    229 ;--------------------------------------------------------
                                    230 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        231 	.ds 8
                                    232 ;--------------------------------------------------------
                                    233 ; internal ram data
                                    234 ;--------------------------------------------------------
                                    235 	.area DSEG    (DATA)
                           00002C   236 _b_start	=	0x002c
                           00002D   237 _b_end	=	0x002d
                           00002E   238 _in_counter	=	0x002e
                           000030   239 _buffer	=	0x0030
                                    240 ;--------------------------------------------------------
                                    241 ; overlayable items in internal ram 
                                    242 ;--------------------------------------------------------
                                    243 ;--------------------------------------------------------
                                    244 ; Stack segment in internal ram 
                                    245 ;--------------------------------------------------------
                                    246 	.area	SSEG
      000008                        247 __start__stack:
      000008                        248 	.ds	1
                                    249 
                                    250 ;--------------------------------------------------------
                                    251 ; indirectly addressable internal ram data
                                    252 ;--------------------------------------------------------
                                    253 	.area ISEG    (DATA)
                                    254 ;--------------------------------------------------------
                                    255 ; absolute internal ram data
                                    256 ;--------------------------------------------------------
                                    257 	.area IABS    (ABS,DATA)
                                    258 	.area IABS    (ABS,DATA)
                                    259 ;--------------------------------------------------------
                                    260 ; bit data
                                    261 ;--------------------------------------------------------
                                    262 	.area BSEG    (BIT)
                                    263 ;--------------------------------------------------------
                                    264 ; paged external ram data
                                    265 ;--------------------------------------------------------
                                    266 	.area PSEG    (PAG,XDATA)
                                    267 ;--------------------------------------------------------
                                    268 ; external ram data
                                    269 ;--------------------------------------------------------
                                    270 	.area XSEG    (XDATA)
                                    271 ;--------------------------------------------------------
                                    272 ; absolute external ram data
                                    273 ;--------------------------------------------------------
                                    274 	.area XABS    (ABS,XDATA)
                                    275 ;--------------------------------------------------------
                                    276 ; external initialized ram data
                                    277 ;--------------------------------------------------------
                                    278 	.area XISEG   (XDATA)
                                    279 	.area HOME    (CODE)
                                    280 	.area GSINIT0 (CODE)
                                    281 	.area GSINIT1 (CODE)
                                    282 	.area GSINIT2 (CODE)
                                    283 	.area GSINIT3 (CODE)
                                    284 	.area GSINIT4 (CODE)
                                    285 	.area GSINIT5 (CODE)
                                    286 	.area GSINIT  (CODE)
                                    287 	.area GSFINAL (CODE)
                                    288 	.area CSEG    (CODE)
                                    289 ;--------------------------------------------------------
                                    290 ; interrupt vector 
                                    291 ;--------------------------------------------------------
                                    292 	.area HOME    (CODE)
      000000                        293 __interrupt_vect:
      000000 02 00 9C         [24]  294 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  295 	reti
      000004                        296 	.ds	7
      00000B 02 00 A3         [24]  297 	ljmp	_timer0_ISR
                                    298 ;--------------------------------------------------------
                                    299 ; global & static initialisations
                                    300 ;--------------------------------------------------------
                                    301 	.area HOME    (CODE)
                                    302 	.area GSINIT  (CODE)
                                    303 	.area GSFINAL (CODE)
                                    304 	.area GSINIT  (CODE)
                                    305 	.globl __sdcc_gsinit_startup
                                    306 	.globl __sdcc_program_startup
                                    307 	.globl __start__stack
                                    308 	.globl __mcs51_genXINIT
                                    309 	.globl __mcs51_genXRAMCLEAR
                                    310 	.globl __mcs51_genRAMCLEAR
                                    311 	.area GSFINAL (CODE)
      000011 02 00 0E         [24]  312 	ljmp	__sdcc_program_startup
                                    313 ;--------------------------------------------------------
                                    314 ; Home
                                    315 ;--------------------------------------------------------
                                    316 	.area HOME    (CODE)
                                    317 	.area HOME    (CODE)
      00000E                        318 __sdcc_program_startup:
      00000E 02 00 84         [24]  319 	ljmp	_main
                                    320 ;	return from main will return to caller
                                    321 ;--------------------------------------------------------
                                    322 ; code
                                    323 ;--------------------------------------------------------
                                    324 	.area CSEG    (CODE)
                                    325 ;------------------------------------------------------------
                                    326 ;Allocation info for local variables in function 'Producer'
                                    327 ;------------------------------------------------------------
                                    328 ;	testpreempt.c:26: void Producer(void)
                                    329 ;	-----------------------------------------
                                    330 ;	 function Producer
                                    331 ;	-----------------------------------------
      000014                        332 _Producer:
                           000007   333 	ar7 = 0x07
                           000006   334 	ar6 = 0x06
                           000005   335 	ar5 = 0x05
                           000004   336 	ar4 = 0x04
                           000003   337 	ar3 = 0x03
                           000002   338 	ar2 = 0x02
                           000001   339 	ar1 = 0x01
                           000000   340 	ar0 = 0x00
                                    341 ;	testpreempt.c:33: while (1)
      000014                        342 00111$:
                                    343 ;	testpreempt.c:38: tmp0 = b_end+1;
      000014 E5 2D            [12]  344 	mov	a,_b_end
      000016 04               [12]  345 	inc	a
      000017 F5 25            [12]  346 	mov	_tmp0,a
                                    347 ;	testpreempt.c:39: if (tmp0==16)tmp0=0;
      000019 74 10            [12]  348 	mov	a,#0x10
      00001B B5 25 03         [24]  349 	cjne	a,_tmp0,00103$
      00001E 75 25 00         [24]  350 	mov	_tmp0,#0x00
                                    351 ;	testpreempt.c:40: while (tmp0 == b_start){
      000021                        352 00103$:
      000021 E5 2C            [12]  353 	mov	a,_b_start
      000023 B5 25 02         [24]  354 	cjne	a,_tmp0,00141$
      000026 80 F9            [24]  355 	sjmp	00103$
      000028                        356 00141$:
                                    357 ;	testpreempt.c:43: EA = 0;
                                    358 ;	assignBit
      000028 C2 AF            [12]  359 	clr	_EA
                                    360 ;	testpreempt.c:44: buffer[b_end] = 'A'+in_counter;
      00002A E5 2D            [12]  361 	mov	a,_b_end
      00002C 24 30            [12]  362 	add	a,#_buffer
      00002E F9               [12]  363 	mov	r1,a
      00002F AF 2E            [24]  364 	mov	r7,_in_counter
      000031 74 41            [12]  365 	mov	a,#0x41
      000033 2F               [12]  366 	add	a,r7
      000034 F7               [12]  367 	mov	@r1,a
                                    368 ;	testpreempt.c:45: b_end++;
      000035 E5 2D            [12]  369 	mov	a,_b_end
      000037 04               [12]  370 	inc	a
      000038 F5 2D            [12]  371 	mov	_b_end,a
                                    372 ;	testpreempt.c:46: if (b_end==16)b_end=0;
      00003A 74 10            [12]  373 	mov	a,#0x10
      00003C B5 2D 03         [24]  374 	cjne	a,_b_end,00107$
      00003F 75 2D 00         [24]  375 	mov	_b_end,#0x00
      000042                        376 00107$:
                                    377 ;	testpreempt.c:47: in_counter++;
      000042 E5 2E            [12]  378 	mov	a,_in_counter
      000044 04               [12]  379 	inc	a
      000045 F5 2E            [12]  380 	mov	_in_counter,a
                                    381 ;	testpreempt.c:48: if (in_counter==26)in_counter=0;
      000047 74 1A            [12]  382 	mov	a,#0x1a
      000049 B5 2E 03         [24]  383 	cjne	a,_in_counter,00109$
      00004C 75 2E 00         [24]  384 	mov	_in_counter,#0x00
      00004F                        385 00109$:
                                    386 ;	testpreempt.c:49: EA = 1;
                                    387 ;	assignBit
      00004F D2 AF            [12]  388 	setb	_EA
                                    389 ;	testpreempt.c:51: }
      000051 80 C1            [24]  390 	sjmp	00111$
                                    391 ;------------------------------------------------------------
                                    392 ;Allocation info for local variables in function 'Consumer'
                                    393 ;------------------------------------------------------------
                                    394 ;	testpreempt.c:58: void Consumer(void)
                                    395 ;	-----------------------------------------
                                    396 ;	 function Consumer
                                    397 ;	-----------------------------------------
      000053                        398 _Consumer:
                                    399 ;	testpreempt.c:64: TMOD |= 0x20;
      000053 43 89 20         [24]  400 	orl	_TMOD,#0x20
                                    401 ;	testpreempt.c:65: TH1 = -6;//for buad (frequency)
      000056 75 8D FA         [24]  402 	mov	_TH1,#0xfa
                                    403 ;	testpreempt.c:66: SCON = 0x50;//for serial port
      000059 75 98 50         [24]  404 	mov	_SCON,#0x50
                                    405 ;	testpreempt.c:67: TR1 = 1;//start
                                    406 ;	assignBit
      00005C D2 8E            [12]  407 	setb	_TR1
                                    408 ;	testpreempt.c:75: while (b_start == b_end){
      00005E                        409 00101$:
      00005E E5 2D            [12]  410 	mov	a,_b_end
      000060 B5 2C 02         [24]  411 	cjne	a,_b_start,00134$
      000063 80 F9            [24]  412 	sjmp	00101$
      000065                        413 00134$:
                                    414 ;	testpreempt.c:78: EA = 0;
                                    415 ;	assignBit
      000065 C2 AF            [12]  416 	clr	_EA
                                    417 ;	testpreempt.c:85: SBUF = buffer[b_start];
      000067 E5 2C            [12]  418 	mov	a,_b_start
      000069 24 30            [12]  419 	add	a,#_buffer
      00006B F9               [12]  420 	mov	r1,a
      00006C 87 99            [24]  421 	mov	_SBUF,@r1
                                    422 ;	testpreempt.c:86: while (TI == 0);
      00006E                        423 00104$:
                                    424 ;	testpreempt.c:87: TI = 0; 
                                    425 ;	assignBit
      00006E 10 99 02         [24]  426 	jbc	_TI,00135$
      000071 80 FB            [24]  427 	sjmp	00104$
      000073                        428 00135$:
                                    429 ;	testpreempt.c:89: b_start++;
      000073 E5 2C            [12]  430 	mov	a,_b_start
      000075 04               [12]  431 	inc	a
      000076 F5 2C            [12]  432 	mov	_b_start,a
                                    433 ;	testpreempt.c:90: if (b_start==16)b_start=0;
      000078 74 10            [12]  434 	mov	a,#0x10
      00007A B5 2C 03         [24]  435 	cjne	a,_b_start,00108$
      00007D 75 2C 00         [24]  436 	mov	_b_start,#0x00
      000080                        437 00108$:
                                    438 ;	testpreempt.c:91: EA = 1;
                                    439 ;	assignBit
      000080 D2 AF            [12]  440 	setb	_EA
                                    441 ;	testpreempt.c:93: }
      000082 80 DA            [24]  442 	sjmp	00101$
                                    443 ;------------------------------------------------------------
                                    444 ;Allocation info for local variables in function 'main'
                                    445 ;------------------------------------------------------------
                                    446 ;	testpreempt.c:100: void main(void)
                                    447 ;	-----------------------------------------
                                    448 ;	 function main
                                    449 ;	-----------------------------------------
      000084                        450 _main:
                                    451 ;	testpreempt.c:106: b_start = b_end = 0;
      000084 75 2D 00         [24]  452 	mov	_b_end,#0x00
      000087 75 2C 00         [24]  453 	mov	_b_start,#0x00
                                    454 ;	testpreempt.c:107: in_counter = 0;
      00008A 75 2E 00         [24]  455 	mov	_in_counter,#0x00
                                    456 ;	testpreempt.c:114: ThreadCreate(Producer);
      00008D 90 00 14         [24]  457 	mov	dptr,#_Producer
      000090 12 00 D9         [24]  458 	lcall	_ThreadCreate
                                    459 ;	testpreempt.c:115: ThreadCreate(Consumer);
      000093 90 00 53         [24]  460 	mov	dptr,#_Consumer
      000096 12 00 D9         [24]  461 	lcall	_ThreadCreate
                                    462 ;	testpreempt.c:116: ThreadExit();
                                    463 ;	testpreempt.c:117: }
      000099 02 01 B4         [24]  464 	ljmp	_ThreadExit
                                    465 ;------------------------------------------------------------
                                    466 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                    467 ;------------------------------------------------------------
                                    468 ;	testpreempt.c:119: void _sdcc_gsinit_startup(void)
                                    469 ;	-----------------------------------------
                                    470 ;	 function _sdcc_gsinit_startup
                                    471 ;	-----------------------------------------
      00009C                        472 __sdcc_gsinit_startup:
                                    473 ;	testpreempt.c:123: __endasm;
      00009C 02 00 A7         [24]  474 	LJMP	_Bootstrap
                                    475 ;	testpreempt.c:124: }
      00009F 22               [24]  476 	ret
                                    477 ;------------------------------------------------------------
                                    478 ;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
                                    479 ;------------------------------------------------------------
                                    480 ;	testpreempt.c:126: void _mcs51_genRAMCLEAR(void) {}
                                    481 ;	-----------------------------------------
                                    482 ;	 function _mcs51_genRAMCLEAR
                                    483 ;	-----------------------------------------
      0000A0                        484 __mcs51_genRAMCLEAR:
      0000A0 22               [24]  485 	ret
                                    486 ;------------------------------------------------------------
                                    487 ;Allocation info for local variables in function '_mcs51_genXINIT'
                                    488 ;------------------------------------------------------------
                                    489 ;	testpreempt.c:127: void _mcs51_genXINIT(void) {}
                                    490 ;	-----------------------------------------
                                    491 ;	 function _mcs51_genXINIT
                                    492 ;	-----------------------------------------
      0000A1                        493 __mcs51_genXINIT:
      0000A1 22               [24]  494 	ret
                                    495 ;------------------------------------------------------------
                                    496 ;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
                                    497 ;------------------------------------------------------------
                                    498 ;	testpreempt.c:128: void _mcs51_genXRAMCLEAR(void) {}
                                    499 ;	-----------------------------------------
                                    500 ;	 function _mcs51_genXRAMCLEAR
                                    501 ;	-----------------------------------------
      0000A2                        502 __mcs51_genXRAMCLEAR:
      0000A2 22               [24]  503 	ret
                                    504 ;------------------------------------------------------------
                                    505 ;Allocation info for local variables in function 'timer0_ISR'
                                    506 ;------------------------------------------------------------
                                    507 ;	testpreempt.c:130: void timer0_ISR(void) __interrupt(1) {
                                    508 ;	-----------------------------------------
                                    509 ;	 function timer0_ISR
                                    510 ;	-----------------------------------------
      0000A3                        511 _timer0_ISR:
                                    512 ;	testpreempt.c:133: __endasm;
      0000A3 02 02 0D         [24]  513 	ljmp	_myTimer0Handler
                                    514 ;	testpreempt.c:134: }
      0000A6 32               [24]  515 	reti
                                    516 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    517 ;	eliminated unneeded push/pop psw
                                    518 ;	eliminated unneeded push/pop dpl
                                    519 ;	eliminated unneeded push/pop dph
                                    520 ;	eliminated unneeded push/pop b
                                    521 ;	eliminated unneeded push/pop acc
                                    522 	.area CSEG    (CODE)
                                    523 	.area CONST   (CODE)
                                    524 	.area XINIT   (CODE)
                                    525 	.area CABS    (ABS,CODE)
