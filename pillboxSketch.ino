
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

  // initialize the LED pin as an output:

  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:

  pinMode(buttonPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  delay(5000);
// set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    lcd.print("Take Your Pills!");
    
    delay(1000);
}


void loop() {

  // read the state of the pushbutton value:

  buttonState = digitalRead(buttonPin);
// set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    int time = millis()/1000;


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  if (buttonState == HIGH) {

    // turn buzzer on:

    digitalWrite(buzzerPin, LOW);

    digitalWrite(ledPin, LOW);

    delay(10000);

  } else {

    // turn buzzer off:

    digitalWrite(buzzerPin, HIGH);

    digitalWrite(ledPin, HIGH);

  }

}
