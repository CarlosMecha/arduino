#define PIN_7SEG_1 2
#define PIN_7SEG_2 3
#define PIN_7SEG_3 4
#define PIN_7SEG_4 5
#define PIN_7SEG_5 6
#define PIN_7SEG_6 7
#define PIN_7SEG_7 8
#define PIN_7SEG_8 9
#define PIN_LED 13
#define BLINK_MS 1000

void blink();

void setup() {
  pinMode(PIN_7SEG_1, OUTPUT);
  pinMode(PIN_7SEG_2, OUTPUT);
  pinMode(PIN_7SEG_3, OUTPUT);
  pinMode(PIN_7SEG_4, OUTPUT);
  pinMode(PIN_7SEG_5, OUTPUT);
  pinMode(PIN_7SEG_6, OUTPUT);
  pinMode(PIN_7SEG_7, OUTPUT);
  pinMode(PIN_7SEG_8, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  blink();
}

void blink() {
  static unsigned int currentIndex = 0;
  static unsigned int lastIndex = currentIndex;
  static unsigned int pins[] = {PIN_LED, PIN_7SEG_1, PIN_7SEG_2, PIN_7SEG_3, PIN_7SEG_4, PIN_7SEG_5, PIN_7SEG_6, PIN_7SEG_7, PIN_7SEG_8};
 
  digitalWrite(pins[lastIndex], LOW);
  digitalWrite(pins[currentIndex], HIGH);

  lastIndex = currentIndex;
  currentIndex = (++currentIndex) % 9;
  
  delay(BLINK_MS);

}
