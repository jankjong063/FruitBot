# FruitBot - Robotic Fruit Picker

FruitBot is a simple Arduino-based robotic arm project designed to detect and pick up fruits (like apples or oranges) using servo motors, an ultrasonic sensor, and a gripper. The robot can move towards the detected fruit, grab it with a gripper, and place it at a designated location.

## Features
- Uses an ultrasonic sensor to detect the distance to an object (fruit).
- Servo motors control the arm's base rotation, arm movement, and gripper for grabbing the fruit.
- Simple, customizable Arduino code to extend functionality.
- Ideal for hobbyists and educational purposes.

## Components
- **Arduino Uno/Nano** (or any compatible microcontroller)
- **Servo Motors** (for the base, arm, and gripper)
- **Ultrasonic Sensor** (HC-SR04 or similar)
- **Gripper** (servo-controlled or mechanical)
- **Motor Driver** (for controlling motor power)
- **Power Supply** (5V or external power source for servos)
- **Breadboard and Wires** (for connections)

## Circuit Setup
- Connect each servo motor's signal pin to the designated Arduino pins (e.g., 3, 5, 6).
- Connect the ultrasonic sensor's **trig** and **echo** pins to Arduino pins 9 and 10, respectively.
- Use a motor driver or external power supply if required for stronger motors.

## Getting Started

### Prerequisites
- Arduino IDE ([Download here](https://www.arduino.cc/en/software))
- Basic knowledge of Arduino and circuits

### Hardware Setup
1. Connect the servo motors to the Arduino board:
   - **Base Servo** to pin 3
   - **Arm Servo** to pin 5
   - **Gripper Servo** to pin 6
2. Connect the ultrasonic sensor:
   - **Trig Pin** to pin 9
   - **Echo Pin** to pin 10
3. Power the Arduino with a 5V power source or USB connection.
4. Upload the code to your Arduino.

### Code

The code can be found in the `src/` folder of this repository. Here's a simple outline of the main functionalities:

```cpp
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
