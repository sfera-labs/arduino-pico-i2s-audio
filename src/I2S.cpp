/*
  I2S.cpp -
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

#include "I2S.h"
#include "machine_i2s.c"

I2SClass::I2SClass() {
}

bool I2SClass::setSCK(pin_size_t pin) {
  _pin_sck = pin;
  return true;
}

bool I2SClass::setWS(pin_size_t pin) {
  _pin_ws = pin;
  return true;
}

bool I2SClass::setSD(pin_size_t pin) {
  _pin_sd = pin;
  return true;
}

bool I2SClass::setBufferSize(int bufferSize) {
  _bufferSize = bufferSize;
  return true;
}

bool I2SClass::begin(int mode, long sampleRate, int bitsPerSample) {
  format_t i2s_format = (mode == I2S_MODE_STEREO) ? STEREO : MONO;
  machine_i2s_obj_t* i2s0 = machine_i2s_make_new(0, _pin_sck, _pin_ws, _pin_sd,
      RX, bitsPerSample, i2s_format, _bufferSize, sampleRate);
  if (i2s0 == NULL) {
    return false;
  }
  return true;
}

void I2SClass::end() {
  machine_i2s_deinit(machine_i2s_obj[0]);
}

int I2SClass::read(void* buffer, size_t size) {
  return machine_i2s_stream_read(machine_i2s_obj[0], buffer, size);
}
