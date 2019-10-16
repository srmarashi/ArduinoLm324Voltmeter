//Simple Arduino VoltMeter CODE BY: s.r.marashi  Schematic: google
//srmarashi@yahoo.com

#include <SPI.h>
#include "U8glib.h"
U8GLIB_PCD8544 u8g(2, 3, 5, 4,6);  // CLK ,DIN ,CE ,DC ,RST  


void setup() {
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  digitalWrite(11,HIGH);
  Serial.begin(9600);
    
}

void loop() {  
  u8g.firstPage(); do {      
       u8g.setFont(u8g_font_profont12);
        float v = analogRead(A0);
         Serial.println(v * 0.01165630 );
       u8g.setPrintPos( 0, 7); 
       u8g.print("Easy Meter ");
       u8g.setPrintPos( 0, 24); 
       u8g.print(v*0.01165630);
       u8g.setPrintPos( 0, 37); 
       u8g.print("VOLT");
       
       } 
      while( u8g.nextPage() );
}
