/*
  MPU6050 Sensor Interface for Arduino

  This Arduino code defines a class, MPU6050, for interfacing with the MPU6050
  accelerometer and gyroscope sensor over I2C. It also includes an interface
  class, IConverter, for converting sensor values.

  The MPU6050 class provides methods for initializing the sensor, reading raw sensor data,
  and converting sensor data to meaningful units like G-forces and degrees per second.
  It also includes methods for setting the I2C address and formatting the object as a string.

  Author: Aleko Khoamsuridze (aleko.khoamsuridze@gmail.com)

  Note: The code assumes that you have the "MPU6050.h" and "MPU6050.cpp" files in your project directory
  or added to your Arduino IDE as a library.

  Wiring:
  - Connect the VCC and GND of the MPU6050 to the 5V and GND pins of the Arduino.
  - Connect the SDA (data) and SCL (clock) pins of the MPU6050 to the corresponding pins on the Arduino.
  - Make sure to check the address of your MPU6050 and set it accordingly in the code.

  Usage:
  - Include the "MPU6050.h" and "MPU6050.cpp" files in your project directory or library.
  - Initialize the MPU6050 sensor and set the I2C address (if needed) in your setup().
  - Use the provided methods to obtain sensor data, including accelerometer, gyroscope, and temperature values.
  - Don't forget to release the allocated memory after using methods that return pointers.
*/

#include <MPU6050.h>

MPU6050 mpu; // Create an instance of the MPU6050 class

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Initialize the Wire library for I2C communication

  // Initialize the MPU6050 sensor and set the I2C address (if needed)
  mpu.begin();
  // mpu.setAddress(0x69); // Uncomment and change the address if necessary

  // Print a header to the serial monitor
  Serial.println("Accelerometer Data (G-forces)");

  // Wait for a moment to ensure the sensor is ready
  delay(1000);
}

void loop() {
  // Call the getFullAccelInG() method to get accelerometer data in G-forces
  double* accelData = mpu.getFullAccelInG();

  if (accelData) {
    Serial.print("X-Axis: ");
    Serial.print(accelData[0]);
    Serial.print("\tY-Axis: ");
    Serial.print(accelData[1]);
    Serial.print("\tZ-Axis: ");
    Serial.println(accelData[2]);

    // Don't forget to release the allocated memory
    delete[] accelData;
  } else {
    Serial.println("Failed to get accelerometer data");
  }

  delay(100); // Add a small delay for readability
}
