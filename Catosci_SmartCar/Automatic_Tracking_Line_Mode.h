// Automatic_Tracking_Line_Mode.h

#ifndef _AUTOMATIC_TRACKING_LINE_MODE_h
#define _AUTOMATIC_TRACKING_LINE_MODE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Catosci_4WD_Car_for_Arduino.h"


#define TK_STOP_SPEED					0
#define TK_FORWARD_SPEED				(35 + tk_VoltageCompensationToSpeed	   )
#define TK_FORWARD_SPEED_LOW			(30 + tk_VoltageCompensationToSpeed	   )
#define TK_TURN_SPEED_LV4				(70 + tk_VoltageCompensationToSpeed   )
#define TK_TURN_SPEED_LV3				(60 + tk_VoltageCompensationToSpeed   )
#define TK_TURN_SPEED_LV2				(-55 + tk_VoltageCompensationToSpeed  )
#define TK_TURN_SPEED_LV1				(-60 + tk_VoltageCompensationToSpeed  )

#define TK_SPEED_OFFSET_PER_V			10


void tk_CalculateVoltageCompensation();
void updateAutomaticTrackingLine();

#endif
