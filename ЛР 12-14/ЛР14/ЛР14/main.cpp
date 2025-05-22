#include "parking.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите размер хеш-таблицы: ";
    cin >> size;

    HashTable table(size);

    int choice;
    while (true) {
        cout << "\n1 - Добавить владельца\n2 - Удалить владельца\n3 - Найти владельца\n4 - Показать таблицу\n0 - Выход\nВыбор: ";
        cin >> choice;

        if (choice == 0) break;

        int place;
        char owner[50];

        switch (choice) {
        case 1:
            cout << "Введите номер места: ";
            cin >> place;
            cout << "Введите имя владельца: ";
            cin.ignore();
            cin.getline(owner, 50);
            table.insert(place, owner);
            break;
        case 2:
            cout << "Введите номер места для удаления: ";
            cin >> place;
            table.remove(place);
            break;
        case 3:
            cout << "Введите номер места для поиска: ";
            cin >> place;
            {
                const char* result = table.search(place);
                if (result)
                    cout << "Владелец: " << result << endl;
                else
                    cout << "Место не найдено.\n";
            }
            break;
        case 4:
            table.print();
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    }

    return 0;
}
