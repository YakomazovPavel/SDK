/*REV. 1.0    31th October 2002
  ADuC831  Apps, Analog Devices Inc.*/

/*  BYTE Register  */
__sfr __at ( 0x80 )  P0       ;
__sfr __at ( 0x81 )  SP       ;
__sfr __at ( 0x82 )  DPL      ;
__sfr __at ( 0x83 )  DPH      ;
__sfr __at ( 0x84 )  DPP      ;
__sfr __at ( 0x87 )  PCON     ;
__sfr __at ( 0x88 )  TCON     ;
__sfr __at ( 0x89 )  TMOD     ;
__sfr __at ( 0x8A )  TL0      ;
__sfr __at ( 0x8B )  TL1      ;
__sfr __at ( 0x8C )  TH0      ;
__sfr __at ( 0x8D )  TH1      ;
__sfr __at ( 0x90 )  P1       ;
__sfr __at ( 0x98 )  SCON     ;
__sfr __at ( 0x99 )  SBUF     ;
__sfr __at ( 0x9A )  I2CDAT   ;
__sfr __at ( 0x9B )  I2CADD   ;
__sfr __at ( 0x9D )  T3FD     ;
__sfr __at ( 0x9E )  T3CON    ;
__sfr __at ( 0xA0 )  P2       ;
__sfr __at ( 0xA1 )  TIMECON  ;
__sfr __at ( 0xA2 )  HTHSEC   ;
__sfr __at ( 0xA3 )  SEC      ;
__sfr __at ( 0xA4 )  MIN      ;
__sfr __at ( 0xA5 )  HOUR     ;
__sfr __at ( 0xA6 )  INTVAL   ;
__sfr __at ( 0xA7 )  DPCON    ;
__sfr __at ( 0xA8 )  IE       ;
__sfr __at ( 0xA9 )  IEIP2    ;
__sfr __at ( 0xAE )  PWMCON   ;
__sfr __at ( 0xAF )  CFG831   ;
__sfr __at ( 0xB0 )  P3       ;
__sfr __at ( 0xB1 )  PWM0L    ;
__sfr __at ( 0xB2 )  PWM0H    ;
__sfr __at ( 0xB3 )  PWM1L    ;
__sfr __at ( 0xB4 )  PWM1H    ;
__sfr __at ( 0xB7 )  SPH      ;
__sfr __at ( 0xB8 )  IP       ;
__sfr __at ( 0xB9 )  ECON     ;
__sfr __at ( 0xBC )  EDATA1   ;
__sfr __at ( 0xBD )  EDATA2   ;
__sfr __at ( 0xBE )  EDATA3   ;
__sfr __at ( 0xBF )  EDATA4   ;
__sfr __at ( 0xC0 )  WDCON    ;
__sfr __at ( 0xC2 )  CHIPID   ;
__sfr __at ( 0xC6 )  EADRL    ;
__sfr __at ( 0xC7 )  EADRH    ;
__sfr __at ( 0xC8 )  T2CON    ;
__sfr __at ( 0xCA )  RCAP2L   ;
__sfr __at ( 0xCB )  RCAP2H   ;
__sfr __at ( 0xCC )  TL2      ;
__sfr __at ( 0xCD )  TH2      ;
__sfr __at ( 0xD0 )  PSW      ;
__sfr __at ( 0xD2 )  DMAL     ;
__sfr __at ( 0xD3 )  DMAH     ;
__sfr __at ( 0xD4 )  DMAP     ;
__sfr __at ( 0xD8 )  ADCCON2  ;
__sfr __at ( 0xD9 )  ADCDATAL ;
__sfr __at ( 0xDA )  ADCDATAH ;
__sfr __at ( 0xDF )  PSMCON   ;
__sfr __at ( 0xE0 )  ACC      ;
__sfr __at ( 0xE8 )  DCON     ;
__sfr __at ( 0xE8 )  I2CCON   ;
__sfr __at ( 0xEF )  ADCCON1  ;
__sfr __at ( 0xF0 )  B        ;
__sfr __at ( 0xF1 )  ADCOFSL  ;
__sfr __at ( 0xF2 )  ADCOFSH  ;
__sfr __at ( 0xF3 )  ADCGAINL ;
__sfr __at ( 0xF4 )  ADCGAINH ;
__sfr __at ( 0xF5 )  ADCCON3  ;
__sfr __at ( 0xF7 )  SPIDAT   ;
__sfr __at ( 0xF8 )  SPICON   ;
__sfr __at ( 0xF9 )  DAC0L    ;
__sfr __at ( 0xFA )  DAC0H    ;
__sfr __at ( 0xFB )  DAC1L    ;
__sfr __at ( 0xFC )  DAC1H    ;
__sfr __at ( 0xFD )  DACCON   ;

/* BIT Register..... */
/* TCON */
__sbit __at ( 0x8F ) TF1      ;
__sbit __at ( 0x8E ) TR1      ;
__sbit __at ( 0x8D ) TF0      ;
__sbit __at ( 0x8C ) TR0      ;
__sbit __at ( 0x8B ) IE1      ;
__sbit __at ( 0x8A ) IT1      ;
__sbit __at ( 0x89 ) IE0      ;
__sbit __at ( 0x88 ) IT0      ;
/* P1 */
__sbit __at ( 0x91 ) T2EX     ;
__sbit __at ( 0x90 ) T2       ;
/* SCON */
__sbit __at ( 0x9F ) SM0      ;
__sbit __at ( 0x9E ) SM1      ;
__sbit __at ( 0x9D ) SM2      ;
__sbit __at ( 0x9C ) REN      ;
__sbit __at ( 0x9B ) TB8      ;
__sbit __at ( 0x9A ) RB8      ;
__sbit __at ( 0x99 ) TI       ;
__sbit __at ( 0x98 ) RI       ;
/* IE */
__sbit __at ( 0xAF ) EA       ;
__sbit __at ( 0xAE ) EADC     ;
__sbit __at ( 0xAD ) ET2      ;
__sbit __at ( 0xAC ) ES       ;
__sbit __at ( 0xAB ) ET1      ;
__sbit __at ( 0xAA ) EX1      ;
__sbit __at ( 0xA9 ) ET0      ;
__sbit __at ( 0xA8 ) EX0      ;
/* P3 */
__sbit __at ( 0xB7 ) RD       ;
__sbit __at ( 0xB6 ) WR       ;
__sbit __at ( 0xB5 ) T1       ;
__sbit __at ( 0xB4 ) T0       ;
__sbit __at ( 0xB3 ) INT1     ;
__sbit __at ( 0xB2 ) INT0     ;
__sbit __at ( 0xB1 ) TXD      ;
__sbit __at ( 0xB0 ) RXD      ;
/* IP */
__sbit __at ( 0xBF ) PSI      ;
__sbit __at ( 0xBE ) PADC     ;
__sbit __at ( 0xBD ) PT2      ;
__sbit __at ( 0xBC ) PS       ;
__sbit __at ( 0xBB ) PT1      ;
__sbit __at ( 0xBA ) PX1      ;
__sbit __at ( 0xB9 ) PT0      ;
__sbit __at ( 0xB8 ) PX0      ;
/* WDCON */
__sbit __at ( 0xC7 ) PRE3     ;
__sbit __at ( 0xC6 ) PRE2     ;
__sbit __at ( 0xC5 ) PRE1     ;
__sbit __at ( 0xC4 ) PRE0     ;
__sbit __at ( 0xC3 ) WDIR     ;
__sbit __at ( 0xC2 ) WDS      ;
__sbit __at ( 0xC1 ) WDE      ;
__sbit __at ( 0xC0 ) WDWR     ;
/* T2CON */
__sbit __at ( 0xCF ) TF2      ;
__sbit __at ( 0xCE ) EXF2     ;
__sbit __at ( 0xCD ) RCLK     ;
__sbit __at ( 0xCC ) TCLK     ;
__sbit __at ( 0xCB ) EXEN2    ;
__sbit __at ( 0xCA ) TR2      ;
__sbit __at ( 0xC9 ) CNT2     ;
__sbit __at ( 0xC8 ) CAP2     ;
/* PSW */
__sbit __at ( 0xD7 ) CY       ;
__sbit __at ( 0xD6 ) AC       ;
__sbit __at ( 0xD5 ) F0       ;
__sbit __at ( 0xD4 ) RS1      ;
__sbit __at ( 0xD3 ) RS0      ;
__sbit __at ( 0xD2 ) OV       ;
__sbit __at ( 0xD1 ) F1       ;
__sbit __at ( 0xD0 ) P        ;
/* ADCCON2 */
__sbit __at ( 0xDF ) ADCI     ;
__sbit __at ( 0xDE ) DMA      ;
__sbit __at ( 0xDD ) CCONV    ;
__sbit __at ( 0xDC ) SCONV    ;
__sbit __at ( 0xDB ) CS3      ;
__sbit __at ( 0xDA ) CS2      ;
__sbit __at ( 0xD9 ) CS1      ;
__sbit __at ( 0xD8 ) CS0      ;
/* DCON */
__sbit __at ( 0xEF ) D1       ;
__sbit __at ( 0xEE ) D1EN     ;
__sbit __at ( 0xED ) D0       ;
__sbit __at ( 0xEB ) D0EN     ;
/* I2CCON */
__sbit __at ( 0xEF ) MDO      ;
__sbit __at ( 0xEE ) MDE      ;
__sbit __at ( 0xED ) MCO      ;
__sbit __at ( 0xEC ) MDI      ;
__sbit __at ( 0xEB ) I2CM     ;
__sbit __at ( 0xEA ) I2CRS    ;
__sbit __at ( 0xE9 ) I2CTX    ;
__sbit __at ( 0xE8 ) I2CI     ;
/* SPICON */
__sbit __at ( 0xFF ) ISPI     ;
__sbit __at ( 0xFE ) WCOL     ;
__sbit __at ( 0xFD ) SPE      ;
__sbit __at ( 0xFC ) SPIM     ;
__sbit __at ( 0xFB ) CPOL     ;
__sbit __at ( 0xFA ) CPHA     ;
__sbit __at ( 0xF9 ) SPR1     ;
__sbit __at ( 0xF8 ) SPR0     ;
