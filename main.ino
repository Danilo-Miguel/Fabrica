#include <SPI.h>
#include <MFRC522.h>
#include "RFIDReader.h"
#include "Processo.h"

// Definição dos pinos para o MFRC522
#define SS_PIN 2   // Pino de seleção (SDA) do RC522 -> corresponde ao D4 (GPIO2)
#define RST_PIN 0  // Pino de reset do RC522 -> corresponde ao D3 (GPIO0)

// Instância do leitor RFID
RFIDReader rfidReader(SS_PIN, RST_PIN);

// Instâncias dos processos
Processo processo1(1, "UID_TAG_1");
Processo processo2(2, "UID_TAG_2");
Processo processo3(3, "UID_TAG_3");
Processo processo4(4, "UID_TAG_4");
Processo processo5(5, "UID_TAG_5");

void setup() {
    Serial.begin(115200);
    rfidReader.init();
    Serial.println("Sistema iniciado. Aproxime uma tag do leitor...");
}

void loop() {
    String dadosLidos = rfidReader.readTag();
    
    if (dadosLidos.length() > 0) {
        Serial.print("Tag lida: ");
        Serial.println(dadosLidos);

        // Simular as bancadas
        if (dadosLidos == processo1.getTagID()) {
            if (!processo1.estaFinalizado()) {
                processo1.concluirProcesso();
                Serial.println("Processo 1 concluído.");
            } else {
                Serial.println("Processo 1 já finalizado.");
            }
        } else if (dadosLidos == processo2.getTagID()) {
            if (processo1.estaFinalizado() && !processo2.estaFinalizado()) {
                processo2.concluirProcesso();
                Serial.println("Processo 2 concluído.");
            } else {
                Serial.println("Processo 2 já finalizado ou Processo 1 não concluído.");
            }
        } else if (dadosLidos == processo3.getTagID()) {
            if (processo2.estaFinalizado() && !processo3.estaFinalizado()) {
                processo3.concluirProcesso();
                Serial.println("Processo 3 concluído.");
            } else {
                Serial.println("Processo 3 já finalizado ou Processo 2 não concluído.");
            }
        } else if (dadosLidos == processo4.getTagID()) {
            if (processo3.estaFinalizado() && !processo4.estaFinalizado()) {
                processo4.concluirProcesso();
                Serial.println("Processo 4 concluído.");
            } else {
                Serial.println("Processo 4 já finalizado ou Processo 3 não concluído.");
            }
        } else if (dadosLidos == processo5.getTagID()) {
            if (processo4.estaFinalizado() && !processo5.estaFinalizado()) {
                processo5.concluirProcesso();
                Serial.println("Processo 5 concluído.");
            } else {
                Serial.println("Processo 5 já finalizado ou Processo 4 não concluído.");
            }
        }
    }
}
