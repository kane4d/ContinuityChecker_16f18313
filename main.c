/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F18313
        Driver Version    :  2.00
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include "nco_melody.h"
/*
                         Main application
 */

/*
 *  probePin adc value
 *  ohm value
 *  14  0.90mV
 *  16  1.02
 *  18  1.14
 *  20  1.26
 *  22  1.38
 *  24  1.50
 *  26  1.62
 *  28  1.74
 *  30  1.86
 */
volatile struct {
    adc_result_t val;
    adc_result_t dacVal;
    uint16_t ttl;
} probe;

// Battery ADC Level
#define BATT_ADC_LEVEL_LOW  (600u)  /* 2.4V */
#define BATT_ADC_LEVEL_STOP (550u)  /* 2.2V */
#define PROBE_ISR_ON() {DAC1_SetOutput(0);__delay_us(10);PIR2bits.C1IF = 0;PIE2bits.C1IE = 1;}
#define PROBE_ISR_OFF() {PIE2bits.C1IE = 0;}
#define PROBE_PWR_ON() {probePwr_SetPushPull(); probePwr_SetHigh();}
#define PROBE_PWR_OFF() {probePwr_SetOpenDrain();probePwr_SetHigh();}
#define DEEP_SLEEP() {VREGCONbits.VREGPM = 1;SLEEP();NOP();}
#define LIGHT_SLEEP() {VREGCONbits.VREGPM = 0;SLEEP();NOP();}
#define WDT_ON() {WDTCONbits.SWDTEN=1;}
#define WDT_OFF() {WDTCONbits.SWDTEN=0;}

// NCO Melody Test mode
// #define TEST_MODE

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
   
    PROBE_ISR_OFF();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    // GE=0でもSLEEPから復帰する
    // SLEEPから復帰後、ISRを実行しないだけのはず
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    // 未使用ピンをLowに設定
    _NC0_SetLow();
    _NC1_SetLow();

    // probePwr_SetLow(); // ProbePwr 0V
    // プローブへのPORTから電源供給を停止する。
    // しかしバッテリーから直接抵抗(5.1MΩ)を通してプローブへ電源供給(約180mV)される。
    // この電圧をSLEEP時にCMP1で監視してSLEEPから復帰する。
    // CMP1ではVdd/32=約90mVとプローブ(約180mV)を比較している。
    // 高インピーダンスのためCMP1(ADC)入力前に誤作動防止の2.2nFを追加した。
    // コンデンサが無いとタッチセンサー並みの感度でCMP1が動作する。
    PROBE_PWR_OFF();
    DAC1_SetOutput(8); // Vdd = 3V, DACout = 750mV

    // FVRの立ち上がり待ち
    // 恐らく不要な処理
    while (!FVR_IsOutputReady()) {
        NOP();
        NOP();
        NOP();
    }
    // バッテリー電圧をチェック
    // FVR = 1.024VとバッテリーをDAC(8)で分圧したものを比較
    probe.dacVal = ADC_GetConversion(channel_DAC1);
    if (probe.dacVal > BATT_ADC_LEVEL_LOW) {
        //playMelody_lowBatt();
    } else if (probe.dacVal < BATT_ADC_LEVEL_STOP) {
        playMelody_halt();
    } else {
        playMelody_lowBatt();
    }
    // SLEEP時の演奏
    playMelody_sleep();
#ifdef TEST_MODE
    while (1) {
        playMelody_pc98_pipo();
        mute(NOTE_WHOLE);
        playMelody_sleep();
        mute(NOTE_WHOLE);
        playMelody_halt();
        mute(NOTE_WHOLE);
        playMelody_lowBatt();
        mute(NOTE_WHOLE);
        playMelody_test();
        mute(NOTE_WHOLE);
        playMelody_charumera();
        mute(NOTE_WHOLE);
        playMelody_fullScale(NOTE_QUOTER);
        mute(NOTE_WHOLE);
    }

#endif

    // PMDでスリープ時に不要な周辺機器を停止する。
    // PMDレジスタに16進数で直接値を代入する自信がないので、ここでは各bitに直接値を代入している。
    // CLKRMD CLKR enabled; SYSCMD SYSCLK enabled; FVRMD FVR disabled; IOCMD IOC enabled; NVMMD NVM enabled; 
    // PMD0 = 0x40;
    // FVR 25uA この消費電力はデカい
    PMD0bits.FVRMD = 1;
    // TMR0MD TMR0 disabled; TMR1MD TMR1 disabled; TMR2MD TMR2 disabled; NCOMD DDS(NCO) disabled; 
    // PMD1 = 0x87;
    PMD1bits.TMR0MD = PMD1bits.TMR1MD = PMD1bits.TMR2MD = 1;
    PMD1bits.NCOMD = 1;
    // DACMD DAC enabled; CMP1MD CMP1 enabled; ADCMD ADC disabled; 
    // PMD2 = 0x20;
    // CMP1 30uA
    PMD2bits.CMP1MD = 0; // On
    PMD2bits.ADCMD = 1;
    // CCP2MD CCP2 disabled; CCP1MD CCP1 disabled; PWM6MD PWM6 disabled; PWM5MD PWM5 disabled; CWG1MD CWG1 disabled; 
    // PMD3 = 0x73;
    PMD3bits.CCP2MD = PMD3bits.CCP1MD = 1;
    PMD3bits.PWM6MD = PMD3bits.PWM5MD = 1;
    PMD3bits.CWG1MD = 1;
    // MSSP1MD MSSP1 disabled; UART1MD EUSART disabled; 
    // PMD4 = 0x22;
    PMD4bits.MSSP1MD = PMD4bits.UART1MD = 1;
    // DSMMD DSM disabled; CLC1MD CLC1 disabled; CLC2MD CLC2 disabled; 
    // PMD5 = 0x07;
    PMD5bits.DSMMD = 1;
    PMD5bits.CLC1MD = PMD5bits.CLC2MD = 1;
    
    // CMP1を使ったプローブ電圧の監視On
    PROBE_ISR_ON();
    
    // 起動時とWDTリセット時にここからSLEEPに突入する
    // WDTではSLEEP解除させない　SYSTEM_Initialize()内でOFFだけど念の為。
    WDT_OFF();
    DEEP_SLEEP();
    // PMDで周辺機器を休止してるので、初期化処理を再実行
    SYSTEM_Initialize();
    WDT_ON();
    PMD1bits.TMR0MD = PMD1bits.TMR1MD = PMD1bits.TMR2MD = 1;
    PMD3bits.CCP2MD = PMD3bits.CCP1MD = 1;
    PMD3bits.PWM6MD = PMD3bits.PWM5MD = 1;
    PMD3bits.CWG1MD = 1;
    PMD4bits.MSSP1MD = PMD4bits.UART1MD = 1;
    PMD5bits.CLC1MD = PMD5bits.CLC2MD = 1;
    
    // 旧国民機の起動音再生
    playMelody_pc98_pipo();
    // プローブへ電源供給
    // ダイオードのVf値500mVがプローブへ供給される
    PROBE_PWR_ON();

    // FVRの立ち上がり待ち
    // 恐らく不要な処理
    

    while (1) {
        toneOff();
        PROBE_PWR_OFF();
        if (!CMP1_GetOutputStatus())
        {   // 省電力化のためにCMP1の値が下がるまでSLEEPしてADCへ行かない。
            // この省電力化のおかげでリセットの必要性が無くなってしまった。
            // しかし、国民機の起動音は捨てがたい。
            // 起動音があるとメリハリがあるので、WDTリセットを残す。
            PMD1bits.NCOMD = 1;// -70uA
            PMD0bits.FVRMD = 1;// -25uA
            DEEP_SLEEP();
            if (STATUSbits.nTO == 0)
            {
                // http://ww1.microchip.com/downloads/en/DeviceDoc/PIC16(L)F1831318323%20Full%20Featured%20Low%20Pin%20Count%20Microcontrollers%20with%20XLP_40001799D.pdf
                // page 63
                // WDT wakeup from sleep
                // nTO == 0, nPD ==0
                RESET();
            }
            PROBE_PWR_ON();
            PMD0bits.FVRMD = 0;
            FVR_Initialize();
            PMD1bits.NCOMD = 0;
            NCO1_Initialize();
            while (!FVR_IsOutputReady()) {
                NOP();
                NOP();
                NOP();
            }
        }
        // ADCの値により音程を変化させている。
        // ダイオードによりVfが違うので、ここの値(CASE)をお好みにより変更する。
        // 将来的にはEEPROMの値テーブルと比較するようにしたい。
        // btWakeupはキャリブレーション等の設定モードへの入り口としてリザーブしている。
        // CLRWDTは演奏中に実行するように変更した。
        probe.val = ADC_GetConversion(probePin);
        switch (probe.val ) {
            case 0: // 
            case 1: // 
            case 2: // 
                toneOn(SCALE_G6, NOTE_128TH);
                break;
            case 3: // 
                toneOn(SCALE_E6, NOTE_64TH);
                break;
            case 4: // 
                toneOn(SCALE_C6, NOTE_32TH);
                break;
            case 5: // 20ohm
                toneOn(SCALE_G5, NOTE_16TH);
                break;

            default:
                toneOff();
        }
    }
}
/**
 End of File
 */