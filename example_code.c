#include <Arduino.h>
/*
  TB6612FNG H-Bridge Demo for ESP32 using Arduino IDE
  Controls two DC Motors using PWM and GPIO
  Written by Ansar Mukash!
*/

// Motor A:
// 1: Forward
// 2: Reverse
int pwmA = 25; // Adjust based on wiring
int in1A = 21;
int in2A = 17;

// Motor B
// 1: Forward
// 2: Reverse
int pwmB = 26; // Adjust based on wiring
int in1B = 22;
int in2B = 23;


const int freq = 5000;      // PWM frequency
const int resolution = 8;   // PWM resolution (8-bit: 0-255)

void setup() {
  // Configure PWM for Motor A
  ledcAttach(pwmA, freq, resolution);

  // Configure PWM for Motor B
  ledcAttach(pwmB, freq, resolution);

  // Set direction pins as outputs
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
}

void loop() {
  // Perform 3 cycles of forward and backward motion
  for (int i = 0; i < 3; i++) {
    // Move forward at half power
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
    ledcWrite(pwmA, 128); // Set Motor A to half power (50% of 255)
    ledcWrite(pwmB, 128); // Set Motor B to half power (50% of 255)
    delay(2000); // Run forward for 2 seconds

    // Move backward at half power
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
    ledcWrite(pwmA, 128); // Set Motor A to half power (50% of 255)
    ledcWrite(pwmB, 128); // Set Motor B to half power (50% of 255)
    delay(2000); // Run backward for 2 seconds
  }

  // Stop the motors after 3 cycles
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  ledcWrite(pwmA, 0); // Turn off PWM for Motor A
  ledcWrite(pwmB, 0); // Turn off PWM for Motor B

  // Halt the loop since the task is completed
  while (true) {
    // Do nothing, effectively stopping the program
  }
}