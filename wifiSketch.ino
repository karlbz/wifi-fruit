#include <ESP8266WiFi.h>

const char *ssid = "testNet_01";
const char *key = "test1212";

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println();
  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP(ssid, key);
  if(result == true) {
    Serial.println("Ready");
  } else {
    Serial.println("Failed!");
  }
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
