                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module buttonlib
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CY
                                     12 	.globl _AC
                                     13 	.globl _F0
                                     14 	.globl _RS1
                                     15 	.globl _RS0
                                     16 	.globl _OV
                                     17 	.globl _F1
                                     18 	.globl _P
                                     19 	.globl _PS
                                     20 	.globl _PT1
                                     21 	.globl _PX1
                                     22 	.globl _PT0
                                     23 	.globl _PX0
                                     24 	.globl _RD
                                     25 	.globl _WR
                                     26 	.globl _T1
                                     27 	.globl _T0
                                     28 	.globl _INT1
                                     29 	.globl _INT0
                                     30 	.globl _TXD
                                     31 	.globl _RXD
                                     32 	.globl _P3_7
                                     33 	.globl _P3_6
                                     34 	.globl _P3_5
                                     35 	.globl _P3_4
                                     36 	.globl _P3_3
                                     37 	.globl _P3_2
                                     38 	.globl _P3_1
                                     39 	.globl _P3_0
                                     40 	.globl _EA
                                     41 	.globl _ES
                                     42 	.globl _ET1
                                     43 	.globl _EX1
                                     44 	.globl _ET0
                                     45 	.globl _EX0
                                     46 	.globl _P2_7
                                     47 	.globl _P2_6
                                     48 	.globl _P2_5
                                     49 	.globl _P2_4
                                     50 	.globl _P2_3
                                     51 	.globl _P2_2
                                     52 	.globl _P2_1
                                     53 	.globl _P2_0
                                     54 	.globl _SM0
                                     55 	.globl _SM1
                                     56 	.globl _SM2
                                     57 	.globl _REN
                                     58 	.globl _TB8
                                     59 	.globl _RB8
                                     60 	.globl _TI
                                     61 	.globl _RI
                                     62 	.globl _P1_7
                                     63 	.globl _P1_6
                                     64 	.globl _P1_5
                                     65 	.globl _P1_4
                                     66 	.globl _P1_3
                                     67 	.globl _P1_2
                                     68 	.globl _P1_1
                                     69 	.globl _P1_0
                                     70 	.globl _TF1
                                     71 	.globl _TR1
                                     72 	.globl _TF0
                                     73 	.globl _TR0
                                     74 	.globl _IE1
                                     75 	.globl _IT1
                                     76 	.globl _IE0
                                     77 	.globl _IT0
                                     78 	.globl _P0_7
                                     79 	.globl _P0_6
                                     80 	.globl _P0_5
                                     81 	.globl _P0_4
                                     82 	.globl _P0_3
                                     83 	.globl _P0_2
                                     84 	.globl _P0_1
                                     85 	.globl _P0_0
                                     86 	.globl _B
                                     87 	.globl _ACC
                                     88 	.globl _PSW
                                     89 	.globl _IP
                                     90 	.globl _P3
                                     91 	.globl _IE
                                     92 	.globl _P2
                                     93 	.globl _SBUF
                                     94 	.globl _SCON
                                     95 	.globl _P1
                                     96 	.globl _TH1
                                     97 	.globl _TH0
                                     98 	.globl _TL1
                                     99 	.globl _TL0
                                    100 	.globl _TMOD
                                    101 	.globl _TCON
                                    102 	.globl _PCON
                                    103 	.globl _DPH
                                    104 	.globl _DPL
                                    105 	.globl _SP
                                    106 	.globl _P0
                                    107 	.globl _AnyButtonPressed
                                    108 	.globl _ButtonToChar
                                    109 ;--------------------------------------------------------
                                    110 ; special function registers
                                    111 ;--------------------------------------------------------
                                    112 	.area RSEG    (ABS,DATA)
      000000                        113 	.org 0x0000
                           000080   114 _P0	=	0x0080
                           000081   115 _SP	=	0x0081
                           000082   116 _DPL	=	0x0082
                           000083   117 _DPH	=	0x0083
                           000087   118 _PCON	=	0x0087
                           000088   119 _TCON	=	0x0088
                           000089   120 _TMOD	=	0x0089
                           00008A   121 _TL0	=	0x008a
                           00008B   122 _TL1	=	0x008b
                           00008C   123 _TH0	=	0x008c
                           00008D   124 _TH1	=	0x008d
                           000090   125 _P1	=	0x0090
                           000098   126 _SCON	=	0x0098
                           000099   127 _SBUF	=	0x0099
                           0000A0   128 _P2	=	0x00a0
                           0000A8   129 _IE	=	0x00a8
                           0000B0   130 _P3	=	0x00b0
                           0000B8   131 _IP	=	0x00b8
                           0000D0   132 _PSW	=	0x00d0
                           0000E0   133 _ACC	=	0x00e0
                           0000F0   134 _B	=	0x00f0
                                    135 ;--------------------------------------------------------
                                    136 ; special function bits
                                    137 ;--------------------------------------------------------
                                    138 	.area RSEG    (ABS,DATA)
      000000                        139 	.org 0x0000
                           000080   140 _P0_0	=	0x0080
                           000081   141 _P0_1	=	0x0081
                           000082   142 _P0_2	=	0x0082
                           000083   143 _P0_3	=	0x0083
                           000084   144 _P0_4	=	0x0084
                           000085   145 _P0_5	=	0x0085
                           000086   146 _P0_6	=	0x0086
                           000087   147 _P0_7	=	0x0087
                           000088   148 _IT0	=	0x0088
                           000089   149 _IE0	=	0x0089
                           00008A   150 _IT1	=	0x008a
                           00008B   151 _IE1	=	0x008b
                           00008C   152 _TR0	=	0x008c
                           00008D   153 _TF0	=	0x008d
                           00008E   154 _TR1	=	0x008e
                           00008F   155 _TF1	=	0x008f
                           000090   156 _P1_0	=	0x0090
                           000091   157 _P1_1	=	0x0091
                           000092   158 _P1_2	=	0x0092
                           000093   159 _P1_3	=	0x0093
                           000094   160 _P1_4	=	0x0094
                           000095   161 _P1_5	=	0x0095
                           000096   162 _P1_6	=	0x0096
                           000097   163 _P1_7	=	0x0097
                           000098   164 _RI	=	0x0098
                           000099   165 _TI	=	0x0099
                           00009A   166 _RB8	=	0x009a
                           00009B   167 _TB8	=	0x009b
                           00009C   168 _REN	=	0x009c
                           00009D   169 _SM2	=	0x009d
                           00009E   170 _SM1	=	0x009e
                           00009F   171 _SM0	=	0x009f
                           0000A0   172 _P2_0	=	0x00a0
                           0000A1   173 _P2_1	=	0x00a1
                           0000A2   174 _P2_2	=	0x00a2
                           0000A3   175 _P2_3	=	0x00a3
                           0000A4   176 _P2_4	=	0x00a4
                           0000A5   177 _P2_5	=	0x00a5
                           0000A6   178 _P2_6	=	0x00a6
                           0000A7   179 _P2_7	=	0x00a7
                           0000A8   180 _EX0	=	0x00a8
                           0000A9   181 _ET0	=	0x00a9
                           0000AA   182 _EX1	=	0x00aa
                           0000AB   183 _ET1	=	0x00ab
                           0000AC   184 _ES	=	0x00ac
                           0000AF   185 _EA	=	0x00af
                           0000B0   186 _P3_0	=	0x00b0
                           0000B1   187 _P3_1	=	0x00b1
                           0000B2   188 _P3_2	=	0x00b2
                           0000B3   189 _P3_3	=	0x00b3
                           0000B4   190 _P3_4	=	0x00b4
                           0000B5   191 _P3_5	=	0x00b5
                           0000B6   192 _P3_6	=	0x00b6
                           0000B7   193 _P3_7	=	0x00b7
                           0000B0   194 _RXD	=	0x00b0
                           0000B1   195 _TXD	=	0x00b1
                           0000B2   196 _INT0	=	0x00b2
                           0000B3   197 _INT1	=	0x00b3
                           0000B4   198 _T0	=	0x00b4
                           0000B5   199 _T1	=	0x00b5
                           0000B6   200 _WR	=	0x00b6
                           0000B7   201 _RD	=	0x00b7
                           0000B8   202 _PX0	=	0x00b8
                           0000B9   203 _PT0	=	0x00b9
                           0000BA   204 _PX1	=	0x00ba
                           0000BB   205 _PT1	=	0x00bb
                           0000BC   206 _PS	=	0x00bc
                           0000D0   207 _P	=	0x00d0
                           0000D1   208 _F1	=	0x00d1
                           0000D2   209 _OV	=	0x00d2
                           0000D3   210 _RS0	=	0x00d3
                           0000D4   211 _RS1	=	0x00d4
                           0000D5   212 _F0	=	0x00d5
                           0000D6   213 _AC	=	0x00d6
                           0000D7   214 _CY	=	0x00d7
                                    215 ;--------------------------------------------------------
                                    216 ; overlayable register banks
                                    217 ;--------------------------------------------------------
                                    218 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        219 	.ds 8
                                    220 ;--------------------------------------------------------
                                    221 ; internal ram data
                                    222 ;--------------------------------------------------------
                                    223 	.area DSEG    (DATA)
                                    224 ;--------------------------------------------------------
                                    225 ; overlayable items in internal ram 
                                    226 ;--------------------------------------------------------
                                    227 ;--------------------------------------------------------
                                    228 ; indirectly addressable internal ram data
                                    229 ;--------------------------------------------------------
                                    230 	.area ISEG    (DATA)
                                    231 ;--------------------------------------------------------
                                    232 ; absolute internal ram data
                                    233 ;--------------------------------------------------------
                                    234 	.area IABS    (ABS,DATA)
                                    235 	.area IABS    (ABS,DATA)
                                    236 ;--------------------------------------------------------
                                    237 ; bit data
                                    238 ;--------------------------------------------------------
                                    239 	.area BSEG    (BIT)
                                    240 ;--------------------------------------------------------
                                    241 ; paged external ram data
                                    242 ;--------------------------------------------------------
                                    243 	.area PSEG    (PAG,XDATA)
                                    244 ;--------------------------------------------------------
                                    245 ; external ram data
                                    246 ;--------------------------------------------------------
                                    247 	.area XSEG    (XDATA)
                                    248 ;--------------------------------------------------------
                                    249 ; absolute external ram data
                                    250 ;--------------------------------------------------------
                                    251 	.area XABS    (ABS,XDATA)
                                    252 ;--------------------------------------------------------
                                    253 ; external initialized ram data
                                    254 ;--------------------------------------------------------
                                    255 	.area XISEG   (XDATA)
                                    256 	.area HOME    (CODE)
                                    257 	.area GSINIT0 (CODE)
                                    258 	.area GSINIT1 (CODE)
                                    259 	.area GSINIT2 (CODE)
                                    260 	.area GSINIT3 (CODE)
                                    261 	.area GSINIT4 (CODE)
                                    262 	.area GSINIT5 (CODE)
                                    263 	.area GSINIT  (CODE)
                                    264 	.area GSFINAL (CODE)
                                    265 	.area CSEG    (CODE)
                                    266 ;--------------------------------------------------------
                                    267 ; global & static initialisations
                                    268 ;--------------------------------------------------------
                                    269 	.area HOME    (CODE)
                                    270 	.area GSINIT  (CODE)
                                    271 	.area GSFINAL (CODE)
                                    272 	.area GSINIT  (CODE)
                                    273 ;--------------------------------------------------------
                                    274 ; Home
                                    275 ;--------------------------------------------------------
                                    276 	.area HOME    (CODE)
                                    277 	.area HOME    (CODE)
                                    278 ;--------------------------------------------------------
                                    279 ; code
                                    280 ;--------------------------------------------------------
                                    281 	.area CSEG    (CODE)
                                    282 ;------------------------------------------------------------
                                    283 ;Allocation info for local variables in function 'AnyButtonPressed'
                                    284 ;------------------------------------------------------------
                                    285 ;	buttonlib.c:10: char AnyButtonPressed(void) {
                                    286 ;	-----------------------------------------
                                    287 ;	 function AnyButtonPressed
                                    288 ;	-----------------------------------------
      0003E3                        289 _AnyButtonPressed:
                           000007   290 	ar7 = 0x07
                           000006   291 	ar6 = 0x06
                           000005   292 	ar5 = 0x05
                           000004   293 	ar4 = 0x04
                           000003   294 	ar3 = 0x03
                           000002   295 	ar2 = 0x02
                           000001   296 	ar1 = 0x01
                           000000   297 	ar0 = 0x00
                                    298 ;	buttonlib.c:11: return !(P2==0xFF);/* @@@ Your code here. returns true  if any bits of P2 is 0; false otherwise.. */;
      0003E3 74 FF            [12]  299 	mov	a,#0xff
      0003E5 B5 A0 04         [24]  300 	cjne	a,_P2,00103$
      0003E8 74 01            [12]  301 	mov	a,#0x01
      0003EA 80 01            [24]  302 	sjmp	00104$
      0003EC                        303 00103$:
      0003EC E4               [12]  304 	clr	a
      0003ED                        305 00104$:
      0003ED B4 01 00         [24]  306 	cjne	a,#0x01,00105$
      0003F0                        307 00105$:
      0003F0 E4               [12]  308 	clr	a
      0003F1 33               [12]  309 	rlc	a
                                    310 ;	buttonlib.c:12: }
      0003F2 F5 82            [12]  311 	mov	dpl,a
      0003F4 22               [24]  312 	ret
                                    313 ;------------------------------------------------------------
                                    314 ;Allocation info for local variables in function 'ButtonToChar'
                                    315 ;------------------------------------------------------------
                                    316 ;	buttonlib.c:17: char ButtonToChar(void) {
                                    317 ;	-----------------------------------------
                                    318 ;	 function ButtonToChar
                                    319 ;	-----------------------------------------
      0003F5                        320 _ButtonToChar:
                                    321 ;	buttonlib.c:18: if ((~P2) & 0x80) {
      0003F5 AE A0            [24]  322 	mov	r6,_P2
      0003F7 7F 00            [12]  323 	mov	r7,#0x00
      0003F9 EE               [12]  324 	mov	a,r6
      0003FA F4               [12]  325 	cpl	a
      0003FB FE               [12]  326 	mov	r6,a
      0003FC EF               [12]  327 	mov	a,r7
      0003FD F4               [12]  328 	cpl	a
      0003FE EE               [12]  329 	mov	a,r6
      0003FF 30 E7 04         [24]  330 	jnb	acc.7,00123$
                                    331 ;	buttonlib.c:19: return '7';
      000402 75 82 37         [24]  332 	mov	dpl,#0x37
      000405 22               [24]  333 	ret
      000406                        334 00123$:
                                    335 ;	buttonlib.c:20: }else if((~P2) & 0x40) {
      000406 AE A0            [24]  336 	mov	r6,_P2
      000408 7F 00            [12]  337 	mov	r7,#0x00
      00040A EE               [12]  338 	mov	a,r6
      00040B F4               [12]  339 	cpl	a
      00040C FE               [12]  340 	mov	r6,a
      00040D EF               [12]  341 	mov	a,r7
      00040E F4               [12]  342 	cpl	a
      00040F EE               [12]  343 	mov	a,r6
      000410 30 E6 04         [24]  344 	jnb	acc.6,00120$
                                    345 ;	buttonlib.c:21: return '6';
      000413 75 82 36         [24]  346 	mov	dpl,#0x36
      000416 22               [24]  347 	ret
      000417                        348 00120$:
                                    349 ;	buttonlib.c:22: }else if((~P2) & 0x20) {
      000417 AE A0            [24]  350 	mov	r6,_P2
      000419 7F 00            [12]  351 	mov	r7,#0x00
      00041B EE               [12]  352 	mov	a,r6
      00041C F4               [12]  353 	cpl	a
      00041D FE               [12]  354 	mov	r6,a
      00041E EF               [12]  355 	mov	a,r7
      00041F F4               [12]  356 	cpl	a
      000420 EE               [12]  357 	mov	a,r6
      000421 30 E5 04         [24]  358 	jnb	acc.5,00117$
                                    359 ;	buttonlib.c:23: return '5';
      000424 75 82 35         [24]  360 	mov	dpl,#0x35
      000427 22               [24]  361 	ret
      000428                        362 00117$:
                                    363 ;	buttonlib.c:24: }else if((~P2) & 0x10) {
      000428 AE A0            [24]  364 	mov	r6,_P2
      00042A 7F 00            [12]  365 	mov	r7,#0x00
      00042C EE               [12]  366 	mov	a,r6
      00042D F4               [12]  367 	cpl	a
      00042E FE               [12]  368 	mov	r6,a
      00042F EF               [12]  369 	mov	a,r7
      000430 F4               [12]  370 	cpl	a
      000431 EE               [12]  371 	mov	a,r6
      000432 30 E4 04         [24]  372 	jnb	acc.4,00114$
                                    373 ;	buttonlib.c:25: return '4';
      000435 75 82 34         [24]  374 	mov	dpl,#0x34
      000438 22               [24]  375 	ret
      000439                        376 00114$:
                                    377 ;	buttonlib.c:26: }else if((~P2) & 0x08) {
      000439 AE A0            [24]  378 	mov	r6,_P2
      00043B 7F 00            [12]  379 	mov	r7,#0x00
      00043D EE               [12]  380 	mov	a,r6
      00043E F4               [12]  381 	cpl	a
      00043F FE               [12]  382 	mov	r6,a
      000440 EF               [12]  383 	mov	a,r7
      000441 F4               [12]  384 	cpl	a
      000442 EE               [12]  385 	mov	a,r6
      000443 30 E3 04         [24]  386 	jnb	acc.3,00111$
                                    387 ;	buttonlib.c:27: return '3';
      000446 75 82 33         [24]  388 	mov	dpl,#0x33
      000449 22               [24]  389 	ret
      00044A                        390 00111$:
                                    391 ;	buttonlib.c:28: }else if((~P2) & 0x04) {
      00044A AE A0            [24]  392 	mov	r6,_P2
      00044C 7F 00            [12]  393 	mov	r7,#0x00
      00044E EE               [12]  394 	mov	a,r6
      00044F F4               [12]  395 	cpl	a
      000450 FE               [12]  396 	mov	r6,a
      000451 EF               [12]  397 	mov	a,r7
      000452 F4               [12]  398 	cpl	a
      000453 EE               [12]  399 	mov	a,r6
      000454 30 E2 04         [24]  400 	jnb	acc.2,00108$
                                    401 ;	buttonlib.c:29: return '2';
      000457 75 82 32         [24]  402 	mov	dpl,#0x32
      00045A 22               [24]  403 	ret
      00045B                        404 00108$:
                                    405 ;	buttonlib.c:30: }else if((~P2) & 0x02) {
      00045B AE A0            [24]  406 	mov	r6,_P2
      00045D 7F 00            [12]  407 	mov	r7,#0x00
      00045F EE               [12]  408 	mov	a,r6
      000460 F4               [12]  409 	cpl	a
      000461 FE               [12]  410 	mov	r6,a
      000462 EF               [12]  411 	mov	a,r7
      000463 F4               [12]  412 	cpl	a
      000464 EE               [12]  413 	mov	a,r6
      000465 30 E1 04         [24]  414 	jnb	acc.1,00105$
                                    415 ;	buttonlib.c:31: return '1';
      000468 75 82 31         [24]  416 	mov	dpl,#0x31
      00046B 22               [24]  417 	ret
      00046C                        418 00105$:
                                    419 ;	buttonlib.c:32: }else if((~P2) & 0x01) {
      00046C AE A0            [24]  420 	mov	r6,_P2
      00046E 7F 00            [12]  421 	mov	r7,#0x00
      000470 EE               [12]  422 	mov	a,r6
      000471 F4               [12]  423 	cpl	a
      000472 FE               [12]  424 	mov	r6,a
      000473 EF               [12]  425 	mov	a,r7
      000474 F4               [12]  426 	cpl	a
      000475 EE               [12]  427 	mov	a,r6
      000476 30 E0 04         [24]  428 	jnb	acc.0,00102$
                                    429 ;	buttonlib.c:33: return '0';
      000479 75 82 30         [24]  430 	mov	dpl,#0x30
      00047C 22               [24]  431 	ret
      00047D                        432 00102$:
                                    433 ;	buttonlib.c:35: return 0;
      00047D 75 82 00         [24]  434 	mov	dpl,#0x00
                                    435 ;	buttonlib.c:38: }
      000480 22               [24]  436 	ret
                                    437 	.area CSEG    (CODE)
                                    438 	.area CONST   (CODE)
                                    439 	.area XINIT   (CODE)
                                    440 	.area CABS    (ABS,CODE)
