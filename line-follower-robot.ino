/*
Line tracking robot by 
Mirafzal Shavkatov and Begzod Muxamedov
*/

//define ports for L298N
#define IN_1 6  //motor right + 
#define IN_2 7  //motor right -
#define IN_3 8  //motor left + (HIGH/LOW)
#define IN_4 9  //motor left- (HIGH/LOW)
#define EN_A 10 //motor1 speed (0-255)
#define EN_B 11 //motor2 speed (0-255)
#define EN_RIGHT 10
#define EN_LEFT 11
//define datchiks
#define DATCHIK_LEFT 2 //ANALOG
#define DATCHIK_LEFT_CENTER 3 //
#define DATCHIK_CENTER 12 //
#define DATCHIK_RIGHT_CENTER 4 //
#define DATCHIK_RIGHT 5 //ANALOG

#define WHITE "WHITE - 0"
#define BLACK "BLACK - 1"

int maxSpeed = 255;
int minSpeed = 0;
int delaytime = 1000;

boolean datchikLeft;
boolean datchikRight;
boolean datchikLeftCenter;
boolean datchikCenter;
boolean datchikRightCenter;

void setup() {
  Serial.begin(9600);
  //driver L298N
  pinMode(EN_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  //datchiks
  pinMode(DATCHIK_LEFT, INPUT);
  pinMode(DATCHIK_LEFT_CENTER, INPUT);
  pinMode(DATCHIK_CENTER, INPUT);
  pinMode(DATCHIK_RIGHT_CENTER, INPUT);
  pinMode(DATCHIK_RIGHT, INPUT);
  delay(3000);
  for (int i = 0; i < 256/2; i++)
  {
    analogWrite(EN_A, i);
    analogWrite(EN_B, i);
    delay(20);
  } 
}


void loop() {
  //main logic
  readAndPrint();
  if ((datchikRight) && !(datchikLeft)) {
    goRight();
  } else if ((datchikLeft) && (!datchikRight)) {
    goLeft();
  } else if (datchikLeft && datchikRight) {
    goForward();
  } else {
    pleaseStop();
  }
  
  delay(delaytime);
}

void readAndPrint() {
  datchikLeft = !digitalRead(DATCHIK_LEFT);
  datchikLeftCenter = digitalRead(DATCHIK_LEFT_CENTER);
  datchikCenter = digitalRead(DATCHIK_CENTER);
  datchikRightCenter = digitalRead(DATCHIK_RIGHT_CENTER);
  datchikRight = !digitalRead(DATCHIK_RIGHT);

  Serial.print("left:         ");
  Serial.println((datchikLeft == 1) ? WHITE : BLACK);
  Serial.print("left center:  ");
  Serial.println((datchikLeftCenter == 1) ? WHITE : BLACK);
  Serial.print("center:       ");
  Serial.println((datchikCenter == 1) ? WHITE : BLACK);
  Serial.print("right center: ");
  Serial.println((datchikRightCenter == 1) ? WHITE : BLACK);
  Serial.print("right:        ");
  Serial.println((datchikRight == 1) ? WHITE : BLACK);
  Serial.println("\n------------------------\n");

}

void goBackward() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(EN_RIGHT, maxSpeed);
  analogWrite(EN_LEFT, maxSpeed);
}

void goForward() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(EN_RIGHT, maxSpeed);
  analogWrite(EN_LEFT, maxSpeed);
}

void goRight() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(EN_RIGHT, maxSpeed/4);
  analogWrite(EN_LEFT, 0);
}

void goLeft() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(EN_RIGHT, 0);
  analogWrite(EN_LEFT, maxSpeed/8);
}

void pleaseStop() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(EN_RIGHT, 0);
  analogWrite(EN_LEFT, 0);
}

