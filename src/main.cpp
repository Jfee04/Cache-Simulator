#include "cache.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::vector<int> cacheSizes = {1024, 2048, 8192, 65536};
    std::vector<int> blockSizes = {4, 8, 32, 256};
    std::vector<PlacementType> placements = {DM, W2, W4, FA};
    std::vector<WritePolicy> writePolicies = {WB, WT};

    std::vector<std::string> trace = read_trace("input.trace");

    std::ofstream fout("test.result");

    for (int cSize : cacheSizes) {
        for (int bSize : blockSizes) {
            for (auto place : placements) {
                for (auto policy : writePolicies) {
                    Cache cache(cSize, bSize, place, policy);
                    for (const std::string& line : trace) {
                        std::istringstream ss{line};
                        std::string op, addrStr;
                        ss >> op >> addrStr;
                        cache.access(hex_to_int(addrStr), op == "write" || op == "store");
                    }
                    cache.report(fout, cSize);
                }
            }
        }
    }

    fout.close();
    std::cout << "Simulation complete. Output written to test.result.\n";
    return 0;
}



uint32_t hex_to_int(const std::string& hexStr) {
    return static_cast<uint32_t>(std::stoul(hexStr, nullptr, 16));
}

std::vector<std::string> read_trace(const std::string& filename) {
    std::vector<std::string> trace;
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line))
        if (!line.empty()) trace.push_back(line);
    return trace;
}