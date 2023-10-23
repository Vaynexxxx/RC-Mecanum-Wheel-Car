#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

const int motorPins[] = {15, 2, 4, 5, 18, 19, 21, 22, 23};

void setup() {
  Serial.begin(115200);
  Dabble.begin("CarOS");

  for (int i = 0; i < 8; i++) {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW);
  }
}

void stopMotors() {
  for (int i = 0; i < 8; i += 2) {
    digitalWrite(motorPins[i], LOW);
    digitalWrite(motorPins[i + 1], LOW);
  }
}

void forward() {
  digitalWrite(15, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("Forward");
}

void backward() {
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(22, HIGH);
  Serial.println("Backward");
}

void rightward() {
  digitalWrite(15, HIGH);
  digitalWrite(19, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(4, HIGH);
  Serial.println("CrabLeft");
}

void leftward() {
  digitalWrite(5, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(18, HIGH);
  Serial.println("CrabRight");
}

void turnleft() {
  digitalWrite(22, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(19, HIGH);
  Serial.println("TurnRight");
}

void turnright() {
  digitalWrite(2, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(4, HIGH);
  Serial.println("TurnLeft");
}

void horn() {
  digitalWrite(23, HIGH);
  Serial.println("Horn");
}

void loop() {
  Dabble.processInput();

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

  delay(100);
}
