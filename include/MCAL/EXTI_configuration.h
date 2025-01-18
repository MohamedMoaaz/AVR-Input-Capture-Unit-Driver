/**
 * @file    EXTI_configuration.h
 * @author  Mohamed Moaaz
 * @brief   External interrupt configuration file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __EXTI_CFG_H__
#define __EXTI_CFG_H__

//==============================================================================
// Macros & Defines
//==============================================================================

/*Select Interrupt0 sense control
options :
            1- LOW_LEVEL
            2- ON_CHANGE
            3- FALLING_EDGE
            4- RISING_EDGE
            */

#define INT0_SENSE_CTL         RISING_EDGE

/*Select Interrupt0 sense control
options :
            1- LOW_LEVEL
            2- ON_CHANGE
            3- FALLING_EDGE
            4- RISING_EDGE
            */
#define INT1_SENSE_CTL          LOW_LEVEL

/*Select Interrupt1 sense control
options :
            1- FALLING_EDGE
            2- RISING_EDGE
            */
#define INT2_SENSE_CTL          FALLING_EDGE

/*Select Interrupt0 Initial state
options :
            1- ENABLED
            2- DISABLED
            */
#define INT0_INITIAL_STATE      ENABLED

/*Select Interrupt1 Initial state
options :
            1- ENABLED
            2- DISABLED
            */
#define INT1_INITIAL_STATE      DISABLED

/*Select Interrupt2 Initial state
options :
            1- ENABLED
            2- DISABLED
            */
#define INT2_INITIAL_STATE      DISABLED

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __EXTI_CFG_H__ */