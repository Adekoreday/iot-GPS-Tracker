#include "UbidotsMicroESP8266.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#define TOKEN  "XXXXXXXXXXXXXXXXXX"  // Put here your Ubidots TOKEN
#define WIFISSID "XXXX" // Put here your Wi-Fi SSID
#define PASSWORD "XXXXXX" // Put here your Wi-Fi password


Ubidotsclient(TOKEN);
TinyGPSPlusgps;
staticconstintRXPin = 0, TXPin = 4;
staticconst uint32_t GPSBaud = 9600;
// The serial connection to the GPS device
SoftwareSerialss(RXPin, TXPin);

floatlatt=8.35555;
floatlngg= 3.7777;

float value1 =20;
char context[25]; 

void setup(){
Serial.begin(115200);
ss.begin(GPSBaud);
Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
client.wifiConnection(WIFISSID, PASSWORD);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}
void loop(){

while (ss.available() > 0)
if (gps.encode(ss.read()))
displayInfo();

if (millis() > 5000 &&gps.charsProcessed() < 10)
  {
Serial.println(F("No GPS detected: check wiring."));
while(true);
  }



}


voiddisplayInfo()
{
Serial.print(F("Location: ")); 
if (gps.location.isValid())
  {

latt=gps.location.lat();
lngg = gps.location.lng();
Serial.println(context); 
client.add("gps_coordinates", value1, context);
client.sendAll(true); 
delay(5000);

Serial.print(gps.location.lat(), 6);
Serial.print(F(","));
Serial.print(gps.location.lng(), 6);
  }
else
  {
Serial.print(F("INVALID"));
  }

Serial.print(F("  Date/Time: "));
if (gps.date.isValid())
  {
Serial.print(gps.date.month());
Serial.print(F("/"));
Serial.print(gps.date.day());
Serial.print(F("/"));
Serial.print(gps.date.year());
  }
else
  {
Serial.print(F("INVALID"));
  }

Serial.print(F(" "));
if (gps.time.isValid())
  {
if (gps.time.hour() < 10) Serial.print(F("0"));
Serial.print(gps.time.hour());
Serial.print(F(":"));
if (gps.time.minute() < 10) Serial.print(F("0"));
Serial.print(gps.time.minute());
Serial.print(F(":"));
if (gps.time.second() < 10) Serial.print(F("0"));
Serial.print(gps.time.second());
Serial.print(F("."));
if (gps.time.centisecond() < 10) Serial.print(F("0"));
Serial.print(gps.time.centisecond());
  }
else
  {
Serial.print(F("INVALID"));
  }

Serial.println();
}

