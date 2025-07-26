#include <Servo.h>

const int leftSpeedPin = 11;
const int leftDirPin1 = 10;
const int leftDirPin2 = 9;
const int rightSpeedPin = 5;
const int rightDirPin1 = 4;
const int rightDirPin2 = 3;
const int servoPin = 6;
const int trigPin = 13;
const int echoPin = 12;

Servo myServo;

void setup() {
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(leftDirPin1, OUTPUT);
  pinMode(leftDirPin2, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
  pinMode(rightDirPin1, OUTPUT);
  pinMode(rightDirPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(90);

  Serial.begin(9600);
  
  stopMotors();
  delay(1000);

  // Initial startup sequence
  moveForward();
  delay(5000);

  moveBackward();
  delay(5000);

  unsigned long turnStartTime = millis();
  while (millis() - turnStartTime < 5000) {
    turnRight();
    delay(1000); 
    
    turnLeft();
    delay(1000);
  }

  stopMotors();
  delay(500);
}

void loop() {
  int distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10 && distance > 0) {
    stopMotors();
    delay(200);
    moveBackward();
    delay(1000);
    stopMotors();
    delay(200);
    turnRight();
    delay(750);
    stopMotors();
  } else {
    moveForward();
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance_cm = duration * 0.034 / 2;
  return distance_cm;
}

void moveForward() {
  myServo.write(90);
  digitalWrite(leftDirPin1, HIGH);
  digitalWrite(leftDirPin2, LOW);
  digitalWrite(rightDirPin1, HIGH);
  digitalWrite(rightDirPin2, LOW);
  analogWrite(leftSpeedPin, 200);
  analogWrite(rightSpeedPin, 200);
}

void moveBackward() {
  myServo.write(180);
  digitalWrite(leftDirPin1, LOW);
  digitalWrite(leftDirPin2, HIGH);
  digitalWrite(rightDirPin1, LOW);
  digitalWrite(rightDirPin2, HIGH);
  analogWrite(leftSpeedPin, 200);
  analogWrite(rightSpeedPin, 200);
}

void turnRight() {
  myServo.write(30);
  digitalWrite(leftDirPin1, HIGH);
  digitalWrite(leftDirPin2, LOW);
  digitalWrite(rightDirPin1, LOW);
  digitalWrite(rightDirPin2, HIGH);
  analogWrite(leftSpeedPin, 200);
  analogWrite(rightSpeedPin, 200);
}

void turnLeft() {
  myServo.write(150);
  digitalWrite(leftDirPin1, LOW);
  digitalWrite(leftDirPin2, HIGH);
  digitalWrite(rightDirPin1, HIGH);
  digitalWrite(rightDirPin2, LOW);
  analogWrite(leftSpeedPin, 200);
  analogWrite(rightSpeedPin, 200);
}

void stopMotors() {
  myServo.write(90);
  analogWrite(leftSpeedPin, 0);
  analogWrite(rightSpeedPin, 0);
}
