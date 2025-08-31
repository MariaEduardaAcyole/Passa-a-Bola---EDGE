#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int botaoTimeA = 2;
const int botaoTimeB = 3;
const int botaoReset = 4;

int pontosA = 0;
int pontosB = 0;

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

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();

  pinMode(botaoTimeA, INPUT_PULLUP);
  pinMode(botaoTimeB, INPUT_PULLUP);
  pinMode(botaoReset, INPUT_PULLUP);

  Serial.begin(9600);

  atualizarDisplay();
}

void loop() {
  static bool ultimoEstadoA = HIGH;
  static bool ultimoEstadoB = HIGH;
  static bool ultimoEstadoReset = HIGH;

  bool estadoAtualA = digitalRead(botaoTimeA);
  bool estadoAtualB = digitalRead(botaoTimeB);
  bool estadoAtualReset = digitalRead(botaoReset);

  if (estadoAtualA == LOW && ultimoEstadoA == HIGH) {
    pontosA = (pontosA + 1) % 100;
    atualizarDisplay();
    enviarPlacarSimulado();
    delay(300);
  }

  if (estadoAtualB == LOW && ultimoEstadoB == HIGH) {
    pontosB = (pontosB + 1) % 100;
    atualizarDisplay();
    enviarPlacarSimulado();
    delay(300);
  }

  if (estadoAtualReset == LOW && ultimoEstadoReset == HIGH) {
    pontosA = 0;
    pontosB = 0;
    atualizarDisplay();
    enviarPlacarSimulado();
    delay(500);
  }

  ultimoEstadoA = estadoAtualA;
  ultimoEstadoB = estadoAtualB;
  ultimoEstadoReset = estadoAtualReset;
}
