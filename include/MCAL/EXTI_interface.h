/**
 * @file    EXTI_interface.h
 * @author  Mohamed Moaaz
 * @brief   External interrupt interface file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__


//==============================================================================
// Macros & Defines
//==============================================================================

#define LOW_LEVEL       1
#define ON_CHANGE       2
#define FALLING_EDGE    3
#define RISING_EDGE     4

#define ENABLED         1
#define DISABLED        2

#define EXTINT_INT0     1
#define EXTINT_INT1     2
#define EXTINT_INT2     3

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

E_Status EXTI_voidInt0SenseControl(uint8_t copy_u8Sense);

E_Status EXTI_voidInt1SenseControl(uint8_t copy_u8Sense);

E_Status EXTI_voidInt2SenseControl(uint8_t copy_u8Sense);

E_Status EXTI_voidInt0State(uint8_t copy_u8State);

E_Status EXTI_voidInt1State(uint8_t copy_u8State);

E_Status EXTI_voidInt2State(uint8_t copy_u8State);

void EXTINT_voidSetCallBack(void (*copy_pvfun)(void), uint8_t copy_u8ExtIntIndex);


#endif /* __EXTI_INTERFACE_H__ */