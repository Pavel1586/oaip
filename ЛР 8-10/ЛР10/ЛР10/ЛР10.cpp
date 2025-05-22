#include <iostream>
using namespace std;

int S(int x) {
    if (x > 100) {
        return x + 10;
    }
    else {
        return S(S(x + 4));
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int x;
    cout << "Введите неотрицательное целое число x: ";
    cin >> x;

    if (x < 0) {
        cout << "Ошибка: x должно быть неотрицательным." << endl;
        return 1;
    }

    int result = S(x);
    cout << "S(" << x << ") = " << result << endl;

    return 0;
}