###ncmpcpp Arduino Controller
Control the most common functions of ncmpcpp with an Arduino 

####Instructions
This works by flashing a keyboard firmware to an arduino and passing inputs to the arduino (via a button) to the computer via usb as a keyboard input.

Button -> Arduino -> Keyboard Firmware -> USB -> Keyboard Driver -> ncmpcpp


This will only work with certain arduino's.

You will need to aquire the firmware for your arduino. 
My arduino uno has a atmega16u2 chip, the instructions below are written for a atmega8u2 chip with notes added for the variations using the 16u2. 
The firmware includud in this repository should work for both.

I highly recomend following the instructions here: http://mitchtech.net/arduino-usb-hid-keyboard/
Afterwards upload the sketch in this repository instead.
Those instructions as well as my notes are written for linux users.

My notes on getting things running:
- The instructions say to use "sudo apt-get install dfu-programmer dfu-util" to install dfu-programmer. I found that (at the time of doing this myself) the version of dfu-programmer that has added support for the atmega16u2 had not yet trickled down into the repos and I had to aquire a more recent version from the projects sourceforge: http://sourceforge.net/projects/dfu-programmer/files/dfu-programmer/
- I had to install libusb-dev to get things working
- You can use 'lusb' to determine what mode the arduino is currently in:
    - "Atmel Corp. LUFA Keyboard Demo Application": Functioning as a keyboard over usb.
    - "Atmel Corp.": Reset and ready to be flashed.
    - "Arduino SA Uno (CDC ACM)": Running stock arduino firmware to upload sketches.
- The scripts included in this repo for flashing the firmwares are for use with the included firmwares. They can be easily modified by just changing the firmware file name.

Some Helpfull Links:
- Flashing the firmware: http://arduino.cc/en/Hacking/DFUProgramming8U2
- Simmilar instructions for the atmega16u2: http://cjdavies.org/?tag=dfu-programmer
- Keyboard key codes: www.usb.org/developers/hidpage/Hut1_12v2.pdf (page 53)
