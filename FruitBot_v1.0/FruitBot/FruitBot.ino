#include <Servo.h>

// Define the servos for the arm and gripper
Servo baseServo;
Servo armServo;
Servo gripperServo;

// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Variables for ultrasonic sensor
long duration;
int distance;

void setup() {
  // Attach the servos to their respective pins
  baseServo.attach(3);   // Base rotation
  armServo.attach(5);    // Arm movement
  gripperServo.attach(6); // Gripper movement
  
  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Move the robot arm to the starting position
  baseServo.write(90);    // Middle position (neutral)
  armServo.write(90);     // Neutral arm position
  gripperServo.write(10); // Open gripper

  Serial.begin(9600);     // Start serial communication
}

void loop() {
  // Measure distance using ultrasonic sensor
  distance = measureDistance();
  
  // If the object is within 15 cm range, pick it up
  if (distance < 15 && distance > 0) {
    pickUpObject();
  }
  
  delay(1000);  // Wait before the next loop
}

// Function to measure distance using the ultrasonic sensor
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}

// Function to simulate picking up the object
void pickUpObject() {
  // Move the arm down
  armServo.write(45);
  delay(1000);  // Wait for the arm to move
  
  // Close the gripper to grab the object
  gripperServo.write(70);
  delay(1000);
  
  // Lift the object
  armServo.write(90);
  delay(1000);

  // Rotate the base to move the object to a new location
  baseServo.write(180);
  delay(1000);

  // Release the object
  gripperServo.write(10);
  delay(1000);

  // Move back to starting position
  baseServo.write(90);
  armServo.write(90);
}
