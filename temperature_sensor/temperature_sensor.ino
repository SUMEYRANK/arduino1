#include "LiquidCrystal.h"
LiquidCrystal lcd(12,11,5,4,3,2);
int sensorPin = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  int reading = analogRead(sensorPin);
  
  float voltage = reading * (5.0 / 1023.0);

  float temperatureC = (voltage - 0.5) * 100; 
  
 
  Serial.print(temperatureC);
  Serial.println("degrees C");
  
   lcd.setCursor(0,0);
   lcd.print("temperature value ");
   lcd.setCursor(0,1);
   lcd.print("degrees C");
  
  delay(1000);
}