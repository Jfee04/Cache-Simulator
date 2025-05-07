#include "cache.h"

#include <string>
#include <iostream>
#include <iomanip>

Cache::Cache(int cacheSize, int blockSize, PlacementType pt, WritePolicy wp) : blockSize(blockSize), pt(pt), wp(wp) {
    //std::cout << "cache constrct";
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

    setCount = cacheSize / (blockSize * associativity);
    
    // Initialize sets
    sets.reserve(setCount);
    for (int i = 0; i < setCount; ++i) {
        sets.emplace_back(associativity);  // Create Set with correct associativity
    }
   // std::cout << "Cache constructed: " << setCount << " sets, associativity = " << associativity << "\n";

}

void Cache::access(uint32_t adress, bool isWrite){
    //std::cout << "cache access";

    requests++;
    uint32_t blockAdr = adress / blockSize;
    uint32_t index = (pt == FA) ? 0 : blockAdr % setCount;
    uint32_t tag = blockAdr / ((pt == FA) ? 1 : setCount);

    bool hit = sets[index].access(tag, isWrite, wp, blockSize, bytesFromMem, bytesToMem);
    //std::cout << "access complete";

    if (hit) hits++;

};

void Cache::report(std::ofstream& fout, int cacheSize){
    //std::cout << "cache report";

    std::string placementStr = (pt == DM) ? "DM" : (pt == W2) ? "2W" : (pt == W4) ? "4W" : "FA";
    std::string policyStr = (wp == WB) ? "WB" : "WT";
    double hitRate = (requests > 0) ? (double)hits / requests : 0.0;

    fout << cacheSize << "\t"
        << blockSize << "\t"
        << placementStr << "\t"
        << associativity << "\t"
        << policyStr << "\t"
        << requests << "\t"
        << hits << "\t"
        << std::fixed << std::setprecision(2) << hitRate << "\t"
        << bytesFromMem << "\t"
        << bytesToMem << "\n";
}
