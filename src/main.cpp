#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  digitalWrite(13, HIGH);
}

// yay
void loop() {
  if(Serial.available() > 0) {
    char data = Serial.read();
    if(data == 'a') {
      digitalWrite(13, LOW);
    }
    Serial.print(data);
  }
}