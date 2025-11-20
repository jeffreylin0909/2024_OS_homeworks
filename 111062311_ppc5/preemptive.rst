                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module preemptive
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Bootstrap
                                     12 	.globl _main
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _bitmap
                                    110 	.globl _tmp2
                                    111 	.globl _tmp1
                                    112 	.globl _tmp0
                                    113 	.globl _current_T
                                    114 	.globl _T_SP
                                    115 	.globl _ThreadCreate
                                    116 	.globl _ThreadYield
                                    117 	.globl _ThreadExit
                                    118 	.globl _myTimer0Handler
                                    119 ;--------------------------------------------------------
                                    120 ; special function registers
                                    121 ;--------------------------------------------------------
                                    122 	.area RSEG    (ABS,DATA)
      000000                        123 	.org 0x0000
                           000080   124 _P0	=	0x0080
                           000081   125 _SP	=	0x0081
                           000082   126 _DPL	=	0x0082
                           000083   127 _DPH	=	0x0083
                           000087   128 _PCON	=	0x0087
                           000088   129 _TCON	=	0x0088
                           000089   130 _TMOD	=	0x0089
                           00008A   131 _TL0	=	0x008a
                           00008B   132 _TL1	=	0x008b
                           00008C   133 _TH0	=	0x008c
                           00008D   134 _TH1	=	0x008d
                           000090   135 _P1	=	0x0090
                           000098   136 _SCON	=	0x0098
                           000099   137 _SBUF	=	0x0099
                           0000A0   138 _P2	=	0x00a0
                           0000A8   139 _IE	=	0x00a8
                           0000B0   140 _P3	=	0x00b0
                           0000B8   141 _IP	=	0x00b8
                           0000D0   142 _PSW	=	0x00d0
                           0000E0   143 _ACC	=	0x00e0
                           0000F0   144 _B	=	0x00f0
                                    145 ;--------------------------------------------------------
                                    146 ; special function bits
                                    147 ;--------------------------------------------------------
                                    148 	.area RSEG    (ABS,DATA)
      000000                        149 	.org 0x0000
                           000080   150 _P0_0	=	0x0080
                           000081   151 _P0_1	=	0x0081
                           000082   152 _P0_2	=	0x0082
                           000083   153 _P0_3	=	0x0083
                           000084   154 _P0_4	=	0x0084
                           000085   155 _P0_5	=	0x0085
                           000086   156 _P0_6	=	0x0086
                           000087   157 _P0_7	=	0x0087
                           000088   158 _IT0	=	0x0088
                           000089   159 _IE0	=	0x0089
                           00008A   160 _IT1	=	0x008a
                           00008B   161 _IE1	=	0x008b
                           00008C   162 _TR0	=	0x008c
                           00008D   163 _TF0	=	0x008d
                           00008E   164 _TR1	=	0x008e
                           00008F   165 _TF1	=	0x008f
                           000090   166 _P1_0	=	0x0090
                           000091   167 _P1_1	=	0x0091
                           000092   168 _P1_2	=	0x0092
                           000093   169 _P1_3	=	0x0093
                           000094   170 _P1_4	=	0x0094
                           000095   171 _P1_5	=	0x0095
                           000096   172 _P1_6	=	0x0096
                           000097   173 _P1_7	=	0x0097
                           000098   174 _RI	=	0x0098
                           000099   175 _TI	=	0x0099
                           00009A   176 _RB8	=	0x009a
                           00009B   177 _TB8	=	0x009b
                           00009C   178 _REN	=	0x009c
                           00009D   179 _SM2	=	0x009d
                           00009E   180 _SM1	=	0x009e
                           00009F   181 _SM0	=	0x009f
                           0000A0   182 _P2_0	=	0x00a0
                           0000A1   183 _P2_1	=	0x00a1
                           0000A2   184 _P2_2	=	0x00a2
                           0000A3   185 _P2_3	=	0x00a3
                           0000A4   186 _P2_4	=	0x00a4
                           0000A5   187 _P2_5	=	0x00a5
                           0000A6   188 _P2_6	=	0x00a6
                           0000A7   189 _P2_7	=	0x00a7
                           0000A8   190 _EX0	=	0x00a8
                           0000A9   191 _ET0	=	0x00a9
                           0000AA   192 _EX1	=	0x00aa
                           0000AB   193 _ET1	=	0x00ab
                           0000AC   194 _ES	=	0x00ac
                           0000AF   195 _EA	=	0x00af
                           0000B0   196 _P3_0	=	0x00b0
                           0000B1   197 _P3_1	=	0x00b1
                           0000B2   198 _P3_2	=	0x00b2
                           0000B3   199 _P3_3	=	0x00b3
                           0000B4   200 _P3_4	=	0x00b4
                           0000B5   201 _P3_5	=	0x00b5
                           0000B6   202 _P3_6	=	0x00b6
                           0000B7   203 _P3_7	=	0x00b7
                           0000B0   204 _RXD	=	0x00b0
                           0000B1   205 _TXD	=	0x00b1
                           0000B2   206 _INT0	=	0x00b2
                           0000B3   207 _INT1	=	0x00b3
                           0000B4   208 _T0	=	0x00b4
                           0000B5   209 _T1	=	0x00b5
                           0000B6   210 _WR	=	0x00b6
                           0000B7   211 _RD	=	0x00b7
                           0000B8   212 _PX0	=	0x00b8
                           0000B9   213 _PT0	=	0x00b9
                           0000BA   214 _PX1	=	0x00ba
                           0000BB   215 _PT1	=	0x00bb
                           0000BC   216 _PS	=	0x00bc
                           0000D0   217 _P	=	0x00d0
                           0000D1   218 _F1	=	0x00d1
                           0000D2   219 _OV	=	0x00d2
                           0000D3   220 _RS0	=	0x00d3
                           0000D4   221 _RS1	=	0x00d4
                           0000D5   222 _F0	=	0x00d5
                           0000D6   223 _AC	=	0x00d6
                           0000D7   224 _CY	=	0x00d7
                                    225 ;--------------------------------------------------------
                                    226 ; overlayable register banks
                                    227 ;--------------------------------------------------------
                                    228 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        229 	.ds 8
                                    230 ;--------------------------------------------------------
                                    231 ; internal ram data
                                    232 ;--------------------------------------------------------
                                    233 	.area DSEG    (DATA)
                           000020   234 _T_SP	=	0x0020
                           000024   235 _current_T	=	0x0024
                           000025   236 _tmp0	=	0x0025
                           000026   237 _tmp1	=	0x0026
                           000027   238 _tmp2	=	0x0027
                           000028   239 _bitmap	=	0x0028
                                    240 ;--------------------------------------------------------
                                    241 ; overlayable items in internal ram 
                                    242 ;--------------------------------------------------------
                                    243 	.area	OSEG    (OVR,DATA)
                                    244 ;--------------------------------------------------------
                                    245 ; indirectly addressable internal ram data
                                    246 ;--------------------------------------------------------
                                    247 	.area ISEG    (DATA)
                                    248 ;--------------------------------------------------------
                                    249 ; absolute internal ram data
                                    250 ;--------------------------------------------------------
                                    251 	.area IABS    (ABS,DATA)
                                    252 	.area IABS    (ABS,DATA)
                                    253 ;--------------------------------------------------------
                                    254 ; bit data
                                    255 ;--------------------------------------------------------
                                    256 	.area BSEG    (BIT)
                                    257 ;--------------------------------------------------------
                                    258 ; paged external ram data
                                    259 ;--------------------------------------------------------
                                    260 	.area PSEG    (PAG,XDATA)
                                    261 ;--------------------------------------------------------
                                    262 ; external ram data
                                    263 ;--------------------------------------------------------
                                    264 	.area XSEG    (XDATA)
                                    265 ;--------------------------------------------------------
                                    266 ; absolute external ram data
                                    267 ;--------------------------------------------------------
                                    268 	.area XABS    (ABS,XDATA)
                                    269 ;--------------------------------------------------------
                                    270 ; external initialized ram data
                                    271 ;--------------------------------------------------------
                                    272 	.area XISEG   (XDATA)
                                    273 	.area HOME    (CODE)
                                    274 	.area GSINIT0 (CODE)
                                    275 	.area GSINIT1 (CODE)
                                    276 	.area GSINIT2 (CODE)
                                    277 	.area GSINIT3 (CODE)
                                    278 	.area GSINIT4 (CODE)
                                    279 	.area GSINIT5 (CODE)
                                    280 	.area GSINIT  (CODE)
                                    281 	.area GSFINAL (CODE)
                                    282 	.area CSEG    (CODE)
                                    283 ;--------------------------------------------------------
                                    284 ; global & static initialisations
                                    285 ;--------------------------------------------------------
                                    286 	.area HOME    (CODE)
                                    287 	.area GSINIT  (CODE)
                                    288 	.area GSFINAL (CODE)
                                    289 	.area GSINIT  (CODE)
                                    290 ;--------------------------------------------------------
                                    291 ; Home
                                    292 ;--------------------------------------------------------
                                    293 	.area HOME    (CODE)
                                    294 	.area HOME    (CODE)
                                    295 ;--------------------------------------------------------
                                    296 ; code
                                    297 ;--------------------------------------------------------
                                    298 	.area CSEG    (CODE)
                                    299 ;------------------------------------------------------------
                                    300 ;Allocation info for local variables in function 'Bootstrap'
                                    301 ;------------------------------------------------------------
                                    302 ;	preemptive.c:80: void Bootstrap(void)
                                    303 ;	-----------------------------------------
                                    304 ;	 function Bootstrap
                                    305 ;	-----------------------------------------
      000161                        306 _Bootstrap:
                           000007   307 	ar7 = 0x07
                           000006   308 	ar6 = 0x06
                           000005   309 	ar5 = 0x05
                           000004   310 	ar4 = 0x04
                           000003   311 	ar3 = 0x03
                           000002   312 	ar2 = 0x02
                           000001   313 	ar1 = 0x01
                           000000   314 	ar0 = 0x00
                                    315 ;	preemptive.c:94: T_SP[0] = 0x3F;
      000161 75 20 3F         [24]  316 	mov	_T_SP,#0x3f
                                    317 ;	preemptive.c:95: T_SP[1] = 0x4F;
      000164 75 21 4F         [24]  318 	mov	(_T_SP + 0x0001),#0x4f
                                    319 ;	preemptive.c:96: T_SP[2] = 0x5F;
      000167 75 22 5F         [24]  320 	mov	(_T_SP + 0x0002),#0x5f
                                    321 ;	preemptive.c:97: T_SP[3] = 0x6F;
      00016A 75 23 6F         [24]  322 	mov	(_T_SP + 0x0003),#0x6f
                                    323 ;	preemptive.c:98: bitmap = 0b0000;
      00016D 75 28 00         [24]  324 	mov	_bitmap,#0x00
                                    325 ;	preemptive.c:100: TMOD = 0;
      000170 75 89 00         [24]  326 	mov	_TMOD,#0x00
                                    327 ;	preemptive.c:101: IE = 0x82;//10000010
      000173 75 A8 82         [24]  328 	mov	_IE,#0x82
                                    329 ;	preemptive.c:103: TR0 = 1;
                                    330 ;	assignBit
      000176 D2 8C            [12]  331 	setb	_TR0
                                    332 ;	preemptive.c:105: current_T = ThreadCreate(main);
      000178 90 01 2C         [24]  333 	mov	dptr,#_main
      00017B 12 01 93         [24]  334 	lcall	_ThreadCreate
      00017E 85 82 24         [24]  335 	mov	_current_T,dpl
                                    336 ;	preemptive.c:106: RESTORESTATE;
      000181 E5 24            [12]  337 	mov	a,_current_T
      000183 24 20            [12]  338 	add	a,#_T_SP
      000185 F9               [12]  339 	mov	r1,a
      000186 87 81            [24]  340 	mov	_SP,@r1
      000188 D0 D0            [24]  341 	POP PSW 
      00018A D0 83            [24]  342 	POP DPH 
      00018C D0 82            [24]  343 	POP DPL 
      00018E D0 F0            [24]  344 	POP B 
      000190 D0 E0            [24]  345 	POP A 
                                    346 ;	preemptive.c:107: return;
                                    347 ;	preemptive.c:108: }
      000192 22               [24]  348 	ret
                                    349 ;------------------------------------------------------------
                                    350 ;Allocation info for local variables in function 'ThreadCreate'
                                    351 ;------------------------------------------------------------
                                    352 ;fp                        Allocated to registers 
                                    353 ;------------------------------------------------------------
                                    354 ;	preemptive.c:116: ThreadID ThreadCreate(FunctionPtr fp)
                                    355 ;	-----------------------------------------
                                    356 ;	 function ThreadCreate
                                    357 ;	-----------------------------------------
      000193                        358 _ThreadCreate:
                                    359 ;	preemptive.c:118: EA = 0;
                                    360 ;	assignBit
      000193 C2 AF            [12]  361 	clr	_EA
                                    362 ;	preemptive.c:124: tmp2 = 0;
      000195 75 27 00         [24]  363 	mov	_tmp2,#0x00
                                    364 ;	preemptive.c:125: do
      000198                        365 00105$:
                                    366 ;	preemptive.c:127: if (tmp2==4){
      000198 74 04            [12]  367 	mov	a,#0x04
      00019A B5 27 02         [24]  368 	cjne	a,_tmp2,00129$
      00019D 80 2A            [24]  369 	sjmp	00107$
      00019F                        370 00129$:
                                    371 ;	preemptive.c:130: if (!(bitmap&(1<<tmp2))){
      00019F AF 27            [24]  372 	mov	r7,_tmp2
      0001A1 8F F0            [24]  373 	mov	b,r7
      0001A3 05 F0            [12]  374 	inc	b
      0001A5 7F 01            [12]  375 	mov	r7,#0x01
      0001A7 7E 00            [12]  376 	mov	r6,#0x00
      0001A9 80 06            [24]  377 	sjmp	00131$
      0001AB                        378 00130$:
      0001AB EF               [12]  379 	mov	a,r7
      0001AC 2F               [12]  380 	add	a,r7
      0001AD FF               [12]  381 	mov	r7,a
      0001AE EE               [12]  382 	mov	a,r6
      0001AF 33               [12]  383 	rlc	a
      0001B0 FE               [12]  384 	mov	r6,a
      0001B1                        385 00131$:
      0001B1 D5 F0 F7         [24]  386 	djnz	b,00130$
      0001B4 AC 28            [24]  387 	mov	r4,_bitmap
      0001B6 7D 00            [12]  388 	mov	r5,#0x00
      0001B8 EC               [12]  389 	mov	a,r4
      0001B9 52 07            [12]  390 	anl	ar7,a
      0001BB ED               [12]  391 	mov	a,r5
      0001BC 52 06            [12]  392 	anl	ar6,a
      0001BE EF               [12]  393 	mov	a,r7
      0001BF 4E               [12]  394 	orl	a,r6
      0001C0 60 07            [24]  395 	jz	00107$
                                    396 ;	preemptive.c:133: tmp2++;
      0001C2 E5 27            [12]  397 	mov	a,_tmp2
      0001C4 04               [12]  398 	inc	a
      0001C5 F5 27            [12]  399 	mov	_tmp2,a
                                    400 ;	preemptive.c:134: } while (1);
      0001C7 80 CF            [24]  401 	sjmp	00105$
      0001C9                        402 00107$:
                                    403 ;	preemptive.c:136: if (tmp2 == 4){
      0001C9 74 04            [12]  404 	mov	a,#0x04
      0001CB B5 27 02         [24]  405 	cjne	a,_tmp2,00133$
      0001CE 80 43            [24]  406 	sjmp	00110$
      0001D0                        407 00133$:
                                    408 ;	preemptive.c:179: bitmap = bitmap|(1<<tmp2);
      0001D0 AF 27            [24]  409 	mov	r7,_tmp2
      0001D2 8F F0            [24]  410 	mov	b,r7
      0001D4 05 F0            [12]  411 	inc	b
      0001D6 74 01            [12]  412 	mov	a,#0x01
      0001D8 80 02            [24]  413 	sjmp	00136$
      0001DA                        414 00134$:
      0001DA 25 E0            [12]  415 	add	a,acc
      0001DC                        416 00136$:
      0001DC D5 F0 FB         [24]  417 	djnz	b,00134$
      0001DF FF               [12]  418 	mov	r7,a
      0001E0 AE 28            [24]  419 	mov	r6,_bitmap
      0001E2 4E               [12]  420 	orl	a,r6
      0001E3 F5 28            [12]  421 	mov	_bitmap,a
                                    422 ;	preemptive.c:180: tmp0 = SP;
      0001E5 85 81 25         [24]  423 	mov	_tmp0,_SP
                                    424 ;	preemptive.c:181: SP = T_SP[tmp2];
      0001E8 E5 27            [12]  425 	mov	a,_tmp2
      0001EA 24 20            [12]  426 	add	a,#_T_SP
      0001EC F9               [12]  427 	mov	r1,a
      0001ED 87 81            [24]  428 	mov	_SP,@r1
                                    429 ;	preemptive.c:185: __endasm;
      0001EF C0 82            [24]  430 	PUSH	DPL
      0001F1 C0 83            [24]  431 	PUSH	DPH
                                    432 ;	preemptive.c:187: ACC = 0;
      0001F3 75 E0 00         [24]  433 	mov	_ACC,#0x00
                                    434 ;	preemptive.c:193: __endasm;
      0001F6 C0 E0            [24]  435 	PUSH	ACC
      0001F8 C0 E0            [24]  436 	PUSH	ACC
      0001FA C0 E0            [24]  437 	PUSH	ACC
      0001FC C0 E0            [24]  438 	PUSH	ACC
                                    439 ;	preemptive.c:195: tmp1 = tmp2<<3;
      0001FE E5 27            [12]  440 	mov	a,_tmp2
      000200 FF               [12]  441 	mov	r7,a
      000201 C4               [12]  442 	swap	a
      000202 03               [12]  443 	rr	a
      000203 54 F8            [12]  444 	anl	a,#0xf8
      000205 F5 26            [12]  445 	mov	_tmp1,a
                                    446 ;	preemptive.c:198: __endasm;
      000207 C0 26            [24]  447 	PUSH	0x26;
                                    448 ;	preemptive.c:200: T_SP[tmp2] = SP;
      000209 E5 27            [12]  449 	mov	a,_tmp2
      00020B 24 20            [12]  450 	add	a,#_T_SP
      00020D F8               [12]  451 	mov	r0,a
      00020E A6 81            [24]  452 	mov	@r0,_SP
                                    453 ;	preemptive.c:201: SP = tmp0;
      000210 85 25 81         [24]  454 	mov	_SP,_tmp0
      000213                        455 00110$:
                                    456 ;	preemptive.c:205: EA = 1;
                                    457 ;	assignBit
      000213 D2 AF            [12]  458 	setb	_EA
                                    459 ;	preemptive.c:206: return tmp2;
      000215 85 27 82         [24]  460 	mov	dpl,_tmp2
                                    461 ;	preemptive.c:207: }
      000218 22               [24]  462 	ret
                                    463 ;------------------------------------------------------------
                                    464 ;Allocation info for local variables in function 'ThreadYield'
                                    465 ;------------------------------------------------------------
                                    466 ;	preemptive.c:216: void ThreadYield(void)
                                    467 ;	-----------------------------------------
                                    468 ;	 function ThreadYield
                                    469 ;	-----------------------------------------
      000219                        470 _ThreadYield:
                                    471 ;	preemptive.c:218: EA = 0;
                                    472 ;	assignBit
      000219 C2 AF            [12]  473 	clr	_EA
                                    474 ;	preemptive.c:219: SAVESTATE;
      00021B C0 E0            [24]  475 	PUSH A 
      00021D C0 F0            [24]  476 	PUSH B 
      00021F C0 82            [24]  477 	PUSH DPL 
      000221 C0 83            [24]  478 	PUSH DPH 
      000223 C0 D0            [24]  479 	PUSH PSW 
      000225 E5 24            [12]  480 	mov	a,_current_T
      000227 24 20            [12]  481 	add	a,#_T_SP
      000229 F8               [12]  482 	mov	r0,a
      00022A A6 81            [24]  483 	mov	@r0,_SP
                                    484 ;	preemptive.c:220: tmp0 = 1<<current_T;
      00022C AF 24            [24]  485 	mov	r7,_current_T
      00022E 8F F0            [24]  486 	mov	b,r7
      000230 05 F0            [12]  487 	inc	b
      000232 74 01            [12]  488 	mov	a,#0x01
      000234 80 02            [24]  489 	sjmp	00124$
      000236                        490 00122$:
      000236 25 E0            [12]  491 	add	a,acc
      000238                        492 00124$:
      000238 D5 F0 FB         [24]  493 	djnz	b,00122$
      00023B F5 25            [12]  494 	mov	_tmp0,a
                                    495 ;	preemptive.c:221: do
      00023D                        496 00105$:
                                    497 ;	preemptive.c:233: current_T++;
      00023D E5 24            [12]  498 	mov	a,_current_T
      00023F 04               [12]  499 	inc	a
      000240 F5 24            [12]  500 	mov	_current_T,a
                                    501 ;	preemptive.c:234: tmp0 <<= 1;
      000242 E5 25            [12]  502 	mov	a,_tmp0
      000244 FF               [12]  503 	mov	r7,a
      000245 25 E0            [12]  504 	add	a,acc
      000247 F5 25            [12]  505 	mov	_tmp0,a
                                    506 ;	preemptive.c:235: if (current_T==4){
      000249 74 04            [12]  507 	mov	a,#0x04
      00024B B5 24 06         [24]  508 	cjne	a,_current_T,00102$
                                    509 ;	preemptive.c:236: current_T = 0;
      00024E 75 24 00         [24]  510 	mov	_current_T,#0x00
                                    511 ;	preemptive.c:237: tmp0 = 1;
      000251 75 25 01         [24]  512 	mov	_tmp0,#0x01
      000254                        513 00102$:
                                    514 ;	preemptive.c:239: if (bitmap&tmp0){
      000254 E5 25            [12]  515 	mov	a,_tmp0
      000256 55 28            [12]  516 	anl	a,_bitmap
      000258 60 E3            [24]  517 	jz	00105$
                                    518 ;	preemptive.c:243: RESTORESTATE;
      00025A E5 24            [12]  519 	mov	a,_current_T
      00025C 24 20            [12]  520 	add	a,#_T_SP
      00025E F9               [12]  521 	mov	r1,a
      00025F 87 81            [24]  522 	mov	_SP,@r1
      000261 D0 D0            [24]  523 	POP PSW 
      000263 D0 83            [24]  524 	POP DPH 
      000265 D0 82            [24]  525 	POP DPL 
      000267 D0 F0            [24]  526 	POP B 
      000269 D0 E0            [24]  527 	POP A 
                                    528 ;	preemptive.c:244: EA = 1;
                                    529 ;	assignBit
      00026B D2 AF            [12]  530 	setb	_EA
                                    531 ;	preemptive.c:245: }
      00026D 22               [24]  532 	ret
                                    533 ;------------------------------------------------------------
                                    534 ;Allocation info for local variables in function 'ThreadExit'
                                    535 ;------------------------------------------------------------
                                    536 ;	preemptive.c:252: void ThreadExit(void)
                                    537 ;	-----------------------------------------
                                    538 ;	 function ThreadExit
                                    539 ;	-----------------------------------------
      00026E                        540 _ThreadExit:
                                    541 ;	preemptive.c:254: EA = 0;
                                    542 ;	assignBit
      00026E C2 AF            [12]  543 	clr	_EA
                                    544 ;	preemptive.c:262: bitmap = bitmap&(~(1<<current_T));
      000270 AF 24            [24]  545 	mov	r7,_current_T
      000272 8F F0            [24]  546 	mov	b,r7
      000274 05 F0            [12]  547 	inc	b
      000276 74 01            [12]  548 	mov	a,#0x01
      000278 80 02            [24]  549 	sjmp	00124$
      00027A                        550 00122$:
      00027A 25 E0            [12]  551 	add	a,acc
      00027C                        552 00124$:
      00027C D5 F0 FB         [24]  553 	djnz	b,00122$
      00027F F4               [12]  554 	cpl	a
      000280 AE 28            [24]  555 	mov	r6,_bitmap
      000282 5E               [12]  556 	anl	a,r6
      000283 F5 28            [12]  557 	mov	_bitmap,a
                                    558 ;	preemptive.c:263: tmp0 = 1<<current_T;
      000285 AF 24            [24]  559 	mov	r7,_current_T
      000287 8F F0            [24]  560 	mov	b,r7
      000289 05 F0            [12]  561 	inc	b
      00028B 74 01            [12]  562 	mov	a,#0x01
      00028D 80 02            [24]  563 	sjmp	00127$
      00028F                        564 00125$:
      00028F 25 E0            [12]  565 	add	a,acc
      000291                        566 00127$:
      000291 D5 F0 FB         [24]  567 	djnz	b,00125$
      000294 F5 25            [12]  568 	mov	_tmp0,a
                                    569 ;	preemptive.c:264: do
      000296                        570 00105$:
                                    571 ;	preemptive.c:266: current_T++;
      000296 E5 24            [12]  572 	mov	a,_current_T
      000298 04               [12]  573 	inc	a
      000299 F5 24            [12]  574 	mov	_current_T,a
                                    575 ;	preemptive.c:267: tmp0 <<= 1;
      00029B E5 25            [12]  576 	mov	a,_tmp0
      00029D FF               [12]  577 	mov	r7,a
      00029E 25 E0            [12]  578 	add	a,acc
      0002A0 F5 25            [12]  579 	mov	_tmp0,a
                                    580 ;	preemptive.c:268: if (current_T==4){
      0002A2 74 04            [12]  581 	mov	a,#0x04
      0002A4 B5 24 06         [24]  582 	cjne	a,_current_T,00102$
                                    583 ;	preemptive.c:269: current_T = 0;
      0002A7 75 24 00         [24]  584 	mov	_current_T,#0x00
                                    585 ;	preemptive.c:270: tmp0 = 1;
      0002AA 75 25 01         [24]  586 	mov	_tmp0,#0x01
      0002AD                        587 00102$:
                                    588 ;	preemptive.c:272: if (bitmap&tmp0){
      0002AD E5 25            [12]  589 	mov	a,_tmp0
      0002AF 55 28            [12]  590 	anl	a,_bitmap
      0002B1 60 E3            [24]  591 	jz	00105$
                                    592 ;	preemptive.c:276: RESTORESTATE;
      0002B3 E5 24            [12]  593 	mov	a,_current_T
      0002B5 24 20            [12]  594 	add	a,#_T_SP
      0002B7 F9               [12]  595 	mov	r1,a
      0002B8 87 81            [24]  596 	mov	_SP,@r1
      0002BA D0 D0            [24]  597 	POP PSW 
      0002BC D0 83            [24]  598 	POP DPH 
      0002BE D0 82            [24]  599 	POP DPL 
      0002C0 D0 F0            [24]  600 	POP B 
      0002C2 D0 E0            [24]  601 	POP A 
                                    602 ;	preemptive.c:277: EA = 1;
                                    603 ;	assignBit
      0002C4 D2 AF            [12]  604 	setb	_EA
                                    605 ;	preemptive.c:278: }
      0002C6 22               [24]  606 	ret
                                    607 ;------------------------------------------------------------
                                    608 ;Allocation info for local variables in function 'myTimer0Handler'
                                    609 ;------------------------------------------------------------
                                    610 ;	preemptive.c:280: void myTimer0Handler(void)
                                    611 ;	-----------------------------------------
                                    612 ;	 function myTimer0Handler
                                    613 ;	-----------------------------------------
      0002C7                        614 _myTimer0Handler:
                                    615 ;	preemptive.c:282: EA = 0;
                                    616 ;	assignBit
      0002C7 C2 AF            [12]  617 	clr	_EA
                                    618 ;	preemptive.c:283: SAVESTATE;
      0002C9 C0 E0            [24]  619 	PUSH A 
      0002CB C0 F0            [24]  620 	PUSH B 
      0002CD C0 82            [24]  621 	PUSH DPL 
      0002CF C0 83            [24]  622 	PUSH DPH 
      0002D1 C0 D0            [24]  623 	PUSH PSW 
      0002D3 E5 24            [12]  624 	mov	a,_current_T
      0002D5 24 20            [12]  625 	add	a,#_T_SP
      0002D7 F8               [12]  626 	mov	r0,a
      0002D8 A6 81            [24]  627 	mov	@r0,_SP
                                    628 ;	preemptive.c:284: tmp0 = 1<<current_T;
      0002DA AF 24            [24]  629 	mov	r7,_current_T
      0002DC 8F F0            [24]  630 	mov	b,r7
      0002DE 05 F0            [12]  631 	inc	b
      0002E0 74 01            [12]  632 	mov	a,#0x01
      0002E2 80 02            [24]  633 	sjmp	00124$
      0002E4                        634 00122$:
      0002E4 25 E0            [12]  635 	add	a,acc
      0002E6                        636 00124$:
      0002E6 D5 F0 FB         [24]  637 	djnz	b,00122$
      0002E9 F5 25            [12]  638 	mov	_tmp0,a
                                    639 ;	preemptive.c:285: do
      0002EB                        640 00105$:
                                    641 ;	preemptive.c:297: current_T++;
      0002EB E5 24            [12]  642 	mov	a,_current_T
      0002ED 04               [12]  643 	inc	a
      0002EE F5 24            [12]  644 	mov	_current_T,a
                                    645 ;	preemptive.c:298: tmp0 <<= 1;
      0002F0 E5 25            [12]  646 	mov	a,_tmp0
      0002F2 FF               [12]  647 	mov	r7,a
      0002F3 25 E0            [12]  648 	add	a,acc
      0002F5 F5 25            [12]  649 	mov	_tmp0,a
                                    650 ;	preemptive.c:299: if (current_T==4){
      0002F7 74 04            [12]  651 	mov	a,#0x04
      0002F9 B5 24 06         [24]  652 	cjne	a,_current_T,00102$
                                    653 ;	preemptive.c:300: current_T = 0;
      0002FC 75 24 00         [24]  654 	mov	_current_T,#0x00
                                    655 ;	preemptive.c:301: tmp0 = 1;
      0002FF 75 25 01         [24]  656 	mov	_tmp0,#0x01
      000302                        657 00102$:
                                    658 ;	preemptive.c:303: if (bitmap&tmp0){
      000302 E5 25            [12]  659 	mov	a,_tmp0
      000304 55 28            [12]  660 	anl	a,_bitmap
      000306 60 E3            [24]  661 	jz	00105$
                                    662 ;	preemptive.c:307: RESTORESTATE;
      000308 E5 24            [12]  663 	mov	a,_current_T
      00030A 24 20            [12]  664 	add	a,#_T_SP
      00030C F9               [12]  665 	mov	r1,a
      00030D 87 81            [24]  666 	mov	_SP,@r1
      00030F D0 D0            [24]  667 	POP PSW 
      000311 D0 83            [24]  668 	POP DPH 
      000313 D0 82            [24]  669 	POP DPL 
      000315 D0 F0            [24]  670 	POP B 
      000317 D0 E0            [24]  671 	POP A 
                                    672 ;	preemptive.c:308: EA = 1;
                                    673 ;	assignBit
      000319 D2 AF            [12]  674 	setb	_EA
                                    675 ;	preemptive.c:311: __endasm;
      00031B 32               [24]  676 	RETI
                                    677 ;	preemptive.c:312: }
      00031C 22               [24]  678 	ret
                                    679 	.area CSEG    (CODE)
                                    680 	.area CONST   (CODE)
                                    681 	.area XINIT   (CODE)
                                    682 	.area CABS    (ABS,CODE)
