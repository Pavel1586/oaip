#include <iostream>
using namespace std;

struct Sanatorium
{
	char name[50];
	char location[50];
	char profile[50];
	int tickets;
};

void data(Sanatorium*& records, int& size);
void listSanatoriums(Sanatorium* records, int size);

void menu(Sanatorium*& records, int& size)
{
    int choice = 0;
	cout << "1) Добавить санаторий" << endl;
	cout << "2) Вывести список санаториев" << endl;
	cout << "3) Найти санаторий по названию" << endl;
	cout << "4) Выход" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        data(records, size);
        break;
    case 2:
        listSanatoriums(records, size);
        break;
    case 3:
        //academicAchievementPercentage(records, size);
        break;
    case 4:
        std::cout << "Выход из программы...\n";
        break;
    default:
        std::cout << "Некорректный ввод! Попробуйте снова.\n";
    }

}

void data(Sanatorium*& records, int& size)
{
    Sanatorium* temp = new Sanatorium[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = records[i];
    }
    cout << "Введите название санатория: " << endl;
    cin >> temp[size].name;
    cout << "Введите местоположение санатория: " << endl;
    cin >> temp[size].location;
    cout << "Введите профиль санатория: " << endl;
    cin >> temp[size].profile;
    cout << "Введите количество путевок: " << endl;
    cin >> temp[size].tickets;

    cout << endl;
    delete[] records;
    records = temp;
    size++;
}

void listSanatoriums(Sanatorium* records, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Название |" << "Местоположение |" <<"Профиль |" << "Путевок |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << records[i].name<< "   |" << records[i].location<< "          |" << records[i].profile<< "    |" << records[i].tickets << endl;
        cout << "--------------------------------------------" << endl;
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");
    int size = 0;
    Sanatorium* records = nullptr;

    while (1)
    {
        menu(records, size);
    }

	return 0;
}