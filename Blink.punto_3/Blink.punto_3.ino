/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.


  http://www.arduino.cc/en/Tutorial/Blink
*/
 volatile int state = LOW;
 const int pin = A1; //unico pin que funciona de muchos que probé. "A pin in the ass"

void blink() {
   state = !state;
   digitalWrite(LED_BUILTIN, state);
   Serial.println("LED change");
}
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(pin,INPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
}
// the loop function runs over and over again forever
void loop() {
  int t_write;
  int t_top;
  
  t_write = millis();
  t_top= t_write + 1000;
  digitalWrite(pin, HIGH); 
  //digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("pin ON");
  while (t_top > millis())
      {}                             // wait for a second
      
  t_write = millis();
  t_top = t_write + 1000;
  digitalWrite(pin, LOW);
  //digitalWrite(LED_BUILTIN, LOW);
  Serial.println("pin OFF"); 
  while (t_top > millis())
      {}                             // wait for a second
}
