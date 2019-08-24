/*
  IR Receiver Demonstration 1
  IR-Rcv-Demo1.ino
  Demonstrates IR codes with IR Receiver
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print Code in HEX
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
}
