#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <windows.h>
using namespace std;

enum Specialties 
{
    programming,
    medicine,
    engineering,
    economy,
    history
};

union ContestOrTuition 
{
    unsigned int lastYearCompetition;
    double tuitionFees;
};

struct University 
{
    char nameUniversity[50];
    char address[50];
    Specialties specialties;
    ContestOrTuition data;
    bool isCompetition;
};

void newUniversity(University*& records, int& size);
void allUniversities(University* records, int size);
void deleteUniversity(University*& records, int& size);
void universitySearch(University* records, int size);
void saveToFile(University* records, int size);
void loadFromFile(University*& records, int& size);

void menu(University*& records, int& size) 
{
    int choice;
    do 
    {
        cout << "1) Добавить новый вуз" << endl;
        cout << "2) Показать все вузы" << endl;
        cout << "3) Удалить вуз" << endl;
        cout << "4) Найти вуз" << endl;
        cout << "5) Сохранить в файл" << endl;
        cout << "6) Загрузить из файла" << endl;
        cout << "7) Выйти" << endl;
        cin >> choice;

        switch (choice) 
        {
        case 1: newUniversity(records, size); 
            break;
        case 2: allUniversities(records, size); 
            break;
        case 3: deleteUniversity(records, size); 
            break;
        case 4: universitySearch(records, size); 
            break;
        case 5: saveToFile(records, size); 
            break;
        case 6: loadFromFile(records, size); 
            break;
        case 7: cout << "Выход..."; 
            exit(0);
        default: cout << "Некорректный выбор!" << endl; 
            break;
        }
    } while (true);
}

void newUniversity(University*& records, int& size) 
{
    University* temp = new University[size + 1];
    for (int i = 0; i < size; i++) 
    {
        temp[i] = records[i];
    }

    cout << "Введите название вуза:"<<endl;
    cin >> temp[size].nameUniversity;
    cout << "Введите адрес университета:"<<endl;
    cin >> temp[size].address;

    int choice;
    cout << "Выберите специальность:" << endl;
    cout << "0) программирование" << endl;
    cout << "1) медицина" << endl;
    cout << "2) инженерия" << endl;
    cout << "3) экономика" << endl;
    cout << "4) история" << endl;
    cin >> choice;
    temp[size].specialties = static_cast<Specialties>(choice);

    cout << "Что вы хотите ввести? (1 - конкурс, 2 - стоимость):"<<endl;
    cin >> choice;
    if (choice == 1) 
    {
        temp[size].isCompetition = true;
        cout << "Введите конкурс прошлого года (1-15): ";
        cin >> temp[size].data.lastYearCompetition;
    }
    else 
    {
        temp[size].isCompetition = false;
        cout << "Введите стоимость обучения:"<<endl;
        cin >> temp[size].data.tuitionFees;
    }

    delete[] records;
    records = temp;
    size++;
}

void allUniversities(University* records, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Название университета: " << records[i].nameUniversity << endl;
        cout << "Адресс университета: " << records[i].address << endl;
        cout << "Специальность: " << records[i].specialties << endl;

        if (records[i].isCompetition) 
        {
            cout << "Конкурс прошлого года: " << records[i].data.lastYearCompetition << endl;
        }
        else 
        {
            cout << "Стоимость обучения: " << records[i].data.tuitionFees << endl;
        }
        cout << endl;
    }
}

void deleteUniversity(University*& records, int& size) 
{
    int index;
    cout << "Введите индекс вуза для удаления: ";
    cin >> index;
    if (index < 0 || index >= size) 
    {
        cout << "Некорректный индекс!" << endl;
        return;
    }
    University* temp = new University[size - 1];
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

void universitySearch(University* records, int size) 
{
    char searchName[50];
    cout << "Введите название вуза для поиска: ";
    cin >> searchName;
    for (int i = 0; i < size; i++) 
    {
        if (strcmp(records[i].nameUniversity, searchName) == 0) 
        {
            cout << "Название университета: " << records[i].nameUniversity << endl;
            cout << "Адресс университета: " << records[i].address << endl;
            cout << "Специальность: " << records[i].specialties << endl;

            if (records[i].isCompetition) 
            {
                cout << "Конкурс прошлого года: " << records[i].data.lastYearCompetition << endl;
            }
            else 
            {
                cout << "Стоимость обучения: " << records[i].data.tuitionFees << endl;
            }
            cout << endl;
        }
    }
}

void saveToFile(University* records, int size) 
{
    ofstream file("universities.txt");
    if (!file) 
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        file <<"Название университета: " << records[i].nameUniversity << endl;
        file << "Адресс университета: " << records[i].address << endl;
        file << "Специальность: " << records[i].specialties << endl;
        if (records[i].isCompetition)
        {
            file << "Конкурс прошлого года: " << records[i].data.lastYearCompetition << endl;
        }
        else
        {
            file << "Стоимость обучения: " << records[i].data.tuitionFees << endl;
        }
        file << "------------------------------------------" << endl;
    }
    file.close();
    cout << "Данные сохранены!" << endl;
}

void loadFromFile(University*& records, int& size) 
{

    ifstream file("universities.txt");
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
    University* records = nullptr;
    menu(records, size);
    delete[] records;
    return 0;
}
