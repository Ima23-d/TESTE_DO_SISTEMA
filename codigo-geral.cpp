// ======================================
// ROBO SUMO SIMPLES
// ESP32 + SHARP + QRE + L298N
// ======================================

// ==========================
// SHARP
// ==========================

// Sharp frontal
#define SHARP_FRENTE 34

// Sharp esquerda
#define SHARP_ESQ 35

// Sharp direita
#define SHARP_DIR 32

// ==========================
// QRE
// ==========================

#define QRE_ESQ 26
#define QRE_DIR 27

// ==========================
// L298N
// ==========================

// Motor esquerdo
#define IN1 14
#define IN2 12
#define ENA 25

// Motor direito
#define IN3 13
#define IN4 15
#define ENB 33

// ==========================
// PWM
// ==========================

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

  // PWM ESP32
  ledcSetup(PWM_A, 5000, 8);
  ledcAttachPin(ENA, PWM_A);

  ledcSetup(PWM_B, 5000, 8);
  ledcAttachPin(ENB, PWM_B);

  // Velocidade inicial
  velocidade(200, 200);
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

  // ==========================
  // LEITURA DOS SENSORES
  // ==========================

  int sharpFrente = analogRead(SHARP_FRENTE);
  int sharpEsq = analogRead(SHARP_ESQ);
  int sharpDir = analogRead(SHARP_DIR);

  int qreEsq = digitalRead(QRE_ESQ);
  int qreDir = digitalRead(QRE_DIR);

  // ==========================
  // MONITOR SERIAL
  // ==========================

  Serial.print("Frente: ");
  Serial.print(sharpFrente);

  Serial.print(" | Esq: ");
  Serial.print(sharpEsq);

  Serial.print(" | Dir: ");
  Serial.print(sharpDir);

  Serial.print(" | QRE E: ");
  Serial.print(qreEsq);

  Serial.print(" | QRE D: ");
  Serial.println(qreDir);

  // ======================================
  // QRE TEM PRIORIDADE
  // ======================================

  // Detectou linha nos dois
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
  // SHARP
  // ======================================

  // Inimigo na frente
  else if(sharpFrente > 1000){

    Serial.println("INIMIGO FRENTE");

    velocidade(255, 255);

    frente();
  }

  // Inimigo esquerda
  else if(sharpEsq > 1000){

    Serial.println("INIMIGO ESQUERDA");

    esquerda();
  }

  // Inimigo direita
  else if(sharpDir > 1000){

    Serial.println("INIMIGO DIREITA");

    direita();
  }

  // Procurando inimigo
  else{

    Serial.println("PROCURANDO");

    velocidade(150, 150);

    direita();
  }

  delay(10);
}
