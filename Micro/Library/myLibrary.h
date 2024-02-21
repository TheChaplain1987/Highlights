// A library for the PIC18F4520

int *TRISA = 0xF92; // Connect to TRISx
int *TRISB = 0xF93;
int *TRISC = 0xF94;
int *TRISD = 0xF95;
int *TRISE = 0xF96;

int *LATA = 0xF89;  // Connect to LATx
int *LATB = 0xF8A;
int *LATC = 0xF8B;
int *LATD = 0xF8C;
int *LATE = 0xF8D;

int *PORTA = 0xF80; // Connect to LATx
int *PORTB = 0xF81;
int *PORTC = 0xF82;
int *PORTD = 0xF83;
int *PORTE = 0xF84;

struct _adcon0 {
   int ADON:1;
   int GODONE:1;
   int CHSx:4;
   int unused:2;
};
struct _adcon0 *ADCON0 = 0xFC2;

struct _adcon1 {   // Analog vs digital
   int PCFGx:4;
   int VCFG0:1;
   int VCFG1:1;
   int unused:2;
};
struct _adcon1 *ADCON1 = 0xFC1;

struct _adcon2 {
   int ADCSx:3;
   int ACQTx:3;
   int unused:1;
   int ADFM:1;
};
struct _adcon2 *ADCON2 = 0xFC0;

int16 *Q = 0xFC3;
int *ADRESH = 0xFC4;
int *ADRESL = 0xFC3;

struct _intcon {
   int RBIF:1;
   int INT0IF:1;
   int TMR0IF:1;
   int RBIE:1;
   int INT0IE:1;
   int TMR0IE:1;
   int PEIE:1;
   int GIE:1;
};
struct _intcon *INTCON = 0xFF2;

struct _intcon3 {
   int INT1IF:1;
   int INT2IF:1;
   int unused:1;
   int INT1IE:1;
   int INT2IE:1;
   int notused:1;
   int INT1IP:1;
   int INT2IP:1;
};
struct _intcon3 *INTCON3 = 0xFF0;

struct _intcon2 {  // Interrupts
   int RBIP:1;
   int unused:1;
   int TMR0IP:1;
   int notused:1;
   int INTEDG2:1;
   int INTEDG1:1;
   int INTEDG0:1;
   int RBPU:1;
};
struct _intcon2 *INTCON2 = 0xFF1;

struct _pie1 {
   int TMR1IE:1;
   int TMR2IE:1;
   int CCP1IE:1;
   int SSPIE:1;
   int TXIE:1;
   int RCIE:1;
   int ADIE:1;
   int PSPIE:1;
};
struct _pie1 *PIE1 = 0xF9D;

struct _pie2 {
   int CCP2IE:1;
   int TMR3IE:1;
   int HLVDIE:1;
   int BCLIE:1;
   int EEIE:1;
   int skip:1;
   int CMIE:1;
   int OSCFIE:1;
};
struct _pie2 *PIE2 = 0xFA0;

struct _t1con {
   int TMR1ON:1;
   int TMR1CS:1;
   int T1SYNC:1;
   int T1OSCEN:1;
   int T1CKPSx:2;
   int T1RUN: 1;
   int RD16:1;
};
struct _t1con *T1CON = 0xFCD;

struct _t2con {
   int T2CKPSx:2;
   int TMR2ON:1;
   int T2OUTPSx:4;
   int unused:1;
};
struct _t2con *T2CON = 0xFCA;

struct _ccpxcon {
   int CCPxMx:4;
   int DCxBx:2;
   int unused:2;
};
struct _ccpxcon *CCP1CON = 0xFBD;
struct _ccpxcon *CCP2CON = 0xFBA;

int16 *CCPR1 = 0xFBE;
int *CCPR1L = 0xFBE;
int16 *CCPR2 = 0xFBB;
int *CCPR2L = 0xFBB;
int *PR2 = 0xFCB;

struct _eccplas {
   int PSSBD:2;
   int PSSAC:2;
   int ECCPAS:3;
   int ECCPASE:1;
};
struct _eccplas *ECCP1AS = 0xFB6;

// USART
struct _txsta{
   int TX9D:1;
   int TRMT:1;
   int BRGH:1;
   int SENDB:1;
   int SYNC:1;
   int TXEN:1;
   int TX9:1;
   int CSRC:1;
};
struct _txsta *TXSTA = 0xFAC;

struct _rcsta{
   int RX9D:1;
   int OERR:1;
   int FERR:1;
   int ADDEN:1;
   int CREN:1;
   int SREN:1;
   int RX9:1;
   int SPEN:1;
};
struct _rcsta *RCSTA = 0xFAB;

struct _baudcon{
   int ABDEN:1;
   int WUE:1;
   int unused:1;
   int BRG16:1;
   int TXCKP:1;
   int RXDTP:1;
   int RCIDL:1;
   int ABDOVF:1;
};
struct _baudcon *BAUDCON = 0xFB8;

int *SPBRG = 0xFAF;  // Speed Control
int *TXREG = 0xFAD;
int *RCREG = 0xFAE;

