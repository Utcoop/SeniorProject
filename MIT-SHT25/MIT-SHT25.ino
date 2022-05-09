//To connect to HC-06 the password is 1234
#include <SoftwareSerial.h>
//2 to RX, 3 to TX
SoftwareSerial HC06(2, 3);
#include <Wire.h>
// SHT25 I2C address is 0x40(64)
#define Addr 0x40

String SerialData = "";
void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}
void loop()
{
  unsigned int data[2];
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send humidity measurement command, NO HOLD master
  Wire.write(0xF5);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(500);
  // Request 2 bytes of data
  Wire.requestFrom(Addr, 2);
  // Read 2 bytes of data
  // humidity msb, humidity lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    // Convert the data
    float humidity = (((data[0] * 256.0 + data[1]) * 125.0) / 65536.0) - 6;
    // Output data to Serial Monitor
    //Serial.print("RH ");
    //Serial.print(humidity);
    //Serial.print(", ");
    SerialData = SerialData + String(humidity) + "|";
  }
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send temperature measurement command, NO HOLD master
  Wire.write(0xF3);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(500);
  // Request 2 bytes of data
  Wire.requestFrom(Addr, 2);
  // Read 2 bytes of data
  // temp msb, temp lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    // Convert the data
    float cTemp = (((data[0] * 256.0 + data[1]) * 175.72) / 65536.0) - 46.85;
    float fTemp = (cTemp * 1.8) + 32;
    SerialData = SerialData + String(cTemp);
  }
  //Output to serial monitor which also sends it to any device connected to HC-06
  Serial.println(SerialData);
  SerialData = "";
  delay(300);
}
