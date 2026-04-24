#include <Servo.h>.

const int trigPin = 10;
const int echoPin = 11;
const int ledPin1 = 9;
const int ledPin2 = 8;

long duration;
int distance;
int safetyDistance;
Servo myServo;

void setup() {

  pinMode(trigPin, OUTPUT); // set trigPin as Output
  pinMode(echoPin, INPUT);  // set echoPin as Input
  pinMode(ledPin1, OUTPUT);  // set ledPin as Output
  pinMode(ledPin2, OUTPUT);

  Serial.begin(9600); // starts the serial communication
  myServo.attach(12);  // attached my servo in Pin 12

}

void loop() {
// clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// sets the trigPin on HIGH state for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// reads the echoPin, returns the sound wave travel in microseconds
duration = pulseIn(echoPin, HIGH);

// calculating distance
distance = duration*0.034/2;

// prints the distance in the serial monitor
Serial.print("Distance:  ");
Serial.print(distance);

safetyDistance = distance;
if(safetyDistance <= 20) {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  myServo.write(90);
  delay(1500);
}

else{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  myServo.write(0);
  delay(10);
}

}


