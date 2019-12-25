/* -*- mode: c++ -*-
 * Kaleidoscope-LED-ChristmasLights
 * Copyright (C) 2019 Andrew vonderLuft
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope-LED-ChristmasLights.h>

namespace kaleidoscope { namespace plugin {

uint16_t LEDChristmasLights::blink_delay = 500;

// map native keyboard coordinates (16x4) into geometric space (14x5)
PROGMEM const uint8_t LEDChristmasLights::rc2pos[ROWS*COLS] = {
     0,  1,  2,  3,  4,  5,  6,    59, 66,    7,  8,  9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 34,    60, 65,   35, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 32, 33, 48,    61, 64,   49, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47,     58,62, 63,67,    50, 51, 52, 53, 54, 55,
};

void LEDChristmasLights::update(void) {
  
  constexpr cRGB white = CRGB(211, 211, 211);
  
  // limit the blink rate
  static uint8_t prev_time = 0;
  uint8_t now = Kaleidoscope.millisAtCycleStart() / blink_delay;
  if (now != prev_time) {
    prev_time = now;
  } else {
    if (now % 2 == 0) {
      int randRow = rand() % 5;
      int randCol = rand() % 14;
      ::LEDControl.setCrgbAt(randRow, randCol, white);
    }
    return;
  }
  
  constexpr cRGB red = CRGB(221, 0, 0);
  constexpr cRGB blue = CRGB(0, 0, 221);
  constexpr cRGB green = CRGB(0, 221, 0);
  constexpr cRGB yellow = CRGB(201, 201, 0);
  
  for (byte r = 0; r < ROWS; r++) {
    for (byte c = 0; c < COLS; c++) {
      uint8_t offset = (r*COLS) + c;
      uint8_t key = pgm_read_byte(rc2pos+offset);
      cRGB colors[4] = {red, blue, green, yellow};
      int RandIndex = rand() % 4;
      ::LEDControl.setCrgbAt(r, c, colors[RandIndex]);
    }
  }
}

} }

kaleidoscope::plugin::LEDChristmasLights LEDChristmasLights;
