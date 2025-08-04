/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_VAL 0

#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
    #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 9

#undef  COCOT_CPI_DEFAULT
#define COCOT_CPI_DEFAULT 2

#undef COCOT_CPI_OPTIONS
#define COCOT_CPI_OPTIONS { 250, 500, 750, 1000, 1625 }

#undef  COCOT_ROTATION_DEFAULT
#define COCOT_ROTATION_DEFAULT 4

#define COCOT_SENSITIVITY 2.0
#define COCOT_SENSITIVITY_MULTIPLIER 3.0
#define COCOT_SMOOTHING_FACTOR 0.7
