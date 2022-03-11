/*-
 * This example demonstrates how to read analog signals.
 *
 * It assumes there are potentiometers connected to the 16 channels of the
 * 74HC4067 mux.22
 * 
 * ------------------------------------------------------------
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include <Arduino.h>
#include "Mux.h"

using namespace admux;

/*
 * Creates a Mux instance.
 *
 * 1st argument is the SIG (signal) pin
 * 2nd argument is the S0-S3 (channel control) pins
 */

Mux muxOne(Pin(A0, INPUT, PinType::Analog), Pinset(8, 9, 10, 11));
Mux muxTwo(Pin(A0, INPUT, PinType::Analog), Pinset(8, 9, 10, 11));
Mux muxTwo(Pin(A0, INPUT, PinType::Analog), Pinset(8, 9, 10, 11));

void setup() {
  // Serial port initialization.
  Serial.begin(115200); 
  while (!Serial) /* Waits for serial port to connect (needed for Leonardo only) */;
}

/**
 * Reads the 16 channels and reports on the serial monitor the corresponding
 * value read by the A/D converter.
 */
void loop() {
  int data;
  for (byte i = 0; i < muxOne.channelCount(); i++) {
    data = muxOne.read(i) /* Reads from channel i (returns a value from 0 to 1023) */;

    Serial.print("Potentiometer at channel "); Serial.print(i); Serial.print(" is at "); Serial.print((double) (data) * 100 / 1023); Serial.println("%%");
  }
  Serial.println();

  delay(1500);
}
