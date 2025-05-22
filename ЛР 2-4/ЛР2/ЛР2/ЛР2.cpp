#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct teachers
{
    char teacher_last_name[30];
    char name_of_the_exam[30];
    int exam_date;
    char choosing_by_last_name[30];
};

void addTeacher(teachers*& records, int& size);
void list_of_teachers(teachers* records, int size);
void Last_Name_Search(teachers* records, int size, char search_name[]);
void saving_to_file(teachers* records, int size);
void data_output(teachers* records);
void deleteExam(teachers*& records, int& size);

void menu(teachers*& records, int& size)
{
    int choice;
    cout << "1)Добавить преподавателя" << endl;
    cout << "2)Показать всех преподавателей" << endl;
    cout << "3)Поиск по фамилии" << endl;
    cout << "4)Сохранить в файл" << endl;
    cout << "5)Загрузить из файла" << endl;
    cout << "6)Удалить экзамен" << endl;
    cout << "Выберите один из вариантов..." << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        addTeacher(records, size);
        break;
    case 2:
        list_of_teachers(records, size);
        break;
    case 3:
        char search_name[30];
        cout << "Введите фамилию преподавателя для поиска: ";
        cin >> search_name;
        Last_Name_Search(records, size, search_name);
        break;
    case 4:
        saving_to_file(records, size);
        break;
    case 5:
        data_output(records);
        break;
    case 6:
        deleteExam(records, size);
        break;
    case 0:
        std::cout << "Выход из программы...\n";
        break;
    default:
        std::cout << "Некорректный ввод! Попробуйте снова.\n";
    }
}

void addTeacher(teachers*& records, int& size)
{
    teachers* temp = new teachers[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = records[i];
    }

    cout << "Введите фамилию преподователя: ";
    cin >> temp[size].teacher_last_name;
    cout << "Введите название экзамена: ";
    cin >> temp[size].name_of_the_exam;
    cout << "Введите дату экзамена: ";
    cin >> temp[size].exam_date;
    cout << endl;
    delete[] records;
    records = temp;
    size++;
}

void list_of_teachers(teachers* records, int size)
{
    cout << "--------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Преподаватель: " << records[i].teacher_last_name << endl;
    }
    cout << "--------------------------" << endl;
}

void Last_Name_Search(teachers* records, int size, char search_name[])
{

    cout << "--------------------------" << endl;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(records[i].teacher_last_name, search_name) == 0)
        {
            cout << "Преподаватель найден!" << endl;
            cout << "Преподаватель: " << records[i].teacher_last_name << endl;
            cout << "Название экзамена: " << records[i].name_of_the_exam << endl;
            cout << "Дата экзамена: " << records[i].exam_date << endl;
            found = true;
            break;
        }
    }
    cout << "--------------------------" << endl;
}

void saving_to_file(teachers* records, int size)
{
    ofstream file("conservation.txt");
    if (!file)
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    file << size << ")" << endl;

    for (int i = 0; i < size; i++)
    {
        file << "Преподаватель: " << records[i].teacher_last_name << "\n" << "Название экзамена: "
            << records[i].name_of_the_exam << "\n" << "Дата проведения: " << records[i].exam_date << "\n";
    }
    file.close();
    cout << "Данные сохранены в файл conservation.txt" << endl;
}

void data_output(teachers* records)
{
    ifstream file("conservation.txt");
    if (!file)
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    string line;
    cout << "--------------------------" << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    cout << "--------------------------" << endl;
    file.close();
}

void deleteExam(teachers*& records, int& size)
{
    int indexToDelete = 0;
    cout << "-------------------------" << endl;
    cout << "Выберите экзамен для удаления:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << ") " << records[i].teacher_last_name << endl;
    }
    cout << "-------------------------" << endl;
    cin >> indexToDelete;

    if (indexToDelete < 0 || indexToDelete >= size)
    {
        cout << "Ошибка! Индекс вне допустимого диапазона." << endl;
        return;
    }

    teachers* temp = new teachers[size - 1];

    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != indexToDelete)
        {
            temp[j++] = records[i];
        }
    }

    delete[] records;
    records = temp;
    size--;

    cout << "Экзамен с индексом " << indexToDelete << " удалён!" << endl;
    cout << "-------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    teachers* records = nullptr;

    while (1)
    {
        menu(records, size);
    }

    delete[] records;
    return 0;
}