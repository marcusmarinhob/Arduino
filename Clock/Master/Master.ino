#include "Wire.h"
#include "SevSeg.h"


/** I2C Slaves configurations *******************************/
#define SLAVE_ADRESS_1 0x08
#define SLAVE_ADRESS_2 0x09

/** Displays configurations *********************************/
SevSeg displayMaster;

/** Time variables *****************************************/
int seconds = 0, minutes = 0, hours = 0;

/** Timer using MILLIS ************************************/
#define TIME_DELAY 1000
unsigned long lastTime = 0;

/** Function Prototypes ************************************/
void updateDisplay(void);
void transmitMinutes(void);
void transmitHours(void);


/** Initial Configurations ********************************/
void setup() 
{
  Wire.begin();

  displayMaster.Begin(1,0,1,8,9,A2,A1,4,3,2,A0,5,6); 
  displayMaster.Brightness(1);
}


/** While loop *********************************************/
void loop() 
{    
  updateDisplay();
  
  if ( (millis() - lastTime) >= TIME_DELAY )
  {
     seconds++;
     if ( seconds > 59 )
     {
        minutes++;
        seconds = 0;                    
        
        if( minutes > 59 )
        {
           hours++;
           minutes = 0;

           if (hours > 23 )
           {
              hours = 0;
           }
           transmitHours();
        }
        transmitMinutes();
     }
     lastTime = millis();
  }

}


void updateDisplay(void)
{
  displayMaster.PrintOutput();
  displayMaster.NewNum(seconds,(byte) 1);
}


void transmitMinutes(void)
{
   Wire.beginTransmission(SLAVE_ADRESS_1);
   Wire.write(minutes);   
   Wire.endTransmission(); 
}

void transmitHours(void)
{
  Wire.beginTransmission(SLAVE_ADRESS_2);
  Wire.write(hours);   
  Wire.endTransmission(); 
}
