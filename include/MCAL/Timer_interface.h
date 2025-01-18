/**
 * @file    Timer_Interface.h
 * @author  Mohamed Moaaz
 * @brief   Timer interfacing file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __TIMER_INTERFACE_H__
#define __TIMER_INTERFACE_H__

//==============================================================================
// Macros & Defines
//==============================================================================


//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

void Timer0_Init(void);
E_Status Timer0_StartFastPWM(uint8_t copy_u8DutyCycle);
E_Status Timer0_SetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer1_Init(void);
void Timer1_voidStart(void);
void Timer1_voidSetTimerValue(uint16_t copy_u16Value);
uint16_t Timer1_u16ReadTimerValue(void);


#endif /* __TIMER_INTERFACE_H__ */