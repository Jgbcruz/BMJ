#ifndef Sensores_H
#define Sensores_H

//BMJ
// ultima atualização 16/05/2026
#define FEsq 12
#define Frente 7
#define FDir 8
#define linhaEsq XX
#define linhaDir XX

uint8_t sensores[] = {FEsq, Frente, FDir, linhaEsq, linhaDir};

void setupSensores() {
  pinMode(FEsq, INPUT);
  pinMode(Frente, INPUT);
  pinMode(FDir, INPUT);
  pinMode(linhaEsq, INPUT);
  pinMode(linhaDir, INPUT);
}

#endif
