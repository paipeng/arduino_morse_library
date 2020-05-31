#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>

class Morse {
public:  
  Morse(int pin);
  ~Morse();
public:
  void encodeTest(char* text);  

private:
  void dot();
  void dash();
  void genSingleMorseCode(char* code);
private:
  int _pin;
};

#endif
