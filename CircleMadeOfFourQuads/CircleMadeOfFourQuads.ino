
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c                                            //initialize with the I2C addr 0x3C Typically eBay OLED's
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

void setup(){
  Serial.begin(9600);
  delay(100);                                                       // wait for the OLED to power up
  display.begin(i2c_Address, true);                                 // Address 0x3C default
  display.clearDisplay();
   
  int xMidPoint = 63;                                               // 0-----127 there fore the middle is (128/2)-1 = 63 
  int yMidPoint = 31;                                               // 0------63 there fore the middle is ( 64/2)-1 = 31
  int radius    = 31;
 
  display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);            // function : display.drawPixel(x , y , SH110X_WHITE); 
  
  for(int i = 0 ; i < 31 ; i++){                                    // equation of a circle x2+y2 = (31)2 since we know the radius which is 31
    xMidPoint++;                                                          //initial x = 63 , final x = 94
    yMidPoint = sqrt((radius*radius) - (xMidPoint-63)*(xMidPoint-63))+31; //initial y = 62  , final y = 31
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
     display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
    //display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
    //--2--
  xMidPoint = 94;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    yMidPoint++;                                                          //initial y = 31 , final y = 0      
    xMidPoint = sqrt((radius*radius)-((yMidPoint-31)*(yMidPoint-31)))+63; //initial x = 94 , final x = 63
    display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
    //display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
  // at this point xMidPoint = 94 and yMidPoint = 31
  xMidPoint = 94;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    yMidPoint--;                                                          //initial y = 31 , final y = 0      
    xMidPoint = sqrt((radius*radius)-((yMidPoint-31)*(yMidPoint-31)))+63; //initial x = 94 , final x = 63
    display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
    //display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
   //--3--
  xMidPoint = 63;
  yMidPoint = 0;
  for(int i = 0 ; i < 31 ; i++){
    xMidPoint++;                                                  //initial x = 63 , final x = 32              
    yMidPoint = (31)-sqrt((radius*radius)-((xMidPoint-63)*(xMidPoint-63)));//initial y = 0 , final y = 31
     display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
   // display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
    // at this point xMidPoint = 63 and yMidPoint = 0
  xMidPoint = 63;
  yMidPoint = 0;
  for(int i = 0 ; i < 31 ; i++){
    xMidPoint--;                                                  //initial x = 63 , final x = 32              
    yMidPoint = (31)-sqrt((radius*radius)-((xMidPoint-63)*(xMidPoint-63)));//initial y = 0 , final y = 31
     display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
   // display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
   //--4--
  xMidPoint = 32;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    yMidPoint--;
    xMidPoint = (63)-sqrt((radius*radius)-((yMidPoint-31)*(yMidPoint-31)));
    display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
   // display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
    // at this point xMidPoint = 32 and yMidPoint = 31
  xMidPoint = 32;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    yMidPoint++;
    xMidPoint = (63)-sqrt((radius*radius)-((yMidPoint-31)*(yMidPoint-31)));
    display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
   // display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
  
  xMidPoint = 63;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){                                    // equation of a circle x2+y2 = (31)2 since we know the radius which is 31
    xMidPoint--;                                                          //initial x = 63 , final x = 94
    yMidPoint = sqrt((radius*radius) - (xMidPoint-63)*(xMidPoint-63))+31; //initial y = 62  , final y = 31
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
     display.drawLine(63, 31, xMidPoint, yMidPoint, SH110X_WHITE);
    //display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(5);
  }
 

  
  
  




 
  
}
void loop(){
  
}
