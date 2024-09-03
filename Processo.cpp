#include "Processo.h"

// Construtor que inicializa o processo com um código e a tag correspondente
Processo::Processo(int codigo, String tag) : codigoProcesso(codigo), tagID(tag), concluido(false) {}

bool Processo::estaFinalizado() const {
    return concluido;
}

// Marca o processo como concluído
void Processo::concluirProcesso() {
    concluido = true;
}

int Processo::getCodigo() const {
    return codigoProcesso;
}

String Processo::getTagID() const {
    return tagID;
}
