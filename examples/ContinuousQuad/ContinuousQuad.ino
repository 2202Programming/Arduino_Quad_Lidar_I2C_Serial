/*
This example shows how to take simple range measurements with the VL53L1X. The
range readings are in units of mm.
*/

#include <Wire.h>
#include <VL53L1X.h>


VL53L1X sensor1;
VL53L1X sensor2;
VL53L1X sensor3;
VL53L1X sensor4;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  
  //turn off one sensor to reprogram addres on second
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
      
  sensor1.setTimeout(500);
  sensor1.init();
  sensor1.setAddress(70);

  digitalWrite(8, HIGH);
  sensor2.setTimeout(500);
  sensor2.init();
  sensor2.setAddress(71);

  digitalWrite(10, HIGH);
  sensor3.setTimeout(500);
  sensor3.init();
  sensor3.setAddress(72);
  
  digitalWrite(12, HIGH);
  sensor4.setTimeout(500);
  sensor4.init();

 
  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  sensor1.setDistanceMode(VL53L1X::Long);
  sensor1.setMeasurementTimingBudget(50000);
  sensor2.setDistanceMode(VL53L1X::Long);
  sensor2.setMeasurementTimingBudget(50000);
  sensor3.setDistanceMode(VL53L1X::Long);
  sensor3.setMeasurementTimingBudget(50000);
  sensor4.setDistanceMode(VL53L1X::Long);
  sensor4.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor1.startContinuous(50);
  sensor2.startContinuous(50);
  sensor3.startContinuous(50);
  sensor4.startContinuous(50);
}

void loop()
{
  //sensor2.stopContinuous();
  //sensor1.startContinuous(50);
  Serial.print("S1");
  //while(!sensor1.dataReady()) sensor1.dataReady();
  Serial.print(sensor1.read());
  //sensor1.stopContinuous();
  
  //sensor2.startContinuous(50);
  Serial.print("ES2");
  //while(!sensor2.dataReady()) sensor2.dataReady();
  Serial.print(sensor2.read());
  Serial.print("ES3");
  Serial.print(sensor3.read());
  Serial.print("ES4");  
  Serial.print(sensor4.read());
  Serial.print("E"); 
 
 }
