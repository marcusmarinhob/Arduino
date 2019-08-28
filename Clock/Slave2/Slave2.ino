#include "SevSeg.h"
#include "Wire.h"

/** I2C Slaves configurations *******************************/
#define SLAVE_ADRESS_2 0x09

int hours = 0;

/** Displays configurations *********************************/
SevSeg displaySlave2;


/** Initial Configurations ********************************/
void setup() {
  displaySlave2.Begin(1,0,1,2,3, A0,A1,6,5,4,A2,A3,8);
  displaySlave2.Brightness(50);
 
  Wire.begin(SLAVE_ADRESS_2);
  Wire.onReceive(receiveHours);

}

/** While loop *********************************************/
void loop() 
{
  displaySlave2.NewNum(hours,(byte) 2);
  displaySlave2.PrintOutput(); 
}


void receiveHours(int howMany) 
{
  while( Wire.available() ) 
  {
     hours = Wire.read();   
  } 
  
}
