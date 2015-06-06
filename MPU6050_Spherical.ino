

#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
#include "GravVector.h"

GravVector gv;

void setup() {  

    Serial.begin(9600);

}

void loop() {
  
    gv.update();
    
    
    Serial.print(gv.getRho()); Serial.print(",\t");
    Serial.print(gv.getTh()); Serial.print(",\t");
    Serial.print(gv.getPhi()); Serial.println(",\t");

}
