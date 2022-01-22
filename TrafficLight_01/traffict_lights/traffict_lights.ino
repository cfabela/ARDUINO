#define redc 4
#define yellowc 3
#define greenc 2

#define greenp 8
#define redp 9

void setup() {
// Select the outputs
  pinMode(redc, OUTPUT);
  pinMode(yellowc, OUTPUT);
  pinMode(greenc, OUTPUT);

  pinMode(greenp, OUTPUT);
  pinMode(redp, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, HIGH);
  delay(4000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, LOW);
  delay(2000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, HIGH);
  delay(2000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, LOW);
  delay(2000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, HIGH);
  delay(2000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, LOW);
  delay(2000);

  digitalWrite(redc, HIGH);
  digitalWrite(greenp, HIGH);
  delay(2000);

  digitalWrite(redc, LOW);
  digitalWrite(greenp, LOW);
  delay(2000);

  digitalWrite(greenc, HIGH);
  digitalWrite(redp, HIGH);
  delay(4000);

  digitalWrite(greenc, LOW);
  digitalWrite(redp, HIGH);
  delay(2000);

  digitalWrite(yellowc, LOW);
  digitalWrite(redp, HIGH);
  delay(1000);

  digitalWrite(yellowc, LOW);
  digitalWrite(redp, LOW);
  delay(4000);
}
