#include <Wire.h>                   // Library that enables I2C communication
#include <Adafruit_Sensor.h>        // Core sensor library
#include <Adafruit_ADXL345_U.h>     // Library for the ADXL345 accelerometer

// An instance of ADXXL345 sensor
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

void setup() {
  Serial.begin(9600);   // Initialise serial communication at 9600 baud rate
  // Initialise the accelerometer
  if (!accel.begin()) {
    Serial.println("Ooops, no ADXL345 detected!"); // Error message for if the sensor is not found 
    while (1); // Stop program execution if sensor was not detected
  }
  // To set the range of my accelerometer to +/-16g. This enables high sensitivity.
  accel.setRange(ADXL345_RANGE_16_G);
}

void loop() {
  sensors_event_t event;                // Defines variable to store sensor event data
  accel.getEvent(&event);               // Reads acceleration daat from the sensor
  
  Serial.print(event.acceleration.x);   // Print acceleration values on X, Y, and Z axes to serial monitor
  Serial.print(",");
  Serial.print(event.acceleration.y);
  Serial.print(",");
  Serial.println(event.acceleration.z);

  delay(100); // Adjust sampling rate by a delay for 100ms to control sampling rate
}
