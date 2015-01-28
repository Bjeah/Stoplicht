int redLed = 13; // Dit is de aansluiting voor de rode LED op pin 13.
int yellowLed = 12; // Dit is de aansluiting voor de gele LED op pin 12.
int greenLed = 11; // Dit is de aansluiting voor de groene LED op pin 11.
int button = 10; // Dit is de aansluiting voor de knop op pin 10.
boolean lastButton = LOW; //Dit is de boolean die zecht dat de huidige status van de knop laag is. (dit is later handig)
void setup() 
{                
  pinMode(redLed, OUTPUT); //Dit verteld de arduino dat de LED een OUTPUT is.
  pinMode(yellowLed, OUTPUT);//Dit verteld de arduino dat de LED een OUTPUT is.
  pinMode(greenLed, OUTPUT);//Dit verteld de arduino dat de LED een OUTPUT is.
  pinMode (button, INPUT);//Dit verteld de arduino dat de knop een INPUT is.
}

void loop() 
{
 if(digitalRead(button) == HIGH)//Als de knop wordt ingedrukt.
 {
   lastButton =! lastButton;//Verwissel dan de satus van boolean lastButton. 
 }

 if (lastButton == HIGH) //Als de status van de boolean Hoog is doe dan moet je het volgende doen.
 {
  digitalWrite (greenLed, HIGH);// Groene LED aan.
  delay(3000);//Wacht voor 3 SEC.
  digitalWrite(greenLed, LOW); //Groene LED af.
  digitalWrite(yellowLed, HIGH);//Gele LED aan.
  delay(1000);//Wacht voor 1 SEC.
  digitalWrite(yellowLed, LOW);//Gele LED af.
  digitalWrite(redLed, HIGH);//Rode LED aan.
  delay(3000);//Wacht voor 3 SEC.
  digitalWrite(redLed, LOW); //Rode LED af.
 }
 else//anders
 {
   digitalWrite(yellowLed, HIGH);//Gele LED aan.
   delay(1000);//Wacht voor 1 SEC.
   digitalWrite(yellowLed, LOW); //Gele LED af.
   delay(1000);//Wacht voor 1 SEC.
   }
}
