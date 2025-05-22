#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sys/stat.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    auto getFileSize = [](const string& filename) -> int {
        struct stat statBuf;
        if (stat(filename.c_str(), &statBuf) != 0) {
            cerr << "ERROR!: " << filename << endl;
            return -1;
        }
        return statBuf.st_size;
        };

    ifstream file("FILE1.txt");
    if (!file) {
        cerr << "Ошибка открытия FILE1.txt!" << endl;
        return 1;
    }

    int size1 = getFileSize("FILE1.txt");
    if (size1 == -1) return 1;

    ofstream outputFile("FILE2.txt");
    if (!outputFile) {
        cerr << "Ошибка создания FILE2.txt!" << endl;
        return 1;
    }

    string line;
    int index = 0;

    while (getline(file, line))
    {
        index++;
        if (index % 2 == 0)
        {
            outputFile << line << endl;
        }
    }

    file.close();
    outputFile.close();

    int size2 = getFileSize("FILE2.txt");
    if (size2 == -1) return 1;

    cout << "Обработка завершена." << endl;
    cout << "Размер FILE1.txt: " << size1 << " байт" << endl;
    cout << "Размер FILE2.txt: " << size2 << " байт" << endl;

    return 0;
}
