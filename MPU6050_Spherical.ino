
//need to include all this if not already included
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
#include "GravVector.h" //stuff for getting acceleration vector

GravVector gv;   //create object to get acceleration vector

void setup() {  

    Serial.begin(9600);

}

void loop() {
  
    gv.update(); //need to run this to read sensor and calculate spherical coordinates
    
    
    //getting the spherical coordinates
    Serial.print(gv.getRho()); Serial.print(",\t");     //this would be magnitude
    
    Serial.print(gv.getTh()); Serial.print(",\t");      //this could be angle of descent
    Serial.print(gv.getPhi()); Serial.println(",\t");   //or this could be angle of descent
                                                        //depends on how the sensor is mounted

}
