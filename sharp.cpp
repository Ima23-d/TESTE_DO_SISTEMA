// ==========================
// TESTE 5 SENSORES SHARP
// ==========================

// Pinos dos sensores
#define SHARP1 34
#define SHARP2 35
#define SHARP3 32
#define SHARP4 33
#define SHARP5 25

void setup() {
  Serial.begin(115200);

  pinMode(SHARP1, INPUT);
  pinMode(SHARP2, INPUT);
  pinMode(SHARP3, INPUT);
  pinMode(SHARP4, INPUT);
  pinMode(SHARP5, INPUT);
}

void loop() {

  int s1 = analogRead(SHARP1);
  int s2 = analogRead(SHARP2);
  int s3 = analogRead(SHARP3);
  int s4 = analogRead(SHARP4);
  int s5 = analogRead(SHARP5);

  Serial.println("===== SHARPS =====");

  Serial.print("Sharp 1: ");
  Serial.println(s1);

  Serial.print("Sharp 2: ");
  Serial.println(s2);

  Serial.print("Sharp 3: ");
  Serial.println(s3);

  Serial.print("Sharp 4: ");
  Serial.println(s4);

  Serial.print("Sharp 5: ");
  Serial.println(s5);

  Serial.println("==================");

  delay(500);
}
