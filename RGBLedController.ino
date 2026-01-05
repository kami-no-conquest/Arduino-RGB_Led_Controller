int ledpin1 = 3;
int ledpin2 = 5;
int ledpin3 = 6;
int button[] = {8, 9, 10, 11, 12 ,13};
int pwmVal1 = 0;
int pwmVal2 = 0;
int pwmVal3 = 0;


void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  for (int x = 0; x < 6; x++){
    pinMode(button[x], INPUT_PULLUP);
  }

}

void loop() {
  analogWrite(ledpin1, pwmVal1);
  analogWrite(ledpin2, pwmVal2);
  analogWrite(ledpin3, pwmVal3);

  if (digitalRead(button[0]) == LOW){
    pwmVal1 += 20;
     if (pwmVal1 > 255){
      pwmVal1 = 255;
    }
    analogWrite(ledpin1, pwmVal1);
    delay(200); 
  }
  if (digitalRead(button[1]) == LOW){
    pwmVal1 -= 20;
     if (pwmVal1 < 0){
      pwmVal1 = 0;
    }
    analogWrite(ledpin1, pwmVal1);
    delay(200); 
  }

  if (digitalRead(button[2]) == LOW){
    pwmVal2 += 20;
    if (pwmVal2 > 255){
      pwmVal2 = 255;
    }
    analogWrite(ledpin2, pwmVal2);
    delay(200);
  }

  if (digitalRead(button[3]) == LOW){
    pwmVal2 -= 20;
    if (pwmVal2 < 0){
      pwmVal2 = 0;
    }
    analogWrite(ledpin2, pwmVal2);
    delay(200);
  }

  if (digitalRead(button[4]) == LOW){
    pwmVal3 += 20;
    if (pwmVal3 > 255){
      pwmVal3 = 255;
    }
    analogWrite(ledpin3, pwmVal3);
    delay(200);
  }

  if (digitalRead(button[5]) == LOW) {
    pwmVal3 -= 20;
    if (pwmVal3 < 0){
      pwmVal3 = 0;
    }
    analogWrite(ledpin3, pwmVal3);
    delay(200);
  }
}
