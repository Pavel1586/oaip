#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct studentExams
{
	char StudentFullName[50];
	int NumberExams;
	char evaluations[10];
};

void newStudent(studentExams*& records, int& size);
void progress(studentExams* records, int size);
void academicAchievementPercentage(studentExams* records, int size);
void allStudents(studentExams* records, int size);

void menu(studentExams*& records, int& size)
{
    int choice;
    cout << "1)Добавить нового студента" << endl;
    cout << "2)Проверить успеваемость студента" << endl;
    cout << "3)Вычислить процент студентов с хорошими оценками" << endl;
    cout << "4)Вывести список студентов" << endl;
    cout << "Выберите один из вариантов..." << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        newStudent(records, size);
        break;
    case 2:
        progress(records, size);
        break;
    case 3:
        academicAchievementPercentage(records, size);
        break;
    case 4:
        allStudents(records, size);
        break;
    case 0:
        std::cout << "Выход из программы...\n";
        break;
    default:
        std::cout << "Некорректный ввод! Попробуйте снова.\n";
    }
}

void newStudent(studentExams*& records, int& size)
{
    studentExams* temp = new studentExams[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = records[i];
    }
    cout << "Введите ФИО студента: " << endl;
    cin.ignore();
    cin.getline(temp[size].StudentFullName, 50);
    cout << "Введите количество экзаменов: " << endl;
    cin >> temp[size].NumberExams;
    cout << "Введите полученные оценки: " << endl;
    cin >> temp[size].evaluations;
    
    cout << endl;
    delete[] records;
    records = temp;
    size++;
}

void progress(studentExams* records, int size)
{
    string str;
    int studentIndex = 0;
    for (int i = 0; i < size; i++)
    {
        cout<< i+1 <<")" << records[i].StudentFullName << endl;
    }

    cout << "Выберите студента: " << endl;
    cin >> studentIndex;

    for (int i = 0; i < size; i++)
    {
        str = records[i].evaluations;
        if (studentIndex == i + 1)
        {
            cout << "Студент " << "(" << i + 1 << ")" << " " << records[i].StudentFullName << endl;
            bool check = true;
            for (char c : str)
            {
                if (c != '4' && c != '5')
                {
                    check = false;
                }
            }

            if (check == true)
            {
                cout << "Студент сдал все экзамены на 4 и 5" << endl;
            }
            else if(!check)
            {
                cout << "Студент не сдал все экзамены на 4 и 5" << endl;
            }
            cout << endl;
        }
    }
}

void academicAchievementPercentage(studentExams* records, int size)
{
    int counter = 0;
    string str;
    for (int i = 0; i < size; i++)
    {
        str = records[i].evaluations;
        bool check = true;
        for (char c: str) 
        {
            if (c != '4' && c != '5') 
            {
                check = false;
                break;
            }
        }

        if (check) 
        {
            counter++;
        }
    }

    double percent;
    percent = (static_cast<double>(counter) / size) * 100;
    cout << "--------------------------" << endl;
    cout << "Процент успешных студентов "<< percent << "%" << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}

void allStudents(studentExams* records, int size)
{
    cout << "-------------------------" << endl;
    cout << "Все студенты:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "-------------------------" << endl;
        cout << "ФИО студента: "<< records[i].StudentFullName;
        cout << endl;
        cout << "Количество экзаменов: "<< records[i].NumberExams;
        cout << endl;
        cout << "Оценки: "<< records[i].evaluations;
        cout << endl;
        cout << "-------------------------" << endl;
    }
    cout << "-------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
    int size = 0;
    studentExams* records = nullptr;

    while (1)
    {
        menu(records, size);
    }
	return 0;
}