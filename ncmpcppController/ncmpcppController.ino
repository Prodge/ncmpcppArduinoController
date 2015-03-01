/* 
    NCMPCPP Controller by Prodge. 
    
    Allows you to control all of the core functions of ncmpcpp from an arduino.
    
      Notes:
        - You will have to upload this sketch as stock firmware and then flash the keyboard firmware with dfu-programmer
        - In order for next/prev track to work, you will have to assign h (next) and H (prev) to those functions in your ~/.ncmpcpp/keys file
    
    Original Sample from: http://mitchtech.net/arduino-usb-hid-keyboard/
    USB HID Documentation (page 53): http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
*/
 
uint8_t buf[8] = { 0 }; /* Keyboard report buffer */

#define ACTIONS 16
#define ACTION_LENGTH 10

#define CAPS 57
#define P 19
#define NEXT 11
#define PREV 11
#define VOL_UP 128
#define VOL_DOWN 129
#define MUTE 127
#define UP 82
#define DOWN 81
#define LEFT 80
#define RIGHT 79
#define PAGE_UP 75
#define PAGE_DOWN 78
#define U 24
#define SPACE 44
#define ENTER 40
#define TAB 43

uint8_t action[ACTIONS][ACTION_LENGTH] = { //ACTIONS different actions of max length ACTION_LENGTH
 {CAPS, P, CAPS, 0}, //0 indicates the end of the sequence
 {NEXT, 0},
 {CAPS, PREV, CAPS, 0},
 {VOL_UP, 0},
 {VOL_DOWN, 0},
 {MUTE, 0},
 {UP, 0},
 {DOWN, 0},
 {LEFT, 0},
 {RIGHT, 0},
 {PAGE_UP, 0},
 {PAGE_DOWN, 0},
 {U, 0},
 {TAB, 0},
 {SPACE, 0},
 {ENTER, 0}
};
 
//The pins to be used, in the corresponding order to the actions above.
int pin[ACTIONS] = {2,3,4,5,6,7,8,9,10,11,12,A0,A1,A2,A3,A4};

void setup()
{
  Serial.begin(9600);
  
  for(int i=0; i<=ACTIONS; i++){
    pinMode(pin[i], INPUT);
    digitalWrite(pin[i], 1);
  }
  
  delay(100);
}
 
 
void loop()
{
  for(int i=0; i<=ACTIONS; i++){
    if (digitalRead(pin[i]) != 1) {
      int x = 0;
      while(action[i][x] != 0){
        buf[2] = action[i][x];
        Serial.write(buf, 8); // Send keypress
        buf[0] = 0;
        buf[2] = 0;
        Serial.write(buf, 8); // Release key
        delay(20);
        x++;
      }
      delay(200);
    }
  }
}

