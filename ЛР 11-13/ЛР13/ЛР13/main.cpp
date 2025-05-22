#include "Hash.h"
#include <iostream>
#include <chrono>

using namespace std;

struct AAA {
	int key;
	char* mas;
	AAA(int k, char* z) {
		key = k; mas = z;
	}
	AAA() {}
};

int key(void* d) {
	AAA* f = (AAA*)d;
	return f->key;
}

void AAA_print(void* d) {
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int siz = 10, choice, k;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> siz;

	Object H = create(siz, key);

	for (;;) {
		cout << "\n1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор: ";
		cin >> choice;

		switch (choice) {
		case 0: exit(0);

		case 1:
			H.scan(AAA_print);
			break;

		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ: ";
			cin >> k;
			a->key = k;
			cout << "введите строку: ";
			cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;

		case 3: {
			cout << "введите ключ для удаления: ";
			cin >> k;
			H.deleteByKey(k);
		} break;

		case 4: {
			cout << "введите ключ для поиска: ";
			cin >> k;
			auto start = chrono::high_resolution_clock::now();
			void* result = H.search(k);
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

			if (result == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(result);

			cout << "Время поиска: " << duration << " нс" << endl;
		} break;
		}
	}
	return 0;
}
