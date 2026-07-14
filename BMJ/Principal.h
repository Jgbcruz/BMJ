#ifndef Principal_H
#define Principal_H

#include "sensores.h"

enum estadoPendulo {
    DIREITA,
    MEIA_ESQUERDA,
    ESQUERDA,
    MEIA_DIREITA
};

// Leitura dos Sensores
// [0] = Frente Esquerda
// [1] = Frente
// [2] = Frente Direita

int leitura[3];

int vel_base = 650;
float erro_angular = 0;
float erro_anterior = 0;

float P = 0;
float I = 0;
float D = 0;

float PID = 0;

// Somente PD 
float Kp = 350.0;
float Ki = 0.0;
float Kd = 120.0;
// Para a melhor calibração das constantes, deve-se:
// -> desligar Kd (Kd = 0)
// -> ir aumentando Kp até obter a resposta rápida e oscilatória
// -> ir aumentando Kd até parar a resposta oscilatória e manter a agressividade

unsigned long last_time = 0;

unsigned long ultimo_pendulo = 0;

estadoPendulo estadoAtual = DIREITA;
 
const int tempo_pendulo = 180; //ms


// quantidade de ciclos consecutivos
// detectando frontal
int ataque_confirmado = 0;

const int ATAQUE_THRESHOLD = 3;


void leituraSensores() {
    leitura[0] = digitalRead(FEsq);
    leitura[1] = digitalRead(Frente);
    leitura[2] = digitalRead(FDir);
}

void calculoErroAngular() {

    leituraSensores();

    // geometria angular
    float peso[3] = {-1.0, 0.0, 1.0};

    float soma_pesos = 0;
    int ativos = 0;

    for (int i = 0; i < 3; i++) {

        if (leitura[i]) {

            soma_pesos += peso[i];
            ativos++;
        }
    }

    if (ativos > 0) {

        erro_angular = soma_pesos / ativos;

    } else {

        // mantém direção anterior
        if (erro_angular >= 0)
            erro_angular = 1.5;
        else
            erro_angular = -1.5;
    }
}

// PID

void pid() {

    unsigned long current_time = millis();

    float dt = (current_time - last_time) / 1000.0;

    if (dt <= 0)
        dt = 0.001;

    calculoErroAngular();

    P = erro_angular;

    // Integral desligada
    I += erro_angular * dt;

    D = (erro_angular - erro_anterior) / dt;

    PID = (Kp * P) + (Ki * I) + (Kd * D);

    erro_anterior = erro_angular;

    last_time = current_time;
}

// VARREDURA PENDULAR

estadoPendulo varreduraPendular(estadoPendulo estadoAtual)
{

    unsigned long agora = millis();

    if((agora-ultimo_pendulo) >= tempo_pendulo) {

        ultimo_pendulo = agora;

        switch(estadoAtual) {

            case DIREITA:
                mover(500,-500);
                return MEIA_ESQUERDA;

            case MEIA_ESQUERDA:
                mover(-500,500);
                return ESQUERDA;

            case ESQUERDA:
                mover(-500,500);
                return MEIA_DIREITA;

            case MEIA_DIREITA:
                mover(500,-500);
                return DIREITA;
        }
    }

    return estadoAtual;

}


// FULL ATTACK

bool fullAttackDetectado() {

    // frontal detectado
    if (leitura[0] && leitura[1] && leitura[2]) {

        ataque_confirmado++;

    } else {

        ataque_confirmado = 0;
    }

    // inimigo muito próximo
    return (ataque_confirmado >= ATAQUE_THRESHOLD); 
}

// TARGET TRACKER PRINCIPAL

void iSeeYou() { // estratégia número 4 no controle
    //if(evitarBorda()) return;
    leituraSensores();

    // SEM ALVO -> VARREDURA PENDULAR

    if (!leitura[0] && !leitura[1] && !leitura[2]) {

        estadoAtual = varreduraPendular(estadoAtual);

        return;
    }

    // OS 3 SENSORES -> FULL ATTACK

    if (fullAttackDetectado()) {

        mover(1023, 1023);

        return;
    }

    // COM ALVO -> PID ANGULAR

    pid();

    int velocidade_esq =
        vel_base - PID;

    int velocidade_dir =
        vel_base + PID;

    velocidade_esq =
        constrain(velocidade_esq, -1023, 1023);

    velocidade_dir =
        constrain(velocidade_dir, -1023, 1023);

    mover(velocidade_esq, velocidade_dir);
}

// bool evitarBorda() {

//     bool linha_esq = digitalRead(linhaEsq);
//     bool linha_dir = digitalRead(linhaDir);

//     if (!linha_esq && !linha_dir) {
//         return false;
//     }

//     Serial.println("!!! BORDA DETECTADA !!!");

//     // trava curta
//     parar();
//     delay(5);

//     // BORDA ESQUERDA

//     if (linha_esq && !linha_dir) {

//         Serial.println("BORDA ESQUERDA");

//         // micro-recuo angular
//         mover(-700, -250);
//         delay(90);

//         // gira rapidamente para dentro
//         mover(850, -850);
//         delay(140);
//     }

//     // BORDA DIREITA

//     else if (linha_dir && !linha_esq) {

//         Serial.println("BORDA DIREITA");

//         // micro-recuo angular
//         mover(-250, -700);
//         delay(90);

//         // gira rapidamente para dentro
//         mover(-850, 850);
//         delay(140);
//     }

//     // BORDA FRONTAL

//     else {

//         Serial.println("BORDA FRONTAL");

//         // recuo curto
//         mover(-850, -850);
//         delay(120);

//         // escolhe direção usando último erro PID
//         if (erro_angular >= 0) {

//             mover(-850, 850);

//         } else {

//             mover(850, -850);
//         }

//         delay(180);
//     }

//     parar();

//     return true;
// }

#endif
