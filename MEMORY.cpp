//
// Created by liyue on 2022-12-21.
//

#include "MEMORY.h"

MEMORY::~MEMORY() {
    delete[] memory;
}

MEMORY::MEMORY(size_t size) {
    this->size = size;
    memory = new uint8_t[size];
    clear();
}

uint8_t MEMORY::read(uint16_t address) {
    if (address >= 0x0000 && address <= 0xFFFF)
        return memory[address];
    return 0x00;
}

void MEMORY::write(uint16_t address, uint8_t data) {
    if (address >= 0x0000 && address <= 0xFFFF)
        memory[address] = data;
}

void MEMORY::clear() {
    setAll(0x00);
}

void MEMORY::setAll(uint8_t value) {
    for (size_t i = 0; i < size; i++) {
        memory[i] = value;
    }
}
