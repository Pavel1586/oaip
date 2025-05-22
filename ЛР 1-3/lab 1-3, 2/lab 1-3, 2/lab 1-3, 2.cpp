#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    string input;
    cout << "Enter the line: ";
    getline(cin, input);

    ofstream outFile("input.txt");
    if (!outFile) {
        cerr << "ERROR!" << endl;
        return 1;
    }
    outFile << input;
    outFile.close();

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "ERROR!" << endl;
        return 1;
    }

    string line;
    getline(inFile, line);
    inFile.close();

    stringstream ss(line);
    string word;

    while (ss >> word)
        if (word.find('x') != string::npos);
    
    cout << "Words containing the letter 'x':"<< word << endl;

    return 0;
}
