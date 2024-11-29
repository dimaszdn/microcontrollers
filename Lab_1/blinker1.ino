const int redLedPin = 2;
const int blueLedPin = 4;
const int buttonPin = 7;

bool buttonState = LOW;
bool lastButtonState = LOW;
bool ledState = LOW;
bool flag = false;

void setup() 
{
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 500;

void loop() 
{
  //взаимодействуем с кнопкой
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButtonState == LOW)
    flag = !flag;
  lastButtonState = buttonState;
  
  //взаимодействуем со светодиодами
  if (flag == false)
  {
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  }
  
  currentMillis = millis();
  if (flag == true && currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    
    digitalWrite(redLedPin, ledState);
    digitalWrite(blueLedPin, !ledState);
  }
}