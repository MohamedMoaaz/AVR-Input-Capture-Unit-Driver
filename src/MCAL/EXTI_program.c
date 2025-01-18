/**
 * @file    EXTI_program.c
 * @author  Mohamed Moaaz
 * @brief   External interrupt program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/PORT_interface.h"
#include "MCAL/EXTI_interface.h"
#include "MCAL/EXTI_private.h"
#include "MCAL/EXTI_register.h"
#include "MCAL/EXTI_configuration.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

static void (*EXTINT_ApfuncEXTINT[3])(void);

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

void EXTI_voidInt0Init(void)
{
    /*Set sense control for INTO*/
    #if(INT0_SENSE_CTL == LOW_LEVEL)
    /*set sense control as low level*/
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
        
    #elif(INT0_SENSE_CTL == ON_CHANGE)
    /*set sense control as any change*/
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
        SET_BIT(MCUCR, MCUCR_ISC00);
    #elif(INT0_SENSE_CTL == FALLING_EDGE)
    /*set sense control as falling edge*/
        SET_BIT(MCUCR, MCUCR_ISC01);
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
    #elif(INT0_SENSE_CTL == RISING_EDGE)
    /*set sense control as rising edge*/
        SET_BIT(MCUCR, MCUCR_ISC01);
        SET_BIT(MCUCR, MCUCR_ISC00);
    #else
    #error "Wrong Sense control configuration option"
    #endif

    /*Set initial state for INT0*/
    #if(INT0_INITIAL_STATE == ENABLED)
    /*set initial state as enabled*/
        SET_BIT(GICR, GICR_INT0);
    #elif(INT0_INITIAL_STATE == DISABLED)
    /*set initial state as disabled*/
        CLEAR_BIT(GICR, GICR_INT0);
    #else
    #error "Wrong Initial state configuration option"
    #endif

}

void EXTI_voidInt1Init(void)
{
    /*Set sense control for INT1*/
    #if(INT1_SENSE_CTL == LOW_LEVEL)
    /*set sense control as low level*/
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
        
    #elif(INT1_SENSE_CTL == ON_CHANGE)
    /*set sense control as any change*/
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
        SET_BIT(MCUCR, MCUCR_ISC10);
    #elif(INT1_SENSE_CTL == FALLING_EDGE)
    /*set sense control as falling edge*/
        SET_BIT(MCUCR, MCUCR_ISC11);
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
    #elif(INT1_SENSE_CTL == RISING_EDGE)
    /*set sense control as rising edge*/
        SET_BIT(MCUCR, MCUCR_ISC11);
        SET_BIT(MCUCR, MCUCR_ISC10);
    #else
    #error "Wrong Sense control configuration option"
    #endif

    /*Set initial state for INT1*/
    #if(INT1_INITIAL_STATE == ENABLED)
    /*set initial state as enabled*/
        SET_BIT(GICR, GICR_INT1);
    #elif(INT1_INITIAL_STATE == DISABLED)
    /*set initial state as disabled*/
        CLEAR_BIT(GICR, GICR_INT1);
    #else
    #error "Wrong Initial state configuration option"
    #endif
}

void EXTI_voidInt2Init(void)
{

    /*Set sense control for INT2*/
    #if(INT2_SENSE_CTL == FALLING_EDGE)
    /*set sense control as falling edge*/
    CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
    #elif(INT2_SENSE_CTL == RISING_EDGE)
    /*set sense control as rising edge*/
        SET_BIT(MCUCSR, MCUCR_ISC2);
    #else
    #error "Wrong Sense control configuration option"
    #endif

    /*Set initial state for INT2*/
    #if(INT2_INITIAL_STATE == ENABLED)
    /*set initial state as enabled*/
        SET_BIT(GICR, GICR_INT2);
    #elif(INT2_INITIAL_STATE == DISABLED)
    /*set initial state as disabled*/
        CLEAR_BIT(GICR, GICR_INT2);
    #else
    #error "Wrong Initial state configuration option"
    #endif
}

E_Status EXTI_voidInt0SenseControl(uint8_t copy_u8Sense)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Set sense control for INTO*/
    switch (copy_u8Sense)
    {
    case LOW_LEVEL:
    /*set sense control as low level*/
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
        break;
    case ON_CHANGE:
    /*set sense control as any change*/
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
        SET_BIT(MCUCR, MCUCR_ISC00);
        break;
    case FALLING_EDGE:
    /*set sense control as falling edge*/
        SET_BIT(MCUCR, MCUCR_ISC01);
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
        break;
    case RISING_EDGE:
    /*set sense control as rising edge*/
        SET_BIT(MCUCR, MCUCR_ISC01);
        SET_BIT(MCUCR, MCUCR_ISC00);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
    }
    return Local_u8ErrorState;

}

E_Status EXTI_voidInt1SenseControl(uint8_t copy_u8Sense)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Set sense control for INT1*/
    switch (copy_u8Sense)
    {
    case LOW_LEVEL:
    /*set sense control as low level*/
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
        break;
    case ON_CHANGE:
    /*set sense control as any change*/
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
        SET_BIT(MCUCR, MCUCR_ISC10);
        break;
    case FALLING_EDGE:
    /*set sense control as falling edge*/
        SET_BIT(MCUCR, MCUCR_ISC11);
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
        break;
    case RISING_EDGE:
    /*set sense control as rising edge*/
        SET_BIT(MCUCR, MCUCR_ISC11);
        SET_BIT(MCUCR, MCUCR_ISC10);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
    }
    return Local_u8ErrorState;
}

E_Status EXTI_voidInt2SenseControl(uint8_t copy_u8Sense)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Set sense control for INT2*/
    switch (copy_u8Sense)
    {
    case FALLING_EDGE:
    /*set sense control as failing edge*/
        CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
        break;
    case RISING_EDGE:
    /*set sense control as rising edge*/
        SET_BIT(MCUCSR, MCUCSR_ISC2);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
    }
    return Local_u8ErrorState;
}

E_Status EXTI_voidInt0State(uint8_t copy_u8State)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Peripheral interrupt enable for INTO*/
    switch (copy_u8State)
    {
    case ENABLED:
    /*set Interrupt state as enabled*/
        SET_BIT(GICR, GICR_INT0);
        break;
    case DISABLED:
    /*set Interrupt state as disabled*/
        CLEAR_BIT(GICR, GICR_INT0);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
}
return Local_u8ErrorState;
}

E_Status EXTI_voidInt1State(uint8_t copy_u8State)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Peripheral interrupt enable for INT1*/
    switch (copy_u8State)
    {
    case ENABLED:
    /*set Interrupt state as enabled*/
        SET_BIT(GICR, GICR_INT1);
        break;
    case DISABLED:
    /*set Interrupt state as disabled*/
        CLEAR_BIT(GICR, GICR_INT1);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
}
return Local_u8ErrorState;
}

E_Status EXTI_voidInt2State(uint8_t copy_u8State)
{
    E_Status Local_u8ErrorState = E_OK;
    /*Peripheral interrupt enable for INT2*/
    switch (copy_u8State)
    {
    case ENABLED:
    /*set Interrupt state as enabled*/
        SET_BIT(GICR, GICR_INT2);
        break;
    case DISABLED:
    /*set Interrupt state as disabled*/
        CLEAR_BIT(GICR, GICR_INT2);
        break;
    default:
    Local_u8ErrorState = E_NOK;
        break;
}
return Local_u8ErrorState;
}

void EXTINT_voidSetCallBack(void (*copy_pvfun)(void), uint8_t copy_u8ExtIntIndex)
{
    EXTINT_ApfuncEXTINT[copy_u8ExtIntIndex] = copy_pvfun;
}

// /* ISR Function for External Interrupt 0 */
// void __vector_1(void)  __attribute__((signal));
// void __vector_1(void)
// {
// 	EXTINT_ApfuncEXTINT[EXTINT_INT0]();
// }
// /* ISR Function for External Interrupt 1 */
// void __vector_2(void)  __attribute__((signal));
// void __vector_2(void)
// {
// 	EXTINT_ApfuncEXTINT[EXTINT_INT1]();
// }
// /* ISR Function for External Interrupt 2 */
// void __vector_3(void)  __attribute__((signal));
// void __vector_3(void)
// {
// 	EXTINT_ApfuncEXTINT[EXTINT_INT2]();
// }