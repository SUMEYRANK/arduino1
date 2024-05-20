int sensorValue = 0;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A1);
  Serial.println(sensorValue);
  
  /*analogWrite(9, map(sensorValue, 6,679,0,255)); 
  /* 255 top of the brightness for the led */
  
  if (sensorValue <= 679 & sensorValue > 6){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }
  
  delay(1000);
  
  
}