#!/bin/bash

avrdude -p atmega32u4 -c avr109 \
  -P /dev/cu.usbmodematreus1 \
  -U flash:w:keyboardio_atreus_wintermute_v2.hex
