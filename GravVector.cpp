
#include "GravVector.h"

MPU6050 accelgyro;

int16_t ax, ay, az;

float rho, th, phi;

GravVector::GravVector()
{
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
  #endif
  //initialize MPU6050 sensor
  accelgyro.initialize();
}

float GravVector::getRho()
{
  return rho;
}

float GravVector::getTh()
{
  return th;
}

float GravVector::getPhi()
{
  return phi;
}


void GravVector::update()
{
  accelgyro.getAcceleration(&ax, &ay, &az);    
  rho = sqrt(ax*ax+ay*ay+az*az);
  th = acos((float)az/(float)rho)*180/M_PI;
  phi = atan((float)ay/(float)az)*180/M_PI;
}
