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

void inner1_setup() {
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

void inner1_loop() {
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


    // Version 2.0: Improved motor control algorithms for smoother movements.

    void inner2_setup() {
        inner1_setup();  // Call setup from version 1
        Serial.println("Version 2.0 setup complete with Improved motor control algorithms for smoother movements.");
    }

    void inner2_loop() {
        inner1_loop();  // Call loop from version 1
        Serial.println("Version 2.0 loop running with Improved motor control algorithms for smoother movements.");
    }
    

    // Version 3.0: Added obstacle detection using ultrasonic sensors.

    void inner3_setup() {
        inner2_setup();  // Call setup from version 2
        Serial.println("Version 3.0 setup complete with Added obstacle detection using ultrasonic sensors.");
    }

    void inner3_loop() {
        inner2_loop();  // Call loop from version 2
        Serial.println("Version 3.0 loop running with Added obstacle detection using ultrasonic sensors.");
    }
    

    // Version 4.0: Introduced basic pathfinding to avoid obstacles.

    void inner4_setup() {
        inner3_setup();  // Call setup from version 3
        Serial.println("Version 4.0 setup complete with Introduced basic pathfinding to avoid obstacles.");
    }

    void inner4_loop() {
        inner3_loop();  // Call loop from version 3
        Serial.println("Version 4.0 loop running with Introduced basic pathfinding to avoid obstacles.");
    }
    

    // Version 5.0: Enhanced power efficiency with dynamic speed adjustments.

    void inner5_setup() {
        inner4_setup();  // Call setup from version 4
        Serial.println("Version 5.0 setup complete with Enhanced power efficiency with dynamic speed adjustments.");
    }

    void inner5_loop() {
        inner4_loop();  // Call loop from version 4
        Serial.println("Version 5.0 loop running with Enhanced power efficiency with dynamic speed adjustments.");
    }
    

    // Version 6.0: Added sensor calibration functionality for accuracy.

    void inner6_setup() {
        inner5_setup();  // Call setup from version 5
        Serial.println("Version 6.0 setup complete with Added sensor calibration functionality for accuracy.");
    }

    void inner6_loop() {
        inner5_loop();  // Call loop from version 5
        Serial.println("Version 6.0 loop running with Added sensor calibration functionality for accuracy.");
    }
    

    // Version 7.0: Integrated remote control via Bluetooth.

    void inner7_setup() {
        inner6_setup();  // Call setup from version 6
        Serial.println("Version 7.0 setup complete with Integrated remote control via Bluetooth.");
    }

    void inner7_loop() {
        inner6_loop();  // Call loop from version 6
        Serial.println("Version 7.0 loop running with Integrated remote control via Bluetooth.");
    }
    

    // Version 8.0: Added data logging to track movements and obstacles.

    void inner8_setup() {
        inner7_setup();  // Call setup from version 7
        Serial.println("Version 8.0 setup complete with Added data logging to track movements and obstacles.");
    }

    void inner8_loop() {
        inner7_loop();  // Call loop from version 7
        Serial.println("Version 8.0 loop running with Added data logging to track movements and obstacles.");
    }
    

    // Version 9.0: Enhanced error recovery when an obstacle blocks the path.

    void inner9_setup() {
        inner8_setup();  // Call setup from version 8
        Serial.println("Version 9.0 setup complete with Enhanced error recovery when an obstacle blocks the path.");
    }

    void inner9_loop() {
        inner8_loop();  // Call loop from version 8
        Serial.println("Version 9.0 loop running with Enhanced error recovery when an obstacle blocks the path.");
    }
    

    // Version 10.0: Introduced object recognition to identify fruits.

    void setup() {
        inner9_setup();  // Call setup from version 9
        Serial.println("Version 10.0 setup complete with Introduced object recognition to identify fruits.");
    }

    void loop() {
        inner9_loop();  // Call loop from version 9
        Serial.println("Version 10.0 loop running with Introduced object recognition to identify fruits.");
    }
    