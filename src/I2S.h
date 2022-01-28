/*
  I2S.h -
    I2S digital audio input Arduino library for the Raspberry Pi Pico RP2040

    Copyright (C) 2022 Sfera Labs S.r.l. - All rights reserved.

    For information, see:
    http://www.sferalabs.cc/

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef I2S_h
#define I2S_h

#include <Arduino.h>

#define I2S_MODE_MONO 0
#define I2S_MODE_STEREO 1

class I2SClass {
  public:
    I2SClass();

    bool setSCK(pin_size_t pin);
    bool setWS(pin_size_t pin);
    bool setSD(pin_size_t pin);
    bool setBufferSize(int bufferSize);
    bool begin(int mode, long sampleRate, int bitsPerSample);
    void end();
    int read(void* buffer, size_t size);

  private:
    pin_size_t _pin_sck;
    pin_size_t _pin_ws;
    pin_size_t _pin_sd;
    int32_t _bufferSize;

};

#endif
