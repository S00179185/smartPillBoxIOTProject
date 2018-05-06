char devid[] = "v14E0E372E6849F8";
char devid2[] = "vECFBBB346AF1084";
char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

const int buttonPin = 4;     // the number of the pushbutton pin

const int ledPin =  5;      // the number of the LED pin

const int buzzerPin = 7;   // the number of the buzzer

// variables will change:

int buttonState = 0;         // variable for reading the pushbutton status
const int colorR = 0;
const int colorG = 0;
const int colorB = 50;

void setup() {
    
  pinMode(13, OUTPUT);
  
  digitalWrite(13, LOW);
  
  Bridge.begin();
  
  digitalWrite(13, HIGH);
  
  
  Serial.begin(9600);
  
  while (!Serial); // wait for a serial connection
  
  


  // LED, Buzzer and Button

  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:

  delay(5000);

  pinMode(buttonPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  

  digitalWrite(buzzerPin, HIGH);

    digitalWrite(ledPin, HIGH);
  
// set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    lcd.print("Take Your Pills!");
    
}


void loop() {

       
      // Initialize the client library
  
             HttpClient client;
  
             String APIRequest;
             String APIRequest2;
       
  
     while (client.available()) {
  
         char c = client.read();
    }
  
  // read the state of the pushbutton value:

      buttonState = digitalRead(buttonPin);
  
  // set the cursor to column 0, line 1
      lcd.setCursor(0, 1);
      int time = millis()/1000;


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
 Serial.print(buttonState);
 
  if (buttonState == HIGH) {

    // turn buzzer off:
   

    digitalWrite(buzzerPin, LOW);

    digitalWrite(ledPin, LOW);

    
     
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&TempC="+1;
   client.get (APIRequest); 

   APIRequest2 = String(serverName) + "/pushingbox?devid=" + String(devid2);
   client.get (APIRequest2); 
    
    delay(15000);

  } else {
    
 Serial.print(buttonState);
 
 
    // turn buzzer on:

    digitalWrite(buzzerPin, HIGH);

    digitalWrite(ledPin, HIGH);

    
  
    

  }

}
