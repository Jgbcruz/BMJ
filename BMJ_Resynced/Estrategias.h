#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "Principal.h"


// ============================================================
// ESTRATÉGIA 5
// RECUO
// ============================================================

void paraTras() {

    mover(
        -1023,
        -1023
    );
}


// ============================================================
// ESTRATÉGIA 6
// SEEK AND DESTROY - ESQUERDA
// ============================================================

void SeekAndDestroy_L() {

    leituraSensores();

    switch (classificarAlvo()) {

        case SEM_ALVO:

            // Procura girando para a esquerda
            mover(
                -723,
                 723
            );

            break;


        case ALVO_CENTRO:

            // Ataque
            mover(
                1023,
                1023
            );

            break;


        case ALVO_ESQUERDA:

            // Corrige para esquerda
            mover(
                -723,
                 723
            );

            break;


        case ALVO_DIREITA:

            // Corrige para direita
            mover(
                 723,
                -723
            );

            break;
    }
}


// ============================================================
// ESTRATÉGIA 7
// SEEK AND DESTROY - DIREITA
// ============================================================

void SeekAndDestroy_R() {

    leituraSensores();

    switch (classificarAlvo()) {

        case SEM_ALVO:

            // Procura girando para a direita
            mover(
                 723,
                -723
            );

            break;


        case ALVO_CENTRO:

            // Ataque
            mover(
                1023,
                1023
            );

            break;


        case ALVO_ESQUERDA:

            // Corrige para esquerda
            mover(
                -723,
                 723
            );

            break;


        case ALVO_DIREITA:

            // Corrige para direita
            mover(
                 723,
                -723
            );

            break;
    }
}

#endif