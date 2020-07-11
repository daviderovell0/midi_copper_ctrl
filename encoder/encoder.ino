/**
 * Read from the incremental encoder 
 * 
 * @author: daviderovell0
 */
 
//digital pin 2 has a pushbutton attached to it. Give it a name:
int knob1_btn = 23;
int knob1a = 24;
int knob1b = 25;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(knob1_btn, INPUT_PULLUP);
  pinMode(knob1a, INPUT_PULLUP);
  pinMode(knob1b, INPUT_PULLUP);
  int k1s_prev = digitalRead(knob1a);
}

// the loop routine runs over and over again forever:
void loop() {
  int k1s = digitalRead(knob1a);
  if (k1s != k1s_prev) { //edge
    delay(4); //debonuce
    if (k1s == digitalRead(knob1b) {
      Serial.println("anticlockwise rotation\n");
    }
    else {
      Serial.println("clockwise rotation\n");
    }
  }
  // read the input pin:
  int buttonState = digitalRead(knob1_btn);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
}
