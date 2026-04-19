#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("color.txt");

    if (!outFile) {
        cout << "Error: Could not create color.txt\n";
        return 1;
    }

    outFile << "Red\n";
    outFile << "Blue\n";
    outFile << "Green\n";
    outFile << "Yellow\n";
    outFile << "Purple\n";

    outFile.close();

    ifstream inFile("color.txt");

    if (!inFile) {
        cout << "Error: Could not open color.txt for reading\n";
        return 1;
    }

    ofstream copyFile("color_copy.txt");

    if (!copyFile) {
        cout << "Error: Could not create color_copy.txt\n";
        inFile.close();
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "File copied successfully!\n";

    return 0;
}
