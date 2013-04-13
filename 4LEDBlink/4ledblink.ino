#define LEDBLINK_PIN    13    // I/O pin connected to the LED.
#define LEDBLINK_RED    2
#define LEDBLINK_YELLOW    4
#define LEDBLINK_GREEN    3
#define LEDBLINK_MS     1000  // Blink rate (in milliseconds).

void ledBlink();

void setup() {
  // For ledBlink(), set LEDBLINK_PIN to output.
  pinMode(LEDBLINK_PIN, OUTPUT);
  pinMode(LEDBLINK_RED, OUTPUT);
  pinMode(LEDBLINK_YELLOW, OUTPUT);
  pinMode(LEDBLINK_GREEN, OUTPUT);
}

void loop() {
  // Blink the LED to let the user know we are still alive.
  ledBlink();

  // Do something.
}

//
// LED Heartbeat routine by Allen C. Huffman (www.appleause.com)
//
void ledBlink() {
  static unsigned int currentLedIndex = 0;  // Last set LED mode.
  static unsigned int lastLedIndex = 0;  // Last set LED mode.
  static unsigned long ledBlinkTime = 0;
  static unsigned int leds[] = {LEDBLINK_PIN, LEDBLINK_RED, LEDBLINK_YELLOW, LEDBLINK_GREEN};

  if ( (long)(millis()-ledBlinkTime) >= 0 ) {
    
    digitalWrite(leds[lastLedIndex], LOW);
    digitalWrite(leds[currentLedIndex], HIGH);
    
    lastLedIndex = currentLedIndex;
    currentLedIndex = (++currentLedIndex) % 4;
    
    // Reset "next time to toggle" time.
    ledBlinkTime = millis()+LEDBLINK_MS;

  }
}
