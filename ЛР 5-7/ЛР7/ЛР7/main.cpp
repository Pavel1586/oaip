#include <iostream>
#include "stack.h"
using namespace std;

void showMenu() 
{
    cout << "\nМеню:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Показать стек\n";
    cout << "3. Очистить стек\n";
    cout << "4. Сохранить в файл\n";
    cout << "5. Загрузить из файла\n";
    cout << "6. Удалить первый дубликат\n";
    cout << "0. Выход\n";
    cout << "Выберите опцию: ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Stack s;
    int choice, value;

    while (true) 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Введите значение (0 чтобы прекратить):" << endl;
            while (1)
            {
                cin >> value;
                if (value == 0)
                    break;
                else
                s.push(value);
            }
            break;
        case 2:
            s.print();
            break;
        case 3:
            s.clear();
            cout << "Стек очищен.\n";
            break;
        case 4:
            s.saveToFile("conservation.txt");
            break;
        case 5:
            s.loadFromFile("conservation.txt");
            break;
        case 6:
            s.removeFirstDuplicate();
            break;
        case 0:
            return 0;
        default:
            cout << "Неверная опция!\n";
        }
    }
}