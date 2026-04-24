#include <Stepper.h>
#include <Servo.h>.

const int stepsPerRevolution = 2048; // defines the number of steps per rotation
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12); // pins entered in sequence IN1-IN2-IN3-IN4 for proper step sequence

const int trigPin = 8;
const int echoPin = 7;

long duration;
int distance;
int stepCount;

void setup() {
// Nothing to do Stepper library sets pins as output
 pinMode (trigPin, OUTPUT);
 pinMode (echoPin, INPUT);
 Serial.begin (9600);

}

void loop() {

  myStepper.setSpeed(5);
  myStepper.step(stepsPerRevolution);

  distance = calculateDistance();
  for (int Angle = stepCount*0.882183842;Angle<=360;Angle++) {
  Serial.print(Angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration*0.034/2;
  return distance;
}
 






