//
// Created by liyue on 2022-12-21.
//

#ifndef NES_EMULATOR_BUS_H
#define NES_EMULATOR_BUS_H

#include "MEMORY.h"
#include "CPU.h"

class BUS {
private:
    CPU cpu{};
    MEMORY *ram{};

public:
    BUS();
    ~BUS();
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);
};


#endif //NES_EMULATOR_BUS_H
