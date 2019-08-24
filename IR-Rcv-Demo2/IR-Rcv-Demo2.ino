/*
  IR Receiver Demonstration 2
  IR-Rcv-Demo2.ino
  Determine IR codes manufacturer type with IR Receiver
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
    Serial.println(results.value, HEX);
    switch (results.decode_type) {
      case NEC:
        Serial.println("NEC");
        break;
      case SONY:
        Serial.println("SONY");
        break;
      case RC5:
        Serial.println("RC5");
        break;
      case RC6:
        Serial.println("RC6");
        break;
      case DISH:
        Serial.println("DISH");
        break;
      case SHARP:
        Serial.println("SHARP");
        break;
      case JVC:
        Serial.println("JVC");
        break;
      case SANYO:
        Serial.println("SANYO");
        break;
      case MITSUBISHI:
        Serial.println("MITSUBISHI");
        break;
      case SAMSUNG:
        Serial.println("SAMSUNG");
        break;
      case LG:
        Serial.println("LG");
        break;
      case WHYNTER:
        Serial.println("WHYNTER");
        break;
      case AIWA_RC_T501:
        Serial.println("AIWA_RC_T501");
        break;
      case PANASONIC:
        Serial.println("PANASONIC");
        break;
      case DENON:
        Serial.println("DENON");
        break;
      default:
      case UNKNOWN:
        Serial.println("UNKNOWN");
        break;
    }
    irrecv.resume();
  }
}
