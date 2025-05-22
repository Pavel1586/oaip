#include <iostream>
using namespace std;

int P(int m, int n) {
    if (n == 1 || m == 1) {
        return 1;
    }
    if (n > m) {
        return P(m, m);
    }
    if (m == n) {
        return P(m, m - 1) + 1;
    }
    return P(m, n - 1) + P(m - n, n);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int m;
    cout << "Введите натуральное число m: ";
    cin >> m;

    if (m <= 0) {
        cout << "Ошибка: m должно быть натуральным (больше 0)." << endl;
        return 1;
    }

    int result = P(m, m);
    cout << "Количество разбиений числа " << m << " равно: " << result << endl;

    return 0;
}