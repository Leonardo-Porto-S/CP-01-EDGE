// Codigo do arduino 

const int LDR_PIN    = A0;
const int LED_GREEN  = 5;
const int LED_YELLOW = 3;
const int LED_RED    = 2;
const int BUZZER_PIN = 4;

const int LUZ_ADEQUADA = 500;
const int LUZ_ALERTA   = 300;

void setup() {
  pinMode(LED_GREEN,  OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED,    OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Vinheria Agnello - Monitoramento de Luminosidade ===");
}

void darBeeps() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 500); 
    delay(300);             
    noTone(BUZZER_PIN);
    delay(300);             
  }
}

void loop() {
  int ldrValor = analogRead(LDR_PIN);
  int luminosidade = map(ldrValor, 0, 1023, 0, 100);

  Serial.print("LDR bruto: ");
  Serial.print(ldrValor);
  Serial.print(" | Luminosidade: ");
  Serial.print(luminosidade);
  Serial.println("%");

  digitalWrite(LED_GREEN,  LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED,    LOW);
  noTone(BUZZER_PIN);

  if (ldrValor >= LUZ_ADEQUADA) {
    digitalWrite(LED_RED, HIGH);
    Serial.println("Estado: CRÍTICO - Luminosidade alta demais!");
    darBeeps();  

  } else if (ldrValor >= LUZ_ALERTA) {
    digitalWrite(LED_YELLOW, HIGH);
    Serial.println("Estado: ALERTA - Luminosidade em nível intermediário.");

  } else {
    digitalWrite(LED_GREEN, HIGH);
    Serial.println("Estado: ADEQUADO - Ambiente com luminosidade ideal.");
  }

  delay(1000);
}