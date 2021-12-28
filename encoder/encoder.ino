/**
 * Read from the incremental encoder 
 * 
 * @author: daviderovell0
 */
 
//digital pin 2 has a pushbutton attached to it. Give it a name:
int knob1_btn = 23;
int knob1A = 24;
int knob1B = 25;
int k1s_prev;

void buttonPress() {
  delayMicroseconds(100); //debounce
  Serial.println("button pressed");
}

void knobTurnA() {
  if (digitalRead(knob1A) == digitalRead(knob1B)) {
    Serial.println("anticlockwise rotation");
  }
  else {
    Serial.println("clockwise rotation");
  }
}

void knobTurnB() {
  if (digitalRead(knob1A) != digitalRead(knob1B)) {
    Serial.println("anticlockwise rotation");
  }
  else {
    Serial.println("clockwise rotation");
  }
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initialise pins
  pinMode(knob1_btn, INPUT_PULLUP);
  pinMode(knob1A, INPUT_PULLUP);
  pinMode(knob1B, INPUT_PULLUP);

  // attach interrupts
  attachInterrupt(digitalPinToInterrupt(knob1_btn), buttonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(knob1A), knobTurnA, FALLING);
  attachInterrupt(digitalPinToInterrupt(knob1B), knobTurnB, RISING);
}

// the loop routine runs over and over again forever:
void loop() {
  // interrupts on
}
