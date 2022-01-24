# escendoMake

# ESCENDO 2022 Makeathon ::
## 3RD place.

> WARNING: Very, very messy code (crunch for the Makeathon), best to not refer from this repo. 


![IMG_A0F2480BCEDA-1](https://user-images.githubusercontent.com/38891057/150741769-9559c910-c854-4413-a671-0db8986039a9.jpeg)

A 3-day makeathon revolving around the theme: Smart Nation.

Vacant is a smart tray system that allows users to see if tables are occupied. 

This project makes use of:
- Arduino
- ESP8266
- Firebase
- Node.js and Material Design Bootstrap

Using an Arduino with an RFID sensor, it detects for a RFID tag, and communicates directly with Firebase through the ESP8266 to update the state of a "table". The web-app then listens for changes to the Firebase Realtime Database and makes appropriate changes to the UI.

To start:
```
- Compile and upload the sketch to an Arduino.
- Set your Firebase keys in the sketch.
- Set the same keys in the HTML.

And you should be good to go. ;)
```
