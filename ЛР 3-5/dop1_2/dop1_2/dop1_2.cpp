#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <windows.h>
using namespace std;

enum Destinations
{
    minsk,
    brest,
    gomel,
    mogilev,
    polotsk
};

union ContestOrTuition
{
    char ArrivalTime[4];
    char DepartureTime[4];
};

struct RailwayStation
{
    int trainNumber;
    int followingDays;
    char address[50];
    Destinations destinations;
    ContestOrTuition data;
    bool isCompetition;
};

void newTrain(RailwayStation*& records, int& size);
void allTrains(RailwayStation* records, int size);
void deleteTrain(RailwayStation*& records, int& size);
void trainSearch(RailwayStation* records, int size);
void saveToFile(RailwayStation* records, int size);
void loadFromFile(RailwayStation*& records, int& size);

void menu(RailwayStation*& records, int& size)
{
    int choice;
    do
    {
        cout << "1) Добавить поезд" << endl;
        cout << "2) Показать все поезда" << endl;
        cout << "3) Удалить поезд" << endl;
        cout << "4) Найти поезд" << endl;
        cout << "5) Сохранить в файл" << endl;
        cout << "6) Загрузить из файла" << endl;
        cout << "7) Выйти" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: 
            newTrain(records, size);
            break;
        case 2: 
            allTrains(records, size);
            break;
        case 3: 
            deleteTrain(records, size);
            break;
        case 4: 
            trainSearch(records, size);
            break;
        case 5: 
            saveToFile(records, size);
            break;
        case 6: 
            loadFromFile(records, size);
            break;
        case 7: 
            cout << "Выход...";
            exit(0);
        default: 
            cout << "Некорректный выбор!" << endl;
            break;
        }
    } while (true);
}

void newTrain(RailwayStation*& records, int& size)
{
    RailwayStation* temp = new RailwayStation[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = records[i];
    }

    cout << "Введите номер поезда:" << endl;
    cin >> temp[size].trainNumber;
    cout << "Введите количество дней следования:" << endl;
    cin >> temp[size].followingDays;

    int choice;
    cout << "Выберите пункт назначения:" << endl;
    cout << "0) Минск" << endl;
    cout << "1) Брест" << endl;
    cout << "2) Гомель" << endl;
    cout << "3) Могилев" << endl;
    cout << "4) Полоцк" << endl;
    cin >> choice;
    temp[size].destinations = static_cast<Destinations>(choice);

    cout << "Что вы хотите ввести? (1 - Время прибытия, 2 - Время отправления):" << endl;
    cin >> choice;
    if (choice == 1)
    {
        temp[size].isCompetition = true;
        cout << "Введите время прибытия (Пример: 12:00): ";
        cin >> temp[size].data.ArrivalTime;
    }
    else
    {
        temp[size].isCompetition = false;
        cout << "Введите время отправления:" << endl;
        cin >> temp[size].data.DepartureTime;
    }

    delete[] records;
    records = temp;
    size++;
}

void allTrains(RailwayStation* records, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Номер поезда: " << records[i].trainNumber << endl;
        cout << "Дни следования: " << records[i].followingDays << endl;
        cout << "Пункт назначения: " << records[i].destinations << endl;

        if (records[i].isCompetition)
        {
            cout << "Время прибытия: " << records[i].data.ArrivalTime << endl;
        }
        else
        {
            cout << "Время отправления: " << records[i].data.DepartureTime << endl;
        }
        cout << endl;
    }
}

void deleteTrain(RailwayStation*& records, int& size)
{
    int index;

    for (int i = 0; i < size; i++)
    {
        cout << i << ")"<< "Номер поезда: " << records[i].trainNumber << endl;
    }

    cout << "Введите индекс поезда для удаления: ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "Некорректный индекс!" << endl;
        return;
    }
    RailwayStation* temp = new RailwayStation[size - 1];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != index)
        {
            temp[j++] = records[i];
        }
    }
    delete[] records;
    records = temp;
    size--;
}

void trainSearch(RailwayStation* records, int size)
{
    int searchNumber = 0; 
    cout << "Введите номер поезда для поиска: ";
    cin >> searchNumber;
    for (int i = 0; i < size; i++)
    {
        if (records[i].trainNumber == searchNumber)
        {
            cout << "Номер поезда: " << records[i].trainNumber << endl;
            cout << "Дни следования: " << records[i].followingDays << endl;
            cout << "Пункт назначения: " << records[i].destinations << endl;

            if (records[i].isCompetition)
            {
                cout << "Время прибытия: " << records[i].data.ArrivalTime << endl;
            }
            else
            {
                cout << "Время отправления: " << records[i].data.DepartureTime << endl;
            }
            cout << endl;
        }
    }
}

void saveToFile(RailwayStation* records, int size)
{
    ofstream file("trains.txt");
    if (!file)
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file << "Номер поезда: " << records[i].trainNumber << endl;
        file << "Дни следования: " << records[i].followingDays << endl;
        file << "Пункт назначения: " << records[i].destinations << endl;
        if (records[i].isCompetition)
        {
            file << "Время прибытия: " << records[i].data.ArrivalTime << endl;
        }
        else
        {
            file << "Время отправления: " << records[i].data.DepartureTime << endl;
        }
        file << "------------------------------------------" << endl;
    }
    file.close();
    cout << "Данные сохранены!" << endl;
}

void loadFromFile(RailwayStation*& records, int& size)
{

    ifstream file("trains.txt");
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
    cout << "Данные загружены!" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 0;
    RailwayStation* records = nullptr;
    menu(records, size);
    delete[] records;
    return 0;
}