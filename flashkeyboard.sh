#!/bin/bash
dfu-programmer atmega16u2 erase --force
dfu-programmer atmega16u2 flash --debug 1 Arduino-keyboard-0.3.hex
dfu-programmer atmega16u2 reset
exit 0
