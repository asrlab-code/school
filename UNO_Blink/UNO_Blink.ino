#define DELAY_TIME 250

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY_TIME);

  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  //delay(DELAY_TIME);
}