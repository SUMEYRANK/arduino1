#include <LiquidCrystal.h>

LiquidCrystal lcd ( 12,11,5,4,3,2);
int sensor = 9;
int state = LOW;
int val = 0;
int buzzer = 7;

void setup()
{
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
}

void loop()
{
  val = digitalRead(sensor);
  
  if (val == LOW)
  {
    delay(100);
    if (state == LOW)
    {
      lcd.setCursor(0,1);
      lcd.print("motion detected");
      digitalWrite(buzzer , HIGH);
      state = HIGH ;
    }
  }
  else
  {
    delay(100);
      if ( state == HIGH)
    {
      lcd.setCursor(0,1);
      lcd.print("motion stopped");
      digitalWrite(buzzer,LOW);
      state = LOW;
    }
  }
}
