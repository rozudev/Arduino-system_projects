#include <Servo.h>.
const int trigPin = 8; // trigpin for ultrasonic sensor
const int echoPin = 9; // echopin for ultrasonic sensor

long duration;
int distance;
int safetyDistance;
Servo myServo1;
Servo myServo2;

void setup() {

  pinMode (trigPin, OUTPUT); // sets trigpin as output
  pinMode (echoPin, INPUT); // sets echopin as input
  myServo1.attach (10); // servo1 signal is connected to pin 12
  myServo2.attach (11); // servo2 signal is connected to pin 11

  Serial.begin (9600); // starts the serial communication
}

void loop() {
   // Sweep from left to right
   for(int i=15;i<=165;i++) {
    myServo1.write(i);
    delay(30);
    distance = calculateDistance(); // Calls a function for calculating the distance by the Ultrasonic sensor for each degree

    Serial.print(i); // Sends the current degrees into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing

    safetyDistance = distance;
    if(safetyDistance <= 20) {
      myServo2.write(90);
      delay(1500);
    
    }
    else{
      myServo2.write(0);
      delay(10);
    
    }
  }

     // Sweep back to right to left
    for(int i=15;i>=165;i--) {
     myServo1.write(i);
     delay(30);
     distance = calculateDistance(); // Calls a function for calculating the distance by the Ultrasonic sensor for each degree

     Serial.print(i); // Sends the current degree into the Serial Port
     Serial.print(","); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing
     Serial.print(distance); // Sends the distance value into the Serial Port
     Serial.print("."); // Sends addition character right next to the previous value needed later in the Proccessing IDE for indexing

     safetyDistance = distance;
     if(safetyDistance <=20) {
      myServo2.write(90);
      delay(1500);
      
    }
    else{
      myServo2.write(0);
      delay(10);
    }
  }
}

  int calculateDistance() {
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

  }
