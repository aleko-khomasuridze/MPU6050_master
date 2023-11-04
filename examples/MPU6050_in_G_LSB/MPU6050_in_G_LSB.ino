/* 
   @Author: Aleko khomasuridze 
   @Date: November 3, 2023

   This Arduino code is designed to interface with an MPU6050 sensor using a custom MPU6050 library.
   The MPU6050 is a widely used Inertial Measurement Unit (IMU) that provides raw accelerometer and
   gyroscope data for the X, Y, and Z axes, as well as raw temperature data.

   In this code, the sensor data is read and printed to the serial monitor. The accelerometer and
   gyroscope data are converted to meaningful units, such as G-forces for acceleration and
   least significant bits (LSB) for gyroscopic values. Additionally, the temperature is displayed
   in degrees Celsius.

   The setup function initializes serial communication for debugging and I2C communication
   with the sensor.

   In the loop function, it reads raw accelerometer and gyroscope data and temperature. Then, it
   converts and prints these values in user-friendly units on the serial monitor for monitoring.

   Make sure that you have the custom MPU6050 library installed in your Arduino IDE.

   Library: YourCustomMPU6050Library (Please replace with the actual library name)

   Ensure the MPU6050 sensor is correctly connected to your Arduino. Consult the datasheet or
   documentation for your specific sensor for wiring details.
*/

#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
  Wire.begin();        // Initialize the I2C communication
  mpu.begin();         // Initialize the MPU6050 sensor
}

void loop() {
  // Read sensor data
  double accelXInG = MPU6050::convertAccelToG(mpu.getRawAccelX());
  double accelYInG = MPU6050::convertAccelToG(mpu.getRawAccelY());
  double accelZInG = MPU6050::convertAccelToG(mpu.getRawAccelZ());
  double gyroXInLSB = MPU6050::convertGyroToLSB(mpu.getRawGyroX());
  double gyroYInLSB = MPU6050::convertGyroToLSB(mpu.getRawGyroY());
  double gyroZInLSB = MPU6050::convertGyroToLSB(mpu.getRawGyroZ());
  double temperature = mpu.getTemperatureInC();


  // Print the sensor data to the serial monitor
  Serial.print("Accel X (G): ");
  Serial.println(accelXInG);
  Serial.print("Accel Y (G): ");
  Serial.println(accelYInG);
  Serial.print("Accel Z (G): ");
  Serial.println(accelZInG);
  Serial.print("Gyro X (LSB): ");
  Serial.println(gyroXInLSB);
  Serial.print("Gyro Y (LSB): ");
  Serial.println(gyroYInLSB);
  Serial.print("Gyro Z (LSB): ");
  Serial.println(gyroZInLSB);
  Serial.print("Temperature (C): ");
  Serial.println(temperature);

  delay(1000);  // Delay for one second
}
