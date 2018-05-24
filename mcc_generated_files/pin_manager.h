/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC16F18313
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set _NC0 aliases
#define _NC0_TRIS               TRISAbits.TRISA0
#define _NC0_LAT                LATAbits.LATA0
#define _NC0_PORT               PORTAbits.RA0
#define _NC0_WPU                WPUAbits.WPUA0
#define _NC0_OD                ODCONAbits.ODCA0
#define _NC0_ANS                ANSELAbits.ANSA0
#define _NC0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define _NC0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define _NC0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define _NC0_GetValue()           PORTAbits.RA0
#define _NC0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define _NC0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define _NC0_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define _NC0_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define _NC0_SetPushPull()    do { ODCONAbits.ODCA0 = 0; } while(0)
#define _NC0_SetOpenDrain()   do { ODCONAbits.ODCA0 = 1; } while(0)
#define _NC0_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define _NC0_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set _NC1 aliases
#define _NC1_TRIS               TRISAbits.TRISA1
#define _NC1_LAT                LATAbits.LATA1
#define _NC1_PORT               PORTAbits.RA1
#define _NC1_WPU                WPUAbits.WPUA1
#define _NC1_OD                ODCONAbits.ODCA1
#define _NC1_ANS                ANSELAbits.ANSA1
#define _NC1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define _NC1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define _NC1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define _NC1_GetValue()           PORTAbits.RA1
#define _NC1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define _NC1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define _NC1_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define _NC1_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define _NC1_SetPushPull()    do { ODCONAbits.ODCA1 = 0; } while(0)
#define _NC1_SetOpenDrain()   do { ODCONAbits.ODCA1 = 1; } while(0)
#define _NC1_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define _NC1_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()     do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()   do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set btWakeup aliases
#define btWakeup_PORT               PORTAbits.RA3
#define btWakeup_WPU                WPUAbits.WPUA3
#define btWakeup_GetValue()           PORTAbits.RA3
#define btWakeup_SetPullup()      do { WPUAbits.WPUA3 = 1; } while(0)
#define btWakeup_ResetPullup()    do { WPUAbits.WPUA3 = 0; } while(0)

// get/set probePin aliases
#define probePin_TRIS               TRISAbits.TRISA4
#define probePin_LAT                LATAbits.LATA4
#define probePin_PORT               PORTAbits.RA4
#define probePin_WPU                WPUAbits.WPUA4
#define probePin_OD                ODCONAbits.ODCA4
#define probePin_ANS                ANSELAbits.ANSA4
#define probePin_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define probePin_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define probePin_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define probePin_GetValue()           PORTAbits.RA4
#define probePin_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define probePin_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define probePin_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define probePin_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define probePin_SetPushPull()    do { ODCONAbits.ODCA4 = 0; } while(0)
#define probePin_SetOpenDrain()   do { ODCONAbits.ODCA4 = 1; } while(0)
#define probePin_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define probePin_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set probePwr aliases
#define probePwr_TRIS               TRISAbits.TRISA5
#define probePwr_LAT                LATAbits.LATA5
#define probePwr_PORT               PORTAbits.RA5
#define probePwr_WPU                WPUAbits.WPUA5
#define probePwr_OD                ODCONAbits.ODCA5
#define probePwr_ANS                ANSELAbits.ANSA5
#define probePwr_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define probePwr_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define probePwr_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define probePwr_GetValue()           PORTAbits.RA5
#define probePwr_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define probePwr_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define probePwr_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define probePwr_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define probePwr_SetPushPull()    do { ODCONAbits.ODCA5 = 0; } while(0)
#define probePwr_SetOpenDrain()   do { ODCONAbits.ODCA5 = 1; } while(0)
#define probePwr_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define probePwr_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF3 pin functionality
 * @Example
    IOCAF3_ISR();
 */
void IOCAF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_InterruptHandler);

*/
extern void (*IOCAF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_DefaultInterruptHandler);

*/
void IOCAF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/