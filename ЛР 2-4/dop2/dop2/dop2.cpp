#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;

struct TRAIN
{
	char destination[50];
	int trainNumber;
	char deparureTime[10];
};

void trainData(TRAIN*& records, int& size);
void listTrains(TRAIN* records, int size);
void trainSearch(TRAIN* records, int size);

void menu(TRAIN*& records, int& size)
{
    int choice = 0;
	cout << "1) Ввести данные о поездах:" << endl;
	cout << "2) Вывести список поездов:" << endl;
	cout << "3) Найти поезда, отправляющиеся после указанного времени:" << endl;
	cout << "4) Выход из программы:" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        trainData(records, size);
        break;
    case 2:
        listTrains(records, size);
        break;
    case 3:
        trainSearch(records, size);
        break;

    case 4:
        std::cout << "Выход из программы...\n";
        return;
        break;
    default:
        std::cout << "Некорректный ввод! Попробуйте снова.\n";
        return;
    }
}

void trainData(TRAIN*& records, int& size)
{
    TRAIN* temp = new TRAIN[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = records[i];
    }
    cout << "Введите название пункта назначения: " << endl;
    cin >> temp[size].destination;
    cout << "Номер поезда: " << endl;
    cin >> temp[size].trainNumber;
    cout << "Время отправления: " << endl;
    cin >> temp[size].deparureTime;

    cout << endl;
    delete[] records;
    records = temp;
    size++;
}

bool compareTrains(const TRAIN& a, const TRAIN& b) {
    return strcmp(a.destination, b.destination) < 0;
}

void listTrains(TRAIN* records, int size) 
{
    sort(records, records + size, compareTrains);

    cout << "-----------------------------" << endl;
    cout << "Отсортированные поезда:\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "Пункт назначения: " << records[i].destination
            << ", Номер поезда: " << records[i].trainNumber
            << ", Время отправления: " << records[i].deparureTime << endl;
    }
    cout << "-----------------------------" << endl;
}

void trainSearch(TRAIN* records, int size)
{
    string time;
    cout << "Введите время отправденяи поезда: " << endl;
    cin >> time;

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (records[i].deparureTime > time)
        {
            found = false;
            cout << "-----------------------------" << endl;
            cout << "Пунк назначения: " << records[i].destination << endl;
            cout << "Номер поезда: " << records[i].trainNumber << endl;
            cout << "Время отправления: " << records[i].deparureTime << endl;
            cout << "-----------------------------" << endl;
        }
    }

    if (!found)
    {
        cout << "Нет поездов, отправляющихся позже " << time << "." << endl;
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");
    int size = 0;
    TRAIN* records = nullptr;

    while (1)
    {
        menu(records, size);
    }

	return 0;
}