
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = A0;
const float baseTemp = 20.0;
int tempb = 13;
boolean lButton = LOW;
void setup() {
  for(int pinNumber = 8; pinNumber<11; pinNumber ++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
}
  
  pinMode(13, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop() {
   if(digitalRead(13) == HIGH){
    lButton =! lButton;
  }
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  float Fa = (temperature * 9 / 5 + 32);
  float Baf = (baseTemp * 9 / 5 + 32);
  
  if(temperature < baseTemp)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  } else if(temperature >= baseTemp && temperature < baseTemp+1)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  } else if(temperature >= baseTemp+1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  if (lButton == LOW)
  {
    lcd.setCursor(0,0);
    lcd.print("Temp: C");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("Base Temp: C");
  lcd.print(baseTemp);
  }
else{
  lcd.setCursor(0,0);
  lcd.print("Temp: F");
  lcd.print(Fa);
  lcd.setCursor(0,1);
 lcd.print("Base Temp: F");
  lcd.print(Baf);
}

  delay(1000);
  lcd.clear();
}
