
#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif



class GravVector
{
  public:
  
  GravVector();
  
  float getRho();
  float getTh();
  float getPhi();
  
  void update();
  
};

