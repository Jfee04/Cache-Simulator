#include "cache.h"

#include <string>
#include <iostream>
#include <iomanip>

Cache::Cache(int cacheSize, int blockSize, PlacementType pt, WritePolicy wp) : blockSize(blockSize), pt(pt), wp(wp) {
    switch (pt) {
        case DM: 
            associativity = 1; 
            break;
        case W2:
            associativity = 2; 
            break;
        case W4: 
            associativity = 4; 
            break;
        case FA: 
            associativity = cacheSize / blockSize; 
            break;
    }
}

void Cache::access(uint32_t adress, bool isWrite){
    requests++;
    uint32_t blockAdr = adress / blockSize;
    uint32_t index = (pt == FA) ? 0 : blockAdr % setCount;
    uint32_t tag = blockAdr / ((pt == FA) ? 1 : setCount);

    bool hit = sets[index].access(tag, isWrite, wp, blockSize, bytesFromMem, bytesToMem);
    if (hit) hits++;

};

void Cache::report(std::ofstream& fout, int cacheSize){
    std::string placementStr = (pt == DM) ? "DM" : (pt == W2) ? "2W" : (pt == W4) ? "4W" : "FA";
    std::string policyStr = (wp == WB) ? "WB" : "WT";
    double hitRate = (requests > 0) ? (double)hits / requests : 0.0;

    fout << cacheSize << " "
        << blockSize << " "
        << placementStr << " "
        << associativity << " "
        << policyStr << " "
        << requests << " "
        << hits << " "
        << std::fixed << std::setprecision(2) << hitRate << " "
        << bytesFromMem << " "
        << bytesToMem << "\n";
}
