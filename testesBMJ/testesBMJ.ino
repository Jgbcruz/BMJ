#include "motores.h"
#include "PID.h"

void setup() {
  // put your setup code here, to run once:
  setupMotores();

  Serial.begin(115200);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoAtual = varreduraPendular(estadoAtual);
  

}
