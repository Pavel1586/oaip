#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	double data;
	Node* next;
};

void addingElement(Node*& head);
void listOutput(Node* head);
void elementSearch(Node* head, double value);
void deletingElement(Node*& head, double value);
void writingFile(Node* head);
void readingList(Node*& head);
void calculations(Node* head);

void menu(Node*& head)
{
	int choice = 0;
	double value = 0;
	cout << "1) Добавление элемента:" << endl;
	cout << "2) Вывод списка:" << endl;
	cout << "3) Поиск элемента:" << endl;
	cout << "4) Удаление элемента:" << endl;
	cout << "5) Запись списка в файл:" << endl;
	cout << "6) Считывание списка из файла:" << endl;
	cout << "7) Найти среднее значение положительных элементов:" << endl;
	cout << "8) Выход..." << endl;
	cin >> choice;

	switch (choice)
	{
	case(1):
		addingElement(head);
		break;
	case(2):
		listOutput(head);
		break;
	case(3):
		elementSearch(head, value);
		break;
	case(4):
		deletingElement(head, value);
		break;
	case(5):
		writingFile(head);
		break;
	case(6):
		readingList(head);
		break;
	case(7):
		calculations(head);
		break;
	case(8):
		exit(0);
		break;
	default:
		cout << "Попробуйте снова" << endl;
		break;
	}
}

void addingElement(Node*& head)
{
	double value;

	cout << "Введите числа (0 для завершения):" << endl;
	while (1)
	{
		cin >> value;
		if (value == 0)
			break;

		Node* newNode = new Node{ value, nullptr };

		if (!head)
		{
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
}

void listOutput(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << endl;
}

void elementSearch(Node* head, double value)
{
	Node* temp = head;
	cout << "Введите значение для поиска:" << endl;
	cin >> value;
	while (temp)
	{
		if (temp->data == value)
		{
			cout << "Элемент " << value << " найден!" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "Элемент " << value << " не найден!" << endl;
}

void deletingElement(Node*& head, double value)
{
	if (!head) {
		cout << "Список пуст!" << endl;
		return;
	}

	cout << "Введите значение для удаления:" << endl;
	cin >> value;

	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
		cout << "Элемент " << value << " удален!" << endl;
		return;
	}

	Node* temp = head;
	while (temp->next && temp->next->data != value) {
		temp = temp->next;
	}

	if (!temp->next) {
		cout << "Элемент " << value << " не найден!" << endl;
		return;
	}

	Node* toDelete = temp->next;
	temp->next = temp->next->next;
	delete toDelete;
	cout << "Элемент " << value << " удален!" << endl;
}

void writingFile(Node* head)
{
	ofstream file("list.txt");
	if (!file) {
		cout << "Не удалось открыть файл для записи!" << endl;
		return;
	}

	Node* temp = head;
	while (temp) {
		file << temp->data << endl;
		temp = temp->next;
	}

	file.close();
	cout << "Список записан в файл list.txt" << endl;
}

void readingList(Node*& head)
{
	ifstream file("list.txt");
	if (!file) {
		cout << "Не удалось открыть файл для чтения!" << endl;
		return;
	}

	double value;
	while (file >> value) {
		Node* newNode = new Node{ value, nullptr };
		if (!head) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
			cout << value << ", ";
		}
	}
	cout << endl;

	file.close();
	cout << "Список считан из файла list.txt" << endl;
}

void calculations(Node* head)
{
	double sum = 0;
	double averageValue = 0;
	int counter = 0;
	Node* temp = head;
	bool found = false;

	while (temp) 
	{
		if (temp->data > 0) 
		{
			sum += temp->data;
			found = true;
			counter++;
		}
		temp = temp->next;
	}


	averageValue = sum / counter;

	if (found) 
	{
		cout << "Среднее значение положительных элемнтов: " << averageValue << endl;
	}
	else 
	{
		cout << "Таких элементов нет!" << endl;
	}
}

void clearList(Node*& head) {
	Node* current = head;
	Node* nextNode = nullptr;

	while (current != nullptr)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* head = nullptr;

	while (1)
	{
		menu(head);
	}

	clearList(head);
	return 0;
}