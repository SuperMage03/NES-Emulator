//
// Created by liyue on 2022-12-21.
//

#include "CPU.h"
#include "BUS.h"


CPU::CPU() {
    OPCodeTable =
            new Instruction[16 * 16]{
         //                            0                                  1                                  2                                  3                                  4                                  5                                  6                                  7                                  8                                  9                                  A                                  B                                  C                                  D                                  E                                  F
         /* 0 */    { "BRK", &CPU::BRK, &CPU::IMM, 7 },{ "ORA", &CPU::ORA, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 3 },{ "ORA", &CPU::ORA, &CPU::ZP0, 3 },{ "ASL", &CPU::ASL, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PHP", &CPU::PHP, &CPU::IMP, 3 },{ "ORA", &CPU::ORA, &CPU::IMM, 2 },{ "ASL", &CPU::ASL, &CPU::ACC, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ORA", &CPU::ORA, &CPU::ABS, 4 },{ "ASL", &CPU::ASL, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* 1 */    { "BPL", &CPU::BPL, &CPU::REL, 2 },{ "ORA", &CPU::ORA, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ORA", &CPU::ORA, &CPU::ZPX, 4 },{ "ASL", &CPU::ASL, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLC", &CPU::CLC, &CPU::IMP, 2 },{ "ORA", &CPU::ORA, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ORA", &CPU::ORA, &CPU::ABX, 4 },{ "ASL", &CPU::ASL, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
         /* 2 */    { "JSR", &CPU::JSR, &CPU::ABS, 6 },{ "AND", &CPU::AND, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "BIT", &CPU::BIT, &CPU::ZP0, 3 },{ "AND", &CPU::AND, &CPU::ZP0, 3 },{ "ROL", &CPU::ROL, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PLP", &CPU::PLP, &CPU::IMP, 4 },{ "AND", &CPU::AND, &CPU::IMM, 2 },{ "ROL", &CPU::ROL, &CPU::ACC, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "BIT", &CPU::BIT, &CPU::ABS, 4 },{ "AND", &CPU::AND, &CPU::ABS, 4 },{ "ROL", &CPU::ROL, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* 3 */    { "BMI", &CPU::BMI, &CPU::REL, 2 },{ "AND", &CPU::AND, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "AND", &CPU::AND, &CPU::ZPX, 4 },{ "ROL", &CPU::ROL, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SEC", &CPU::SEC, &CPU::IMP, 2 },{ "AND", &CPU::AND, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "AND", &CPU::AND, &CPU::ABX, 4 },{ "ROL", &CPU::ROL, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
         /* 4 */    { "RTI", &CPU::RTI, &CPU::IMP, 6 },{ "EOR", &CPU::EOR, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 3 },{ "EOR", &CPU::EOR, &CPU::ZP0, 3 },{ "LSR", &CPU::LSR, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PHA", &CPU::PHA, &CPU::IMP, 3 },{ "EOR", &CPU::EOR, &CPU::IMM, 2 },{ "LSR", &CPU::LSR, &CPU::ACC, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "JMP", &CPU::JMP, &CPU::ABS, 3 },{ "EOR", &CPU::EOR, &CPU::ABS, 4 },{ "LSR", &CPU::LSR, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* 5 */    { "BVC", &CPU::BVC, &CPU::REL, 2 },{ "EOR", &CPU::EOR, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "EOR", &CPU::EOR, &CPU::ZPX, 4 },{ "LSR", &CPU::LSR, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLI", &CPU::CLI, &CPU::IMP, 2 },{ "EOR", &CPU::EOR, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "EOR", &CPU::EOR, &CPU::ABX, 4 },{ "LSR", &CPU::LSR, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
         /* 6 */    { "RTS", &CPU::RTS, &CPU::IMP, 6 },{ "ADC", &CPU::ADC, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 3 },{ "ADC", &CPU::ADC, &CPU::ZP0, 3 },{ "ROR", &CPU::ROR, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PLA", &CPU::PLA, &CPU::IMP, 4 },{ "ADC", &CPU::ADC, &CPU::IMM, 2 },{ "ROR", &CPU::ROR, &CPU::ACC, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "JMP", &CPU::JMP, &CPU::IND, 5 },{ "ADC", &CPU::ADC, &CPU::ABS, 4 },{ "ROR", &CPU::ROR, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* 7 */    { "BVS", &CPU::BVS, &CPU::REL, 2 },{ "ADC", &CPU::ADC, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ADC", &CPU::ADC, &CPU::ZPX, 4 },{ "ROR", &CPU::ROR, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SEI", &CPU::SEI, &CPU::IMP, 2 },{ "ADC", &CPU::ADC, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ADC", &CPU::ADC, &CPU::ABX, 4 },{ "ROR", &CPU::ROR, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
         /* 8 */    { "???", &CPU::NOP, &CPU::IMP, 2 },{ "STA", &CPU::STA, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "STY", &CPU::STY, &CPU::ZP0, 3 },{ "STA", &CPU::STA, &CPU::ZP0, 3 },{ "STX", &CPU::STX, &CPU::ZP0, 3 },{ "???", &CPU::XXX, &CPU::IMP, 3 },{ "DEY", &CPU::DEY, &CPU::IMP, 2 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "TXA", &CPU::TXA, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "STY", &CPU::STY, &CPU::ABS, 4 },{ "STA", &CPU::STA, &CPU::ABS, 4 },{ "STX", &CPU::STX, &CPU::ABS, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
         /* 9 */    { "BCC", &CPU::BCC, &CPU::REL, 2 },{ "STA", &CPU::STA, &CPU::IZY, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "STY", &CPU::STY, &CPU::ZPX, 4 },{ "STA", &CPU::STA, &CPU::ZPX, 4 },{ "STX", &CPU::STX, &CPU::ZPY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },{ "TYA", &CPU::TYA, &CPU::IMP, 2 },{ "STA", &CPU::STA, &CPU::ABY, 5 },{ "TXS", &CPU::TXS, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "???", &CPU::NOP, &CPU::IMP, 5 },{ "STA", &CPU::STA, &CPU::ABX, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },
         /* A */    { "LDY", &CPU::LDY, &CPU::IMM, 2 },{ "LDA", &CPU::LDA, &CPU::IZX, 6 },{ "LDX", &CPU::LDX, &CPU::IMM, 2 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "LDY", &CPU::LDY, &CPU::ZP0, 3 },{ "LDA", &CPU::LDA, &CPU::ZP0, 3 },{ "LDX", &CPU::LDX, &CPU::ZP0, 3 },{ "???", &CPU::XXX, &CPU::IMP, 3 },{ "TAY", &CPU::TAY, &CPU::IMP, 2 },{ "LDA", &CPU::LDA, &CPU::IMM, 2 },{ "TAX", &CPU::TAX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "LDY", &CPU::LDY, &CPU::ABS, 4 },{ "LDA", &CPU::LDA, &CPU::ABS, 4 },{ "LDX", &CPU::LDX, &CPU::ABS, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
         /* B */    { "BCS", &CPU::BCS, &CPU::REL, 2 },{ "LDA", &CPU::LDA, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "LDY", &CPU::LDY, &CPU::ZPX, 4 },{ "LDA", &CPU::LDA, &CPU::ZPX, 4 },{ "LDX", &CPU::LDX, &CPU::ZPY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },{ "CLV", &CPU::CLV, &CPU::IMP, 2 },{ "LDA", &CPU::LDA, &CPU::ABY, 4 },{ "TSX", &CPU::TSX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 4 },{ "LDY", &CPU::LDY, &CPU::ABX, 4 },{ "LDA", &CPU::LDA, &CPU::ABX, 4 },{ "LDX", &CPU::LDX, &CPU::ABY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
         /* C */    { "CPY", &CPU::CPY, &CPU::IMM, 2 },{ "CMP", &CPU::CMP, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "CPY", &CPU::CPY, &CPU::ZP0, 3 },{ "CMP", &CPU::CMP, &CPU::ZP0, 3 },{ "DEC", &CPU::DEC, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "INY", &CPU::INY, &CPU::IMP, 2 },{ "CMP", &CPU::CMP, &CPU::IMM, 2 },{ "DEX", &CPU::DEX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "CPY", &CPU::CPY, &CPU::ABS, 4 },{ "CMP", &CPU::CMP, &CPU::ABS, 4 },{ "DEC", &CPU::DEC, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* D */    { "BNE", &CPU::BNE, &CPU::REL, 2 },{ "CMP", &CPU::CMP, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "CMP", &CPU::CMP, &CPU::ZPX, 4 },{ "DEC", &CPU::DEC, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLD", &CPU::CLD, &CPU::IMP, 2 },{ "CMP", &CPU::CMP, &CPU::ABY, 4 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "CMP", &CPU::CMP, &CPU::ABX, 4 },{ "DEC", &CPU::DEC, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
         /* E */    { "CPX", &CPU::CPX, &CPU::IMM, 2 },{ "SBC", &CPU::SBC, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "CPX", &CPU::CPX, &CPU::ZP0, 3 },{ "SBC", &CPU::SBC, &CPU::ZP0, 3 },{ "INC", &CPU::INC, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "INX", &CPU::INX, &CPU::IMP, 2 },{ "SBC", &CPU::SBC, &CPU::IMM, 2 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::SBC, &CPU::IMP, 2 },{ "CPX", &CPU::CPX, &CPU::ABS, 4 },{ "SBC", &CPU::SBC, &CPU::ABS, 4 },{ "INC", &CPU::INC, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
         /* F */    { "BEQ", &CPU::BEQ, &CPU::REL, 2 },{ "SBC", &CPU::SBC, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 8 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "SBC", &CPU::SBC, &CPU::ZPX, 4 },{ "INC", &CPU::INC, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SED", &CPU::SED, &CPU::IMP, 2 },{ "SBC", &CPU::SBC, &CPU::ABY, 4 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", &CPU::XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "SBC", &CPU::SBC, &CPU::ABX, 4 },{ "INC", &CPU::INC, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
            };
}

CPU::~CPU() {
    // Disconnects the CPU from the BUS
    bus = nullptr;
    delete[] OPCodeTable;
}

void CPU::setBus(BUS *b) {
    bus = b;
}

uint8_t CPU::read(uint16_t address) {
    return bus->cpuRead(address);
}

void CPU::write(uint16_t address, uint8_t data) {
    return bus->cpuWrite(address, data);
}

void CPU::clock() {
    // Get the next operation
    if (cycles == 0) {
        opcode = read(pc);
        pc++;

        cycles = OPCodeTable[opcode].cycles;

        uint8_t additionalCycle1 = (this->*OPCodeTable[opcode].addressMode)();
        uint8_t additionalCycle2 = (this->*OPCodeTable[opcode].operate)();
        cycles += (additionalCycle1 & additionalCycle2);
    }

    cycles--;
}

void CPU::reset() {
    operandAddr = 0xFFFC;
    uint8_t LL = read(operandAddr);
    uint8_t HH = read(operandAddr + 1);
    pc = (HH << 8) | LL;

    acc = 0;
    xReg = 0;
    yReg = 0;
    stkptr = 0xFD;
    status.BYTE = 0b00100000;

    operandAddr = 0x0000;
    addressOffset = 0x0000;
    fetchedData = 0x00;

    cycles = 8;
}

void CPU::irq() {
    if (!status.FLAG.I) {
        // Write High Byte of pc to stack
        write(0x0100 + stkptr, (pc >> 8) & 0x00FF);
        stkptr--;
        // Write Low Byte of pc to stack
        write(0x0100 + stkptr, pc & 0x00FF);
        stkptr--;

        status.FLAG.B = 0;
        status.FLAG.U = 1;
        status.FLAG.I = 1;

        // Write status to stack
        write(0x0100 + stkptr, status.BYTE);
        stkptr--;

        operandAddr = 0xFFFE;
        uint16_t LL = read(operandAddr);
        uint16_t HH = read(operandAddr + 1);
        pc = (HH << 8) | LL;

        cycles = 7;
    }
}

void CPU::nmi() {
    // Write High Byte of pc to stack
    write(0x0100 + stkptr, (pc >> 8) & 0x00FF);
    stkptr--;
    // Write Low Byte of pc to stack
    write(0x0100 + stkptr, pc & 0x00FF);
    stkptr--;

    status.FLAG.B = 0;
    status.FLAG.U = 1;
    status.FLAG.I = 1;

    // Write status to stack
    write(0x0100 + stkptr, status.BYTE);
    stkptr--;

    operandAddr = 0xFFFA;
    uint16_t LL = read(operandAddr);
    uint16_t HH = read(operandAddr + 1);
    pc = (HH << 8) | LL;

    cycles = 7;
}

uint8_t CPU::fetch() {
    if (OPCodeTable[opcode].addressMode != &CPU::ACC && OPCodeTable[opcode].addressMode != &CPU::IMP) {
        fetchedData = read(operandAddr);
    }
    return fetchedData;
}


// Addressing Modes
uint8_t CPU::ACC() {
    fetchedData = acc;
    return 0;
}

uint8_t CPU::ABS() {
    uint16_t LL = read(pc);
    pc++;
    uint16_t HH = read(pc);
    pc++;

    operandAddr = (HH << 8) | LL;
    return 0;
}

uint8_t CPU::ABX() {
    uint16_t LL = read(pc);
    pc++;
    uint16_t HH = read(pc);
    pc++;

    operandAddr = (HH << 8) | LL;
    operandAddr += xReg;

    // If the operandAddr was being carried, then have 1 more cycle
    return (operandAddr & 0xFF00) == (HH << 8) ? 0 : 1;
}

uint8_t CPU::ABY() {
    uint16_t LL = read(pc);
    pc++;
    uint16_t HH = read(pc);
    pc++;

    operandAddr = (HH << 8) | LL;
    operandAddr += yReg;

    // If the operandAddr was being carried, then have 1 more cycle
    return (operandAddr & 0xFF00) == (HH << 8) ? 0 : 1;
}

uint8_t CPU::IMM() {
    operandAddr = pc;
    pc++;
    return 0;
}

// NOTE: Operate Functions that uses Implied addressing mode ONLY has this addressing mode!
// Thus, the operate functions that uses Implied addressing mode will never use any data
// from the memory, so we don't need to set any operand address as it will not fetch any data.
// Therefore, this addressing mode will simply do nothing.
uint8_t CPU::IMP() {
    return 0;
}

uint8_t CPU::IND() {
    uint16_t LL = read(pc);
    pc++;
    uint16_t HH = read(pc);
    pc++;

    uint16_t effectiveAddr = (HH << 8) | LL;

    // If the page is being crossed, it will just wrap back in the same page
    if (LL == 0x00FF) {
        operandAddr = (read(effectiveAddr & 0xFF00) << 8) | read(effectiveAddr);
    }
    else {
        operandAddr = (read(effectiveAddr + 1) << 8) | read(effectiveAddr);
    }
    return 0;
}

uint8_t CPU::IZX() {
    uint16_t addressAtZP = read(pc);
    pc++;

    uint16_t effectiveAddr = 0x00FF & (addressAtZP + xReg);
    operandAddr = (read(effectiveAddr + 1) << 8) | read(effectiveAddr);
    return 0;
}

uint8_t CPU::IZY() {
    uint16_t addressAtZP = read(pc);
    pc++;

    uint16_t LL = read(0x00FF & addressAtZP);
    uint16_t HH = read(0x00FF & (addressAtZP + 1));

    operandAddr = (HH << 8) | LL;
    operandAddr += yReg;
    return (operandAddr & 0xFF00) == (HH << 8) ? 0 : 1;
}

// Relative MIGHT add 1 or 2 additional cycle.
// HOWEVER, this addressing mode function will not tell
// the program to add additional cycles.
// We will add additional cycles in the operate function
// as we calculate the absolute address for the operand.
uint8_t CPU::REL() {
    addressOffset = read(pc);
    pc++;
    if (addressOffset & 0b10000000)
        addressOffset |= 0xFF00;
    return 0;
}

uint8_t CPU::ZP0() {
    operandAddr = read(pc);
    pc++;
    operandAddr &= 0x00FF;
    return 0;
}

uint8_t CPU::ZPX() {
    operandAddr = read(pc);
    pc++;
    operandAddr = (operandAddr + xReg) & 0x00FF;
    return 0;
}

uint8_t CPU::ZPY() {
    operandAddr = read(pc);
    pc++;
    operandAddr = (operandAddr + yReg) & 0x00FF;
    return 0;
}


// Operate Functions
uint8_t CPU::ADC() {
    fetch();
    uint16_t result = (uint16_t)acc + (uint16_t)fetchedData + (uint16_t)status.FLAG.C;

    uint8_t accSign = (acc & 0b10000000) > 0;
    uint8_t fetchedDataSign = (fetchedData & 0b10000000) > 0;
    uint8_t resultSign = (result & 0b10000000) > 0;

    status.FLAG.C = (result & 0xFF00) > 0;
    status.FLAG.Z = (result & 0x00FF) == 0;
    status.FLAG.N = resultSign;
    status.FLAG.V = (~(accSign ^ fetchedDataSign) & (accSign ^ result));

    acc = result & 0x00FF;
    return 1;
}


uint8_t CPU::AND() {
    fetch();
    acc &= fetchedData;

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;

    return 1;
}

uint8_t CPU::ASL() {
    fetch();
    uint8_t result = ((uint16_t)fetchedData << 1) & 0x00FF;

    status.FLAG.C = (fetchedData & 0b10000000) > 0;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;

    if (OPCodeTable[opcode].addressMode == &CPU::ACC) {
        acc = result;
    }
    else {
        write(operandAddr, result);
    }

    return 0;
}

uint8_t CPU::BCC() {
    if (!status.FLAG.C) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}


uint8_t CPU::BCS() {
    if (status.FLAG.C) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::BEQ() {
    if (status.FLAG.Z) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::BIT() {
    fetch();
    uint8_t result = acc & fetchedData;

    status.FLAG.Z = result == 0;
    status.FLAG.V = (result & 0b01000000) > 0;
    status.FLAG.N = (result & 0b10000000) > 0;

    return 0;
}

uint8_t CPU::BMI() {
    if (status.FLAG.N) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}


uint8_t CPU::BNE() {
    if (!status.FLAG.Z) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::BPL() {
    if (!status.FLAG.N) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::BRK() {
    // Second Byte is a padding byte
    pc++;

    // Write High Byte of pc to stack
    write(0x0100 + stkptr, (pc >> 8) & 0x00FF);
    stkptr--;
    // Write Low Byte of pc to stack
    write(0x0100 + stkptr, pc & 0x00FF);
    stkptr--;

    status.FLAG.B = 1;
    // Write status to stack
    write(0x0100 + stkptr, status.BYTE);
    stkptr--;
    status.FLAG.B = 0;

    operandAddr = 0xFFFE;
    uint16_t LL = read(operandAddr);
    uint16_t HH = read(operandAddr + 1);
    pc = (HH << 8) | LL;

    return 0;
}

uint8_t CPU::BVC() {
    if (!status.FLAG.V) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::BVS() {
    if (status.FLAG.V) {
        operandAddr = pc + addressOffset;
        cycles++; // Branch Succeeded

        // Page Flipped
        if ((operandAddr & 0xFF00) != (pc & 0xFF00)) {
            cycles++;
        }
        pc = operandAddr;
    }
    return 0;
}

uint8_t CPU::CLC() {
    status.FLAG.C = 0;
    return 0;
}

uint8_t CPU::CLD() {
    status.FLAG.D = 0;
    return 0;
}

uint8_t CPU::CLI() {
    status.FLAG.I = 0;
    return 0;
}

uint8_t CPU::CLV() {
    status.FLAG.V = 0;
    return 0;
}

uint8_t CPU::CMP() {
    fetch();
    uint8_t result = ((uint16_t)acc - (uint16_t)fetchedData) & 0x00FF;

    status.FLAG.C = acc >= fetchedData;
    status.FLAG.Z = acc == fetchedData;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::CPX() {
    fetch();
    uint8_t result = ((uint16_t)xReg - (uint16_t)fetchedData) & 0x00FF;

    status.FLAG.C = xReg >= fetchedData;
    status.FLAG.Z = xReg == fetchedData;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::CPY() {
    fetch();
    uint8_t result = ((uint16_t)yReg - (uint16_t)fetchedData) & 0x00FF;

    status.FLAG.C = yReg >= fetchedData;
    status.FLAG.Z = yReg == fetchedData;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::DEC() {
    fetch();
    uint8_t result = ((uint16_t)fetchedData - 1) & 0x00FF;

    write(operandAddr, result);
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::DEX() {
    fetch();
    uint8_t result = ((uint16_t)xReg - 1) & 0x00FF;

    xReg = result;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::DEY() {
    fetch();
    uint8_t result = ((uint16_t)yReg - 1) & 0x00FF;

    yReg = result;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::EOR() {
    fetch();
    acc ^= fetchedData;

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;
    return 1;
}

uint8_t CPU::INC() {
    fetch();
    uint8_t result = ((uint16_t)fetchedData + 1) & 0x00FF;

    write(operandAddr, result);
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::INX() {
    fetch();
    uint8_t result = ((uint16_t)xReg + 1) & 0x00FF;

    xReg = result;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::INY() {
    fetch();
    uint8_t result = ((uint16_t)yReg + 1) & 0x00FF;

    yReg = result;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::JMP() {
    pc = operandAddr;
    return 0;
}

uint8_t CPU::JSR() {
    // Need to store pc - 1;
    pc--;

    // Write High Byte of pc to stack
    write(0x0100 + stkptr, (pc >> 8) & 0x00FF);
    stkptr--;
    // Write Low Byte of pc to stack
    write(0x0100 + stkptr, pc & 0x00FF);
    stkptr--;

    pc = operandAddr;
    return 0;
}

uint8_t CPU::LDA() {
    fetch();
    acc = fetchedData;

    status.FLAG.Z = acc == 0;
    status.FLAG.C = (acc & 0b10000000) > 0;

    return 1;
}

uint8_t CPU::LDX() {
    fetch();
    xReg = fetchedData;

    status.FLAG.Z = xReg == 0;
    status.FLAG.C = (xReg & 0b10000000) > 0;

    return 1;
}

uint8_t CPU::LDY() {
    fetch();
    yReg = fetchedData;

    status.FLAG.Z = yReg == 0;
    status.FLAG.C = (yReg & 0b10000000) > 0;

    return 1;
}

uint8_t CPU::LSR() {
    fetch();
    uint8_t result = ((uint16_t)fetchedData << 1) & 0x00FF;

    status.FLAG.C = (fetchedData & 0b00000001) > 0;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;

    if (OPCodeTable[opcode].addressMode == &CPU::ACC) {
        acc = result;
    }
    else {
        write(operandAddr, result);
    }

    return 0;
}

// NOP does nothing.
// BUT, in some illegal opcode, it has the possibility to add 1 more cycle.
uint8_t CPU::NOP() {
    return 1;
}

uint8_t CPU::ORA() {
    fetch();
    acc |= fetchedData;

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;
    return 1;
}

uint8_t CPU::PHA() {
    write(0x0100 + stkptr, acc);
    stkptr--;
    return 0;
}

uint8_t CPU::PHP() {
    status.FLAG.B = 1;
    status.FLAG.U = 1;

    write(0x0100 + stkptr, status.BYTE);
    stkptr--;

    status.FLAG.B = 0;
    status.FLAG.U = 0;
    return 0;
}

uint8_t CPU::PLA() {
    stkptr++;
    acc = read(0x0100 + stkptr);

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;

    return 0;
}

uint8_t CPU::PLP() {
    stkptr++;
    STATUS statusFromStack = { read(0x0100 + stkptr) };
    statusFromStack.FLAG.B = 0;
    statusFromStack.FLAG.U = 0;

    status.BYTE |= statusFromStack.BYTE;
    return 0;
}

uint8_t CPU::ROL() {
    fetch();
    uint8_t result = (((uint16_t)fetchedData << 1) | status.FLAG.C) & 0x00FF;

    status.FLAG.C = (fetchedData & 0b10000000) > 0;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;

    if (OPCodeTable[opcode].addressMode == &CPU::ACC) {
        acc = result;
    }
    else {
        write(operandAddr, result);
    }

    return 0;
}

uint8_t CPU::ROR() {
    fetch();
    uint8_t result = ((uint8_t)status.FLAG.C << 7) | (fetchedData >> 1);

    status.FLAG.C = (fetchedData & 0b00000001) > 0;
    status.FLAG.Z = result == 0;
    status.FLAG.N = (result & 0b10000000) > 0;

    if (OPCodeTable[opcode].addressMode == &CPU::ACC) {
        acc = result;
    }
    else {
        write(operandAddr, result);
    }

    return 0;
}

uint8_t CPU::RTI() {
    stkptr++;
    status.BYTE = read(0x0100 + stkptr);
    status.FLAG.B = 0;
    status.FLAG.U = 0;


    stkptr++;
    uint16_t LL = read(0x0100 + stkptr);
    stkptr++;
    uint16_t HH = read(0x0100 + stkptr);
    pc = (HH << 8) | LL;

    return 0;
}

uint8_t CPU::RTS() {
    // Pulls back the normal pc from stack
    stkptr++;
    uint16_t LL = read(0x0100 + stkptr);
    stkptr++;
    uint16_t HH = read(0x0100 + stkptr);

    pc = (HH << 8) | LL;
    return 0;
}

uint8_t CPU::SBC() {
    fetch();

    uint16_t inverted = (uint16_t)fetchedData ^ 0x00FF;
    uint16_t result = (uint16_t)acc + inverted + (uint16_t)status.FLAG.C;

    uint8_t accSign = (acc & 0b10000000) > 0;
    uint8_t invertedSign = (inverted & 0b10000000) > 0;
    uint8_t resultSign = (result & 0b10000000) > 0;

    status.FLAG.C = (result & 0xFF00) > 0;
    status.FLAG.Z = (result & 0x00FF) == 0;
    status.FLAG.N = resultSign;
    status.FLAG.V = (~(accSign ^ invertedSign) & (accSign ^ result));

    acc = result & 0x00FF;
    return 1;
}

uint8_t CPU::SEC() {
    status.FLAG.C = 1;
    return 0;
}

uint8_t CPU::SED() {
    status.FLAG.D = 1;
    return 0;
}

uint8_t CPU::SEI() {
    status.FLAG.I = 1;
    return 0;
}

uint8_t CPU::STA() {
    write(operandAddr, acc);
    return 0;
}

uint8_t CPU::STX() {
    write(operandAddr, xReg);
    return 0;
}

uint8_t CPU::STY() {
    write(operandAddr, yReg);
    return 0;
}

uint8_t CPU::TAX() {
    xReg = acc;

    status.FLAG.Z = xReg == 0;
    status.FLAG.N = (xReg & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::TAY() {
    yReg = acc;

    status.FLAG.Z = yReg == 0;
    status.FLAG.N = (yReg & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::TSX() {
    xReg = stkptr;

    status.FLAG.Z = xReg == 0;
    status.FLAG.N = (xReg & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::TXA() {
    acc = xReg;

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;
    return 0;
}

uint8_t CPU::TXS() {
    stkptr = xReg;
    return 0;
}

uint8_t CPU::TYA() {
    acc = yReg;

    status.FLAG.Z = acc == 0;
    status.FLAG.N = (acc & 0b10000000) > 0;
    return 0;
}

// This is the placeholder operate function for illegal opcodes
uint8_t CPU::XXX() {
    return 0;
}
