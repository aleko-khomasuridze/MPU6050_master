#include<Arduino.h>
#include<Wire.h>


#define ACCEL_REG_X_HIGH 0x3B
#define ACCEL_REG_Y_HIGH 0x3D
#define ACCEL_REG_Z_HIGH 0x3F

#define TEMP_REG_HIGH    0x41

#define GYRO_REG_X_HIGH  0x3B
#define GYRO_REG_Y_HIGH  0x3D
#define GYRO_REG_Z_HIGH  0x3F


class IConverter{
  public:
  virtual double convertAccelToG(double IMU_val) = 0;
  virtual double convertGyroToLSB(double IMU_val) = 0;
};

class MPU6050: public IConverter{ 
  private:
    int rawXAccel;
    int rawYAccel;
    int rawZAccel;

    int temperature, rawTemperature;

    int rawXGyro;
    int rawYGyro;
    int rawZGyro;

    uint8_t MPU6050_ADDR = 0x68;

    const uint8_t numberOfValues = 7;

  public:
    bool begin();
    
    int getRawAccelX();
    int getRawAccelY();
    int getRawAccelZ();

    int getRawTemperature();
    double getTemperatureInC();
    double getTemperatureInF();

    int getRawGyroX();
    int getRawGyroY();
    int getRawGyroZ();

    int* getAllData();

    double* getFullAccelInG();
    double* getFullGyroInLSB();


    uint8_t getNumberOfValues();

    void setAddress(uint8_t MPU6050_ADDR);

    static double convertAccelToG(int IMU_val);
    static double convertGyroToLSB(int IMU_val);

    String toString();
};