Arduino_Quad_Lidar_I2C_Serial

Arduino code for initializing and reading LIDAR over I2C, and transmitting data over serial.

Needs to power up one chip at a time so it can switch it's I2C address off the default address.

Uses 4 of the VL53L1X LIDAR chips.

Uses API from Pololu: https://github.com/pololu/vl53l1x-arduino


Expects the XSHUT line from each LIDAR to go to the arduino pins 6,8,10, and 12 respectively.

Otherwise, all the chips are on a common 5V, gnd, SDA and SCL bus.

Writes out a serial message in this format:

S[LIDAR # from 1-4][Distance in mm]E

Example for all chips at 100 mm:

S1100ES2100ES3100ES4100E
