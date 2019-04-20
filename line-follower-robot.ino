/*
Line tracking robot by 
Mirafzal Shavkatov and Begzod Muxamedov
*/

//define ports for L298N
#define IN_1 5  //motor1 +
#define IN_2 6  //motor1 -
#define IN_3 7  //motor2 + (HIGH/LOW)
#define IN_4 8  //motor2 - (HIGH/LOW)
#define EN_A 9  //motor1 speed (0-255)
#define EN_B 10 //motor2 speed (0-255)
//define datchiks
#define DATCHIK_1 3 //left
#define DATCHIK_2 4 //right

int max = 255;
int delaytime = 1;

int datchik1;
int datchik2;

void setup() {
  // put your setup code here, to run once:
  pinMode (EN_A, OUTPUT);
  pinMode (IN_1, OUTPUT);
  pinMode (IN_2, OUTPUT);
  pinMode (EN_B, OUTPUT);
  pinMode (IN_3, OUTPUT);
  pinMode (IN_4, OUTPUT);
  delay(3000);
}


void loop() {
  datchik1 = digitalRead(DATCHIK_1);
  datchik2 = digitalRead(DATCHIK_2);
  if (datchik1 && datchik2) {
    goForward(max);
  } else if(datchik1) {
    goRight(max);
  } else if(datchik2) {
    goLeft(max);
  } else {
    pleaseSTOP();
  }
  delay(delaytime);
}

void goForward(int speed) {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
//  analogWrite(EN_A, max);
//  analogWrite(EN_B, max);
//  analogWrite(EN_A,55);
//  analogWrite(EN_B,55);
//  delay(500);
//  analogWrite(EN_A,105);
//  analogWrite(EN_B,105);
//  delay(1000);
//  analogWrite(EN_A,255);
//  analogWrite(EN_B,255);
//  delay(1500);
//  for (int i = 0; i <= max; i++)
//  {
//      analogWrite(EN_A, i);
//      analogWrite(EN_B, i);
//      delay(delaytime);
//  }
//  for (int i = 50; i >= max; i--)
//  {
//      analogWrite(EN_A, i);
//      analogWrite(EN_B, i);
//      delay(delaytime);
//  }
}

void goBackward(int speed) {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
//  analogWrite(EN_A, max);
//  analogWrite(EN_B, max);
//  analogWrite(EN_A,55);
//  analogWrite(EN_B,55);
//  delay(500);
//  analogWrite(EN_A,105);
//  analogWrite(EN_B,105);
//  delay(1000);
//  analogWrite(EN_A,255);
//  analogWrite(EN_B,255);
//  delay(1500);
  
//  for (int i = 0; i <= max; i++)
//  {
//      analogWrite(EN_A, i);
//      analogWrite(EN_B, i);
//      delay(delaytime);
//  }
//  for (int i = max; i >= 0; i--)
//  {
//      analogWrite(EN_A, i);
//      analogWrite(EN_B, i);
//      delay(delaytime);
//  }
}

void goRight(int speed) {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
}

void goLeft(int speed) {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

void pleaseSTOP() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

