#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Define an array of motor pins for controlling the robotic car
const int motorPins[] = {15, 2, 4, 5, 18, 19, 21, 22, 23};

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  // Initialize the Dabble library with the given project name "CarOS"
  Dabble.begin("CarOS");

  // Set the motor pins as OUTPUT and initialize them to LOW
  for (int i = 0; i < 8; i++) {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW);
  }
}

// Function to stop all motors by setting them to LOW
void stopMotors() {
  for (int i = 0; i < 8; i += 2) {
    digitalWrite(motorPins[i], LOW);
    digitalWrite(motorPins[i + 1], LOW);
  }
}

// Functions for different car movements
void forward() {
  // Set specific motor pins to HIGH to move forward
  // Also, print a message to Serial Monitor
  digitalWrite(15, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("Forward");
}

void backward() {
  // Set specific motor pins to HIGH to move backward
  // Also, print a message to Serial Monitor
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(22, HIGH);
  Serial.println("Backward");
}

// Similar functions for other movements: rightward, leftward, turnleft, turnright, and horn

void loop() {
  // Process input from the Dabble app
  Dabble.processInput();

  // Check the state of buttons in the Dabble GamePad module
  // Execute the corresponding car movement functions based on button presses
  if (GamePad.isUpPressed()) {
    forward();
  } else if (GamePad.isDownPressed()) {
    backward();
  } else if (GamePad.isLeftPressed()) {
    leftward();
  } else if (GamePad.isRightPressed()) {
    rightward();
  } else if (GamePad.isCirclePressed()) {
    turnright();
  } else if (GamePad.isSquarePressed()) {
    turnleft();
  } else if (GamePad.isTrianglePressed()) {
    horn();
  } else {
    stopMotors();
  }

  // Introduce a delay to control the loop execution rate
  delay(100);
}
