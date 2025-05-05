#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFilename{"test1.trace"};
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile("output.txt");

    // Check if input file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    // Check if output file opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return 1;
    }

    std::string line;

    // Read each line from the input file and write it to the output file
    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    std::cout << "File copied to output.txt successfully." << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
