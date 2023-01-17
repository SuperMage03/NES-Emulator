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
    struct CommonHeader {
        uint32_t Constant;
        uint8_t prgROMChunk;
        uint8_t chrROMChunk;

        uint8_t mirror : 1;
        uint8_t hasPrgRAM : 1;
        uint8_t hasTrainer : 1;
        uint8_t ignoreMirror : 1; // Hard-wired 4-screen mode
        uint8_t mapperNumLL : 4;

        uint8_t VSUnisystem : 1;
        uint8_t PlayChoice10 : 1;
        uint8_t isNES2 : 2;
        uint8_t mapperNumHH : 4;

        union {
            // iNES 1.0
            struct {
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
            };
        } typeHeader;

    } header;

    uint8_t mapperNum;

    // Don't know what it does, loaded into 0x7000 of PRG-RAM before the start of games
    uint8_t* trainer;

    uint8_t* prgROM;
    uint8_t* chrROM;


public:
    Cartridge(const std::string &iNESPath);
    ~Cartridge();
};


#endif //NES_EMULATOR_CARTRIDGE_H
