#include <SoftwareSerial.h>
#include <TinyGPS++.h>

int kmph = 0;
int hour = 0;
int min = 0;
int sat = 0;
int GPS = 0;

SoftwareSerial ss(3, 2);
TinyGPSPlus gps;

void setup() { 
  Serial.begin(9600);
  ss.begin(9600);
}

void loop() {

        while (ss.available() > 0)
          gps.encode(ss.read());

        if (gps.location.isUpdated())
        {
          kmph  = (gps.speed.kmph());
          hour  = ((gps.time.hour()) + 2);
          min   = (gps.time.minute());
          sat   = (gps.satellites.value());
          
          Serial.print("t0.txt=");
          Serial.print("\""); Serial.print(kmph); Serial.print("\"");
          Serial.write(0xff);      Serial.write(0xff);      Serial.write(0xff);

          Serial.print("t1.txt=");
          Serial.print("\""); Serial.print(hour); Serial.print("\"");
          Serial.write(0xff);      Serial.write(0xff);      Serial.write(0xff);
        
          Serial.print("t2.txt=");
          Serial.print("\""); Serial.print(min); Serial.print("\"");
          Serial.write(0xff);      Serial.write(0xff);      Serial.write(0xff);

          Serial.print("t3.txt=");
          Serial.print("\""); Serial.print(sat); Serial.print("\"");
          Serial.write(0xff);      Serial.write(0xff);      Serial.write(0xff);
        }
    delay(10);
}
