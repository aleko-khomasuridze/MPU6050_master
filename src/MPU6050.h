/*
  Arduino MPU6050 Interface

  This Arduino code defines a class, MPU6050, for interfacing with the MPU6050
  accelerometer and gyroscope sensor over I2C. It also includes an interface
  class, IConverter, for converting sensor values.

  The MPU6050 class provides methods for initializing the sensor, reading raw sensor data,
  and converting sensor data to meaningful units like G-forces and degrees per second.
  It also includes methods for setting the I2C address and formatting the object as a string.

  The code is well-organized with explanatory comments for each section.

  Author: Aleko Khoamsuridze (aleko.khoamsuridze@gamil.com)
*/

#include<Arduino.h>  // Include the Arduino library for your project.
#include<Wire.h>     // Include the Wire library for I2C communication.


// Define constants for the accelerometer and gyroscope registers.
#define ACCEL_REG_X_HIGH 0x3B
#define ACCEL_REG_Y_HIGH 0x3D
#define ACCEL_REG_Z_HIGH 0x3F
#define TEMP_REG_HIGH    0x41
#define GYRO_REG_X_HIGH  0x3B
#define GYRO_REG_Y_HIGH  0x3D
#define GYRO_REG_Z_HIGH  0x3F

// Create an interface class IConverter for converting IMU sensor values.
class IConverter {
  public:
    static double convertAccelToG(double IMU_val);  // Method to convert accelerometer value to G-force.
    static double convertGyroToLSB(double IMU_val); // Method to convert gyroscope value to LSB.
};

// Create a class MPU6050 that inherits from IConverter.
class MPU6050 : public IConverter {
  private:
    int rawXAccel;
    int rawYAccel;
    int rawZAccel;
    int rawTemperature;
    int rawXGyro;
    int rawYGyro;
    int rawZGyro;
    uint8_t MPU6050_ADDR = 0x68;  // Default I2C address for the MPU6050 sensor.

  public:
    bool begin();  // Method to initialize the MPU6050 sensor.

    int getRawAccelX();  // Method to get the raw X-axis accelerometer value.
    int getRawAccelY();  // Method to get the raw Y-axis accelerometer value.
    int getRawAccelZ();  // Method to get the raw Z-axis accelerometer value.

    int getRawTemperature();      // Method to get the raw temperature value.
    double getTemperatureInC();   // Method to convert temperature to Celsius.
    double getTemperatureInF();   // Method to convert temperature to Fahrenheit.

    int getRawGyroX();  // Method to get the raw X-axis gyroscope value.
    int getRawGyroY();  // Method to get the raw Y-axis gyroscope value.
    int getRawGyroZ();  // Method to get the raw Z-axis gyroscope value.

    int* getAllData();  // Method to retrieve all sensor data.

    double* getFullAccelInG();  // Method to convert and retrieve accelerometer data in G-forces.
    double* getFullGyroInLSB();  // Method to retrieve gyroscope data in LSB.

    void setAddress(uint8_t MPU6050_ADDR);  // Method to set the I2C address of the sensor.

    static double convertAccelToG(double IMU_val) {
      // Provide the actual implementation of the conversion here
      return (double)(IMU_val / 16384.0); // Example implementation
    }

    static double convertGyroToLSB(double IMU_val) {
      // Provide the actual implementation of the conversion here
      return (double)(IMU_val / 131.0); // Example implementation
    }
    
    String toString();  // Method to convert the object to a string representation.
};

