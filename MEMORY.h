//
// Created by liyue on 2022-12-21.
//

#ifndef NES_EMULATOR_RAM_H
#define NES_EMULATOR_RAM_H


#include <cstdint>

class MEMORY {
private:
    size_t size;
    uint8_t *memory;

public:
    ~MEMORY();
    explicit MEMORY(size_t size);

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);

    void clear();
    void setAll(uint8_t value);
};


#endif //NES_EMULATOR_RAM_H
