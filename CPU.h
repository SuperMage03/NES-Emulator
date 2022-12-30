//
// Created by liyue on 2022-12-21.
//

#ifndef NES_EMULATOR_CPU_H
#define NES_EMULATOR_CPU_H

#include <cstdint>
#include <string>

class BUS;

class CPU {
private:
    struct Instruction {
        std::string name;
        uint8_t (CPU::*operate)() = nullptr;
        uint8_t (CPU::*addressMode)() = nullptr;
        uint8_t cycles = 0;
    } *OPCodeTable{};


    BUS *bus = nullptr;

    // Addressing Modes
    uint8_t ACC();
    uint8_t ABS();
    uint8_t ABX();
    uint8_t ABY();
    uint8_t IMM();
    uint8_t IMP();
    uint8_t IND();
    uint8_t IZX();
    uint8_t IZY();
    uint8_t REL();
    uint8_t ZP0();
    uint8_t ZPX();
    uint8_t ZPY();

    // Operate Functions
    uint8_t ADC();
    uint8_t AND();
    uint8_t ASL();
    uint8_t BCC();
    uint8_t BCS();
    uint8_t BEQ();
    uint8_t BIT();
    uint8_t BMI();
    uint8_t BNE();
    uint8_t BPL();
    uint8_t BRK();
    uint8_t BVC();
    uint8_t BVS();
    uint8_t CLC();
    uint8_t CLD();
    uint8_t CLI();
    uint8_t CLV();
    uint8_t CMP();
    uint8_t CPX();
    uint8_t CPY();
    uint8_t DEC();
    uint8_t DEX();
    uint8_t DEY();
    uint8_t EOR();
    uint8_t INC();
    uint8_t INX();
    uint8_t INY();
    uint8_t JMP();
    uint8_t JSR();
    uint8_t LDA();
    uint8_t LDX();
    uint8_t LDY();
    uint8_t LSR();
    uint8_t NOP();
    uint8_t ORA();
    uint8_t PHA();
    uint8_t PHP();
    uint8_t PLA();
    uint8_t PLP();
    uint8_t ROL();
    uint8_t ROR();
    uint8_t RTI();
    uint8_t RTS();
    uint8_t SBC();
    uint8_t SEC();
    uint8_t SED();
    uint8_t SEI();
    uint8_t STA();
    uint8_t STX();
    uint8_t STY();
    uint8_t TAX();
    uint8_t TAY();
    uint8_t TSX();
    uint8_t TXA();
    uint8_t TXS();
    uint8_t TYA();
    uint8_t XXX();


public:
    CPU();
    ~CPU();

    void setBus(BUS *b);

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);

    uint16_t pc = 0x0000; // Program Counter
    uint8_t acc = 0x00; // Accumulator Register
    uint8_t xReg = 0x00; // X-Register
    uint8_t yReg = 0x00; // Y-Register
    uint8_t stkptr = 0x00; // Stack Pointer

    union STATUS {
        uint8_t BYTE;

        struct {
            uint8_t C : 1;
            uint8_t Z : 1;
            uint8_t I : 1;
            uint8_t D : 1;
            uint8_t B : 1;
            uint8_t U : 1;
            uint8_t V : 1;
            uint8_t N : 1;
        } FLAG;
    } status { 0x00 };


    void clock();
    void reset();
    void irq();
    void nmi();

    uint8_t fetch();
    uint8_t fetchedData = 0x00;

    uint16_t operandAddr = 0x00;
    uint16_t addressOffset = 0x00;

    uint8_t opcode = 0x00;
    uint8_t cycles = 0x00;
};


#endif //NES_EMULATOR_CPU_H
