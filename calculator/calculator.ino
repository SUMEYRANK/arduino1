#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,9,8);

long num1 = 0;
long num2 = 0;

double total = 0;

char customKey;
const byte ROWS = 4;
const byte =COLS =4;

char keys[ROWS][COLS] = 
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {3,2,1,0};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins,ROWS,COLS);

void setup()
{
  lcd.begin(16,2);
  
  for( int i=0; i<=3; i++);
  lcd.setCursor(0,0);
  lcd.print("calculator");
  
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey)
  {
    case '0'...'9':
    lcd.setCursor(0,0);
    num1 = num1*10 + (customKey -'0');
    lcd.print(num1);
    break;
    
    case '+':
    num1 = (total != 0? total :first);
    lcd.setCursor(0,1);
    lcd.print("+"),
    num2 = Secondnum();
    total = num1 + num2;
    lcd.setCursor(0,3);
    lcd.print(total);
    num1 =0,num2 =0;
    break;
    
    case'-':
    num1 = (total != 0? total :first);
    lcd.setCursor(0,1);
    lcd.print("-"),
    num2 = Secondnum();
    total = num1 - num2;
    lcd.setCursor(0,3);
    lcd.print(total);
    num1 =0,num2 =0;
    break;
    
    case'*':
    num1 = (total != 0? total :first);
    lcd.setCursor(0,1);
    lcd.print("*"),
    num2 = Secondnum();
    total = num1 * num2;
    lcd.setCursor(0,3);
    lcd.print(total);
    num1 =0,num2 =0;
    break;
    
    case'/':
    num1 = (total != 0? total :first);
    lcd.setCursor(0,1);
    lcd.print("/"),
    num2 = Secondnum();
    lcd.setCursor(0,3);
    
    num2 == 0? lcd.print("invalid") : total = (float)num1 / (float)num2;
    
    lcd.print(total);
    num1 =0;
    num2 =0;
    break;
    
    case'C':
    total =0;
    lcd.clear();
    break;
    
  }
}
long secondnum()
{
  while(1)
  {
    customKey = customKeypad.getKey();
    if (customKey >= '0' && customKey <= '9')
    {
      num2 = num2*10 +(customKey -'0');
      lcd.setCursor(0,2);
      lcd.print(num2);
    }
    if(customKey == '=')
      break;
  }
  return num2;
}
  