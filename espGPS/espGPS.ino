#include <TinyGPS++.h>
#define serial_gps Serial1
TinyGPSPlus gps;

void setup() {
Serial.begin(9600);
serial_gps.begin(9600, SERIAL_8N1, 27, 26);
Serial.println("GPS Mulai");
}

void loop() {
  
  while(serial_gps.available()) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    Serial.print("Latitude=");
    Serial.print(gps.location.lat(),6);
    Serial.print(" Longitude=");
    Serial.println(gps.location.lng(),6);
    delay(2000);
  }
}
