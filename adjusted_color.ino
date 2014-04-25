int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redInput = A0;
int greenInput = A1;
int blueInput = A2;

int redMax = 255;
int greenMax = 140;
int blueMax = 40;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setAdjustedColor(int redValue, int greenValue, int blueValue) {
  setColor(map(redValue, 0, 255, 0, redMax),
           map(greenValue, 0, 255, 0, greenMax),
           map(blueValue, 0, 255, 0, blueMax));
}

void loop() {
  setAdjustedColor(analogRead(redInput)/4,
                   analogRead(greenInput)/4,
                   analogRead(blueInput)/4);
}
