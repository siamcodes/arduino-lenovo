#include "Automatic_Obstacle_Avoidance_Mode.h"

Servo servo;
char servoOffset = 0;
int oa_VoltageCompensationToSpeed;
int distance[3];

void servoSetup() {
	getServoOffsetFromEEPROM();
	servo.attach(PIN_SERVO);
	servo.write(90 + servoOffset);
}

void setServoOffset(char offset) {
	servoOffset = offset = constrain(offset, -100, 100);
	servo.write(90 + offset);
}

void writeServo(u8 n)
{
	servo.write(90 + servoOffset);
}

void writeServoOffsetToEEPROM() {
	servo.write(90 + servoOffset);
	EEPROM.write(OA_SERVO_OFFSET_ADDR_IN_EEPROM, servoOffset);
}

void getServoOffsetFromEEPROM() {
	servoOffset = EEPROM.read(OA_SERVO_OFFSET_ADDR_IN_EEPROM);
	servoOffset = constrain(servoOffset, -10, 10);
}

float getSonar() {
	unsigned long pingTime;
	float distance;
	digitalWrite(PIN_SONIC_TRIG, HIGH); // make trigPin output high level lasting for 10��s to triger HC_SR04,
	delayMicroseconds(10);
	digitalWrite(PIN_SONIC_TRIG, LOW);
	pingTime = pulseIn(PIN_SONIC_ECHO, HIGH, SONIC_TIMEOUT); // Wait HC-SR04 returning to the high level and measure out this waitting time
	if (pingTime != 0)
		distance = (float)pingTime * SOUND_VELOCITY / 2 / 10000; // calculate the distance according to the time
	else
		distance = MAX_DISTANCE;
	return distance; // return the distance value
}

int GetLeftInfraredAvoidanceValue(){
  return digitalRead(IR_AVOIDANCE_LEFT_PIN);
}

int GetRightInfraredAvoidanceValue(){
  return digitalRead(IR_AVOIDANCE_RIGHT_PIN);
}

void oa_CalculateVoltageCompensation() {
	getBatteryVoltage();
	float voltageOffset = BAT_VOL_STANDARD - batteryVoltage;
	oa_VoltageCompensationToSpeed = voltageOffset * OA_SPEED_OFFSET_PER_V;
  oa_VoltageCompensationToSpeed=0;
//	Serial.print(voltageOffset);
//	Serial.print('\t');
//	Serial.println(oa_VoltageCompensationToSpeed);
}



//**********************************************************************************************
// Name : UltrasonicFollow
//Function :Ultrasonic Follow
//Parameter:null
//**********************************************************************************************
void UltrasonicFollow()
{
  int  LeftValue , RightValue, UlFrontDistance;
  LeftValue = GetLeftInfraredAvoidanceValue();
  RightValue = GetRightInfraredAvoidanceValue();
  UlFrontDistance =  getSonar();;
  delay(10);
  if ((UlFrontDistance < 5) && (RightValue != IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_LOW);
    GoBack();
  }
  else if ((UlFrontDistance < 5) && (RightValue == IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(5);
  }
  else if ((UlFrontDistance < 5) && (RightValue != IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(175);

  }
  else if ((UlFrontDistance < 5) && (RightValue == IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_LOW);
    GoBack();

  }
  else if ((UlFrontDistance > 8) && (RightValue != IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_LOW);
    GoForward();

  }
  else if ((UlFrontDistance > 8) && (RightValue == IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    TurnRight();
  }
  else if ((UlFrontDistance > 8) && (RightValue != IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    TurnLeft();

  }
  else if ((5 <= UlFrontDistance <= 8) && (RightValue == IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(5);

  }
  else if ((5 <= UlFrontDistance <= 8) && (RightValue != IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(175);

  }
  else if ((5 <= UlFrontDistance <= 8) && (RightValue != IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    KeepStop();
  }

}


void updateAutomaticObstacleAvoidance() {
  int RightValue, LeftValue;
  int UlFrontDistance, UlLeftDistance, UlRightDistance;

  int tempDistance[3][5], sumDisntance=0;
  static u8 corner_cnt = 0, servoAngle = 0, lastServoAngle = 0;  //

  //***** scan sonar at OA_SERVO_CENTER *************
  servoAngle = OA_SCAN_ANGLE_MAX - 1 * OA_SCAN_ANGLE_INTERVAL + servoOffset;
  servo.write(servoAngle);
  if (lastServoAngle != servoAngle) {
    delay(OA_WAITTING_SERVO_TIME);
  }
  lastServoAngle = servoAngle;
  for (int j = 0; j < 5; j++) {
    tempDistance[1][j] = getSonar();
    delayMicroseconds(2 * SONIC_TIMEOUT);
    sumDisntance += tempDistance[1][j];
  }
  distance[1] = sumDisntance / 5;
  sumDisntance = 0;
  //Serial.println("distance[1] " + String(distance[1]));
  //*************************************************

  LeftValue = GetLeftInfraredAvoidanceValue();
  RightValue = GetRightInfraredAvoidanceValue();
  UlFrontDistance =  distance[1]; //GetUltrasonicFrontDistance();

  if ((RightValue != IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(5);
  }
  else if ((RightValue == IA_THRESHOLD) && (LeftValue != IA_THRESHOLD))
  {
    SetSpeed(OA_ROTATY_SPEED_HIGH);
    Drive(175);
  }
  else if ((RightValue == IA_THRESHOLD) && (LeftValue == IA_THRESHOLD))
  {
    KeepStop();
    SetSpeed(OA_ROTATY_SPEED_NORMAL);
    GoBack();
    delay(300);
    KeepStop();
  }
  else
  {
    SetSpeed(OA_ROTATY_SPEED_NORMAL);
    GoForward();
  }

  if (UlFrontDistance < UL_LIMIT_MID)
  {
    KeepStop();
    if (UlFrontDistance <= UL_LIMIT_MIN || (RightValue == IA_THRESHOLD && LeftValue == IA_THRESHOLD))
    {
      SetSpeed(OA_ROTATY_SPEED_NORMAL);
      GoBack();      
      delay(300);
      KeepStop();
    }

    //***** scan sonar at OA_SCAN_ANGLE_MAX
    servoAngle = OA_SCAN_ANGLE_MAX - 0 * OA_SCAN_ANGLE_INTERVAL + servoOffset;
    servo.write(servoAngle);
    if (lastServoAngle != servoAngle) {
      delay(OA_WAITTING_SERVO_TIME);
    }
    lastServoAngle = servoAngle;
    for (int j = 0; j < 5; j++) {
      tempDistance[0][j] = getSonar();
      delayMicroseconds(2 * SONIC_TIMEOUT);
      sumDisntance += tempDistance[0][j];
    }
    distance[0] = sumDisntance / 5;
    sumDisntance = 0;
    //Serial.println("distance[0] " + String(distance[0]));
    //*************************************************
      
    //***** scan sonar at OA_SCAN_ANGLE_MIN
    servoAngle = OA_SCAN_ANGLE_MAX - 2 * OA_SCAN_ANGLE_INTERVAL + servoOffset;
    servo.write(servoAngle);
    if (lastServoAngle != servoAngle) {
      delay(OA_WAITTING_SERVO_TIME);
    }
    lastServoAngle = servoAngle;
    for (int j = 0; j < 5; j++) {
      tempDistance[2][j] = getSonar();
      delayMicroseconds(2 * SONIC_TIMEOUT);
      sumDisntance += tempDistance[2][j];
    }
    distance[2] = sumDisntance / 5;
    sumDisntance = 0;
    //Serial.println("distance[2] " + String(distance[2]));
    //*************************************************

    UlLeftDistance = distance[0]; 
    UlRightDistance = distance[2];
    if ((UlRightDistance > UL_LIMIT_MIN) && (UlRightDistance < UL_LIMIT_MAX) && (UlLeftDistance > UL_LIMIT_MIN) && (UlLeftDistance < UL_LIMIT_MAX))
    {
      if (UlRightDistance >= UlLeftDistance)
      {
        SetSpeed(OA_ROTATY_SPEED_HIGH);      
        TurnRight();
        delay(300);
      }
      if (UlLeftDistance > UlRightDistance)
      {
        SetSpeed(OA_ROTATY_SPEED_HIGH);
        TurnLeft();
        delay(300);
      }
    }
    else if (((UlRightDistance > UL_LIMIT_MIN) && (UlRightDistance < UL_LIMIT_MAX)) || ((UlLeftDistance > UL_LIMIT_MIN) && (UlLeftDistance < UL_LIMIT_MAX)))
    {
      if ((UlLeftDistance > UL_LIMIT_MIN) && (UlLeftDistance < UL_LIMIT_MAX))
      {
        SetSpeed(OA_ROTATY_SPEED_NORMAL);
        TurnLeft();
        delay(310);
      }
      else if ((UlRightDistance > UL_LIMIT_MIN) && (UlRightDistance < UL_LIMIT_MAX))
      {
        SetSpeed(OA_ROTATY_SPEED_NORMAL);
        TurnRight();
        delay(310);
      }
    }
    else if (UlLeftDistance <= UL_LIMIT_MIN && UlRightDistance <= UL_LIMIT_MIN )
    {
      SetSpeed(OA_ROTATY_SPEED_HIGH);
      Drive(0);
      delay(700);
      KeepStop();
    }
    KeepStop();
  }
}

void updateAutomaticObstacleAvoidanceNoInfrared() {
  int RightValue, LeftValue;
  int UlFrontDistance, UlLeftDistance, UlRightDistance;

  int tempDistance[3][5], sumDisntance;
  static u8 cnt = 0, servoAngle = 0, lastServoAngle = 0;  //
  if (cnt == 0) {
    for (int i = 0; i < 3; i++) {
      servoAngle = OA_SCAN_ANGLE_MAX - i * OA_SCAN_ANGLE_INTERVAL + servoOffset;
      servo.write(servoAngle);
      if (lastServoAngle != servoAngle) {
        delay(OA_WAITTING_SERVO_TIME);
      }
      lastServoAngle = servoAngle;
      for (int j = 0; j < 5; j++) {
        tempDistance[i][j] = getSonar();
        delayMicroseconds(2 * SONIC_TIMEOUT);
        sumDisntance += tempDistance[i][j];
      }
      distance[i] = sumDisntance / 5;
      sumDisntance = 0;
    }
    cnt++;
  }
  else {
    for (int i = 2; i > 0; i--) {
      servoAngle = OA_SCAN_ANGLE_MAX - i * OA_SCAN_ANGLE_INTERVAL + servoOffset;
      servo.write(servoAngle);
      if (lastServoAngle != servoAngle) {
        delay(OA_WAITTING_SERVO_TIME);
      }
      lastServoAngle = servoAngle;
      for (int j = 0; j < 5; j++) {
        tempDistance[i][j] = getSonar();
        delayMicroseconds(2 * SONIC_TIMEOUT);
        sumDisntance += tempDistance[i][j];
      }
      distance[i] = sumDisntance / 5;
      sumDisntance = 0;
    }
    cnt = 0;
  }

  UlFrontDistance =  distance[1]; //GetUltrasonicFrontDistance();
  Serial.println("UlFrontDistance "+ String((distance[1])));
  
  if (distance[1] < UL_LIMIT_MID) {       //Too little distance ahead
    Serial.println("Too little distance ahead");
    if (distance[0] > UL_LIMIT_MID || distance[2] > UL_LIMIT_MID) {
      motorRun(-OA_ROTATY_SPEED_LOW, -OA_ROTATY_SPEED_LOW); //Move back a little
      delay(100);
      if (distance[0] > distance[2]) {      //Left distance is greater than right distance
        motorRun(-OA_ROTATY_SPEED_LOW, OA_ROTATY_SPEED_LOW);
      }
      else {                    //Right distance is greater than left distance
        motorRun(OA_ROTATY_SPEED_LOW, -OA_ROTATY_SPEED_LOW);
      }
    }
    else {                      //Get into the dead corner, move back a little, then spin.
      motorRun(-OA_ROTATY_SPEED_HIGH, -OA_ROTATY_SPEED_HIGH);
      delay(100);
      motorRun(-OA_ROTATY_SPEED_NORMAL, OA_ROTATY_SPEED_NORMAL);
    }
  }
  else {                        //No obstacles ahead
    Serial.println("No obstacles ahead");
    if (distance[0] < UL_LIMIT_MID) {     //Obstacles on the left front.
      if (distance[0] < UL_LIMIT_MIN) { //Very close to the left front obstacle.
        motorRun(-OA_ROTATY_SPEED_LOW, -OA_ROTATY_SPEED_LOW); //Move back
      }
      motorRun(OA_TURN_SPEED_LV4, OA_TURN_SPEED_LV1);
    }
    else if (distance[2] < UL_LIMIT_MID) {      //Obstacles on the right front.
      if (distance[2] < UL_LIMIT_MIN) {   //Very close to the right front obstacle.
        motorRun(-OA_ROTATY_SPEED_LOW, -OA_ROTATY_SPEED_LOW); //Move back
        delay(100);
      }
      motorRun(OA_TURN_SPEED_LV1, OA_TURN_SPEED_LV4);
    }
    else {                        //Cruising
      motorRun(OA_ROTATY_SPEED_NORMAL, OA_ROTATY_SPEED_NORMAL);
    }
  }

}
