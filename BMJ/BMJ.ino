/*
  BMJ
  16/05/2026, para a CCBB;
  Modo AUTÔNOMO usando SumoIR;

  https://github.com/Jgbcruz/BMJ
*/


//#define PID_2222

#include <Arduino.h>
#include <SumoIR.h>

#include "motores.h"
#include "sensores.h"
#include "PID.h"
#include "Empate.h"
#include "LEDFX.h"
#include "placa.h"


#define boot 0

int strategy = 0;

SumoIR IR;

void setup() {
  Serial.begin(115200);

  IR.begin(IR_PIN); 
  
  //! motor.bip(5, 250, 2500); // motor bipa (x vezes, intervalo (ms), frequencia em Hz)

  setupSensores();
  setupMotores();

  pinMode(boot, INPUT_PULLUP);

  /////// para o LED ///////
  pixels.begin();
  pixels.setBrightness(50);
  pixels.clear();
  
  ledLight(0, 0, 150);
  //////////////////////////

  Serial.println("Sistema iniciado no modo AUTO");
}


void loop() {

    IR.update();
 
    if (IR.prepare()) { // número 1 no controle
      pixels.clear();
      ledLight(255, 255, 255);
      parar();
      Serial.println("-> sumo prepare"); 
    }
    
    else if (IR.start()) {
      Serial.println("-> sumo start"); 
    } 
    
    else if (IR.on()) { // número 2 no controle
      pixels.clear();
      ledLight(0, 255, 0);
      
      switch (strategy) {
        default: //fallthrough
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
      }
      Serial.println("-> sumo on"); 
    }

    else if (IR.stop()) { // número 3 no controle
      pixels.clear();
      ledLight(255, 255, 0);
      parar();
      delay(20);
      Serial.println("-> sumo stop"); 
    }

    else { // robô inicia caindo aqui
      pixels.clear();
      strategySelection();     // seletor de estratégias
      ledDetection();
      Serial.println("-> sumo off"); 
    }
  } 

void strategySelection() {
  int cmd = IR.read();
  if (cmd >= 4 && cmd <= 7) { 
    strategy = cmd;
  } else return;

  if (cmd <= 7) {
    const int num_leds = cmd % 8;
    for(uint8_t i = 0; i < num_leds; i++) {
      switch ((cmd-3) % 6) { 
        case 0: pixels.setPixelColor(i, pixels.Color(255, 50,  50  )); break; // Vermelho claro
        case 1: pixels.setPixelColor(i, pixels.Color(0,   255, 100 )); break; // Verde com toque de azul
        case 2: pixels.setPixelColor(i, pixels.Color(255, 0,   180 )); break; // Magenta
        case 3: pixels.setPixelColor(i, pixels.Color(255, 140, 0   )); break; // Laranja
        case 4: pixels.setPixelColor(i, pixels.Color(100, 200, 255 )); break; // Azul claro
        case 5: pixels.setPixelColor(i, pixels.Color(180, 255, 0   )); break; // Verde-amarelado
      } pixels.show();
    }
    delay(80);
    for(uint8_t i = 0; i < num_leds; i++) { 
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Desliga os LEDs
      pixels.show();
    }
    delay(80);
  }
}
