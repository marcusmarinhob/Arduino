#include "SevSeg.h"
#include "Wire.h"

/** I2C Slaves configurations *******************************/
#define SLAVE_ADRESS_1 0x08

int minutes = 0;

/** Displays configurations *********************************/
SevSeg displaySlave1;


/** Initial Configurations ********************************/
void setup() {
  displaySlave1.Begin(1,0,1,3,2, A1,A0,6,5,4,A2,A3,8);
  displaySlave1.Brightness(50);
 
  Wire.begin(SLAVE_ADRESS_1);
  Wire.onReceive(receiveMinutes);

}

/** While loop *********************************************/
void loop() 
{
  displaySlave1.NewNum(minutes,(byte) 2);
  displaySlave1.PrintOutput(); 
}


void receiveMinutes(int howMany) 
{
  while( Wire.available() ) 
  {
     minutes = Wire.read();   
  } 
  
}
