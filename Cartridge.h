//
// Created by liyue on 2023-01-06.
//

#ifndef NES_EMULATOR_CARTRIDGE_H
#define NES_EMULATOR_CARTRIDGE_H

#include <cstdint>
#include <string>
#include <fstream>

class Cartridge {
private:
    struct Header {
        uint32_t Constant;
        uint8_t prgROMChunk;
        uint8_t chrROMChunk;

        uint8_t mirror : 1;
        uint8_t hasPrgRAM : 1;
        uint8_t hasTrainer : 1;
        uint8_t ignoreMirror : 1;
        uint8_t mapperNumLL : 4;

        uint8_t VSUnisystem : 1;
        uint8_t PlayChoice10 : 1;
        uint8_t isNES2 : 2;
        uint8_t mapperNumHH : 4;

        uint8_t prgRAMChunk;
        uint8_t TVSystem;

        // Rarely Used
        struct {
            uint8_t tvSystem : 2;
            uint8_t unused1 : 2;
            uint8_t hasPrgRAM : 1;
            uint8_t hasBusConflicts : 1;
            uint8_t unused2 : 2;
        } flag10;

        uint8_t padding[5];
    } header;


public:
    Cartridge(const std::string &iNESPath);
    ~Cartridge();

    uint8_t mapperNum;

    // Don't know what it does, loaded into 0x7000 of PRG-RAM before the start of games
    uint8_t* trainer;
};


#endif //NES_EMULATOR_CARTRIDGE_H
