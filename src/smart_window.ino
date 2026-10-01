/****************************************************
 Smart Window Automation System
 ESP32 + Blynk + DHT11 + MQ135 + Servo + IR Remote
****************************************************/

#define BLYNK_PRINT Serial

// ----------- BLYNK DETAILS -----------
#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Window System"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

// ----------- LIBRARIES ---------------
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <ESP32Servo.h>
#include <IRremote.h>

// ----------- WIFI --------------------
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// ----------- PIN DEFINITIONS ----------
#define DHTPIN     4
#define DHTTYPE    DHT11
#define MQ135_PIN  34
#define SERVO_PIN  18
#define IR_PIN     15

// ----------- OBJECTS -----------------
DHT dht(DHTPIN, DHTTYPE);
Servo windowServo;

// ----------- VARIABLES ---------------
bool autoMode = true;
int temperatureLimit = 30;
int airQualityLimit = 600;

// ----------- BLYNK CONTROLS -----------

// OPEN BUTTON (V0)
BLYNK_WRITE(V0) {
  if (!autoMode && param.asInt() == 1) {
    Serial.println("APP: Window OPEN");
    windowServo.write(90);
  }
}

// CLOSE BUTTON (V1)
BLYNK_WRITE(V1) {
  if (!autoMode && param.asInt() == 1) {
    Serial.println("APP: Window CLOSE");
    windowServo.write(0);
  }
}

// AUTO MODE SWITCH (V3)
BLYNK_WRITE(V3) {
  autoMode = param.asInt();

  if (autoMode) {
    Serial.println("MODE: AUTO");
  } else {
    Serial.println("MODE: MANUAL");
  }
}

// ----------- SETUP --------------------
void setup() {

  Serial.begin(9600);
  delay(1000);

  Serial.println("\n==============================");
  Serial.println("SMART WINDOW SYSTEM STARTED");
  Serial.println("==============================");

  // Servo
  windowServo.attach(SERVO_PIN);
  windowServo.write(0);

  // Sensors
  dht.begin();

  // IR Receiver
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Ready");

  // WiFi
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  int wifiTimeout = 0;

  while (WiFi.status() != WL_CONNECTED && wifiTimeout < 20) {
    delay(500);
    Serial.print(".");
    wifiTimeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi CONNECTED!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi FAILED!");
    return;
  }

  // Blynk
  Serial.println("Connecting to Blynk...");
  Blynk.config(BLYNK_AUTH_TOKEN);

  if (Blynk.connect()) {
    Serial.println("Blynk CONNECTED!");
  } else {
    Serial.println("Blynk NOT connected!");
  }
}

// ----------- LOOP ---------------------
void loop() {

  Blynk.run();

  // ----- READ SENSORS -----
  float temperature = dht.readTemperature();
  int airQuality = analogRead(MQ135_PIN);

  if (isnan(temperature)) {
    Serial.println("DHT11 ERROR");
    delay(2000);
    return;
  }

  // Send sensor values to Blynk
  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V4, airQuality);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Air: ");
  Serial.println(airQuality);

  // ----- AUTO MODE -----
  if (autoMode) {

    if (temperature >= temperatureLimit ||
        airQuality >= airQualityLimit) {

      Serial.println("AUTO: OPEN");
      windowServo.write(90);

    } else {

      Serial.println("AUTO: CLOSE");
      windowServo.write(0);
    }
  }

  // ----- IR REMOTE -----
  if (IrReceiver.decode()) {

    int command = IrReceiver.decodedIRData.command;

    Serial.print("IR: ");
    Serial.println(command);

    // OPEN
    if (command == 90) {
      Serial.println("IR: OPEN");
      windowServo.write(90);
      autoMode = false;
    }

    // CLOSE
    if (command == 8) {
      Serial.println("IR: CLOSE");
      windowServo.write(0);
      autoMode = false;
    }

    IrReceiver.resume();
  }

  delay(2000);
}
