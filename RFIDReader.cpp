#include "RFIDReader.h"

// Construtor que inicializa o objeto MFRC522
RFIDReader::RFIDReader(int ssPin, int rstPin) : mfrc522(ssPin, rstPin) {}

void RFIDReader::init() {
    SPI.begin();  // Inicia o SPI
    mfrc522.PCD_Init();  // Inicia o MFRC522
}

String RFIDReader::readTag() {
    String tagUID = "";
    
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return tagUID;
    }
    
    if (!mfrc522.PICC_ReadCardSerial()) {
        return tagUID;
    }

    for (byte i = 0; i < mfrc522.uid.size; i++) {
        tagUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
        tagUID += String(mfrc522.uid.uidByte[i], HEX);
    }

    tagUID.toUpperCase();
    return tagUID;
}

void RFIDReader::writeTag(String data) {
    // Implemente a função de gravação de tags se necessário
}
