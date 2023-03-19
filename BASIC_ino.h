
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

// ------------------ ARDUINO ----------------------

// Serial

#define _SERIAL_BEGIN(...) Serial.begin(__VA_ARGS__);
#define SERIAL_BEGIN _SERIAL_BEGIN(

#define _SERIAL_END(...) Serial.end(__VA_ARGS__);
#define SERIAL_END _SERIAL_END(

// SPI

#define _SPI_BEGIN(...) SPI.begin(__VA_ARGS__);
#define SPI_BEGIN _SPI_BEGIN(

#define _SPI_END(...) SPI.end(__VA_ARGS__);
#define SPI_END _SPI_END(

// Wire

#define _WIRE_BEGIN(...) Wire.begin(__VA_ARGS__);
#define WIRE_BEGIN _WIRE_BEGIN(

#define _WIRE_END(...) Wire.end(__VA_ARGS__);
#define WIRE_END _WIRE_END(

// USB

#define _KEYBRD_BEGIN(...) Keyboard.begin(__VA_ARGS__);
#define KEYBRD_BEGIN _KEYBRD_BEGIN(

#define _KEYBRD_END(...) Keyboard.end(__VA_ARGS__);
#define KEYBRD_END _KEYBRD_END(

#define _MOUSE_BEGIN(...) Mouse.begin(__VA_ARGS__);
#define MOUSE_BEGIN _MOUSE_BEGIN(

#define _MOUSE_END(...) Mouse.end(__VA_ARGS__);
#define MOUSE_END _MOUSE_END(

// Digital I/O

#define _DREAD(val, pin) val = digitalRead(pin);
#define DREAD _DREAD(

#define _DWRITE(pin, val) digitalWrite(pin, val);
#define DWRITE _DWRITE(

#define _PINMODE(pin, mode) pinMode(pin, mode);
#define PINMODE _PINMODE(

// Analog I/O 

#define _AREAD(val, pin) val = analogRead(pin);
#define AREAD _AREAD(

#define _AREF(...) analogReference(__VA_ARGS__);
#define AREF _AREF(

#define _AWRITE(pin, v) analogWrite(pin, val);
#define AWRITE _AWRITE(

// Zero, Due & MKR Family

#define _AREAD_RESO(bits) analogReadResolution(bits);
#define AREAD_RESO _AREAD_RESO(

#define _AWRITE_RESO(bits) analogWriteResolution(bits);
#define AWRITE_RESO _AWRITE_RESO(

// Advanced I/O

#define _NOTONE(pin) noTone(pin);
#define NOTONE _NOTONE(

#define _PULSEIN(dur, ...) dur = pulseIn(__VA_ARGS__);
#define PULSEIN _PULSEIN(

#define _PULSEIN_LONG(dur, ...) dur = pulseInLong(__VA_ARGS__);
#define PULSEIN_LONG _PULSEIN_LONG(

#define _SHIFTIN(incoming, dataPin, clockPin, bitOrder) incoming = shiftIn(dataPin, clockPin, bitOrder);
#define SHIFTIN _SHIFTIN(

#define _SHIFTOUT(dataPin, clockPin, bitOrder, value) shiftOut(dataPin, clockPin, bitOrder, value);
#define SHIFTOUT _SHIFTOUT(

#define _TONE(...) tone(__VA_ARGS__);
#define TONE _TONE(

// Time

#define _DELAY(ms) delay(ms);
#define DELAY _DELAY(

#define _DELAY_MICROS(us) delayMicroseconds(us);
#define DELAY_MICROS _DELAY_MICROS(

#define _MICROS(t) t = micros();
#define MICROS _MICROS(

#define _MILLIS(t) t = millis();
#define MILLIS _MILLIS(

// External Interrupts

#define _ATTACH_INTR(pin, ISR, mode) attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
#define ATTACH_INTR _ATTACH_INTR(

#define _DETACH_INTR(pin) detachInterrupt(digitalPinToInterrupt(pin));
#define DETACH_INTR _DETACH_INTR(

// Interrupts

#define INTR() interrupts();
#define INTR _INTR(

#define _NOINTR() noInterrupts();
#define NOINTR _NOINTR(
