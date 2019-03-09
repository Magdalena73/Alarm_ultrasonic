#include <LiquidCrystal.h>
//lcd(RS, Enable, D4, D5, D6, D7);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  
int pinTrigger = 8;
int pinEcho = 9;
int buzzerPin = 10;
long Zeit;
int Abstand;
boolean AlarmOn;

void setup(){
  AlarmOn = false;
  lcd.begin(16,2); 
  lcd.clear();
 
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(buzzerPin,OUTPUT);
  analogWrite(buzzerPin,255);
  
  Serial.begin(9600);
}

void loop(){
analogWrite(buzzerPin, 255);

// get distance
digitalWrite(pinTrigger,LOW);
delay(5);
digitalWrite(pinTrigger,HIGH);
delay(10);
digitalWrite(pinTrigger,LOW);
Zeit = pulseIn(pinEcho,HIGH); // Zeit hin und zurück
Zeit = Zeit/2;
// Abstand = Zeit * Geschwindigkeit
Abstand = int((Zeit*0.0343)); // Schallgeschwindigkeit @20°C
//Serial.print("Distance (cm): ");
//Serial.println(distance);

// show distance on LCD
showDistance(Abstand);

if (Abstand < 16)
 { 
  AlarmOn = true;
 }
else
AlarmOn = false;

if(AlarmOn)
makeSound(50);

delay(1000);
}

void makeSound(int freqNum)
{
  for(int i; i< 20; i++)
  {
  analogWrite(buzzerPin, 0);
  delay(freqNum);
  analogWrite(buzzerPin, 255);
  delay(freqNum);
  }
 }
 void showDistance( int dist)
 {
  lcd.clear();
  lcd.print("*   Abstand:  *");
  lcd.setCursor(6,1);
  lcd.print(dist);
  lcd.setCursor(9,1);
  lcd.print("cm");
  }
