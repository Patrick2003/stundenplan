#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "config.h"


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);



/*
  #define shiftPin D2   // Pin SCK an 74HC595
  #define storePin D1   // Pin RCK an 74HC595
  #define dataPin D0    // Pin SER an 74HC595
*/



unsigned long Time = 0;

void setup() {
  Serial.begin(9600); 
  WiFi.begin(ssid, password);  //start WiFi connection

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Serial.println("WiFi connected");

  timeClient.begin();
  
  /*pinMode(storePin, OUTPUT);  // Pins auf Output setzen
  pinMode(shiftPin, OUTPUT);
  pinMode(dataPin, OUTPUT);*/

}



void loop() {
  
  if(millis() - Time > 1000) {
    timeClient.update();
    int day = timeClient.getDay() - 1;
    Serial.println(subjects(day));

    Time = millis();  
  }
/*


  for (int i = 0; i < 16; i++)
  {
    if (leds[i] = '1')
    {
      Shift |= (1 << i);
    }
  }

  digitalWrite(storePin, LOW);
  shiftOut(dataPin, shiftPin, MSBFIRST, subjects(day));
  digitalWrite(storePin, HIGH);
  delay(500); */
}

unsigned short subjects(int day) { //Funktion liefert unsigned short für shiftOut()
  
  char output[17] = "0000000000000000"; //16BIT  für 16 LEDs
  int binaer = 1; //Binärcounter
  unsigned short Shift = 0; //Ausabe für shiftout
  
  for(int element = 0; element < 16; element++) {  //erstellt einen 16-stelligen string (binärzahl) für die Schieberegister
    if(timetable [day] [element]) {
      output [timetable [day] [element]] = '1';
    }
  }
  Serial.println(output);
  for(int i = 15; i >= 0; i--) {   //konvertiert den 'binärstring' zu unsigned short für die ShiftOut Funktion 
    if(output [i] == '1') {
      Shift += binaer;
    }
    binaer = binaer*2;
  }
  return Shift;
}
