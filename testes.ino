// Esse arquivo simula os eventos sem precisar apertar botões físicos.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pontosA = 0;
int pontosB = 0;

// Funções do código original reutilizadas
void atualizarDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time A: ");
  lcd.print(pontosA);

  lcd.setCursor(0, 1);
  lcd.print("Time B: ");
  lcd.print(pontosB);
}

void enviarPlacarSimulado() {
  Serial.println("---- Enviando para API ----");
  Serial.println("POST https://meu-servidor.com/api/placar");
  Serial.print("Payload: { \"timeA\": ");
  Serial.print(pontosA);
  Serial.print(", \"timeB\": ");
  Serial.print(pontosB);
  Serial.println(" }");
  Serial.println("----------------------------");
}

// Funções de teste
void testarIncrementoTimeA() {
  pontosA++;
  atualizarDisplay();
  enviarPlacarSimulado();
  Serial.println("Teste Incremento Time A OK");
}

void testarIncrementoTimeB() {
  pontosB++;
  atualizarDisplay();
  enviarPlacarSimulado();
  Serial.println("✔️ Teste Incremento Time B OK");
}

void testarReset() {
  pontosA = 0;
  pontosB = 0;
  atualizarDisplay();
  enviarPlacarSimulado();
  Serial.println("Teste Reset OK");
}

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  Serial.println("===== INICIANDO TESTES =====");
  
  testarIncrementoTimeA();
  delay(1000);

  testarIncrementoTimeB();
  delay(1000);

  testarReset();
  delay(1000);

  Serial.println("===== TODOS OS TESTES FINALIZADOS =====");
}

void loop() {
  // Não precisa de nada no loop — apenas roda os testes no setup()
}
