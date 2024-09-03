#ifndef RFIDREADER_H
#define RFIDREADER_H

#include <SPI.h>
#include <MFRC522.h>

// Classe que gerencia a leitura e gravação de tags RFID usando o módulo RC522
class RFIDReader {
private:
    MFRC522 mfrc522;

public:
    RFIDReader(int ssPin, int rstPin);
    void init();
    String readTag();
    void writeTag(String data);
};

#endif
