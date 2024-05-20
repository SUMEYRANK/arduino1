#define floor4led 12
#define floor4button 11
#define floor3led 10
#define floor3button 9
#define floor2led 8
#define floor2button 7
#define floor1led 6
#define floor1button 5

int topfloor = 4;
int lobby = 1;

int position = 0;

bool button_state[] = {false, false, false, false};

int elevator_state = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(floor4led, OUTPUT);
  pinMode(floor3led, OUTPUT);
  pinMode(floor2led, OUTPUT);
  pinMode(floor1led, OUTPUT);

  pinMode(floor4button, INPUT_PULLUP);
  pinMode(floor3button, INPUT_PULLUP);
  pinMode(floor2button, INPUT_PULLUP);
  pinMode(floor1button, INPUT_PULLUP);
}

void loop()
{
  for (int checkbutton = 1; checkbutton <= topfloor; checkbutton++) // Her adımda bir düğmenin durumunu kontrol et
  {
    button_state[checkbutton] = digitalRead(get_button_pin(checkbutton)) == LOW; // Düğme durumunu güncelle
    delay(50); // Kararlılık için kısa bir gecikme ekle
  }

  bool floorabove = false;
  bool floorbelow = false;

  for (int i = position + 1; i <= topfloor; i++)
  {
    if (button_state[i])
      floorabove = true;
  }
  for (int i = position - 1; i >= lobby; i--)
  {
    if (button_state[i])
      floorbelow = true;
  }

  if (elevator_state == 1 && !floorabove)
  {
    elevator_state = 0;
  }
  if (elevator_state == -1 && !floorbelow)
  {
    elevator_state = 0;
  }
  if (elevator_state == 0 && floorabove)
  {
    elevator_state = 1;
  }
  else if (elevator_state == 0 && floorbelow)
  {
    elevator_state = -1;
  }
  else
  {
    if (position != lobby)
      button_state[lobby] = true;
  }

  if (elevator_state == 1)
  {
    position = constrain(position + 1, lobby, topfloor);
  }
  else if (elevator_state == -1)
  {
    position = constrain(position - 1, lobby, topfloor);
  }

  Serial.print(position);
  Serial.print(",");
  Serial.print(floorabove);
  Serial.print(",");
  Serial.print(floorbelow);
  Serial.print(",");
  Serial.print(elevator_state);
  Serial.print(",");
  Serial.print("button state:");
  for (int i = 1; i <= topfloor; i++)
  {
    Serial.print(button_state[i]);
    Serial.print(",");
  }
  Serial.println();

  update_leds();
  delay(100); 

  if (random(0, 10) < 5)
    button_state[random(lobby, topfloor + 1)] = true; 
}

int get_button_pin(int floor)
{
  switch (floor)
  {
  case 1:
    return floor1button;
  case 2:
    return floor2button;
  case 3:
    return floor3button;
  case 4:
    return floor4button;
  default:
    return -1;
  }
}

void update_leds()
{
  digitalWrite(floor1led, position == 1);
  digitalWrite(floor2led, position == 2);
  digitalWrite(floor3led, position == 3);
  digitalWrite(floor4led, position == 4);
}

                     