/**
 * Seven segment driver:
 * Code example to drive a standard 7-segment display (common cathode).
 * 
 * TODO: turn into class (library?) & import in main
 * 
 * Wiring:
 * 
 * 46 47 GND 48 49   
 * |__|___|__|__|
 * |            |
 * |     8.     |
 * |____________|
 * |  |   |  |  |
 * 50 51 GND 52 53
 *
 */
int sevenseg_pins[] = {46,47,48,49,50,51,52,53};

void writeDigit(int number) {
  String binary_word;
  
  switch(number){
    case 0:
      binary_word = "01111110";
      break;
    case 1:
      binary_word = "00010010";
      break;
    case 2:
      binary_word = "10111100";
      break;
    case 3:
      binary_word = "10110110";
      break;
    case 4:
      binary_word = "11010010";
      break;
    case 5:
      binary_word = "11100110";
      break;
    case 6:
      binary_word = "11101110";
      break;
    case 7:
      binary_word = "00110010";
      break;
    case 8:
      binary_word = "11111110";
      break;
    case 9:
      binary_word = "11110110";
      break;
    case -1: //clear
    default:
      binary_word = "00000000";
      break;
  }

  // write out
  for (int i = 0; i < 8; i++){
    if(binary_word[i] == '0') {
      digitalWrite(sevenseg_pins[i], LOW);
    }
    else {
      digitalWrite(sevenseg_pins[i], HIGH);
    }
        
  }
}

// MAIN
void setup() {
  // 7 segment init
  for (int i = 0; i<8; i++) {
    pinMode(sevenseg_pins[i], OUTPUT);
  }
}

void loop() {
  for (int i = -1; i<10; i++) {
    writeDigit(i);
    delay(200);
  }
}
