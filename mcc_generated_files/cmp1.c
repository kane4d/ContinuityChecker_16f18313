 /**
   CMP1 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cmp1.c
 
   @Summary
     This is the generated driver implementation file for the CMP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CMP1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
         Device            :  PIC16F18313
         Driver Version    :  2.00
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.45 or later
         MPLAB             :  MPLAB X 4.10
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
 
 /**
   Section: Included Files
 */


#include <xc.h>
#include "cmp1.h"
/**
  Section: CMP1 APIs
*/

void CMP1_Initialize(void)
{
    /* Disable CMP1 interrupt before configuring the CMP1
       control register. Although a comparator is disabled, an interrupt can be
       generated by changing the output polarity with the CxPOL bit of the
       CMxCON0 register,or by switching the comparator on or off with the CxON
       bit of the CMxCON0 register.*/
    PIE2bits.C1IE = 0;

	// C1HYS disabled; C1SP lo_speed; C1ON enabled; C1POL not inverted; C1SYNC asynchronous;                          
    CM1CON0 = 0x80;
	
	// C1INTN intFlag_neg; C1INTP no_intFlag; C1PCH DAC; C1NCH CIN1-;                          
    CM1CON1 = 0x69;
	
    // Clearing IF flag before enabling the interrupt.
    PIR2bits.C1IF = 0;

    // Enabling CMP1 interrupt.
    PIE2bits.C1IE = 1;
}

bool CMP1_GetOutputStatus(void)
{
	return (CMOUTbits.MC1OUT);
}

void CMP1_ISR(void)
{
    // clear the CMP1 interrupt flag
    PIR2bits.C1IF = 0;
}

/**
 End of File
*/
