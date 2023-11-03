/* 
   @Author: Aleko khomasuridze 
   @Date: November 3, 2023

   This Arduino code is designed for interfacing with an MPU6050 sensor using a custom MPU6050 library.
   The MPU6050 is a popular Inertial Measurement Unit (IMU) that provides raw accelerometer and
   gyroscope data for the X, Y, and Z axes, as well as raw temperature data.

   In this code, the sensor data is read and printed to the serial monitor. This is a useful
   debugging tool to visualize the sensor's output.

   The setup function initializes the serial communication for debugging, as well as the I2C
   communication with the sensor.

   In the loop function, it reads raw accelerometer and gyroscope data for all three axes
   and the raw temperature data. It then prints these values to the serial monitor for
   monitoring.

   Make sure that you have the custom MPU6050 library installed in your Arduino IDE.

   Library: YourCustomMPU6050Library (Please replace with the actual library name)

   Make sure to connect the MPU6050 sensor to the appropriate pins on your Arduino board.
   Consult the datasheet or documentation for your specific sensor for wiring details.
*/

#include <MPU6050.h>

MPU6050 mpu;  // Create an instance of the MPU6050 class

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
  Wire.begin();        // Initialize the I2C communication
  mpu.begin();         // Initialize the MPU6050 sensor
}

void loop() {
  // Read sensor data
  int accelX = mpu.getRawAccelX();  // Read raw accelerometer data for the X-axis
  int accelY = mpu.getRawAccelY();  // Read raw accelerometer data for the Y-axis
  int accelZ = mpu.getRawAccelZ();  // Read raw accelerometer data for the Z-axis
  int gyroX = mpu.getRawGyroX();    // Read raw gyroscope data for the X-axis
  int gyroY = mpu.getRawGyroY();    // Read raw gyroscope data for the Y-axis
  int gyroZ = mpu.getRawGyroZ();    // Read raw gyroscope data for the Z-axis
  int temperature = mpu.getRawTemperature();  // Read raw temperature data

  // Print the sensor data to the serial monitor
  Serial.print("Accel X: ");
  Serial.println(accelX);  // Print the raw accelerometer value for X-axis
  Serial.print("Accel Y: ");
  Serial.println(accelY);  // Print the raw accelerometer value for Y-axis
  Serial.print("Accel Z: ");
  Serial.println(accelZ);  // Print the raw accelerometer value for Z-axis
  Serial.print("Gyro X: ");
  Serial.println(gyroX);    // Print the raw gyroscope value for X-axis
  Serial.print("Gyro Y: ");
  Serial.println(gyroY);    // Print the raw gyroscope value for Y-axis
  Serial.print("Gyro Z: ");
  Serial.println(gyroZ);    // Print the raw gyroscope value for Z-axis
  Serial.print("Temperature (raw): ");
  Serial.println(temperature);  // Print the raw temperature value

  delay(1000);  // Delay for one second
}
