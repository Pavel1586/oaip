#include <iostream>
#include <string>
using namespace std;

enum Specialties
{
	programming,
	medicine,
	engineering,
	economy,
	history
};

struct Contest
{
	unsigned int lastYearCompetition : 4;
};

struct university
{
	char nameUniversity[50];
	char address[50];
	Specialties specialties;
	Contest contest;
	double tuitionFees;
};


void newUniversity(university*& records, int& size, university& uni);
void allUniversities(university* records, int size);
void deleteUniversity(university*& records, int& size);
void universitySearch(university* records, int size);
void minimumCompetition(university* records, int size);

void menu(university*& records, int& size, university& uni)
{
	int choice = 0;
	cout << "1) Добавить новый вуз" << endl;
	cout << "2) Показать все вузы" << endl;
	cout << "3) Удалить вуз" << endl;
	cout << "4) Найти вуз" << endl;
	cout << "5) Найти вуз с минимальным конкурсом" << endl;
	cout << "6) Выйти из программы" << endl;
	cin >> choice;

	switch (choice)
	{
	case(1):
		newUniversity(records, size, uni);
		break;
	case(2):
		allUniversities(records, size);
		break;
	case(3):
		deleteUniversity(records, size);
		break;
	case(4):
		universitySearch(records, size);
		break;
	case(5):
		minimumCompetition(records, size);
		break;
	case(6):
		cout << "Выход из программы..." << endl;
		exit(0);
	default:
		cout << "Некоректный вариант!" << endl;
		break;
	}
}

void newUniversity(university*& records, int& size, university& uni)
{
	university* temp = new university[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = records[i];
	}
	cout << "-------------------------" << endl;
	cout << "Введите название вуза: " << endl;
	cin >> temp[size].nameUniversity;
	cout << "Введите адресс университета: " << endl;
	cin >> temp[size].address;

	int choiceSpecialty = 0;
	cout << "-------------------------" << endl;
	cout << "Выберите Специальность: " << endl;
	cout << "0) Программирование" << endl;
	cout << "1) Медицина" << endl;
	cout << "2) Инженерия" << endl;
	cout << "3) Экономика" << endl;
	cout << "4) История" << endl;
	cout << "-------------------------" << endl;
	cin >> choiceSpecialty;

	if (choiceSpecialty >= 0 && choiceSpecialty <= 4)
	{
		temp[size].specialties = static_cast<Specialties>(choiceSpecialty);
	}
	else
	{
		cout << "Ошибка ввода! Выбрана специальность по умолчанию (Программирование)." << endl;
		temp[size].specialties = programming;
	}

	int contest;
	cout << "Введите конкурс прошлого года (от 1 до 15):" << endl;
	do
	{
		cin >> contest;
		if (contest < 0 || contest>15)
		{
			cout << "Попробуйте снова:" << endl;
		}
	}
	while (contest < 0 || contest>15);
	temp[size].contest.lastYearCompetition = contest;

	cout << "Стоимость обучения: " << endl;
	cin >> temp[size].tuitionFees;

	cout << endl;
	delete[] records;
	records = temp;
	size++;
}

string getSpecialtyName(Specialties specialty)
{
	switch (specialty)
	{
	case programming: return "Программирование";
	case medicine: return "Медицина";
	case engineering: return "Инженерия";
	case economy: return "Экономика";
	case history: return "История";
	default: return "Неизвестно";
	}
}

void allUniversities(university* records, int size)
{

	cout << "-------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Название университета: "<< records[i].nameUniversity << endl;
		cout << "Адресс университета: "<< records[i].address << endl;
		cout << "Специальность: " << getSpecialtyName(records[i].specialties) << endl;
		cout << "Конкурс прошлого года: " << records[i].contest.lastYearCompetition << endl;
		cout << "Стоимость обучения: " << records[i].tuitionFees << endl;
		cout << "-------------------------" << endl;
	}
}

void deleteUniversity(university*& records, int& size)
{
	int indexToDelete = 0;
	cout << "-------------------------" << endl;
	cout << "Выберите университет для удаления:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ") " << records[i].nameUniversity << endl;
	}
	cout << "-------------------------" << endl;
	cin >> indexToDelete;

	if (indexToDelete < 0 || indexToDelete >= size)
	{
		cout << "Ошибка! Индекс вне допустимого диапазона." << endl;
		return;
	}

	university* temp = new university[size - 1];

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

	cout << "Университет с индексом " << indexToDelete << " удалён!" << endl;
	cout << "-------------------------" << endl;
}

void universitySearch(university* records, int size)
{
	char searchName[50];
	cout << "----------------------------------------" << endl;
	cout << "Введите название университета для поиска" << endl;
	cin >> searchName;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(records[i].nameUniversity, searchName) == 0)
		{
			cout << "Название университета: " << records[i].nameUniversity << endl;
			cout << "Адресс университета: " << records[i].address << endl;
			cout << "Специальность: " << getSpecialtyName(records[i].specialties) << endl;
			cout << "Конкурс прошлого года: " << records[i].contest.lastYearCompetition << endl;
			cout << "Стоимость обучения: " << records[i].tuitionFees << endl;
		}
	}
	cout << "----------------------------------------" << endl;
}

void minimumCompetition(university* records, int size)
{
	int minIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (records[i].contest.lastYearCompetition < records[minIndex].contest.lastYearCompetition)
		{
			minIndex = i;
		}
	}
	cout << "----------------------------------------" << endl;
	cout << "Название университета: " << records[minIndex].nameUniversity << endl;
	cout << "Адресс университета: " << records[minIndex].address << endl;
	cout << "Специальность: " << getSpecialtyName(records[minIndex].specialties) << endl;
	cout << "Конкурс прошлого года: " << records[minIndex].contest.lastYearCompetition << endl;
	cout << "Стоимость обучения: " << records[minIndex].tuitionFees << endl;
	cout << "----------------------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	university* records = nullptr;
	university uni;

	while (1)
	{
		menu(records, size, uni);
	}

	return 0;
}