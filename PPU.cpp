//
// Created by liyue on 2023-01-06.
//

#include "PPU.h"
#include "BUS.h"

void PPU::setBus(BUS *b) {
    bus = b;
}

uint8_t PPU::readRegister(uint16_t address) {
    switch (address) {
        case 0x2000:
            return PPUCTRL;
        case 0x2001:
            return PPUMASK;
        case 0x2002:
            return PPUSTATUS;
        case 0x2003:
            return OAMADDR;
        case 0x2004:
            return OAMDATA;
        case 0x2005:
            return PPUSCROLL;
        case 0x2006:
            return PPUADDR;
        case 0x2007:
            return PPUDATA;
        default:
            return 0;
    }
}

void PPU::writeRegister(uint16_t address, uint8_t data) {
    switch (address) {
        case 0x2000:
            PPUCTRL = data;
        case 0x2001:
            PPUMASK = data;
        case 0x2002:
            PPUSTATUS = data;
        case 0x2003:
            OAMADDR = data;
        case 0x2004:
            OAMDATA = data;
        case 0x2005:
            PPUSCROLL = data;
        case 0x2006:
            PPUADDR = data;
        case 0x2007:
            PPUDATA = data;
        default:
             return;
    }
}
