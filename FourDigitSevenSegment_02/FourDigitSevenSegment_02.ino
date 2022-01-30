

/*
Displays the numbers 0-9 on the display, with one second inbetween.
     A
    ---
 F |   | B  
   | G |  
    ---
 E |   | C
   |   |
    ---
     D

 Configuration:
  Arduino Pin    Segment   Display Pin
      5             A           11
      7             B            7
      4             C            4
      11             D            2
      10            E            1
      3             F            10
      6             G            5
*/


// Pin Configuration variables
int pinPush = 2;
int pinA = 5;
int pinB = 7;
int pinC = 4;
int pinD = 11;
int pinE = 10;
int pinF = 3;
int pinG = 6;

int pinD1 = 13;
int pinD2 = 12;
int pinD3 = 9;
int pinD4 = 8;

// Properties
int n = 0;
int x = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinD1, OUTPUT);
  pinMode(pinD2, OUTPUT);
  pinMode(pinD3, OUTPUT);
  pinMode(pinD4, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  
  pinMode(pinPush, INPUT);//PUSH BUTTON
  pinMode(A0, INPUT);//POTENCIOMETRO
}

void loop() {
  // put your main code here, to run repeatedly:

  int isReset = digitalRead(pinPush);
  if(isReset == 1){
    clean();
    n = 0;
    delayMicroseconds(500);
  }
  int t = analogRead(A0);
  clean();
  digit(1);
  number((n/x/1000)%10);
  delayMicroseconds(t);
  clean();
  digit(2);
  number((n/x/100)%10);
  delayMicroseconds(t);
  clean();
  digit(3);
  number((n/x/10)%10);
  delayMicroseconds(t);
  clean();
  digit(4);
  number(n/x % 10);
  delayMicroseconds(t);

  if(n / x > 9999){
    n = 0;
    delayMicroseconds(5000);
  }else{
    n++;
  }
  
}

void clean(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

// Display Digits

void digit(int digitToTurn){
  digitalWrite(pinD1, HIGH);
  digitalWrite(pinD2, HIGH);
  digitalWrite(pinD3, HIGH);
  digitalWrite(pinD4, HIGH);

  switch (digitToTurn){
    case 1: digitalWrite(pinD1, LOW); break;
    case 2: digitalWrite(pinD2, LOW); break;
    case 3: digitalWrite(pinD3, LOW); break;
    case 4: digitalWrite(pinD4, LOW); break;
  }
}

void number(int numberToShow){
  switch (numberToShow){
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}

void zero(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void one(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void two(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void three(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void four(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void five(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void six(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void seven(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void eight(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void nine(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
