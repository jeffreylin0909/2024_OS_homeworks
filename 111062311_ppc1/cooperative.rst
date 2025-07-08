                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module cooperative
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
                                    118 ;--------------------------------------------------------
                                    119 ; special function registers
                                    120 ;--------------------------------------------------------
                                    121 	.area RSEG    (ABS,DATA)
      000000                        122 	.org 0x0000
                           000080   123 _P0	=	0x0080
                           000081   124 _SP	=	0x0081
                           000082   125 _DPL	=	0x0082
                           000083   126 _DPH	=	0x0083
                           000087   127 _PCON	=	0x0087
                           000088   128 _TCON	=	0x0088
                           000089   129 _TMOD	=	0x0089
                           00008A   130 _TL0	=	0x008a
                           00008B   131 _TL1	=	0x008b
                           00008C   132 _TH0	=	0x008c
                           00008D   133 _TH1	=	0x008d
                           000090   134 _P1	=	0x0090
                           000098   135 _SCON	=	0x0098
                           000099   136 _SBUF	=	0x0099
                           0000A0   137 _P2	=	0x00a0
                           0000A8   138 _IE	=	0x00a8
                           0000B0   139 _P3	=	0x00b0
                           0000B8   140 _IP	=	0x00b8
                           0000D0   141 _PSW	=	0x00d0
                           0000E0   142 _ACC	=	0x00e0
                           0000F0   143 _B	=	0x00f0
                                    144 ;--------------------------------------------------------
                                    145 ; special function bits
                                    146 ;--------------------------------------------------------
                                    147 	.area RSEG    (ABS,DATA)
      000000                        148 	.org 0x0000
                           000080   149 _P0_0	=	0x0080
                           000081   150 _P0_1	=	0x0081
                           000082   151 _P0_2	=	0x0082
                           000083   152 _P0_3	=	0x0083
                           000084   153 _P0_4	=	0x0084
                           000085   154 _P0_5	=	0x0085
                           000086   155 _P0_6	=	0x0086
                           000087   156 _P0_7	=	0x0087
                           000088   157 _IT0	=	0x0088
                           000089   158 _IE0	=	0x0089
                           00008A   159 _IT1	=	0x008a
                           00008B   160 _IE1	=	0x008b
                           00008C   161 _TR0	=	0x008c
                           00008D   162 _TF0	=	0x008d
                           00008E   163 _TR1	=	0x008e
                           00008F   164 _TF1	=	0x008f
                           000090   165 _P1_0	=	0x0090
                           000091   166 _P1_1	=	0x0091
                           000092   167 _P1_2	=	0x0092
                           000093   168 _P1_3	=	0x0093
                           000094   169 _P1_4	=	0x0094
                           000095   170 _P1_5	=	0x0095
                           000096   171 _P1_6	=	0x0096
                           000097   172 _P1_7	=	0x0097
                           000098   173 _RI	=	0x0098
                           000099   174 _TI	=	0x0099
                           00009A   175 _RB8	=	0x009a
                           00009B   176 _TB8	=	0x009b
                           00009C   177 _REN	=	0x009c
                           00009D   178 _SM2	=	0x009d
                           00009E   179 _SM1	=	0x009e
                           00009F   180 _SM0	=	0x009f
                           0000A0   181 _P2_0	=	0x00a0
                           0000A1   182 _P2_1	=	0x00a1
                           0000A2   183 _P2_2	=	0x00a2
                           0000A3   184 _P2_3	=	0x00a3
                           0000A4   185 _P2_4	=	0x00a4
                           0000A5   186 _P2_5	=	0x00a5
                           0000A6   187 _P2_6	=	0x00a6
                           0000A7   188 _P2_7	=	0x00a7
                           0000A8   189 _EX0	=	0x00a8
                           0000A9   190 _ET0	=	0x00a9
                           0000AA   191 _EX1	=	0x00aa
                           0000AB   192 _ET1	=	0x00ab
                           0000AC   193 _ES	=	0x00ac
                           0000AF   194 _EA	=	0x00af
                           0000B0   195 _P3_0	=	0x00b0
                           0000B1   196 _P3_1	=	0x00b1
                           0000B2   197 _P3_2	=	0x00b2
                           0000B3   198 _P3_3	=	0x00b3
                           0000B4   199 _P3_4	=	0x00b4
                           0000B5   200 _P3_5	=	0x00b5
                           0000B6   201 _P3_6	=	0x00b6
                           0000B7   202 _P3_7	=	0x00b7
                           0000B0   203 _RXD	=	0x00b0
                           0000B1   204 _TXD	=	0x00b1
                           0000B2   205 _INT0	=	0x00b2
                           0000B3   206 _INT1	=	0x00b3
                           0000B4   207 _T0	=	0x00b4
                           0000B5   208 _T1	=	0x00b5
                           0000B6   209 _WR	=	0x00b6
                           0000B7   210 _RD	=	0x00b7
                           0000B8   211 _PX0	=	0x00b8
                           0000B9   212 _PT0	=	0x00b9
                           0000BA   213 _PX1	=	0x00ba
                           0000BB   214 _PT1	=	0x00bb
                           0000BC   215 _PS	=	0x00bc
                           0000D0   216 _P	=	0x00d0
                           0000D1   217 _F1	=	0x00d1
                           0000D2   218 _OV	=	0x00d2
                           0000D3   219 _RS0	=	0x00d3
                           0000D4   220 _RS1	=	0x00d4
                           0000D5   221 _F0	=	0x00d5
                           0000D6   222 _AC	=	0x00d6
                           0000D7   223 _CY	=	0x00d7
                                    224 ;--------------------------------------------------------
                                    225 ; overlayable register banks
                                    226 ;--------------------------------------------------------
                                    227 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        228 	.ds 8
                                    229 ;--------------------------------------------------------
                                    230 ; internal ram data
                                    231 ;--------------------------------------------------------
                                    232 	.area DSEG    (DATA)
                           000020   233 _T_SP	=	0x0020
                           000024   234 _current_T	=	0x0024
                           000025   235 _tmp0	=	0x0025
                           000026   236 _tmp1	=	0x0026
                           000027   237 _tmp2	=	0x0027
                           000028   238 _bitmap	=	0x0028
                                    239 ;--------------------------------------------------------
                                    240 ; overlayable items in internal ram 
                                    241 ;--------------------------------------------------------
                                    242 	.area	OSEG    (OVR,DATA)
                                    243 ;--------------------------------------------------------
                                    244 ; indirectly addressable internal ram data
                                    245 ;--------------------------------------------------------
                                    246 	.area ISEG    (DATA)
                                    247 ;--------------------------------------------------------
                                    248 ; absolute internal ram data
                                    249 ;--------------------------------------------------------
                                    250 	.area IABS    (ABS,DATA)
                                    251 	.area IABS    (ABS,DATA)
                                    252 ;--------------------------------------------------------
                                    253 ; bit data
                                    254 ;--------------------------------------------------------
                                    255 	.area BSEG    (BIT)
                                    256 ;--------------------------------------------------------
                                    257 ; paged external ram data
                                    258 ;--------------------------------------------------------
                                    259 	.area PSEG    (PAG,XDATA)
                                    260 ;--------------------------------------------------------
                                    261 ; external ram data
                                    262 ;--------------------------------------------------------
                                    263 	.area XSEG    (XDATA)
                                    264 ;--------------------------------------------------------
                                    265 ; absolute external ram data
                                    266 ;--------------------------------------------------------
                                    267 	.area XABS    (ABS,XDATA)
                                    268 ;--------------------------------------------------------
                                    269 ; external initialized ram data
                                    270 ;--------------------------------------------------------
                                    271 	.area XISEG   (XDATA)
                                    272 	.area HOME    (CODE)
                                    273 	.area GSINIT0 (CODE)
                                    274 	.area GSINIT1 (CODE)
                                    275 	.area GSINIT2 (CODE)
                                    276 	.area GSINIT3 (CODE)
                                    277 	.area GSINIT4 (CODE)
                                    278 	.area GSINIT5 (CODE)
                                    279 	.area GSINIT  (CODE)
                                    280 	.area GSFINAL (CODE)
                                    281 	.area CSEG    (CODE)
                                    282 ;--------------------------------------------------------
                                    283 ; global & static initialisations
                                    284 ;--------------------------------------------------------
                                    285 	.area HOME    (CODE)
                                    286 	.area GSINIT  (CODE)
                                    287 	.area GSFINAL (CODE)
                                    288 	.area GSINIT  (CODE)
                                    289 ;--------------------------------------------------------
                                    290 ; Home
                                    291 ;--------------------------------------------------------
                                    292 	.area HOME    (CODE)
                                    293 	.area HOME    (CODE)
                                    294 ;--------------------------------------------------------
                                    295 ; code
                                    296 ;--------------------------------------------------------
                                    297 	.area CSEG    (CODE)
                                    298 ;------------------------------------------------------------
                                    299 ;Allocation info for local variables in function 'Bootstrap'
                                    300 ;------------------------------------------------------------
                                    301 ;	cooperative.c:80: void Bootstrap(void)
                                    302 ;	-----------------------------------------
                                    303 ;	 function Bootstrap
                                    304 ;	-----------------------------------------
      000097                        305 _Bootstrap:
                           000007   306 	ar7 = 0x07
                           000006   307 	ar6 = 0x06
                           000005   308 	ar5 = 0x05
                           000004   309 	ar4 = 0x04
                           000003   310 	ar3 = 0x03
                           000002   311 	ar2 = 0x02
                           000001   312 	ar1 = 0x01
                           000000   313 	ar0 = 0x00
                                    314 ;	cooperative.c:94: T_SP[0] = 0x3F;
      000097 75 20 3F         [24]  315 	mov	_T_SP,#0x3f
                                    316 ;	cooperative.c:95: T_SP[1] = 0x4F;
      00009A 75 21 4F         [24]  317 	mov	(_T_SP + 0x0001),#0x4f
                                    318 ;	cooperative.c:96: T_SP[2] = 0x5F;
      00009D 75 22 5F         [24]  319 	mov	(_T_SP + 0x0002),#0x5f
                                    320 ;	cooperative.c:97: T_SP[3] = 0x6F;
      0000A0 75 23 6F         [24]  321 	mov	(_T_SP + 0x0003),#0x6f
                                    322 ;	cooperative.c:98: bitmap = 0b0000;
      0000A3 75 28 00         [24]  323 	mov	_bitmap,#0x00
                                    324 ;	cooperative.c:100: current_T = ThreadCreate(main);
      0000A6 90 00 78         [24]  325 	mov	dptr,#_main
      0000A9 12 00 C1         [24]  326 	lcall	_ThreadCreate
      0000AC 85 82 24         [24]  327 	mov	_current_T,dpl
                                    328 ;	cooperative.c:101: RESTORESTATE;
      0000AF E5 24            [12]  329 	mov	a,_current_T
      0000B1 24 20            [12]  330 	add	a,#_T_SP
      0000B3 F9               [12]  331 	mov	r1,a
      0000B4 87 81            [24]  332 	mov	_SP,@r1
      0000B6 D0 D0            [24]  333 	POP PSW 
      0000B8 D0 83            [24]  334 	POP DPH 
      0000BA D0 82            [24]  335 	POP DPL 
      0000BC D0 F0            [24]  336 	POP B 
      0000BE D0 E0            [24]  337 	POP A 
                                    338 ;	cooperative.c:102: return;
                                    339 ;	cooperative.c:103: }
      0000C0 22               [24]  340 	ret
                                    341 ;------------------------------------------------------------
                                    342 ;Allocation info for local variables in function 'ThreadCreate'
                                    343 ;------------------------------------------------------------
                                    344 ;fp                        Allocated to registers 
                                    345 ;------------------------------------------------------------
                                    346 ;	cooperative.c:111: ThreadID ThreadCreate(FunctionPtr fp)
                                    347 ;	-----------------------------------------
                                    348 ;	 function ThreadCreate
                                    349 ;	-----------------------------------------
      0000C1                        350 _ThreadCreate:
                                    351 ;	cooperative.c:118: tmp2 = 0;
      0000C1 75 27 00         [24]  352 	mov	_tmp2,#0x00
                                    353 ;	cooperative.c:119: do
      0000C4                        354 00105$:
                                    355 ;	cooperative.c:121: if (tmp2==4){
      0000C4 74 04            [12]  356 	mov	a,#0x04
      0000C6 B5 27 02         [24]  357 	cjne	a,_tmp2,00128$
      0000C9 80 2A            [24]  358 	sjmp	00107$
      0000CB                        359 00128$:
                                    360 ;	cooperative.c:124: if (!(bitmap&(1<<tmp2))){
      0000CB AF 27            [24]  361 	mov	r7,_tmp2
      0000CD 8F F0            [24]  362 	mov	b,r7
      0000CF 05 F0            [12]  363 	inc	b
      0000D1 7F 01            [12]  364 	mov	r7,#0x01
      0000D3 7E 00            [12]  365 	mov	r6,#0x00
      0000D5 80 06            [24]  366 	sjmp	00130$
      0000D7                        367 00129$:
      0000D7 EF               [12]  368 	mov	a,r7
      0000D8 2F               [12]  369 	add	a,r7
      0000D9 FF               [12]  370 	mov	r7,a
      0000DA EE               [12]  371 	mov	a,r6
      0000DB 33               [12]  372 	rlc	a
      0000DC FE               [12]  373 	mov	r6,a
      0000DD                        374 00130$:
      0000DD D5 F0 F7         [24]  375 	djnz	b,00129$
      0000E0 AC 28            [24]  376 	mov	r4,_bitmap
      0000E2 7D 00            [12]  377 	mov	r5,#0x00
      0000E4 EC               [12]  378 	mov	a,r4
      0000E5 52 07            [12]  379 	anl	ar7,a
      0000E7 ED               [12]  380 	mov	a,r5
      0000E8 52 06            [12]  381 	anl	ar6,a
      0000EA EF               [12]  382 	mov	a,r7
      0000EB 4E               [12]  383 	orl	a,r6
      0000EC 60 07            [24]  384 	jz	00107$
                                    385 ;	cooperative.c:127: tmp2++;
      0000EE E5 27            [12]  386 	mov	a,_tmp2
      0000F0 04               [12]  387 	inc	a
      0000F1 F5 27            [12]  388 	mov	_tmp2,a
                                    389 ;	cooperative.c:128: } while (1);
      0000F3 80 CF            [24]  390 	sjmp	00105$
      0000F5                        391 00107$:
                                    392 ;	cooperative.c:130: if (tmp2 == 4){
      0000F5 74 04            [12]  393 	mov	a,#0x04
      0000F7 B5 27 04         [24]  394 	cjne	a,_tmp2,00109$
                                    395 ;	cooperative.c:131: return tmp2;
      0000FA 85 27 82         [24]  396 	mov	dpl,_tmp2
      0000FD 22               [24]  397 	ret
      0000FE                        398 00109$:
                                    399 ;	cooperative.c:172: bitmap = bitmap|(1<<tmp2);
      0000FE AF 27            [24]  400 	mov	r7,_tmp2
      000100 8F F0            [24]  401 	mov	b,r7
      000102 05 F0            [12]  402 	inc	b
      000104 74 01            [12]  403 	mov	a,#0x01
      000106 80 02            [24]  404 	sjmp	00136$
      000108                        405 00134$:
      000108 25 E0            [12]  406 	add	a,acc
      00010A                        407 00136$:
      00010A D5 F0 FB         [24]  408 	djnz	b,00134$
      00010D FF               [12]  409 	mov	r7,a
      00010E AE 28            [24]  410 	mov	r6,_bitmap
      000110 4E               [12]  411 	orl	a,r6
      000111 F5 28            [12]  412 	mov	_bitmap,a
                                    413 ;	cooperative.c:173: tmp0 = SP;
      000113 85 81 25         [24]  414 	mov	_tmp0,_SP
                                    415 ;	cooperative.c:174: SP = T_SP[tmp2];
      000116 E5 27            [12]  416 	mov	a,_tmp2
      000118 24 20            [12]  417 	add	a,#_T_SP
      00011A F9               [12]  418 	mov	r1,a
      00011B 87 81            [24]  419 	mov	_SP,@r1
                                    420 ;	cooperative.c:178: __endasm;
      00011D C0 82            [24]  421 	PUSH	DPL
      00011F C0 83            [24]  422 	PUSH	DPH
                                    423 ;	cooperative.c:180: ACC = 0;
      000121 75 E0 00         [24]  424 	mov	_ACC,#0x00
                                    425 ;	cooperative.c:186: __endasm;
      000124 C0 E0            [24]  426 	PUSH	ACC
      000126 C0 E0            [24]  427 	PUSH	ACC
      000128 C0 E0            [24]  428 	PUSH	ACC
      00012A C0 E0            [24]  429 	PUSH	ACC
                                    430 ;	cooperative.c:188: tmp1 = tmp2<<3;
      00012C E5 27            [12]  431 	mov	a,_tmp2
      00012E FF               [12]  432 	mov	r7,a
      00012F C4               [12]  433 	swap	a
      000130 03               [12]  434 	rr	a
      000131 54 F8            [12]  435 	anl	a,#0xf8
      000133 F5 26            [12]  436 	mov	_tmp1,a
                                    437 ;	cooperative.c:191: __endasm;
      000135 C0 26            [24]  438 	PUSH	0x26;
                                    439 ;	cooperative.c:193: T_SP[tmp2] = SP;
      000137 E5 27            [12]  440 	mov	a,_tmp2
      000139 24 20            [12]  441 	add	a,#_T_SP
      00013B F8               [12]  442 	mov	r0,a
      00013C A6 81            [24]  443 	mov	@r0,_SP
                                    444 ;	cooperative.c:194: SP = tmp0;
      00013E 85 25 81         [24]  445 	mov	_SP,_tmp0
                                    446 ;	cooperative.c:196: return tmp2;
      000141 85 27 82         [24]  447 	mov	dpl,_tmp2
                                    448 ;	cooperative.c:197: }
      000144 22               [24]  449 	ret
                                    450 ;------------------------------------------------------------
                                    451 ;Allocation info for local variables in function 'ThreadYield'
                                    452 ;------------------------------------------------------------
                                    453 ;	cooperative.c:206: void ThreadYield(void)
                                    454 ;	-----------------------------------------
                                    455 ;	 function ThreadYield
                                    456 ;	-----------------------------------------
      000145                        457 _ThreadYield:
                                    458 ;	cooperative.c:208: SAVESTATE;
      000145 C0 E0            [24]  459 	PUSH A 
      000147 C0 F0            [24]  460 	PUSH B 
      000149 C0 82            [24]  461 	PUSH DPL 
      00014B C0 83            [24]  462 	PUSH DPH 
      00014D C0 D0            [24]  463 	PUSH PSW 
      00014F E5 24            [12]  464 	mov	a,_current_T
      000151 24 20            [12]  465 	add	a,#_T_SP
      000153 F8               [12]  466 	mov	r0,a
      000154 A6 81            [24]  467 	mov	@r0,_SP
                                    468 ;	cooperative.c:209: tmp0 = 1<<current_T;
      000156 AF 24            [24]  469 	mov	r7,_current_T
      000158 8F F0            [24]  470 	mov	b,r7
      00015A 05 F0            [12]  471 	inc	b
      00015C 74 01            [12]  472 	mov	a,#0x01
      00015E 80 02            [24]  473 	sjmp	00124$
      000160                        474 00122$:
      000160 25 E0            [12]  475 	add	a,acc
      000162                        476 00124$:
      000162 D5 F0 FB         [24]  477 	djnz	b,00122$
      000165 F5 25            [12]  478 	mov	_tmp0,a
                                    479 ;	cooperative.c:210: do
      000167                        480 00105$:
                                    481 ;	cooperative.c:222: current_T++;
      000167 E5 24            [12]  482 	mov	a,_current_T
      000169 04               [12]  483 	inc	a
      00016A F5 24            [12]  484 	mov	_current_T,a
                                    485 ;	cooperative.c:223: tmp0 <<= 1;
      00016C E5 25            [12]  486 	mov	a,_tmp0
      00016E FF               [12]  487 	mov	r7,a
      00016F 25 E0            [12]  488 	add	a,acc
      000171 F5 25            [12]  489 	mov	_tmp0,a
                                    490 ;	cooperative.c:224: if (current_T==4){
      000173 74 04            [12]  491 	mov	a,#0x04
      000175 B5 24 06         [24]  492 	cjne	a,_current_T,00102$
                                    493 ;	cooperative.c:225: current_T = 0;
      000178 75 24 00         [24]  494 	mov	_current_T,#0x00
                                    495 ;	cooperative.c:226: tmp0 = 1;
      00017B 75 25 01         [24]  496 	mov	_tmp0,#0x01
      00017E                        497 00102$:
                                    498 ;	cooperative.c:228: if (bitmap&tmp0){
      00017E E5 25            [12]  499 	mov	a,_tmp0
      000180 55 28            [12]  500 	anl	a,_bitmap
      000182 60 E3            [24]  501 	jz	00105$
                                    502 ;	cooperative.c:232: RESTORESTATE;
      000184 E5 24            [12]  503 	mov	a,_current_T
      000186 24 20            [12]  504 	add	a,#_T_SP
      000188 F9               [12]  505 	mov	r1,a
      000189 87 81            [24]  506 	mov	_SP,@r1
      00018B D0 D0            [24]  507 	POP PSW 
      00018D D0 83            [24]  508 	POP DPH 
      00018F D0 82            [24]  509 	POP DPL 
      000191 D0 F0            [24]  510 	POP B 
      000193 D0 E0            [24]  511 	POP A 
                                    512 ;	cooperative.c:233: }
      000195 22               [24]  513 	ret
                                    514 ;------------------------------------------------------------
                                    515 ;Allocation info for local variables in function 'ThreadExit'
                                    516 ;------------------------------------------------------------
                                    517 ;	cooperative.c:240: void ThreadExit(void)
                                    518 ;	-----------------------------------------
                                    519 ;	 function ThreadExit
                                    520 ;	-----------------------------------------
      000196                        521 _ThreadExit:
                                    522 ;	cooperative.c:249: bitmap = bitmap&(~(1<<current_T));
      000196 AF 24            [24]  523 	mov	r7,_current_T
      000198 8F F0            [24]  524 	mov	b,r7
      00019A 05 F0            [12]  525 	inc	b
      00019C 74 01            [12]  526 	mov	a,#0x01
      00019E 80 02            [24]  527 	sjmp	00124$
      0001A0                        528 00122$:
      0001A0 25 E0            [12]  529 	add	a,acc
      0001A2                        530 00124$:
      0001A2 D5 F0 FB         [24]  531 	djnz	b,00122$
      0001A5 F4               [12]  532 	cpl	a
      0001A6 AE 28            [24]  533 	mov	r6,_bitmap
      0001A8 5E               [12]  534 	anl	a,r6
      0001A9 F5 28            [12]  535 	mov	_bitmap,a
                                    536 ;	cooperative.c:250: tmp0 = 1<<current_T;
      0001AB AF 24            [24]  537 	mov	r7,_current_T
      0001AD 8F F0            [24]  538 	mov	b,r7
      0001AF 05 F0            [12]  539 	inc	b
      0001B1 74 01            [12]  540 	mov	a,#0x01
      0001B3 80 02            [24]  541 	sjmp	00127$
      0001B5                        542 00125$:
      0001B5 25 E0            [12]  543 	add	a,acc
      0001B7                        544 00127$:
      0001B7 D5 F0 FB         [24]  545 	djnz	b,00125$
      0001BA F5 25            [12]  546 	mov	_tmp0,a
                                    547 ;	cooperative.c:251: do
      0001BC                        548 00105$:
                                    549 ;	cooperative.c:253: current_T++;
      0001BC E5 24            [12]  550 	mov	a,_current_T
      0001BE 04               [12]  551 	inc	a
      0001BF F5 24            [12]  552 	mov	_current_T,a
                                    553 ;	cooperative.c:254: tmp0 <<= 1;
      0001C1 E5 25            [12]  554 	mov	a,_tmp0
      0001C3 FF               [12]  555 	mov	r7,a
      0001C4 25 E0            [12]  556 	add	a,acc
      0001C6 F5 25            [12]  557 	mov	_tmp0,a
                                    558 ;	cooperative.c:255: if (current_T==4){
      0001C8 74 04            [12]  559 	mov	a,#0x04
      0001CA B5 24 06         [24]  560 	cjne	a,_current_T,00102$
                                    561 ;	cooperative.c:256: current_T = 0;
      0001CD 75 24 00         [24]  562 	mov	_current_T,#0x00
                                    563 ;	cooperative.c:257: tmp0 = 1;
      0001D0 75 25 01         [24]  564 	mov	_tmp0,#0x01
      0001D3                        565 00102$:
                                    566 ;	cooperative.c:259: if (bitmap&tmp0){
      0001D3 E5 25            [12]  567 	mov	a,_tmp0
      0001D5 55 28            [12]  568 	anl	a,_bitmap
      0001D7 60 E3            [24]  569 	jz	00105$
                                    570 ;	cooperative.c:263: RESTORESTATE;
      0001D9 E5 24            [12]  571 	mov	a,_current_T
      0001DB 24 20            [12]  572 	add	a,#_T_SP
      0001DD F9               [12]  573 	mov	r1,a
      0001DE 87 81            [24]  574 	mov	_SP,@r1
      0001E0 D0 D0            [24]  575 	POP PSW 
      0001E2 D0 83            [24]  576 	POP DPH 
      0001E4 D0 82            [24]  577 	POP DPL 
      0001E6 D0 F0            [24]  578 	POP B 
      0001E8 D0 E0            [24]  579 	POP A 
                                    580 ;	cooperative.c:264: }
      0001EA 22               [24]  581 	ret
                                    582 	.area CSEG    (CODE)
                                    583 	.area CONST   (CODE)
                                    584 	.area XINIT   (CODE)
                                    585 	.area CABS    (ABS,CODE)
