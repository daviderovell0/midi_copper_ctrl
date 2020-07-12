/**
 * Read from the incremental encoder 
 * 
 * @author: daviderovell0
 */
 
//digital pin 2 has a pushbutton attached to it. Give it a name:
int knob1_btn = 23;
int knob1a = 24;
int knob1b = 25;
int k1s_prev;

void buttonPress() {
  delayMicroseconds(100); //debounce
  Serial.println("button pressed");
}

void knobTurn() {
  if (digitalRead(knob1a) == digitalRead(knob1b)) {
    Serial.println("anticlockwise rotation");
  }
  else {
    Serial.println("clockwise rotation");
  }
  
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(knob1_btn, INPUT_PULLUP);
  pinMode(knob1a, INPUT_PULLUP);
  pinMode(knob1b, INPUT_PULLUP);

  // attach interrupts
  attachInterrupt(digitalPinToInterrupt(knob1_btn), buttonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(knob1a), knobTurn, CHANGE);
}

// the loop routine runs over and over again forever:
void loop() {
  
}
