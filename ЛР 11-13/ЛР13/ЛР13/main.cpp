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
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int siz = 10, choice, k;
	cout << "������� ������ ���-�������" << endl;
	cin >> siz;

	Object H = create(siz, key);

	for (;;) {
		cout << "\n1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����: ";
		cin >> choice;

		switch (choice) {
		case 0: exit(0);

		case 1:
			H.scan(AAA_print);
			break;

		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "������� ����: ";
			cin >> k;
			a->key = k;
			cout << "������� ������: ";
			cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "������� ���������" << endl;
			else
				H.insert(a);
		} break;

		case 3: {
			cout << "������� ���� ��� ��������: ";
			cin >> k;
			H.deleteByKey(k);
		} break;

		case 4: {
			cout << "������� ���� ��� ������: ";
			cin >> k;
			auto start = chrono::high_resolution_clock::now();
			void* result = H.search(k);
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

			if (result == NULL)
				cout << "������� �� ������" << endl;
			else
				AAA_print(result);

			cout << "����� ������: " << duration << " ��" << endl;
		} break;
		}
	}
	return 0;
}
