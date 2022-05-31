// Include the library:
#include <TM1637Display.h>

// Define the connections pins:
#define CLK 2
#define DIO 3
#define MQ3Pin A3

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  // Clear the display:
  display.clear();
  display.setBrightness(7);
  delay(1000);
}

void loop() {

 //waarde inlezen
 float alcoholWaarde = analogRead(MQ3Pin);

 // ingelezen waarde omrekenen naar mg/L
 float v = (alcoholWaarde /10) * (5.0/1024.0); 
 float mgL= 0.67 * v;

 int value = mgL*100;


 //Waarde printen
 Serial.print("Sensor Value: ");
 Serial.print(mgL);
 Serial.print(" mg/L");
 Serial.println();

 // waarde laten zien op 7segement display
 display.showNumberDec(alcoholWaarde);
 delay(1000);
 display.showNumberDec(value);
 delay(1000);

  
}
