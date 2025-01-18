/**
 * @file    EXTI_register.h
 * @author  Mohamed Moaaz
 * @brief   External interrupt register file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __EXTI_REGISTER_H__
#define __EXTI_REGISTER_H__

//==============================================================================
// Macros & Defines
//==============================================================================

#define GICR                *((volatile uint8_t*) 0x5B)
#define GICR_INT1           7
#define GICR_INT0           6
#define GICR_INT2           5

#define GIFR                *((volatile uint8_t*) 0x5A)

#define MCUCR               *((volatile uint8_t*) 0x55)
#define MCUCR_ISC11         3
#define MCUCR_ISC10         2
#define MCUCR_ISC01         1
#define MCUCR_ISC00         0

#define MCUCSR              *((volatile uint8_t*) 0x54)
#define MCUCSR_ISC2         6

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __EXTI_REGISTER_H__ */