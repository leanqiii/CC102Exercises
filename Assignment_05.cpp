#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "Error creating original.txt\n";
        return 1;
    }

    outFile << "One\n";
    outFile << "Two\n";
    outFile << "Three\n";
    outFile << "Four\n";
    outFile << "Five\n";
    outFile << "Six\n";

    outFile.close();

    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "Error opening original.txt\n";
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = 0; j < words.size() - i - 1; j++) {
            if (words[j] > words[j + 1]) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    ofstream outSorted("sorted.txt");

    if (!outSorted) {
        cout << "Error creating sorted.txt\n";
        return 1;
    }

    for (int i = 0; i < words.size(); i++) {
        outSorted << words[i] << endl;
    }

    outSorted.close();

    cout << "Sorting complete!\n";

    return 0;
}
