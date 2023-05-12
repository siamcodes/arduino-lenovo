#include "Catosci_4WD_Car_for_Arduino.h"

float batteryVoltage = 0;
bool isBuzzered = false;
byte Speed = 0;
int Degree = 0;
E_SMARTCAR_STATUS SmartCar_Status = E_STOP;

void pinsSetup() {
	pinMode(PIN_DIRECTION_LEFT_FWD, OUTPUT);
	pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
	pinMode(PIN_DIRECTION_RIGHT_FWD, OUTPUT);
	pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);

	pinMode(PIN_SONIC_TRIG, OUTPUT);// set trigPin to output mode
	pinMode(PIN_SONIC_ECHO, INPUT); // set echoPin to input mode

	pinMode(PIN_TRACKING_LEFT, INPUT); // 
	pinMode(PIN_TRACKING_RIGHT, INPUT); // 
	pinMode(PIN_TRACKING_CENTER, INPUT); // 

  pinMode(IR_AVOIDANCE_LEFT_PIN, INPUT); // 
  pinMode(IR_AVOIDANCE_RIGHT_PIN, INPUT); // 

	setBuzzer(false);
}

void GoForward(void)
{
  int value = (Speed / 10) * 25;
  #ifdef DEBUG 
    Serial.println("GoForward\n");
  #endif
  SetStatus(E_FORWARD);
  digitalWrite(PIN_DIRECTION_LEFT_FWD, HIGH);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
  digitalWrite(PIN_DIRECTION_RIGHT_FWD, HIGH);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
  analogWrite(PIN_MOTOR_PWM_LEFT, value);
  analogWrite(PIN_MOTOR_PWM_RIGHT, value);
}

void GoBack(void)
{
  int value = (Speed / 10) * 25;
  #ifdef DEBUG 
    Serial.println("GoBack\n");
  #endif
  SetStatus(E_BACK);
  digitalWrite(PIN_DIRECTION_LEFT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, HIGH );
  digitalWrite(PIN_DIRECTION_RIGHT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, HIGH );
  analogWrite(PIN_MOTOR_PWM_LEFT, value);
  analogWrite(PIN_MOTOR_PWM_RIGHT, value);
}

void KeepStop(void)
{
  #ifdef DEBUG 
    Serial.println("KeepStop\n");
  #endif
  SetStatus(E_STOP);
  digitalWrite(PIN_DIRECTION_LEFT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
  digitalWrite(PIN_DIRECTION_RIGHT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
  analogWrite(PIN_MOTOR_PWM_LEFT, 0);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 0);
}

void TurnLeft(void)
{
  int value = (Speed / 10) * 25.5; //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
  #ifdef DEBUG 
    Serial.println("TurnLeft =%d \n", value);
  #endif
  SetStatus(E_LEFT);
  digitalWrite(PIN_DIRECTION_LEFT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, HIGH );
  digitalWrite(PIN_DIRECTION_RIGHT_FWD, HIGH);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
  analogWrite(PIN_MOTOR_PWM_LEFT, value);
  analogWrite(PIN_MOTOR_PWM_RIGHT, value);
}

void TurnRight(void)
{
  int value = (Speed / 10) * 25.5; //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
  #ifdef DEBUG 
    Serial.println("TurnLeft =%d \n", value);
  #endif
  SetStatus(E_RIGHT);
  digitalWrite(PIN_DIRECTION_LEFT_FWD, HIGH);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
  digitalWrite(PIN_DIRECTION_RIGHT_FWD, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, HIGH );
  analogWrite(PIN_MOTOR_PWM_LEFT, value);
  analogWrite(PIN_MOTOR_PWM_RIGHT, value);
}


void Drive(int degree)
{
  Degree = degree;
  #ifdef DEBUG 
    Serial.println("degree = %d speed = %d\n", degree, Speed);
  #endif
  int value = (Speed / 10) * 25.5;   //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
  float f;
  if (degree >= 0 && degree <= 90) {
    f = (float)(degree) / 90;
    digitalWrite(PIN_DIRECTION_LEFT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
    digitalWrite(PIN_DIRECTION_RIGHT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
    analogWrite(PIN_MOTOR_PWM_LEFT, value);
    analogWrite(PIN_MOTOR_PWM_RIGHT, (float)(value * f));
    #ifdef DEBUG 
      Serial.println("TurnRight\n");
    #endif
    SetStatus(E_RIGHT);
  } else if (degree > 90 && degree <= 180) {
    f = (float)(180 - degree) / 90;
    digitalWrite(PIN_DIRECTION_LEFT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
    digitalWrite(PIN_DIRECTION_RIGHT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
    analogWrite(PIN_MOTOR_PWM_LEFT,  (float)(value * f));
    analogWrite(PIN_MOTOR_PWM_RIGHT, value);
    #ifdef DEBUG 
      Serial.println("TurnLeft\n");
    #endif
    SetStatus(E_LEFT);
  } else if (degree > 180 && degree <= 270) {
    f = (float)(degree - 180) / 90;
    digitalWrite(PIN_DIRECTION_LEFT_FWD, LOW);
    digitalWrite(PIN_DIRECTION_LEFT_BWD, HIGH );
    digitalWrite(PIN_DIRECTION_RIGHT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_RIGHT_BWD, LOW );
    analogWrite(PIN_MOTOR_PWM_LEFT,  (float)(value * f));
    analogWrite(PIN_MOTOR_PWM_RIGHT, value);
    #ifdef DEBUG 
      Serial.println("TurnLeft\n");
    #endif
    SetStatus(E_LEFT);
  } else if (degree >= 270 && degree <= 360) {
    f = (float)(360 - degree) / 90;
    digitalWrite(PIN_DIRECTION_LEFT_FWD, HIGH);
    digitalWrite(PIN_DIRECTION_LEFT_BWD, LOW );
    digitalWrite(PIN_DIRECTION_RIGHT_FWD, LOW);
    digitalWrite(PIN_DIRECTION_RIGHT_BWD, HIGH );
    analogWrite(PIN_MOTOR_PWM_LEFT, value);
    analogWrite(PIN_MOTOR_PWM_RIGHT, (float)(value * f));
    #ifdef DEBUG 
      Serial.println("TurnRight\n");
    #endif
    SetStatus(E_RIGHT);
  }
  else {
    KeepStop();
  }
}

void SetSpeed(int8_t s)
{
    // DEBUG_LOG(DEBUG_LEVEL_INFO, "SetSpeed =%d \n", s);
    if (s > 100) {
        Speed = 100;
        return;
    } else if (s < 0) {
        Speed = 0;
        return;
    }
    Speed = s;
}

void SpeedUp(int8_t Duration = 5)
{
    SetSpeed(Speed + Duration);
    SetStatus(E_SPEED_UP);
    //mStatus = E_SPEED_UP;
}

void SpeedDown(int8_t Duration = 5)
{
    SetSpeed(Speed - Duration);
    SetStatus(E_SPEED_DOWN);
    //mStatus = E_SPEED_DOWN;
}

void motorRun(int speedl, int speedr) {
	int dirL_fwd = 0, dirR_fwd = 0;
  int dirL_bwd = 0, dirR_bwd = 0;
	if (speedl > 0) {
		dirL_fwd = 1;
    dirL_bwd = 0;
	}
	else {
		dirL_fwd = 0;
    dirL_bwd = 1;
		speedl = -speedl;
	}

	if (speedr > 0) {
		dirR_fwd = 1;
    dirR_bwd = 0;
	}
	else {
		dirR_fwd = 0;
    dirR_bwd = 1;
		speedr = -speedr;
	}

  int valuel = (speedl / 10) * 25.5; //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
  int valuer = (speedr / 10) * 25.5; //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
  
	valuel = constrain(valuel, 0, 255);
	valuer = constrain(valuer, 0, 255);

	if (abs(valuel) < MOTOR_PWM_DEAD && abs(valuer) < MOTOR_PWM_DEAD) {
		valuel = 0;
		valuer = 0;
	}

	digitalWrite(PIN_DIRECTION_LEFT_FWD, dirL_fwd);
  digitalWrite(PIN_DIRECTION_LEFT_BWD, dirL_bwd );
	digitalWrite(PIN_DIRECTION_RIGHT_FWD, dirR_fwd);
  digitalWrite(PIN_DIRECTION_RIGHT_BWD, dirR_bwd );
	analogWrite(PIN_MOTOR_PWM_LEFT, valuel);
	analogWrite(PIN_MOTOR_PWM_RIGHT, valuer);
}


bool getBatteryVoltage() {
	if (!isBuzzered) {
		pinMode(PIN_BATTERY, INPUT);
		int batteryADC = analogRead(PIN_BATTERY);
//		if (batteryADC < 614)		// 3V/12V ,Voltage read: <2.1V/8.4V
//		{
			batteryVoltage = batteryADC / 1023.0 * 5.0 * 11;
			return true;
//		}
	}
	return false;
}
void setBuzzer(bool flag) {
	isBuzzered = flag;
	pinMode(PIN_BUZZER, !flag); //!flag per buzzer attivo con signal basso
	digitalWrite(PIN_BUZZER, !flag); //!flag per buzzer attivo con signal basso
}
void alarm(u8 beat, u8 repeat) {
	beat = constrain(beat, 1, 9);
	repeat = constrain(repeat, 1, 255);
	for (int j = 0; j < repeat; j++) {
		for (int i = 0; i < beat; i++) {
			setBuzzer(true);
			delay(100);
			setBuzzer(false);
			delay(100);
		}
		delay(500);
	}
}
void resetCarAction() {
	motorRun(0, 0);
	setBuzzer(false);
}

void SetStatus(E_SMARTCAR_STATUS status=0)
{
    SmartCar_Status = status;
}
