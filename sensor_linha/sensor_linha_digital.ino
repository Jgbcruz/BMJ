/*
  Teste de Sensor de Linha (modo digital)
  Objetivo:
  Detectar rapidamente se o sensor está vendo a linha branca do dohyo.

  IMPORTANTE:
  - O sensor precisa estar ligado em uma porta digital.
  - Muitos sensores IR possuem saída digital "DO".
  - Ajuste o trimpot do módulo para calibrar o limiar.

  Comportamento esperado:
  HIGH  -> sem linha branca
  LOW   -> linha branca detectada

  (isso pode inverter dependendo do sensor)

Esse código só funciona corretamente se seu sensor tiver:

saída digital (DO)
comparador LM393 (muito comum)

Exemplo típico:

VCC
GND
AO (analógico)
DO (digital)

Você deve ligar o DO no pino 3.
*/

#define SENSOR_PIN 3
#define LED_PIN 12

bool linhaDetectada = false;

void setup() {
  Serial.begin(115200);

  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  int leitura = digitalRead(SENSOR_PIN);

  /*
    Ajuste conforme seu sensor:
    Alguns módulos retornam LOW ao detectar branco.
    Outros retornam HIGH.

    Aqui estamos assumindo:
    LOW = linha branca detectada
  */

  if (leitura == LOW) {

    linhaDetectada = true;

    digitalWrite(LED_PIN, HIGH);

    Serial.println("-> LINHA BRANCA DETECTADA");

  } else {

    linhaDetectada = false;

    digitalWrite(LED_PIN, LOW);

    Serial.println("-> Sem linha");

  }

  delay(10);
}