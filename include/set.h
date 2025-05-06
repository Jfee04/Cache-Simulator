#pragma once

#include "block.h"

#include <list>

enum WritePolicy {WB, WT};

class Set {

public:
    std::list<Block> blocks;
    size_t associativity;

    Set(size_t a){};

    bool access(uint32_t tag, bool isWrite, WritePolicy wp, int blockSize, int& bytesFromMem, int& bytesToMem, bool& hit) {};

};