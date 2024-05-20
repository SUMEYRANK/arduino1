#include<Servo.h>

Servo servo_1;
int servo1 =180;
int servo1HIGH =175;
int servo1LOW =5;

Servo servo_2;
int servo2 =45;
int servo2HIGH =60;
int servo2LOW =1;

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;

void setup(){
  servo_1.attach(9);
  servo_2.attach(10);
  servo_1.write(180);
  servo_2.write(45);
  delay(1000);
}

void loop(){
  int ser1= analogRead(A0);
  int ser2= analogRead(A1);
  int ser3= analogRead(A2);
  int ser4= analogRead(A3);
  int dtime =10;
  int tol= 90;
  
  int ave12 = (ldr1 + ldr2)/2; //average of left
  int ave13 = (ldr1 + ldr3)/2; // average of down
  int ave34 = (ldr3 + ldr4)/2; // average of right
  int ave24 = (ldr4 + ldr2)/2; // average of top
  
  int differ_horizon = ave12-ave34;
  int differ_vertical = ave24-ave13;
  
  if(-1*tol > differ_vertical ||  differ_vertical > tol)
    {
    if ( ave24 > ave13)
    {
    servo2 = ++ servo2;
      if (servo2 > servo2HIGH){
        servo2 = servo2HIGH;
      }
      else if (ave24<ave13){
        servo2 = --servo2;}
      if (servo2 < servo2LOW)
      {
        servo2 = servo2LOW;
      }
      servo_2.write(servo2);
      
      if(-1*tol > differ_horizon || differ_horizon > tol) // check if the difference is in the tolerance else change horizontal angle.
      {
        if ( ave12 > ave34){
          servo1 = --servo1;
        }
        if(servo1 < servo1LOW){
          servo1 = servo1LOW;
        }
      }
      else if (ave12 < ave34 )
      {
        servo1 = ++ servo1;
        if (servo1 > servo1HIGH){
          servo1 = servo1HIGH ;
        }
      }
      else if (ave12= ave34){
        delay(1000);
      }
      servo_1.write(servo1);
      
      delay(dtime);
    }
  }
}
