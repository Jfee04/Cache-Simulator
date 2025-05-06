#pragma once
#include <cstdint>

class Block {

public: 
    uint32_t tag;
    bool valid = false;
    bool dirty = false;

};