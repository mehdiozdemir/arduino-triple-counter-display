byte segment1[] = {2, 3, 4, 5}; // A, B, C, D
byte segment2[] = {6, 7, 8, 9};
byte segment3[] = {10, 11, 12, 13};

byte speedPin = A0;
byte directionPin = A1;

int speed;
int direction;

/*const byte digits[10][4] = {
  {0, 1, 1, 0}, 
  {1, 0, 1, 1}, 
  {1, 1, 0, 1}, 
  {1, 1, 1, 0}, 
  {0, 1, 0, 1}, 
  {1, 0, 0, 1}, 
  {1, 0, 1, 0}, 
  {1, 1, 1, 1}, 
  {0, 1, 1, 1}, 
  {1, 1, 0, 0}  
};*/

int counter = 0;
int currentDigit[3] = {0, 0, 0}; 

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(segment1[i], OUTPUT);
    pinMode(segment2[i], OUTPUT);
    pinMode(segment3[i], OUTPUT);
  }
  pinMode(speedPin, INPUT);
  pinMode(directionPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  updatePotentiometerValues();
  if (direction < 512) {
    countDown();
  } else {
    countUp();
  }
}

void updatePotentiometerValues() {
  speed = analogRead(speedPin);
  direction = analogRead(directionPin);
  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(", Direction: ");
  Serial.println(direction);
}

void countDown() {
  int delayTime = map(speed, 0, 1023, 0, 255);

  counter--;
  if (counter < 0) {
    counter = 999;
  }

  separateDigits(counter, currentDigit);

  displayNumber(currentDigit);
  delay(delayTime);
}

void countUp() {
  int delayTime = map(speed, 0, 1023, 0, 255);

  counter++;
  if (counter > 999) {
    counter = 0;
  }

  separateDigits(counter, currentDigit);

  displayNumber(currentDigit);
  delay(delayTime);
}

void separateDigits(int number, int digits[]) {
  digits[0] = number / 100; 
  number %= 100;           
  digits[1] = number / 10;  
  digits[2] = number % 10;  
}

void displayNumber(int digits[]) {
  for (int digit = 0; digit < 3; digit++) {
    byte* currentSegmentPins;
    if (digit == 0) {
      currentSegmentPins = segment3; 
    } else if (digit == 1) {
      currentSegmentPins = segment2; 
    } else {
      currentSegmentPins = segment1; 
    }

    for (int segment = 0; segment < 4; segment++) {
      digitalWrite(currentSegmentPins[segment], digits[digit] & (1 << segment));
    }
  }
}
