// ==========================
// TESTE 2 SENSORES QRE
// ==========================

#define QRE_ESQUERDO 26
#define QRE_DIREITO 27

void setup() {

  Serial.begin(115200);

  pinMode(QRE_ESQUERDO, INPUT);
  pinMode(QRE_DIREITO, INPUT);
}

void loop() {

  int esquerdo = digitalRead(QRE_ESQUERDO);
  int direito  = digitalRead(QRE_DIREITO);

  Serial.println("===== QRE =====");

  Serial.print("QRE Esquerdo: ");
  Serial.println(esquerdo);

  Serial.print("QRE Direito: ");
  Serial.println(direito);

  // ==========================
  // DETECÇÕES
  // ==========================

  
  if(esquerdo == 0 && direito == 0){

    Serial.println("LINHA DETECTADA NOS DOIS SENSORES");
  }
  else if(esquerdo == 0){

    Serial.println("Linha detectada ESQUERDA");
  }
  else if(direito == 0){

    Serial.println("Linha detectada DIREITA");
  }
  else{

    Serial.println("Nenhuma linha detectada");
  }

  Serial.println("================");

  delay(300);
}
