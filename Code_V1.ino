/* Hi,
 * This is my code. (I know that it is not the best)
 */

// including librarys:
#include "HID-Project.h"
// defining Input Pins:
#define CLK 4 // Rotary encoder side A
#define DT 3  // Rotary encoder side B
#define SW 2  // Button Pin
// defining output pins / Leds:
#define L1 5  // Led 1
// we also need some variables:
 int currStateCLK;
 int prevStateCLK;
 int incvol;  // increase volume
 int decvol;  // decrease volume
 int plps;    // Play Pause variable (Button is pressed)
 int bttncycle = 1;
void setup() {
  Serial.begin(9600);
  //defining I/O:
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  pinMode(L1, OUTPUT);

  //send clean hid report to host
  Consumer.begin();

  //set prevStateCLK to CLK
  prevStateCLK = digitalRead(CLK);
}

void loop() {
  // Read encoder

 //Read current state of CLK
 currStateCLK = digitalRead(CLK);
 //if current state != Previous state: Pulse has occured
 if (currStateCLK != prevStateCLK){
  //if DT != CLK counterclockwise
  if (digitalRead(DT) != currStateCLK) {
    incvol ++;
  }else{ // else it is clockwise
    decvol ++;
  }
  //Update Prev clk to current CLK
  prevStateCLK = currStateCLK;
 }
  
  // Read Button
if (digitalRead(SW) == LOW){
  delay(10);
  if (digitalRead(SW) == HIGH){
    plps ++; 
  }
}


  // Set media control an set variables to 0

 // bttncycle is useless must be removed in the future

  if (bttncycle == 1){
    if(plps == 1){
Consumer.write(MEDIA_PLAY_PAUSE);
  } else if(plps >= 1){
    Consumer.write(MEDIA_NEXT);
  }
  plps = 0;
 // bttncycle = 0;
  } else {
    
  
  //bttncycle ++;
  }
if (incvol == 2){
Consumer.write(MEDIA_VOL_UP);
  incvol = 0;
}
if (decvol == 2){
Consumer.write(MEDIA_VOL_DOWN);
  decvol = 0;
}
delay(1);
}
