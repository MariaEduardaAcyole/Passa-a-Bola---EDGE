#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// === LCD ===
LiquidCrystal_I2C lcd(0x27, 16, 2);

// === BOTÕES ===
const int botaoTimeA = 12;
const int botaoTimeB = 13;
const int botaoReset = 14;

// === VARIÁVEIS DO PLACAR ===
int pontosA = 0;
int pontosB = 0;

// === CONFIGURAÇÃO DE REDE E MQTT ===
const char* ssid = "Wokwi-GUEST";   // ou nome do Wi-Fi da sua escola/celular
const char* password = "";           // senha do Wi-Fi (vazio no Wokwi)
const char* mqtt_server = "test.mosquitto.org"; // broker público gratuito

WiFiClient espClient;
PubSubClient client(espClient);

// === FUNÇÕES ===

void atualizarDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time A: ");
  lcd.print(pontosA);
  lcd.setCursor(0, 1);
  lcd.print("Time B: ");
  lcd.print(pontosB);
}

// Publica os dados do placar no tópico MQTT
void publicarPlacar() {
  String payload = "{\"timeA\": " + String(pontosA) + ", \"timeB\": " + String(pontosB) + "}";
  client.publish("placarIoT/dados", payload.c_str());
  Serial.println("Publicado MQTT: " + payload);
}

// Recebe comandos MQTT (ex: resetar placar)
void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) msg += (char)payload[i];
  Serial.print("Mensagem recebida: ");
  Serial.println(msg);

  if (msg == "reset") {
    pontosA = 0;
    pontosB = 0;
    atualizarDisplay();
    publicarPlacar();
  }
}

// Conecta ao Wi-Fi
void setup_wifi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// Reconnecta ao broker MQTT caso caia
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    if (client.connect("placarESP32")) {
      Serial.println("Conectado ao broker!");
      client.subscribe("placarIoT/comando");
    } else {
      Serial.print("Falha, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

// === SETUP ===
void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22); // SDA, SCL
  lcd.init();
  lcd.backlight();

  pinMode(botaoTimeA, INPUT_PULLUP);
  pinMode(botaoTimeB, INPUT_PULLUP);
  pinMode(botaoReset, INPUT_PULLUP);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  atualizarDisplay();
}

// === LOOP PRINCIPAL ===
void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  static bool lastA = HIGH, lastB = HIGH, lastR = HIGH;
  bool a = digitalRead(botaoTimeA);
  bool b = digitalRead(botaoTimeB);
  bool r = digitalRead(botaoReset);

  if (a == LOW && lastA == HIGH) {
    pontosA++;
    atualizarDisplay();
    publicarPlacar();
    delay(300);
  }
  if (b == LOW && lastB == HIGH) {
    pontosB++;
    atualizarDisplay();
    publicarPlacar();
    delay(300);
  }
  if (r == LOW && lastR == HIGH) {
    pontosA = 0;
    pontosB = 0;
    atualizarDisplay();
    publicarPlacar();
    delay(500);
  }

  lastA = a; lastB = b; lastR = r;
}
