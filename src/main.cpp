#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFilename{"test1.trace"};
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    std::cout << "File copied to output.txt successfully." << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
