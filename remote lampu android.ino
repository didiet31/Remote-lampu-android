#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


String res = "";

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  SerialBT.begin("motorku"); //Nama bluetooth kalian
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  while (!SerialBT.available());
  
  while (SerialBT.available()) 
  {
    char add = SerialBT.read();
    res = res + add;
    delay(1);
  }

  if (res == "T")
  {
    Serial.println("Connection Established!!!");
  }
  if (res == "1")
  {
    Serial.println("Matikan Lampu 1");
    digitalWrite(12, LOW);
  }
  if (res == "A")
  {
    Serial.println("MENGHIDUPKAN Lampu 1");
    digitalWrite(12,HIGH);
  }  
  if (res == "4")
  {
    Serial.println("Matikan Lampu 2");
    digitalWrite(13, LOW);
  }
  if (res == "D")
  {
    Serial.println("hidupkan Lampu 2");
    digitalWrite(13,HIGH);
  }
  if (res == "9")
  {
    Serial.println("MENGHIDUPKAN SEMUA");
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (res == "I")
  {
    Serial.println("OFF SEMUA");
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }

  res = ""; // clearing the string.
}
