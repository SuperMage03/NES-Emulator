//
// Created by liyue on 2023-01-06.
//

#ifndef NES_EMULATOR_APU_H
#define NES_EMULATOR_APU_H

#include <cstdint>


class APU {
public:
    APU();
    ~APU();

    struct PULSE {
        union {
            uint8_t byte;
            struct {
                uint8_t N : 4;
                uint8_t C : 1;
                uint8_t L : 1;
                uint8_t D : 2;
            };
        } VOL;

        union {
            uint8_t byte;
            struct {
                uint8_t S : 3;
                uint8_t N : 1;
                uint8_t P : 3;
                uint8_t E : 1;
            };
        } SWEEP;

        union {
            uint8_t byte;
            uint8_t L;
        } LOW;

        union {
            uint8_t byte;
            struct {
                uint8_t H : 3;
                uint8_t L : 5;
            };
        } HIGH;
    } pulse1, pulse2;

};


#endif //NES_EMULATOR_APU_H
