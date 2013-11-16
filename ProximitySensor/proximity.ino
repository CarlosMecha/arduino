#define PIN_ANALOG 1
#define PIN_LED 13
#define BLINK_MS 50

int value = 0;

void proximity();

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  proximity();
}

void proximity() {
  value = analogRead(PIN_ANALOG);
  if (value < 900) {
    digitalWrite(PIN_LED, HIGH); 
  } else {
    digitalWrite(PIN_LED, LOW);
  }
  delay(BLINK_MS);
}
