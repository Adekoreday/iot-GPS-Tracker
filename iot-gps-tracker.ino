#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-aBjFZDzCpO68YSlbUocYtb8oLGisK8"  // Put here your Ubidots TOKEN
#define WIFISSID "kay" // Put here your Wi-Fi SSID
#define PASSWORD "kore@123" // Put here your Wi-Fi password


Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}
void loop(){
  float value1 =20;
  char context[25];   
  float lat = 8.3792;
  float lng = 7.5244;
  
    //sprintf(context, "lat=8.3792$lng=7.5244"); //Sends latitude and longitude for watching position in a map 
    sprintf(context, "lat=%d.%03d$lng=%d.%03d",(int)lat,(int)(lat*1000)%1000,(int)lng,(int)(lng* 1000)%1000); 
    Serial.println(context);
    client.add("gps_coordinates", value1, context);
        client.sendAll(true); 
    delay(5000);
}
