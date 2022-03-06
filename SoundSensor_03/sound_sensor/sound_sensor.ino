// Constants
const int max_number = 9999;

// Properties
int soundCounter = 0;
int soundValue = 0;

// Pin Configuration variables
int pinMic = 2;

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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pinMic, INPUT);

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

  soundCounter = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  soundValue = digitalRead(pinMic);
  if(soundValue >= HIGH){
    if(soundCounter <= max_number){
      soundCounter += 1;
      Serial.print("SoundCounter\n");
      Serial.print(soundCounter);
      Serial.print("\n");
    }else{
      soundCounter = 0;
    }
  }

  int digits = digitLength(soundCounter);
  int tmp = soundCounter;
  int i = 4;
  
  while(tmp > 0){
    clean();
    
    digit(i);
    number(tmp%10);
    tmp/=10;
    i-=1;
    
    delay(1.5);
  }
}

//Private Methods

// Returns the digit lenght
int digitLength(int digit){
  int digitCounter = 0;

  while(digit >= 1){
    digit /= 10;
    digitCounter += 1;
  }

  return digitCounter;
}  

// Display Digits

void clean(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

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
