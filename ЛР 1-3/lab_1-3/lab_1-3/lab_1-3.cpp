#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    ifstream file("FILE1.txt");
    if (!file) {
        cerr << "ERROR!" << endl;
        return 1;
    }

    ofstream outputFile("FILE2.txt");
    if (!outputFile) {
        cerr << "ERROR!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        map<string, int> wordCount;
        stringstream ss(line);
        string word;
        int maxLen = 0, position = 0, index = 0;

        while (ss >> word) {
            wordCount[word]++;
            index++;
            if (word.length() > maxLen) {
                maxLen = word.length();
                position = index;
            }
        }

        bool hasRepeatingWords = false;
        for (auto& pair : wordCount) {
            if (pair.second >= 2) {
                hasRepeatingWords = true;
                break;
            }
        }

        if (hasRepeatingWords) {
            outputFile << line << endl;
            outputFile << "Longest word position: " << position << endl;
        }
    }

    file.close();
    outputFile.close();

    cout << "Completed" << endl;

    return 0;
}
