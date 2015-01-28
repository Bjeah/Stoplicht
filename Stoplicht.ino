int redLed = 13;
int yellowLed = 12;
int greenLed = 11;
int button = 10;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup() 
{                
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() 
{
  digitalWrite (greenLed, HIGH);
  delay(3000);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(3000);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(3000);
  digitalWrite(redLed, LOW);
  
}
