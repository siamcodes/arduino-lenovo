// Catosci_4WD_Car_for_Arduino.h

#ifndef _FREENOVE_4WD_CAR_FOR_ARDUINO_h
#define _FREENOVE_4WD_CAR_FOR_ARDUINO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define PIN_SERVO			12

#define PIN_DIRECTION_RIGHT_FWD	4
#define PIN_DIRECTION_RIGHT_BWD  5
#define PIN_DIRECTION_LEFT_FWD	7
#define PIN_DIRECTION_LEFT_BWD 6
#define PIN_MOTOR_PWM_RIGHT	3
#define PIN_MOTOR_PWM_LEFT	11

#define PIN_SONIC_TRIG		A2
#define	PIN_SONIC_ECHO		A3

#define IR_AVOIDANCE_LEFT_PIN 8
#define IR_AVOIDANCE_RIGHT_PIN 2

//#define PIN_IRREMOTE_RECV	9

//#define PIN_SPI_CE			9
//#define PIN_SPI_CSN			10
//#define PIN_SPI_MOSI		11
//#define PIN_SPI_MISO		12
//#define PIN_SPI_SCK			13

#define PIN_BATTERY			A5
#define PIN_BUZZER			13

#define PIN_TRACKING_LEFT	0
#define PIN_TRACKING_CENTER	A1
#define PIN_TRACKING_RIGHT	A4
#define MOTOR_PWM_DEAD		5

#define BAT_VOL_STANDARD	7.0

typedef enum
{
    E_FORWARD = 0,
    E_BACK,
    E_LEFT,
    E_RIGHT,
    E_RIGHT_ROTATE,
    E_LEFT_ROTATE,
    E_STOP,
    E_RUNNING,
    E_SPEED_UP,
    E_SPEED_DOWN,
    E_LOW_POWER,
} E_SMARTCAR_STATUS;

extern float batteryVoltage;
extern byte Speed;
extern int Degree;
extern E_SMARTCAR_STATUS SmartCar_Status;

void GoForward(void);
void GoBack(void);
void TurnLeft(void);
void TurnRight(void);
void KeepStop(void);
void Drive(int degree);
void SetSpeed(int8_t s);
void SpeedUp(int8_t Duration = 5);
void SpeedDown(int8_t Duration = 5);
void SetStatus(E_SMARTCAR_STATUS status);
    

void pinsSetup();
void motorRun(int speedl, int speedr);

bool getBatteryVoltage();
void setBuzzer(bool flag);
void alarm(u8 beat, u8 repeat);
void resetCarAction();

#endif
