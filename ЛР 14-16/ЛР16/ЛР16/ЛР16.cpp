#include <iostream>
using namespace std;

struct Item {
    int id;
    int priority;
    Item* next;
};

Item* head = NULL;
Item* tail = NULL;

bool isNull() {
    return head == NULL;
}

void clearQueue() {
    while (!isNull()) {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
}

void insertQueue1(int id, int priority) {
    Item* newItem = new Item{ id, priority, NULL };

    if (isNull()) {
        head = tail = newItem;
        return;
    }

    // Вставка по приоритету: min + LIFO
    Item* cur = head;
    Item* prev = NULL;

    while (cur != NULL && cur->priority < priority) {
        prev = cur;
        cur = cur->next;
    }
    while (cur != NULL && cur->priority == priority) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = cur;
        prev->next = newItem;
    }

    if (newItem->next == NULL)
        tail = newItem;
}

void insertQueue2(int id, int priority) {
    Item* newItem = new Item{ id, priority, NULL };

    if (isNull()) {
        head = tail = newItem;
        return;
    }

    // Вставка по убыванию приоритета (max + FIFO)
    Item* cur = head;
    Item* prev = NULL;

    while (cur != NULL && cur->priority > priority) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = cur;
        prev->next = newItem;
    }

    if (newItem->next == NULL)
        tail = newItem;
}

void deletFirst() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Item* temp = head;
    head = head->next;
    delete temp;

    if (head == NULL)
        tail = NULL;
}

void deleteFromTail() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Item* cur = head;
    while (cur->next != tail)
        cur = cur->next;

    delete tail;
    tail = cur;
    tail->next = NULL;
}

void getFromHead() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        cout << "ID = " << head->id << ", Priority = " << head->priority << endl;
    }
}

void printQueue() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Item* p = head;
    while (p != NULL) {
        cout << "[" << p->id << "|" << p->priority << "] -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice, id, priority;

    do {
        cout << "\n1 - Добавить в очередь (min+LIFO, с головы)\n";
        cout << "2 - Добавить в очередь (max+FIFO, с головы)\n";
        cout << "3 - Извлечь элемент с головы\n";
        cout << "4 - Извлечь элемент с конца\n";
        cout << "5 - Показать голову\n";
        cout << "6 - Показать всю очередь\n";
        cout << "7 - Очистить очередь\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите ID и приоритет: ";
            cin >> id >> priority;
            insertQueue1(id, priority);
            break;
        case 2:
            cout << "Введите ID и приоритет: ";
            cin >> id >> priority;
            insertQueue2(id, priority);
            break;
        case 3:
            deletFirst();
            break;
        case 4:
            deleteFromTail();
            break;
        case 5:
            getFromHead();
            break;
        case 6:
            printQueue();
            break;
        case 7:
            clearQueue();
            break;
        }
    } while (choice != 0);

    clearQueue();
    return 0;
}