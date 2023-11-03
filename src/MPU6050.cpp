#include "MPU6050.h"  // header file of IMU library

// Initialize the MPU6050 object (waking it up)
bool MPU6050::begin() {
  Wire.begin();
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(0x6B);  // Power management register
  Wire.write(0x00);   // Set power management register to wake up the MPU6050
  Wire.endTransmission(true);
  return true;
}

// *********************** Accelerometer value getters ***********************; 

// Get raw accelerometer data for the X-axis
int MPU6050::getRawAccelX() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_X_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawXAccel = Wire.read() << 8 | Wire.read();
  return this->rawXAccel;
}

// Get raw accelerometer data for the Y-axis
int MPU6050::getRawAccelY() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_Y_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawYAccel = Wire.read() << 8 | Wire.read();
  return this->rawYAccel;
}

// Get raw accelerometer data for the Z-axis
int MPU6050::getRawAccelZ() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_Z_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawZAccel = Wire.read() << 8 | Wire.read();
  return this->rawZAccel;
}

// *********************** temperature methods ***********************; 


// Get raw temperature data
int MPU6050::getRawTemperature() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(TEMP_REG_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawTemperature = Wire.read() << 8 | Wire.read();
  return this->rawTemperature;
}

// get temperature of MPU6050 in celsius
double MPU6050::getTemperatureInC(){
  return (double)(this->rawTemperature / 340) + 36.53;
}

// get temperature of MPU6050 in Farenheit
double MPU6050::getTemperatureInF(){
  return (this->getTemperatureInC() * 9.00 / 5.00) + 32.00;
}


// *********************** Gyroscope value getters ***********************; 

// Get raw gyro data for the X-axis
int MPU6050::getRawGyroX() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(GYRO_REG_X_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawXGyro = Wire.read() << 8 | Wire.read();
  return this->rawXGyro;
}

// Get raw gyro data for the Y-axis
int MPU6050::getRawGyroY() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(GYRO_REG_Y_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawYGyro = Wire.read() << 8 | Wire.read();
  return this->rawYGyro;
}

// Get raw gyro data for the Z-axis
int MPU6050::getRawGyroZ() {
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(GYRO_REG_Z_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  this->rawZGyro = Wire.read() << 8 | Wire.read();
  return this->rawZGyro;
}



// Set the address of the MPU6050 sensor
void MPU6050::setAddress(uint8_t MPU6050_ADDR) {
  this->MPU6050_ADDR = MPU6050_ADDR;
}


int* MPU6050::getAllData(){
  int data[7];
  //uint8_t lenght = sizeof(data) / sizeof(data[0]);
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_X_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 14, true);
  for(int i = 0; i < 7/*lenght*/; i++)
    data[i] = Wire.read() << 8 | Wire.read();
  return data;
}

double* MPU6050::getFullAccelInG(){
  double data[3];
  //uint8_t lenght = sizeof(data) / sizeof(data[0]);
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_X_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);
  for(uint8_t i = 0; i < 3/*lenght*/; i++)
    data[i] = this->convertAccelToG((int)(Wire.read() << 8 | Wire.read()));
  return data;
}


double* MPU6050::getFullGyroInLSB(){
  double data[3];
  //uint8_t lenght = sizeof(data) / sizeof(data[0]);
  Wire.beginTransmission(this->MPU6050_ADDR);
  Wire.write(ACCEL_REG_X_HIGH);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);
  for(uint8_t i = 0; i < 3/*lenght*/; i++)
    data[i] = this->convertGyroToLSB((int)(Wire.read() << 8 | Wire.read()));
  return data;
}


// 
String MPU6050::toString(){
  return "MPU6050{\n\tAcX: " + String(this->getRawAccelX()) + 
  ",\n\tAcY: " + String(this->getRawAccelY()) + 
  ",\n\tAcZ: " + String(this->getRawAccelZ()) + 
  ",\n\tTmp: " + String(this->getTemperatureInC()) + 
  ",\n\tGyX: " + String(this->getRawGyroX()) + 
  ",\n\tGyY: " + String(this->getRawGyroY()) + 
  ",\n\tGyZ: " + String(this->getRawGyroZ()) + 
  "\n}";
}
