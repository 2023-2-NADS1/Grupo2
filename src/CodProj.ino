#define RELAY_PIN 17 // ESP32 pin GPIO17 that connects to relay
#define MOISTURE_PIN 36 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor
#define THRESHOLD 500 // => CHANGE YOUR THRESHOLD HERE

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(MOISTURE_PIN); // read the analog value from soild moisture sensor
  if (value < THRESHOLD) {
    Serial.print("The soil moisture is DRY => activate pump");
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    Serial.print("The soil moisture is WET=> deactivate the pump");
    digitalWrite(RELAY_PIN, LOW);
  }
  Serial.print(" (");
  Serial.print(value);
  Serial.println(")");
  delay(1000);
}



LED

#define LED_PIN 2 // ESP32 pin GPIO2 that connects to LED

unsigned long previousMillis = 0;
const long interval = 600000; // interval at which to blink (milliseconds)

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (digitalRead(LED_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
