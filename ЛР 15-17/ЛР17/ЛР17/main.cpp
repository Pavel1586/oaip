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
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Показать список\n";
        cout << "3. Найти элемент по имени\n";
        cout << "4. Удалить элемент по имени\n";
        cout << "5. Подсчитать количество элементов\n";
        cout << "6. Удалить весь список\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1: 
        {
            Person* p = new Person;
            cout << "Введите имя: ";
            cin.getline(p->name, 20);
            cout << "Введите возраст: ";
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
            cout << "Введите имя для поиска: ";
            char name[20];
            cin.getline(name, 20);
            Element* e = L.GetFirst();
            while (e != nullptr) 
            {
                Person* p = (Person*)e->Data;
                if (strcmp(p->name, name) == 0) 
                {
                    cout << "Найден: ";
                    print(p);
                    break;
                }
                e = e->GetNext();
            }
            if (e == nullptr)
                cout << "Элемент не найден.\n";
            break;
        }
        case 4: 
            {
            cout << "Введите имя для удаления: ";
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
                    cout << "Удален элемент: " << name << endl;
                    break;
                }
                e = e->GetNext();
            }
            if (e == nullptr)
                cout << "Элемент не найден.\n";
            break;
        }
        case 5:
            cout << "Количество элементов: " << L.CountList() << endl;
            break;
        case 6:
            L.DeleteList();
            cout << "Список очищен.\n";
            break;
        case 0:
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    L.DeleteList();
    return 0;
}