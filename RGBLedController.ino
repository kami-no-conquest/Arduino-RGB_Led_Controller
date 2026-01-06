const int button[] = {8, 9, 10};
const int ledPin[] = {3, 5, 6};

const unsigned long longPress = 300;
const unsigned long debounce = 20;

unsigned long debounceTime1 = 0;
unsigned long debounceTime2 = 0;
unsigned long debounceTime3 = 0;
unsigned long pressTime1 = 0;
unsigned long pressTime2 = 0;
unsigned long pressTime3 = 0;
bool lastReading1 = HIGH;
bool lastReading2 = HIGH;
bool lastReading3 = HIGH;
bool steadyState1 = HIGH;
bool steadyState2 = HIGH;
bool steadyState3 = HIGH;
bool button1Held = false;
bool button2Held = false;
bool button3Held = false;

int pwm1 = 0;
int pwm2 = 0;
int pwm3 = 0;


void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(button[i], INPUT_PULLUP);
    pinMode(ledPin[i], OUTPUT);
    analogWrite(ledPin[i], 0);
  }

}

void loop() {
  button1();
  button2();
  button3();
}

void button1() {
  bool reading1 = digitalRead(button[0]);
  if (reading1 != lastReading1) {
    debounceTime1 = millis();
  }
  if (millis() - debounceTime1 > debounce) {
    if (reading1 != steadyState1){
      steadyState1 = reading1;

      if (steadyState1 == LOW) {
        pressTime1 = millis();
        button1Held = true;
      }
      if (reading1 == HIGH && button1Held) {
        unsigned long duration = millis() - pressTime1;
        if (duration < longPress) {
          pwm1 += 15;
        }
        else {
          pwm1 -= 15;
        }
        pwm1 = constrain(pwm1, 0, 255);
        analogWrite(ledPin[0], pwm1);
        button1Held = false;
      }
    }
  }
  lastReading1 = reading1;
}

void button2() {
  bool reading2 = digitalRead(button[1]);
  if (reading2 != lastReading2) {
    debounceTime2 = millis();
  }
  if (millis() - debounceTime2 > debounce) {
    if (reading2 != steadyState2){
      steadyState2 = reading2;

      if (steadyState2 == LOW) {
        pressTime2 = millis();
        button2Held = true;
      }
      if (reading2 == HIGH && button2Held) {
        unsigned long duration = millis() - pressTime2;
        if (duration < longPress) {
          pwm2 += 15;
        }
        else {
          pwm2 -= 15;
        }
        pwm2 = constrain(pwm2, 0, 255);
        analogWrite(ledPin[1], pwm2);
        button2Held = false;
      }
    }
  }
  lastReading2 = reading2;
}

void button3() {
  bool reading3 = digitalRead(button[2]);
  if (reading3 != lastReading3) {
    debounceTime3 = millis();
  }
  if (millis() - debounceTime3 > debounce) {
    if (reading3 != steadyState3){
      steadyState3 = reading3;

      if (steadyState3 == LOW) {
        pressTime3 = millis();
        button3Held = true;
      }
      if (reading3 == HIGH && button3Held) {
        unsigned long duration = millis() - pressTime3;
        if (duration < longPress) {
          pwm3 += 15;
        }
        else {
          pwm3 -= 15;
        }
        pwm3 = constrain(pwm3, 0, 255);
        analogWrite(ledPin[2], pwm3);
        button3Held = false;
      }
    }
  }
  lastReading3 = reading3;
}
