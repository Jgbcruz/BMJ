/*
  BMJ
  Mini Sumo
  Modo AUTÔNOMO usando SumoIR
*/

#include <Arduino.h>

#include "SumoIR.h"

#include "motores.h"
#include "sensores.h"
#include "Principal.h"
#include "Estrategias.h"
#include "placa.h"


#define boot 0
#define LED_PIN 2

int strategy = 0;

SumoIR IR;


void setup() {

    Serial.begin(115200);

    IR.begin(IR_PIN);

    setupSensores();
    setupMotores();

    pinMode(boot, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, LOW);

    Serial.println("Sistema iniciado no modo AUTO");
}


void loop() {

    IR.update();


    // ========================================================
    // STOP
    // ========================================================

    if (IR.stop()) {

        digitalWrite(LED_PIN, LOW);

        parar();

        return;
    }


    // ========================================================
    // PREPARE
    // ========================================================

    if (IR.prepare()) {

        digitalWrite(LED_PIN, HIGH);

        parar();

        return;
    }


    // ========================================================
    // START
    // ========================================================

    if (IR.start()) {

       for(int i=0;i<6;i++){
        digitalWrite(LED_PIN,!digitalRead(LED_PIN));
        delay(50);
      }

        return;
    }


    // ========================================================
    // ROBÔ ATIVO
    // ========================================================

    if (IR.on()) {

        switch (strategy) {

            case 4:
                iSeeYou();
                break;


            case 5:
                paraTras();
                break;


            case 6:
                SeekAndDestroy_L();
                break;


            case 7:
                SeekAndDestroy_R();
                break;


            default:
                parar();
                break;
        }

        return;
    }


    // ========================================================
    // SELEÇÃO DA ESTRATÉGIA
    // ========================================================

    int cmd = IR.read();

    if (cmd >= 4 && cmd <= 7) {

        strategy = cmd;

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
    }
}