//
// Created by liyue on 2023-01-06.
//

#ifndef NES_EMULATOR_PPU_H
#define NES_EMULATOR_PPU_H

#include <cstdint>

class BUS;

class PPU {
private:
    BUS *bus = nullptr;
    // PPU Registers
    uint8_t PPUCTRL;
    uint8_t PPUMASK;
    uint8_t PPUSTATUS;
    uint8_t OAMADDR;
    uint8_t OAMDATA;
    uint8_t PPUSCROLL;
    uint8_t PPUADDR;
    uint8_t PPUDATA;


public:
    PPU();
    ~PPU();

    void setBus(BUS *b);

    uint8_t readRegister(uint16_t address);
    void writeRegister(uint16_t address, uint8_t data);

    uint8_t readVRAM(uint16_t address);
    void writeVRAM(uint16_t address, uint8_t data);
};


#endif //NES_EMULATOR_PPU_H
