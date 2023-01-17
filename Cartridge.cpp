//
// Created by liyue on 2023-01-06.
//

#include "Cartridge.h"

Cartridge::Cartridge(const std::string &iNESPath) {
    std::ifstream ifs;
    ifs.open(iNESPath, std::ifstream::binary);
    // Read 16 bytes of data, each char* chunk is 1 byte.
    ifs.read((char*)&header, sizeof(Header));

    mapperNum = ((uint8_t)(header.mapperNumHH) << 4) | (uint8_t)(header.mapperNumLL);

    if (header.hasTrainer) {
        trainer = new uint8_t[512];
        ifs.read((char*)trainer, sizeof(uint8_t) * 512);
    }
    else {
        ifs.seekg(512, std::ios_base::cur);
    }

    // iNES2 implementation, maybe later
//    if (header.isNES2) {
//
//    }
//    else {
//
//    }
    prgROM = new uint8_t[16384 * header.prgROMChunk];
    chrROM = new uint8_t[8192  * header.chrROMChunk];


}

Cartridge::~Cartridge() {
    delete[] trainer;
    delete[] prgROM;
    delete[] chrROM;
}
