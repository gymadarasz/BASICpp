
#pragma once

#include "BASIC_min.h"

// ---------------------- BASIC Ardino -------------------------
// This header file is based on the BASIC.h but for Arduino

void BASIC_print(double x) {
  if((long)x == x) {
    Serial.print((long)x);
  } else {
    Serial.print(x);
  }
}

void BASIC_print(String x) {
    Serial.print(x);
}

void BASIC_print_all() {}

template<typename T>
void BASIC_print_all(T arg) {
  BASIC_print(arg);
}

template<typename T, typename... Args>
void BASIC_print_all(T first, Args... args) {
  BASIC_print(first);
  BASIC_print_all(args...);
}

void BASIC_input(String& inp, const String& prompt = "") {
  BASIC_print(prompt);
  while (Serial.available() == 0) { // wait for input
    delay(100);
  }
  inp = Serial.readStringUntil('\n');
  inp.trim(); // remove leading/trailing whitespace
}

void BASIC_input(int& inp, String prompt = "") {
    Serial.print(prompt);
    while (Serial.available() == 0); // Wait for input to be available
    inp = Serial.parseInt();
    while (Serial.available() > 0) Serial.read(); // Clear input buffer to remove any newline characters
}


void BASIC_input(double& inp, String prompt = "") {
  Serial.print(prompt);
  while (Serial.available() == 0) { // Wait for input
    delay(10);
  }
  while (Serial.available() > 0) { // Read input and discard any extra characters
    char c = Serial.read();
    if (isdigit(c) || c == '.' || c == '-') { // Allow digits, decimal point, and negative sign
      String numStr = String(c);
      while (Serial.available() > 0) { // Read remaining digits
        c = Serial.read();
        if (isdigit(c) || c == '.') {
          numStr += c;
        } else {
          break;
        }
      }
      inp = numStr.toDouble();
      break;
    }
  }
  Serial.println(inp);
  while (Serial.available() > 0) { // Discard any extra characters
    Serial.read();
  }
}


#define _PRINT(...) { \
    BASIC_print_all(__VA_ARGS__); \
    BASIC_print("\n"); \
    fflush(stdout); \
}

#define PRINT _PRINT(
#define PRINTL PRINT ""

#define _INPUT(...) BASIC_input(__VA_ARGS__);
#define INPUT _INPUT(

#define _PROMPT(...) { \
    BASIC_print_all(__VA_ARGS__); \
    fflush(stdout); \
}
#define PROMPT _PROMPT(

// ------------------- LIB (platfor specific) ---------------------

#define _EXIT(...) while(true);
#define EXIT _EXIT(

