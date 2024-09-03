#include "ControleLinhaDeProducao.h"

// Construtor que inicializa as bancadas da linha de produção
ControleLinhaDeProducao::ControleLinhaDeProducao(Bancada* b1, Bancada* b2, Bancada* b3, Bancada* b4, Bancada* b5) {
    bancadas[0] = b1;
    bancadas[1] = b2;
    bancadas[2] = b3;
    bancadas[3] = b4;
    bancadas[4] = b5;
}

// Inicia o processo de produção passando por todas as bancadas
void ControleLinhaDeProducao::iniciarProducao() {
    for (int i = 0; i < 5; i++) {
        bancadas[i]->executar();
    }
}
