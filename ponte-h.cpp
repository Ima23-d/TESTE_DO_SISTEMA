// ==========================
// TESTE PONTE H L298N
// ==========================

// ========= MOTOR ESQUERDO =========
#define IN1 14
#define IN2 12
#define ENA 26

// ========= MOTOR DIREITO =========
#define IN3 13
#define IN4 15
#define ENB 27

// ========= CANAIS PWM =========
#define CANAL_PWM_A 0
#define CANAL_PWM_B 1

// ==========================

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // ==========================
  // CONFIGURA PWM ESP32
  // ==========================

  ledcSetup(CANAL_PWM_A, 5000, 8);
  ledcAttachPin(ENA, CANAL_PWM_A);

  ledcSetup(CANAL_PWM_B, 5000, 8);
  ledcAttachPin(ENB, CANAL_PWM_B);
}

// ==========================
// FUNÇÃO VELOCIDADE
// valor: 0 até 255
// ==========================

void velocidade(int velA, int velB) {

  ledcWrite(CANAL_PWM_A, velA);
  ledcWrite(CANAL_PWM_B, velB);
}

// ==========================
// MOVIMENTOS
// ==========================

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

void frenteEsquerda() {

  // Motor esquerdo mais lento
  velocidade(100, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void frenteDireita() {

  // Motor direito mais lento
  velocidade(255, 100);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void trasEsquerda() {

  velocidade(100, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void trasDireita() {

  velocidade(255, 100);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  velocidade(0, 0);
}

// ==========================

void loop() {

  // Frente velocidade máxima
  velocidade(255, 255);
  frente();
  delay(2000);

  // Trás
  velocidade(255, 255);
  tras();
  delay(2000);

  // Esquerda
  velocidade(255, 255);
  esquerda();
  delay(2000);

  // Direita
  velocidade(255, 255);
  direita();
  delay(2000);

  // Frente esquerda
  frenteEsquerda();
  delay(2000);

  // Frente direita
  frenteDireita();
  delay(2000);

  // Trás esquerda
  trasEsquerda();
  delay(2000);

  // Trás direita
  trasDireita();
  delay(2000);

  // Parar
  parar();
  delay(2000);
}
