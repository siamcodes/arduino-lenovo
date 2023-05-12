// Automatic_Obstacle_Avoidance.h

#ifndef _AUTOMATIC_OBSTACLE_AVOIDANCE_h
#define _AUTOMATIC_OBSTACLE_AVOIDANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <EEPROM.h>
#include "Servo.h"
#include "Catosci_4WD_Car_for_Arduino.h"

#define OA_SERVO_CENTER					  (90)
#define OA_SCAN_ANGLE_INTERVAL	  50
#define OA_SCAN_ANGLE_MIN		      (OA_SERVO_CENTER - OA_SCAN_ANGLE_INTERVAL)
#define OA_SCAN_ANGLE_MAX		      (OA_SERVO_CENTER + OA_SCAN_ANGLE_INTERVAL)
#define OA_WAITTING_SERVO_TIME	  130

#define OA_ROTATY_SPEED_LOW        (45 + oa_VoltageCompensationToSpeed)
#define OA_ROTATY_SPEED_NORMAL    (60 + oa_VoltageCompensationToSpeed)
#define OA_ROTATY_SPEED_HIGH      (70 + oa_VoltageCompensationToSpeed)

#define OA_TURN_SPEED_LV4          (70 + oa_VoltageCompensationToSpeed)
#define OA_TURN_SPEED_LV1         (20 + oa_VoltageCompensationToSpeed )

#define OA_SPEED_OFFSET_PER_V	    10
#define OA_SERVO_OFFSET_ADDR_IN_EEPROM		0

#define UL_LIMIT_MIN              15
#define UL_LIMIT_MID              40
#define UL_LIMIT_MAX              400

#define MAX_DISTANCE		300		//cm
#define SONIC_TIMEOUT		(MAX_DISTANCE*60)
#define SOUND_VELOCITY		340		//soundVelocity: 340m/s

#define IA_THRESHOLD 0

extern Servo servo;
extern char servoOffset;

void servoSetup();
void setServoOffset(char offset);
void writeServo(u8 n);
void writeServoOffsetToEEPROM();
void getServoOffsetFromEEPROM();

float getSonar();
void oa_CalculateVoltageCompensation();
void updateAutomaticObstacleAvoidance();
void updateAutomaticObstacleAvoidanceNoInfrared();
void UltrasonicFollow();

#endif
