//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <FirebaseArduino.h>

// Wifi Credentials.
#define WIFI_SSID "poopstickle"
#define WIFI_PASSWORD "abcd1234"
//Firebase Credentials
#define FIREBASE_HOST "escendotwo-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Acn3iTOoSJU3SKn3B4fMX6CAobFmke2QmX1UMAQT"

//Offset for Singapore Timing
const long utcOffsetInSeconds = 28800;

//Define NTP Client and UDP protocol
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String values,sensor_data;
int value1;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  //Starting of NTP Server Communication
  timeClient.begin();

  //Starting of Firebase Server communication
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}


void loop() {
   bool Sr =false;
  while(Serial.available()){
       //get sensor data from serial
       sensor_data=Serial.readString(); 
       Serial.print("Data Available");
       Sr=true;    
   }
   delay(1000);

  if(Sr==true){

  values=sensor_data;
  
  timeClient.update();
  //Elapsed Seconds since 1970 Jan 1
  unsigned long epochTime = timeClient.getEpochTime();
  
  struct tm *ptm = gmtime ((time_t *)&epochTime);

  //calculate Year,month and Day
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  int currentYear = ptm->tm_year+1900;
  //Serial.print(values);
   //String manipulation before sending off to firebase
  String timestamp = String(currentYear)+","+String(currentMonth)+","+String(monthDay)+","+String(timeClient.getHours())+","+String(timeClient.getMinutes())+","+String(timeClient.getSeconds());
  value1= values.toInt();
  //Firebase directory to store in
  Firebase.setString("/vacant/one/timestamp",timestamp);
  Firebase.setInt("/vacant/one/status",value1);


  // handle error
  if (Firebase.failed()) {
      //Serial.print("settin1111g /number failed:");
      //Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  }
  
}
