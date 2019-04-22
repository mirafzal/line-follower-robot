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
#define DATCHIK_LEFT 1 //ANALOG
#define DATCHIK_RIGHT 5 //ANALOG
#define DATCHIK_LEFT_CENTER 2 //
#define DATCHIK_CENTER 3 //
#define DATCHIK_RIGHT_CENTER 4 //

#define WHITE "WHITE - 0"
#define BLACK "BLACK - 1"

int maxSpeed = 255;
int minSpeed = 0;
int delaytime = 1000;

String datchikLeft;
String datchikRight;
String datchikLeftCenter;
String datchikCenter;
String datchikRightCenter;

void setup() {
  Serial.begin(9600);
  //driver L298N
  pinMode (EN_A, OUTPUT);
  pinMode (IN_1, OUTPUT);
  pinMode (IN_2, OUTPUT);
  pinMode (EN_B, OUTPUT);
  pinMode (IN_3, OUTPUT);
  pinMode (IN_4, OUTPUT);
  //datchiks
  pinMode (DATCHIK_LEFT, INPUT);
  pinMode (DATCHIK_RIGHT, INPUT);
  pinMode (DATCHIK_LEFT_CENTER, INPUT);
  pinMode (DATCHIK_CENTER, INPUT);
  pinMode (DATCHIK_RIGHT_CENTER, INPUT);
  delay(3000);
}


void loop() {
  datchikLeft = (digitalRead(DATCHIK_LEFT) == 0) ? WHITE : BLACK;
  datchikRight = (digitalRead(DATCHIK_RIGHT) == 0) ? WHITE : BLACK;
  datchikLeftCenter = (digitalRead(DATCHIK_LEFT_CENTER) == 1) ? WHITE : BLACK;
  datchikCenter = (digitalRead(DATCHIK_CENTER) == 1) ? WHITE : BLACK;
  datchikRightCenter = (digitalRead(DATCHIK_RIGHT_CENTER) == 1) ? WHITE : BLACK;
  
  Serial.print("left:         ");
  Serial.println(datchikLeft);
  Serial.print("left center:  ");
  Serial.println(datchikLeftCenter);
  Serial.print("center:       ");
  Serial.println(datchikCenter);
  Serial.print("right center: ");
  Serial.println(datchikRightCenter);
  Serial.print("right:        ");
  Serial.println(datchikRight);
  Serial.println("\n------------------------\n");

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
