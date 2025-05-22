#include <iostream>
#include <Windows.h>
using namespace std;

struct Queue 
{
    Queue(int size);
    ~Queue();

    bool isFull() const;
    bool isEmpty() const;
    bool Enqueue(char item);
    bool Dequeue(char& item);
    void PrintAll() const;
    size_t SizeCount() const;

    int Head;
    int Tail;
    int Size;
    char* Data;
};

Queue::Queue(int size) 
{
    Head = Tail = 0;
    Size = size + 1;
    Data = new char[Size];
}

Queue::~Queue() 
{
    delete[] Data;
}

bool Queue::isFull() const 
{
    return (Tail + 1) % Size == Head;
}

bool Queue::isEmpty() const 
{
    return Head == Tail;
}

bool Queue::Enqueue(char item) 
{
    if (!isFull()) 
    {
        Data[Tail] = item;
        Tail = (Tail + 1) % Size;
        return true;
    }
    return false;
}

bool Queue::Dequeue(char& item) 
{
    if (!isEmpty()) 
    {
        item = Data[Head];
        Head = (Head + 1) % Size;
        return true;
    }
    return false;
}

void Queue::PrintAll() const 
{
    if (isEmpty()) 
    {
        cout << "Очередь пуста.\n";
        return;
    }
    cout << "Элементы очереди: ";
    int current = Head;
    while (current != Tail) 
    {
        cout << Data[current] << " ";
        current = (current + 1) % Size;
    }
    cout << endl;
}

size_t Queue::SizeCount() const 
{
    size_t count = 0;
    int current = Head;
    while (current != Tail) 
    {
        count++;
        current = (current + 1) % Size;
    }
    return count;
}

void inputUntilEtalon(Queue& queue, char etalon) 
{
    char ch;
    cout << "Введите символы (эталонный символ для остановки: '" << etalon << "'):\n";
    while (true) 
    {
        cout << ">> ";
        cin >> ch;
        if (ch == etalon) 
        {
            cout << "Встречен эталонный символ '" << etalon << "' — удаляем 2 элемента из очереди...\n";
            char removed;
            if (!queue.Dequeue(removed))
                cout << "Очередь пуста — нечего удалять.\n";
            else
                cout << "Удалён: " << removed << endl;

            if (!queue.Dequeue(removed))
                cout << "Очередь пуста — нечего удалять.\n";
            else
                cout << "Удалён: " << removed << endl;
            break;
        }
        else 
        {
            if (!queue.Enqueue(ch)) 
            {
                cout << "Очередь переполнена!\n";
            }
        }
    }
}

void showMenu() 
{
    cout << "\nМЕНЮ\n";
    cout << "1. Ввести символы до эталонного\n";
    cout << "2. Удалить элемент из очереди\n";
    cout << "3. Показать очередь\n";
    cout << "4. Показать размер очереди\n";
    cout << "5. Выход\n";
    cout << "Выберите пункт: ";
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int maxSize;
    char etalon;

    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    cout << "Введите эталонный символ: ";
    cin >> etalon;

    Queue queue(maxSize);

    int choice;
    do 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1:
            inputUntilEtalon(queue, etalon);
            break;
        case 2: 
            {
            char removed;
            if (queue.Dequeue(removed))
                cout << "Удалён: " << removed << endl;
            else
                cout << "Очередь пуста!\n";
            break;
        }
        case 3:
            queue.PrintAll();
            break;
        case 4:
            cout << "Размер очереди: " << queue.SizeCount() << endl;
            break;
        case 5:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}