#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int M1 = 23;
int M2 = 22;
int M3 = 21;
int M4 = 19;

void setup() {
 pinMode(M1,OUTPUT);
 pinMode(M2,OUTPUT);
 pinMode(M3,OUTPUT);
 pinMode(M4,OUTPUT);
 Serial.begin(9600);
 SerialBT.begin("ESP32-ROBOT"); //Bluetooth device name
 Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() 
{
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
  
 if(Serial.available())
 {
 int z = Serial.read();

 if(z==1)
 {
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
 }

 if(z==2)
 {
 digitalWrite(M1,LOW);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
 }

  if(z==3)
 {
  
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);
 }

 if(z==4)
 {
 
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,HIGH);
 }

 if(z==5)
 {
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,HIGH);
 }
 }

}
