#include <iostream>
#include <fstream>
using namespace std;

void generateNumbers(int A, int pos, int num[], ofstream& fout) 
{
    if (pos == A) 
    {
        for (int i = 0; i < A; ++i) 
        {
            fout << num[i];
        }
        fout << endl;
        return;
    }

    for (int digit = 0; digit <= A; ++digit) 
    {
        num[pos] = digit;
        generateNumbers(A, pos + 1, num, fout);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int A;
    cout << "Введите цифру A (1-9): ";
    cin >> A;

    if (A < 1 || A > 9) 
    {
        cout << "Ошибка: A должна быть от 1 до 9." << endl;
        return 1;
    }

    ofstream fout("conservation.txt");
    if (!fout) 
    {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    int* num = new int[A];

    generateNumbers(A, 0, num, fout);

    delete[] num;
    fout.close();

    cout << "Числа записаны в файл conservation.txt" << endl;
    return 0;
}