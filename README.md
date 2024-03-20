# glowCube
ESP32 based RGB Matrix Cube
#### Features
* uses 5x8x8 WS2812 RGB LED
* uses MPU6050 as 3-Axis Gyroscope and Accelerometer
* uses INMP441 as I2S Microphone
* controllable via WebUI
* works as WLAN client and AP (AP chooser included)
* WebUI with IP address 192.168.4.1
* mDNS hostname glowcube.local
* DNS hostname glowcube.local (WLAN AP mode only)
#### GPIO LED Matrix
* GPIO 25 - 8x8 Matrix 0
* GPIO 26 - 8x8 Matrix 1
* GPIO 27 - 8x8 Matrix 2
* GPIO 32 - 8x8 Matrix 3
* GPIO 33 - 8x8 Matrix 4
#### GPIO MPU6050 (I2C)
* GPIO 21 - SDA
* GPIO 22 - SCL
#### GPIO INMP441 (I2S)
* GPIO 16 - DIN
* GPIO 17 - BCK
* GPIO 18 - WS
#### Development Hardware
![IMAGE ALT TEXT HERE](documentation/glowCube_a.png)
#### Web UI
![IMAGE ALT TEXT HERE](documentation/webui.png)
#### Matrix orientation
![IMAGE ALT TEXT HERE](documentation/matrix_orientation.png)
#### LED orientation
![IMAGE ALT TEXT HERE](documentation/led_orientation.png)
#### MPU6050 orientation
![IMAGE ALT TEXT HERE](documentation/mpu6050_orientation.png)