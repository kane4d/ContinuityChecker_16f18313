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

// NCO Melody Test mode
// #define TEST_MODE

void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
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

    probePwr_SetLow(); // ProbePwr 0V
    DAC1_SetOutput(8); // Vdd = 3V, DACout = 750mV

    // FVRの立ち上がり待ち
    while (!FVR_IsOutputReady()) {
        NOP();
        NOP();
        NOP();
    }
    // バッテリー電圧をチェック
    probe.dacVal = ADC_GetConversion(channel_DAC1);
    if (probe.dacVal > BATT_ADC_LEVEL_LOW) {
        //playMelody_lowBatt();
    } else if (probe.dacVal < BATT_ADC_LEVEL_STOP) {
        playMelody_halt();
    } else {
        playMelody_lowBatt();
    }

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

    SLEEP();
    NOP();
    playMelody_pc98_pipo();
    probePwr_SetHigh();
    while (1) {
        toneOff();
        probe.val = ADC_GetConversion(probePin);
        switch (probe.val ) {
            case 0: // 
            case 1: // 
            case 2: // 
                toneOn(SCALE_G6, NOTE_64TH);
                break;
            case 3: // 
                toneOn(SCALE_E6, NOTE_64TH);
                break;
            case 4: // 
                toneOn(SCALE_C6, NOTE_64TH);
                break;
            case 5: // 3mV
                //CLRWDT();
                toneOn(SCALE_G5, NOTE_64TH);
                break;

            default:
                toneOff();

        }
    }
}
/**
 End of File
 */