#include <iostream>
#include <string>
using namespace std;

enum Gender
{
	male,
	female
};

struct Date
{
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

struct townsman
{
	char fullName[50];
	char address[50];
	Gender gender;
	Date date;
};

void newСitizen(townsman*& records, int& size, townsman& uni);
void allTownspeople(townsman* records, int size);
void removalList(townsman*& records, int& size);
void searchcitizen(townsman* records, int size);

void menu(townsman*& records, int& size, townsman& uni)
{
	int choice = 0;
	cout << "1) Добавить нового горожанина" << endl;
	cout << "2) Показать всех горожан" << endl;
	cout << "3) Удалить горожанина" << endl;
	cout << "4) Найти горожанина" << endl;
	cout << "5) Выйти из программы" << endl;
	cin >> choice;

	switch (choice)
	{
	case(1):
		newСitizen(records, size, uni);
		break;
	case(2):
		allTownspeople(records, size);
		break;
	case(3):
		removalList(records, size);
		break;
	case(4):
		searchcitizen(records, size);
		break;
	case(5):
		cout << "Выход из программы..." << endl;
		exit(0);
	default:
		cout << "Некоректный вариант!" << endl;
		break;
	}
}

void newСitizen(townsman*& records, int& size, townsman& uni)
{
	townsman* temp = new townsman[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = records[i];
	}
	cout << "-------------------------" << endl;
	cout << "Введите ФИО:" << endl;
	cin >> temp[size].fullName;
	cout << "Введите адресс:" << endl;
	cin >> temp[size].address;

	int choiceGender = 0;
	cout << "-------------------------" << endl;
	cout << "Выберите пол:" << endl;
	cout << "0) Мужской" << endl;
	cout << "1) Женский" << endl;
	cout << "-------------------------" << endl;
	cin >> choiceGender;

	if (choiceGender >= 0 && choiceGender <= 4)
	{
		temp[size].gender = static_cast<Gender>(choiceGender);
	}
	else
	{
		cout << "Ошибка ввода! Выбран пол по умолчанию (мужской)." << endl;
		temp[size].gender = male;
	}

	int date;

	cout << "Введите день рождения (1-31): " << endl;
	do
	{
		cin >> date;
		if (date < 1 || date>31)
		{
			cout << "Попробуйте снова:" << endl;
		}
	} while (date < 1 || date > 31);
		temp[size].date.day = date;

		cout << "Введите месяц рождения (1-12):" << endl;
		do
		{
			cin >> date;
			if (date < 1 || date > 12)
			{
				cout << "Попробуйте снова:" << endl;
			}
		} while (date < 1 || date > 12);
		temp[size].date.month = date;

		cout << "Введите год рождения (1900-4095): "<<endl;
		do
		{
			cin >> date;
			if (date < 1900 || date > 4095)
			{
				cout << "Попробуйте снова:" << endl;
			}
		} while (date < 1900 || date>4095);
		temp[size].date.year = date;

	cout << endl;
	delete[] records;
	records = temp;
	size++;
}

string chooseGender(Gender gender)
{
	switch (gender)
	{
	case male: return "Мужской";
	case female: return "Женский";
	default: return "Неизвестно";
	}
}

void allTownspeople(townsman* records, int size)
{
	cout << "-------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "ФИО: " << records[i].fullName << endl;
		cout << "Дата рождения: "
			<< records[i].date.day << "."
			<< records[i].date.month << "."
			<< records[i].date.year << endl;

		cout << "Адресс: " << records[i].address << endl;
		cout << "Пол: " << chooseGender(records[i].gender) << endl;
		cout << "-------------------------" << endl;
	}
}

void removalList(townsman*& records, int& size)
{
	int indexToDelete = 0;
	cout << "-------------------------" << endl;
	cout << "Выберите горожанина для удаления:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ") " << records[i].fullName << endl;
	}
	cout << "-------------------------" << endl;
	cin >> indexToDelete;

	if (indexToDelete < 0 || indexToDelete >= size)
	{
		cout << "Ошибка! Индекс вне допустимого диапазона." << endl;
		return;
	}

	townsman* temp = new townsman[size - 1];

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

	cout << "Горожанин с индексом " << indexToDelete << " удалён!" << endl;
	cout << "-------------------------" << endl;
}

void searchcitizen(townsman* records, int size)
{
	char searchName[50];
	cout << "----------------------------------------" << endl;
	cout << "Введите ФИО горожанина для поиска" << endl;
	cin >> searchName;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(records[i].fullName, searchName) == 0)
		{
			cout << "ФИО: " << records[i].fullName << endl;
			cout << "Дата рождения: "
				<< records[i].date.day << "."
				<< records[i].date.month << "."
				<< records[i].date.year << endl;

			cout << "Адресс: " << records[i].address << endl;
			cout << "Пол: " << chooseGender(records[i].gender) << endl;
		}
	}
	cout << "----------------------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	townsman* records = nullptr;
	townsman uni;

	while (1)
	{
		menu(records, size, uni);
	}

	return 0;
}