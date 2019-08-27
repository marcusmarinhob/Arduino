#include "Wire.h"

#define SLAVE_ADRESS_1 0x08
#define SLAVE_ADRESS_2 0x09

int seconds = 0, minutes = 0, hours = 0;

void setup() 
{
  Wire.begin();
}

void loop() 
{    
      Wire.beginTransmission(SLAVE_ADRESS_1);
      Wire.write(minutes);   
      Wire.endTransmission(); 

      Wire.beginTransmission(SLAVE_ADRESS_2);
      Wire.write(hours);   
      Wire.endTransmission(); 
  
}
