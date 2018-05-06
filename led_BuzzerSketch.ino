const int buttonPin = 2;     // the number of the pushbutton pin

const int ledPin =  4;      // the number of the LED pin

const int buzzerPin = 3;   // the number of the buzzer

// variables will change:

int buttonState = 0;         // variable for reading the pushbutton status


void setup() {

  // initialize the LED pin as an output:

  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:

  pinMode(buttonPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  delay(7000);

}


void loop() {

  // read the state of the pushbutton value:

  buttonState = digitalRead(buttonPin);



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
