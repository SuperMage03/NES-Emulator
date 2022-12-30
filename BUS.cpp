//
// Created by liyue on 2022-12-21.
//

#include "BUS.h"

BUS::BUS() {
    ram = new MEMORY(64 * 1024);
    cpu.setBus(this);
}

BUS::~BUS() {
    delete ram;
}

uint8_t BUS::read(uint16_t address) {
    if (ram == nullptr) return 0x00;
    return ram->read(address);
}

void BUS::write(uint16_t address, uint8_t data) {
    if (ram == nullptr) return;
    ram->write(address, data);
}



