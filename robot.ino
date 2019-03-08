/**
  Remote Control Motor Driver
  
  Set two motor pins based on input from an infrared remote control.
 **/

#include <IRremote.h>

int remoteInputPin = 2;
IRrecv receiver(remoteInputPin);
decode_results results;

int motorRightForward   = 9;
int motorRightReverse   = 10;
int motorLeftForward    = 11;
int motorLeftReverse    = 12;
int headlight = 7;
int reverselight = 8;
int leftlight = 5;
int rightlight = 4;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightReverse, OUTPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftReverse, OUTPUT);
}

void forward() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,HIGH);
  digitalWrite(reverselight,LOW);
  digitalWrite(leftlight,LOW);
  digitalWrite(rightlight,LOW);
}

void reverse() {
  digitalWrite(motorRightForward, LOW);
  analogWrite(motorRightReverse, 140);
  digitalWrite(motorLeftForward, LOW);
  analogWrite(motorLeftReverse, 140);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,HIGH);
  digitalWrite(leftlight,LOW);
  digitalWrite(rightlight,LOW);
}

void left() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, HIGH);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);
  digitalWrite(leftlight,HIGH);
  digitalWrite(rightlight,LOW);
}

void right() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, HIGH);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);
  digitalWrite(leftlight,LOW);
  digitalWrite(rightlight,HIGH);
}

void halt() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, LOW);
  digitalWrite(headlight,LOW);
  digitalWrite(reverselight,LOW);
  digitalWrite(leftlight,LOW);
  digitalWrite(rightlight,LOW);  
}
void dance() {
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  reverse();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  left();
  delay(100);
  right();
  delay(100);
  halt();

}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0xC1AA0DF2) {
      Serial.println("FORWARD");
      forward();
    } else if (results.value == 0xC1AA4DB2) {
      Serial.println("REVERSE");
      reverse();
    } else if (results.value == 0xC1AACD32) {
      Serial.println("LEFT");
      left();
    } else if (results.value == 0xC1AA8D72) {
      Serial.println("RIGHT");
      right();
    } else if (results.value == 0xC1AAA15E) {
      Serial.println("HALT");
      halt();
    } else if (results.value == 0xC1AA09F6) {
      Serial.println("DANCE");
      dance();
    }

    receiver.resume();
  }
}
