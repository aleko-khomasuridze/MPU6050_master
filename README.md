# MPU6050_master

The Arduino MPU6050 Interface is a library that simplifies the interaction with the MPU6050 accelerometer and gyroscope sensor using the Arduino platform. This library provides a convenient way to initialize the sensor, read raw sensor data, and convert these values into meaningful units. It also includes methods to set the I2C address and format the object as a string.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Library Usage](#library-usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Initialize the MPU6050 sensor.
- Read raw sensor data for accelerometer, gyroscope, and temperature.
- Convert sensor data to G-forces (acceleration) and LSB (gyroscope).
- Set a custom I2C address for the sensor.
- Format the sensor object as a string.

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) installed.
- An MPU6050 sensor connected to your Arduino board.

### Installation

1. Download the library files (MPU6050.h and MPU6050.cpp) from this repository.
2. Open your Arduino IDE.
3. Go to Sketch > Include Library > Add .ZIP Library.
4. Select the downloaded ZIP file containing the library files.
5. The library is now installed and ready to use.

## Library Usage

To use the library, follow these steps:

1. Import the library at the beginning of your Arduino sketch:

```cpp
#include <MPU6050.h>
```

2. Create an instance of the `MPU6050` class:

```cpp
MPU6050 mpu;
```

3. Initialize the sensor in the `setup` function:

```cpp
void setup() {
  Serial begin(9600);  // Initialize serial communication for debugging
  Wire.begin();        // Initialize the I2C communication
  mpu.begin();         // Initialize the MPU6050 sensor
}
```

4. Read sensor data and perform conversions in the `loop` function:

```cpp
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
  Serial print("Accel X (G): ");
  Serial.println(accelXInG);
  // ... (print other sensor data)

  delay(1000);  // Delay for one second
}
```

5. Customize the library according to your specific conversion needs by implementing `convertAccelToG` and `convertGyroToLSB` functions within the `MPU6050` class.

## Contributing

If you'd like to contribute to this library, please feel free to create a pull request. We welcome any improvements, bug fixes, or additional features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

You can now copy this content as a whole.
