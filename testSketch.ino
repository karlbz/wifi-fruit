#include <ESP8266WiFi.h>

class TestSketch {
    public:
        const char *ssid = "Some_Id";
        const char *password = "Some_Key";

    void WifiConnect() {
        Serial.println();
        Serial.print("Setting soft-AP ... ");
        boolean result = WiFi.softAP(ssid, password);
        if(result == true) {
            Serial.println("Ready");
        } else {
            Serial.println("Failed!");
        }
    }

    void WifiConnectStrings() {
        Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
        delay(3000);
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second
    }
};

TestSketch wifi;

void setup() {
    wifi.WifiConnect();
}

void loop() {
    wifi.WifiConnectStrings();
}
