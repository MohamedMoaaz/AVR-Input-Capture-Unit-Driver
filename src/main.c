/**
 * @file    main.c
 * @author  Mohamed Moaaz
 * @brief   Main executable file
 * @version 0.1
 * @date    2023-10-31
 * 
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/PORT_interface.h"
#include "MCAL/GIE_interface.h"
#include "MCAL/Timer_interface.h"
#include "MCAL/EXTI_interface.h"

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


//==============================================================================
// Static Functions Prototypes
//==============================================================================


//==============================================================================
// Static Functions
//==============================================================================


//==============================================================================
// Global Functions
//==============================================================================
void ICU_SW(void);
/**
 * @brief   Main function.
 * @return  Status code.
 */

static uint16_t PeriodTicks = 0;
static uint16_t OnTicks = 0;
int main(void)
{
    PORT_voidInit();
    Timer0_SetCallBack(ICU_SW);
    EXTI_voidInt0Init();
    Timer1_Init();
    Timer1_voidStart();
    Timer0_Init();
    Timer0_StartFastPWM(64);
    GIE_voidEnable();
    
    for (;;)
    {
        while ((PeriodTicks == 0) && (OnTicks == 0));
    }
    return 0;
}

void ICU_SW(void)
{
    static uint8_t Local_u8counter = 0;
    Local_u8counter++;
    if (Local_u8counter == 1)
    {
        Timer1_voidSetTimerValue(0);
    }
    else if(Local_u8counter == 2)
    {
        PeriodTicks = Timer1_voidReadTimerValue();
        EXTI_voidInt0SenseControl(FALLING_EDGE);
    }
    else if(Local_u8counter == 3)
    {
        OnTicks  = Timer1_voidReadTimerValue();
        OnTicks -= PeriodTicks;
        EXTI_voidInt0State(DISABLED);
    }

}
