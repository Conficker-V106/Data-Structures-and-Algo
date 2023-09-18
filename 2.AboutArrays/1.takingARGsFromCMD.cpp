#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Please Follow the instructions(Syntax) Below: \nProgramName(.exe) inputfile outputfile\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Error opening input file: " << argv[1] << "\n";
        return 1; 
    }

    ostringstream outputStream;
    outputStream << inputFile.rdbuf();

    inputFile.close();

    std::ofstream outputFile(argv[2]);
    if (!outputFile) {
        cout << "Error opening output file: " << argv[2] << "\n";
        return 1; 
    }

    outputFile << outputStream.str();
    outputFile.close();

    return 0; 
}
