#ifndef PROCESSO_H
#define PROCESSO_H

#include <Arduino.h>

// Classe que representa um processo de produção
class Processo {
private:
    int codigoProcesso;
    String tagID;
    bool concluido;

public:
    Processo(int codigo, String tag);
    bool estaFinalizado() const;
    void concluirProcesso();
    int getCodigo() const;
    String getTagID() const;
};

#endif
