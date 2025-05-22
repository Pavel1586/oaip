#include "List.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Person 
{
    char name[20];
    int age;
};

void print(void* b) 
{
    Person* a = (Person*)b;
    cout << a->name << "  " << a->age << endl;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    Object L = Create();
    int choice;

    do 
    {
        cout << "\n����:\n";
        cout << "1. �������� �������\n";
        cout << "2. �������� ������\n";
        cout << "3. ����� ������� �� �����\n";
        cout << "4. ������� ������� �� �����\n";
        cout << "5. ���������� ���������� ���������\n";
        cout << "6. ������� ���� ������\n";
        cout << "0. �����\n";
        cout << "��� �����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1: 
        {
            Person* p = new Person;
            cout << "������� ���: ";
            cin.getline(p->name, 20);
            cout << "������� �������: ";
            cin >> p->age;
            cin.ignore();
            L.Insert(p);
            break;
        }
        case 2:
            L.PrintList(print);
            break;
        case 3: 
            {
            cout << "������� ��� ��� ������: ";
            char name[20];
            cin.getline(name, 20);
            Element* e = L.GetFirst();
            while (e != nullptr) 
            {
                Person* p = (Person*)e->Data;
                if (strcmp(p->name, name) == 0) 
                {
                    cout << "������: ";
                    print(p);
                    break;
                }
                e = e->GetNext();
            }
            if (e == nullptr)
                cout << "������� �� ������.\n";
            break;
        }
        case 4: 
            {
            cout << "������� ��� ��� ��������: ";
            char name[20];
            cin.getline(name, 20);
            Element* e = L.GetFirst();
            while (e != nullptr) 
            {
                Person* p = (Person*)e->Data;
                if (strcmp(p->name, name) == 0) 
                {
                    L.Delete(p);
                    delete p;
                    cout << "������ �������: " << name << endl;
                    break;
                }
                e = e->GetNext();
            }
            if (e == nullptr)
                cout << "������� �� ������.\n";
            break;
        }
        case 5:
            cout << "���������� ���������: " << L.CountList() << endl;
            break;
        case 6:
            L.DeleteList();
            cout << "������ ������.\n";
            break;
        case 0:
            break;
        default:
            cout << "�������� �����.\n";
        }
    } while (choice != 0);

    L.DeleteList();
    return 0;
}