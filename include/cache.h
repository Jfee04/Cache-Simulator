#pragma once

#include "set.h"

#include <vector>
#include <fstream>

enum PlacementType {DM, W2, W4, FA};

class Cache {

public: 
    std::vector<Set> sets;
    int blockSize, setCount, associativity;
    WritePolicy wp;
    PlacementType pt;
    int bytesFromMem = 0;
    int bytesToMem = 0;
    int hits = 0;
    int requests = 0;

    Cache(int cacheSize, int blockSize, PlacementType pt, WritePolicy wp) : blockSize(blockSize), pt(pt), wp(wp) {};

    void access(uint32_t adress, bool isWrite){};

    void report(std::ofstream& fout, int cacheSize){};

};