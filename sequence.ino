int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void clear() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(1000);
  clear();

  digitalWrite(greenPin, HIGH);
  delay(1000);
  clear();

  digitalWrite(bluePin, HIGH);
  delay(1000);
  clear();

  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  delay(1000);
  clear();

  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  delay(1000);
  clear();

  digitalWrite(bluePin, HIGH);
  digitalWrite(redPin, HIGH);
  delay(1000);
  clear();

  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  delay(1000);
  clear();
}
