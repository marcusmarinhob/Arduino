/* Include the standard LiquidCrystal library */
#include <LiquidCrystal.h>


/* DIO pin definitions */
#define LCD_DATA4 4         /* LCD data DIO pin 4 */
#define LCD_DATA5 5         /* LCD data DIO pin 5 */
#define LCD_DATA6 6         /* LCD data DIO pin 6 */
#define LCD_DATA7 7         /* LCD data DIO pin 7 */
#define LCD_RESET 8         /* LCD Reset DIO pin */
#define LCD_ENABLE 9        /* LCD Enable DIO pin */
#define LCD_BACKLIGHT 10    /* LCD backlight DIO pin */


/* Initialise the LiquidCrystal library with the correct DIO pins */
LiquidCrystal lcd(LCD_RESET, LCD_ENABLE, LCD_DATA4, LCD_DATA5, LCD_DATA6, LCD_DATA7);


void setup() 
{
  /* Set the correct display size (16 character, 2 line display) */
  lcd.begin(16, 2);  
}

/* Main program loop */
void loop() 
{
  /* Put the LCD cursor on the first row an print the HELLO WORLD message */
  lcd.setCursor(0,0); 
  lcd.print("HELLO WORLD !");
}
