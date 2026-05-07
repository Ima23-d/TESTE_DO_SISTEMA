// ======================================
// ROBO SUMO COMPLETO
// 5 SHARPS + 2 QRE + L298N
// ESP32
// ======================================

// ======================================
// SHARPS
// ======================================

// Frente centro
#define SHARP_FRENTE 34

// Frente canto esquerdo
#define SHARP_FRENTE_ESQ 35

// Frente canto direito
#define SHARP_FRENTE_DIR 32

// Lateral esquerda
#define SHARP_LADO_ESQ 33

// Lateral direita
#define SHARP_LADO_DIR 25

// ======================================
// QRE
// ======================================

#define QRE_ESQ 26
#define QRE_DIR 27

// ======================================
// L298N
// ======================================

// Motor esquerdo
#define IN1 14
#define IN2 12
#define ENA 4

// Motor direito
#define IN3 13
#define IN4 15
#define ENB 5

// ======================================
// PWM
// ======================================

#define PWM_A 0
#define PWM_B 1

// ======================================
// SETUP
// ======================================

void setup() {

  Serial.begin(115200);

  // QRE
  pinMode(QRE_ESQ, INPUT);
  pinMode(QRE_DIR, INPUT);

  // Motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // PWM
  ledcSetup(PWM_A, 5000, 8);
  ledcAttachPin(ENA, PWM_A);

  ledcSetup(PWM_B, 5000, 8);
  ledcAttachPin(ENB, PWM_B);

  // Velocidade inicial
  velocidade(180, 180);
}

// ======================================
// VELOCIDADE
// ======================================

void velocidade(int velA, int velB) {

  ledcWrite(PWM_A, velA);
  ledcWrite(PWM_B, velB);
}

// ======================================
// MOVIMENTOS
// ======================================

void frente() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ======================================
// LOOP
// ======================================

void loop() {

  // ======================================
  // LEITURA DOS SHARPS
  // ======================================

  int frente = analogRead(SHARP_FRENTE);

  int frenteEsq = analogRead(SHARP_FRENTE_ESQ);

  int frenteDir = analogRead(SHARP_FRENTE_DIR);

  int ladoEsq = analogRead(SHARP_LADO_ESQ);

  int ladoDir = analogRead(SHARP_LADO_DIR);

  // ======================================
  // LEITURA QRE
  // ======================================

  int qreEsq = digitalRead(QRE_ESQ);

  int qreDir = digitalRead(QRE_DIR);

  // ======================================
  // SERIAL
  // ======================================

  Serial.print("F:");
  Serial.print(frente);

  Serial.print(" FE:");
  Serial.print(frenteEsq);

  Serial.print(" FD:");
  Serial.print(frenteDir);

  Serial.print(" LE:");
  Serial.print(ladoEsq);

  Serial.print(" LD:");
  Serial.print(ladoDir);

  Serial.print(" QRE E:");
  Serial.print(qreEsq);

  Serial.print(" QRE D:");
  Serial.println(qreDir);

  // ======================================
  // QRE TEM PRIORIDADE
  // ======================================

  // Linha nos dois lados
  if(qreEsq == 0 && qreDir == 0){

    Serial.println("LINHA NOS DOIS");

    tras();
    delay(500);

    direita();
    delay(400);
  }

  // Linha esquerda
  else if(qreEsq == 0){

    Serial.println("LINHA ESQUERDA");

    tras();
    delay(400);

    direita();
    delay(300);
  }

  // Linha direita
  else if(qreDir == 0){

    Serial.println("LINHA DIREITA");

    tras();
    delay(400);

    esquerda();
    delay(300);
  }

  // ======================================
  // SHARPS
  // ======================================

  // Inimigo na frente
  else if(frente > 1000){

    Serial.println("INIMIGO FRENTE");

    velocidade(255, 255);

    frente();
  }

  // Frente esquerda
  else if(frenteEsq > 1000){

    Serial.println("INIMIGO FRENTE ESQUERDA");

    velocidade(180, 255);

    frente();
  }

  // Frente direita
  else if(frenteDir > 1000){

    Serial.println("INIMIGO FRENTE DIREITA");

    velocidade(255, 180);

    frente();
  }

  // Lado esquerdo
  else if(ladoEsq > 1000){

    Serial.println("INIMIGO LADO ESQUERDO");

    esquerda();
  }

  // Lado direito
  else if(ladoDir > 1000){

    Serial.println("INIMIGO LADO DIREITO");

    direita();
  }

  // ======================================
  // PROCURAR ADVERSARIO
  // ======================================

  else{

    Serial.println("PROCURANDO");

    velocidade(150, 150);

    direita();
  }

  delay(10);
}
