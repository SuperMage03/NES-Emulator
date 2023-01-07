//
// Created by liyue on 2022-12-21.
//

#ifndef NES_EMULATOR_BUS_H
#define NES_EMULATOR_BUS_H

#include "MEMORY.h"
#include "CPU.h"
#include "APU.h"
#include "PPU.h"

class BUS {
private:
    CPU cpu{};
    APU apu{};
    PPU ppu{};

    MEMORY *ram{};
    MEMORY *vram{};

public:
    BUS();
    ~BUS();

    uint8_t cpuRead(uint16_t address);
    void cpuWrite(uint16_t address, uint8_t data);
    uint8_t ppuRead(uint16_t address);
    void ppuWrite(uint16_t address, uint8_t data);
};


#endif //NES_EMULATOR_BUS_H
