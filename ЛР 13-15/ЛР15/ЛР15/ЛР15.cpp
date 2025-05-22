#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Пузырьковая сортировка по убыванию
void bubbleSortDesc(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Быстрая сортировка (Хоара) по убыванию
void quickSortDesc(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[(low + high) / 2];
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j) quickSortDesc(arr, low, j);
    if (i < high) quickSortDesc(arr, i, high);
}

// Генерация массива случайных чисел
void generateArray(int arr[], int size, int maxVal = 10000) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % maxVal;
}

// Получение максимального элемента массива
int getMaxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Создание массива C
int createC(int A[], int sizeA, int maxB, int*& C) {
    int count = 0;
    // Первый проход — считаем нужный размер
    for (int i = 0; i < sizeA; ++i)
        if (A[i] < maxB)
            count++;

    C = new int[count];
    int index = 0;
    for (int i = 0; i < sizeA; ++i)
        if (A[i] < maxB)
            C[index++] = A[i];

    return count;
}

int main() {
    srand(time(nullptr));
    int sizes[] = { 1000, 2000, 3000, 4000, 5000 };

    for (int s = 0; s < 5; ++s) {
        int size = sizes[s];
        cout << "\nArray size: " << size << endl;

        int* A = new int[size];
        int* B = new int[size];

        generateArray(A, size);
        generateArray(B, size);

        int maxB = getMaxElement(B, size);

        int* C = nullptr;
        int sizeC = createC(A, size, maxB, C);

        // Копии массива для сортировок
        int* C_bubble = new int[sizeC];
        int* C_quick = new int[sizeC];
        for (int i = 0; i < sizeC; ++i) {
            C_bubble[i] = C[i];
            C_quick[i] = C[i];
        }

        // Bubble Sort
        auto start_bubble = high_resolution_clock::now();
        bubbleSortDesc(C_bubble, sizeC);
        auto end_bubble = high_resolution_clock::now();

        // Quick Sort
        auto start_quick = high_resolution_clock::now();
        quickSortDesc(C_quick, 0, sizeC - 1);
        auto end_quick = high_resolution_clock::now();

        auto time_bubble = duration_cast<milliseconds>(end_bubble - start_bubble).count();
        auto time_quick = duration_cast<milliseconds>(end_quick - start_quick).count();

        cout << "Bubble Sort Time: " << time_bubble << " ms" << endl;
        cout << "Quick Sort Time: " << time_quick << " ms" << endl;

        delete[] A;
        delete[] B;
        delete[] C;
        delete[] C_bubble;
        delete[] C_quick;
    }

    return 0;
}