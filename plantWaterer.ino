#include <Arduino.h>

#define SENSOR_PIN 12
#define RELAY_PIN 13

void pumpOn();
void pumpOff();

const int DryThreshold = 0;
const int WetThreshold = 4095;

const int PumpTrigger = 2500;

int soilMoistureValue = 0;

int moisturePercentage = 0;

void setup() {
  Serial.begin(115200);

  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  soilMoistureValue = analogRead(SENSOR_PIN);

  Serial.println(soilMoistureValue);

  if(soilMoistureValue >= PumpTrigger) {
    pumpOn();
    delay(5000);
    pumpOff();
    delay(5000);
  }

}

void pumpOn() {
  digitalWrite(RELAY_PIN, LOW);
}

void pumpOff() {
  digitalWrite(RELAY_PIN, HIGH);
}
