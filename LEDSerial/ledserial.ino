
#define LEDPIN 3

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(LEDPIN, OUTPUT); 

}

void loop() {

  static unsigned int value = LOW;
  static unsigned int status = LOW;

  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // Not time for checkers!
    value = (Serial.parseInt() == 0) ? LOW : HIGH; 

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {

      if (value != status) {
        status = (status == LOW) ? HIGH : LOW;
        digitalWrite(LEDPIN, status);
      }

    }
  }
}

