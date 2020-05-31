
#include "morse.h"

// assign a pointer for the letters represented in morse code (A,B,C,...,Z)
char* letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
// assign a pointer for the numbers represented in morsecode (0,1,2,...9)
char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

Morse::Morse(int pin, boolean output) {
  _pin = pin;
  _output = output;
  pinMode(_pin, OUTPUT);
}


Morse::~Morse() {

}
void Morse::encodeTest(char* text) {
  char* morse_code;
  if (text != NULL && strlen(text) > 0) {
    for (int i = 0; i < strlen(text); i++) {
      morse_code = NULL;
      char t = text[i];
      if (t >= 48 && t <= 57) { // number
        morse_code = numbers[(int)t - 48];
      } else if (t >= 65 && t <= 90) {
        morse_code = letters[(int)t - 65];
      } else if (t >= 97 && t <= 122) {
        morse_code = letters[(int)t - 97];
      }
      if (morse_code != NULL) {
        genSingleMorseCode(morse_code);
      }
      pause();
    }
  }
}

void Morse::dot()
{
  if (_output == true) {
    Serial.print(".");
  }
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void Morse::dash()
{
  if (_output == true) {
    Serial.print("-");
  }
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

void Morse:: pause() {
  if (_output == true) {
    Serial.print(" ");
  }
  delay(250);
}

void Morse::genSingleMorseCode(char* code) {
  for (int i = 0; i < strlen(code); i++) {
    if (code[i] == '.') {
      dot();
    } else {
      dash();
    }
  }
}
