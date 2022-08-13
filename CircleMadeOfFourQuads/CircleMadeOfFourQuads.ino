
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

void setup(){
  Serial.begin(9600);
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  display.clearDisplay();
  // 0-------------------------127 there fore the middle is (128/2)-1 = 63 
  // 0--------------------------63 there fore the middle is ( 64/2)-1 = 31
  int xMidPoint = 63;
  int yMidPoint = 31;
  int radius    = 31;
  // function : display.drawPixel(x , y , SH110X_WHITE); 
  display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
  // equation of a circle x2+y2 = (31)2 since we know the radius which is 31
  for(int i = 0 ; i < 31 ; i++){
    xMidPoint++;
    yMidPoint = sqrt((radius*radius) - (xMidPoint-63)*(xMidPoint-63))+31;
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
    display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(10);
  }
   xMidPoint = 63;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    yMidPoint--;
    xMidPoint = sqrt((radius*radius) - (yMidPoint-31)*(yMidPoint-31))+63;
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
    display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(10);
  }
  xMidPoint = 63;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    xMidPoint--;
    yMidPoint = sqrt((radius*radius) - (xMidPoint-63)*(xMidPoint-63))+31;
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
    display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(10);
  }

 xMidPoint = 63;
  yMidPoint = 31;
  for(int i = 0 ; i < 31 ; i++){
    xMidPoint++;             
    yMidPoint = sqrt((radius*radius) - (xMidPoint-63)*(xMidPoint-63))-63;
    Serial.print(xMidPoint); Serial.print(" ");Serial.println(yMidPoint);
    display.drawPixel(xMidPoint, yMidPoint, SH110X_WHITE);
    display.display();
    delay(10);
  }

 
 
}
void loop(){
  
}
