#include <Servo.h>
const int EMG =A0;
const int LED = 13;
const int BTN = 7;
const int ON = 300; // Hysterisis on signal
const int OFF = 80; // Hysterisis off signal
int AVG = 0;
int H1 = 0; // home position for fingerServo
int H2 = 180; // home position for thumbServo
int P1 = 125; // Stop (grasped) position for fingerServo
int P2 = 60; // Stop (grasped) position for thumbServo 

unsigned long TMR = 0; // stop timer 
unsigned long sTMR= 0;

bool ledon = false; // when the LED is on hand is grasped
bool armed = true; // allows the arduino to recieve EMG signal
bool stop = false; // tells the servos to stop after the timer reaches set point 

Servo fingerServo;
Servo thumbServo;



void setup() {
Serial.begin(115200);
pinMode(LED, OUTPUT);
pinMode(BTN, INPUT);
fingerServo.attach(10); //Orange Wire
thumbServo.attach(11); //Yellow Wire
fingerServo.write(0);
thumbServo.write(180);

}

void loop() {
if (armed) 
    {AVG = (
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG) +
    analogRead(EMG)
      )/8;

    Serial.println(AVG);}

if (AVG >= ON) 
{ledon = !ledon; 
 armed = false;
 AVG = 0;
 TMR = millis();}

if (millis() - TMR >= 600 && AVG <= OFF)
   {armed = true;
    TMR = 0;}

digitalWrite(LED, ledon ? HIGH : LOW);

if (digitalRead(BTN) == HIGH)
    {stop = true;
    Serial.println("Pressed");}
else
    stop= false;


if (ledon && !stop){
    if (H1 < P1){
        H1 = H1 + 1; // adds a degree of movement while both conditions are met
        fingerServo.write(H1);}
    if (H2 > P2){
        H2 = H2 - 1; // subtracts a dgree of movement while both conditions are met
        thumbServo.write(H2);}
    delay(5);} // this delay contolls close speed of the hand
    


if (!ledon){
    H1 = 0;
    H2 = 180;
    fingerServo.write(H1);
    thumbServo.write(H2);}

}
