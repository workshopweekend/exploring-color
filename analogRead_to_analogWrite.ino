int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redInput = A0;
int greenInput = A1;
int blueInput = A2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int redValue = analogRead(redInput)/4;
  int greenValue = analogRead(greenInput)/4;
  int blueValue = analogRead(blueInput)/4;
  
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  
  Serial.println(String(redValue)+","+String(greenValue)+","+String(blueValue));
}