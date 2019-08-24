/*
  IR Receiver Demonstration 4
  IR-Rcv-Demo4.ino
  Demonstrates IR codes with Custom Remote and IR Receiver
  Makes use of Repeat function

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Include Arduino Servo Library
#include <Servo.h>

// Define Sensor Pin
const int RECV_PIN = 4;

// Define Servo Pin
const int SERVO_PIN = 6;

// Define Variable for Servo position
// Start at 90 Degrees (Center position)
int pos = 90;

// Define variable to store last code received
unsigned long lastCode;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Create servo object
Servo myservo;

void setup()
{
  // Start the receiver
  irrecv.enableIRIn();

  // Attach the servo
  myservo.attach(SERVO_PIN);

  // Start with Servo in Center
  myservo.write(pos);
}

void loop() {
  if (irrecv.decode(&results)) //this checks to see if a code has been received
  {

    if (results.value == 0xFFFFFFFF)
    {
      // If Repeat then use last code received
      results.value = lastCode;
    }

    if (results.value == 0xFF22DD)
    {
      // Left Button Pressed
      lastCode = results.value;
      // Move left 2 degrees
      pos += 2;
      // Prevent position above 180
      if (pos > 180) {
        pos = 180;
      }
      myservo.write(pos);
    }

    if (results.value == 0xFFC23D)
    {
      // Right Button Pressed
      lastCode = results.value;
      // Move Right 2 degrees
      pos -= 2;
      // Prevent position below 0
      if (pos < 0) {
        pos = 0;
      }
      myservo.write(pos);
    }

    if (results.value == 0xFF02FD)
    {
      // Center Button Pressed
      lastCode = results.value;
      // Move to Center
      pos = 90;
      myservo.write(pos);
    }

    // Add delay to prevent false readings
    delay(30);
    //receive the next value
    irrecv.resume();
  }

}
