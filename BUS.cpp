//
// Created by liyue on 2022-12-21.
//

#include "BUS.h"

BUS::BUS() {
    ram = new MEMORY(2 * 1024);
    vram = new MEMORY(2 * 1024);

    cpu.setBus(this);
    ppu.setBus(this);
}

BUS::~BUS() {
    delete ram;
    delete vram;
}

// This is read by CPU, and it's memory addressing map
uint8_t BUS::cpuRead(uint16_t address) {
    // NES RAM
    if (0x0000 <= address && address <= 0x1FFF) {
        if (ram == nullptr) return 0x00;
        // 0x0000 to 0x07FF are mirrored onto the range 0x0800 to 0x1FFF
        return ram->read(address % 0x0800);
    }

    // NES PPU Registers
    else if (0x2000 <= address && address <= 0x3FFF) {
        // 0x2000 to 0x2007 are mirrored onto the range 0x2008 to 0x3FFF
        return ppu.readRegister(0x2000 + ((address - 0x2000) % 8));
    }

    // NES APU and I/O Registers
    else if (0x4000 <= address && address <= 0x4017) {
        return 0;
    }

    // APU and I/O functionality that is normally disabled.
    else if (0x4018 <= address && address <= 0x401F) {
        return 0;
    }

    // Cartridge space: PRG ROM, PRG RAM, and mapper registers
    else {
        return 0;
    }
}


// This is write by CPU, and it's memory addressing map
void BUS::cpuWrite(uint16_t address, uint8_t data) {
    // NES RAM
    if (0 <= address && address <= 0x1FFF) {
        if (ram == nullptr) return;
        // 0x0000 to 0x07FF are mirrored onto the range 0x0800 to 0x1FFF
        ram->write(address % 0x0800, data);
    }

    // NES PPU Registers
    else if (0x2000 <= address && address <= 0x3FFF) {
        // 0x2000 to 0x2007 are mirrored onto the range 0x2008 to 0x3FFF
        ppu.writeRegister(0x2000 + ((address - 0x2000) % 8), data);
    }

    // NES APU and I/O Registers
    else if (0x4000 <= address && address <= 0x4017) {
        return;
    }

    // APU and I/O functionality that is normally disabled.
    else if (0x4018 <= address && address <= 0x401F) {

    }

    // Cartridge space: PRG ROM, PRG RAM, and mapper registers
    else {

    }
}


void BUS::ppuRead(uint16_t address) {
    // NES RAM
    if (0x0000 <= address && address <= 0x1FFF) {
        Cartridge
    }

        // NES PPU Registers
    else if (0x2000 <= address && address <= 0x3FFF) {
        // 0x2000 to 0x2007 are mirrored onto the range 0x2008 to 0x3FFF
        return ppu.readRegister(0x2000 + ((address - 0x2000) % 8));
    }

        // NES APU and I/O Registers
    else if (0x4000 <= address && address <= 0x4017) {
        return 0;
    }

        // APU and I/O functionality that is normally disabled.
    else if (0x4018 <= address && address <= 0x401F) {
        return 0;
    }

        // Cartridge space: PRG ROM, PRG RAM, and mapper registers
    else {
        return 0;
    }
}

void BUS::ppuWrite(uint16_t address, uint8_t data) {

}



