#pragma once
#include <cstdint>

class Block {

public: 
    uint32_t tag;
    bool valid;
    bool dirty;

    Block(uint32_t tag) : tag(tag), valid(false), dirty(false){};

    Block(uint32_t tag, bool valid, bool dirty) : tag(tag), valid(valid), dirty(dirty){};
};