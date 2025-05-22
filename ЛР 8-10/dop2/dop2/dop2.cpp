#include <iostream>
#include <climits>
using namespace std;

const int MAX_N = 20;
int A[MAX_N][MAX_N];
int group[MAX_N];
int N;
int minCross = INT_MAX;

int countCrossEdges() 
{
    int count = 0;
    for (int i = 0; i < N; ++i) 
    {
        for (int j = i + 1; j < N; ++j) 
        {
            if (A[i][j] == 1 && group[i] != group[j]) 
            {
                count++;
            }
        }
    }
    return count;
}

void divide(int index) 
{
    if (index == N) 
    {
        int cross = countCrossEdges();
        if (cross < minCross) 
        {
            minCross = cross;
        }
        return;
    }

    group[index] = 0;
    divide(index + 1);

    group[index] = 1;
    divide(index + 1);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество стран (N <= " << MAX_N << "): ";
    cin >> N;

    if (N > MAX_N) 
    {
        cout << "Слишком много стран. Увеличьте MAX_N." << endl;
        return 1;
    }

    cout << "Введите матрицу смежности (" << N << " x " << N << "):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    divide(0);

    cout << "Минимальное количество границ между группами: " << minCross << endl;

    return 0;
}