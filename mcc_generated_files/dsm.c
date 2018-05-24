/**
  DSM Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dsm.c

  @Summary
    This is the generated driver implementation file for the DSM driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DSM.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F18313
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45 
        MPLAB 	          :  MPLAB X 4.10
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
#include "dsm.h"

/**
  Section: DSM APIs
*/

void DSM_Initialize(void)
{
    // set the DSM to the options selected in the User Interface
    
    // Modulator Output Pin Polarity is not inverted
    MDCONbits.MDOPOL = 0; 

    // MDMS Manual; 
    MDSRC = 0x00;

    // MDCHSYNC disabled; MDCH NCO1_out; MDCHPOL not inverted; 
    MDCARH = 0x08;

    // MDCLPOL not inverted; MDCL VSS; MDCLSYNC disabled; 
    MDCARL = 0x00;

    // Enable the Modulator
    MDCONbits.MDEN = 1;  

}

void DSM_ManualModulationSet (void)
{
    // Set MDBIT to High, Modulator uses high carrier source
    MDCONbits.MDBIT = 1;
}

void DSM_ManualModulationClear (void)
{
    // Set MDBIT to Low, Modulator uses low carrier source
    MDCONbits.MDBIT = 0;
}

void DSM_ManualModulationToggle (void)
{
    // Toggle the MDBIT
    MDCONbits.MDBIT ^= 1;
}

void DSM_ModulationStart (void)
{
    // Enables module and begins modulation
    MDCONbits.MDEN = 1;
}

void DSM_ModulationStop (void)
{
    // Disables module and stops modulation
    MDCONbits.MDEN = 0;
}

/**
 End of File
*/