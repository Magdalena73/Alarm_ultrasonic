int pin_trigger=7;
int pin_echo=6;

float tiempo;
float distance;

void setup() {
  // put your setup code here, to run once:
pinMode(pin_trigger, OUTPUT);
pinMode(pin_echo, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin_trigger,LOW);
delay(5);
digitalWrite(pin_trigger,HIGH);
delay(10);
tiempo= pulseIn(pin_echo, HIGH);
distance= int(tiempo*0.0342/2);
Serial.print(distance);
Serial.println(" cm");
delay(5000);
}
