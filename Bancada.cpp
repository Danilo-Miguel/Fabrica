#include "Bancada.h"

// Construtor que inicializa a bancada com um leitor RFID e um processo
Bancada::Bancada(int ssPin, int rstPin, Processo* processo) : rfidReader(ssPin, rstPin), processoAtual(processo) {}

void Bancada::init() {
    rfidReader.init();
}

// Executa a leitura da tag e verifica se o processo atual pode ser concluído
void Bancada::executar() {
    String tagID = rfidReader.readTag();
    if (tagID == processoAtual->getTagID() && !processoAtual->estaFinalizado()) {
        processoAtual->concluirProcesso();
        rfidReader.writeTag("Processo " + String(processoAtual->getCodigo()) + " concluído.");
    }
}
