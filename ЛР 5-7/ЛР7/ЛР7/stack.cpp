#include "stack.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

Stack::Stack() 
{
    top = nullptr;
}

Stack::~Stack() 
{
    clear();
}

void Stack::push(int val) 
{
    Node* node = new Node{ val, top };
    top = node;
}

int Stack::pop() 
{
    if (!top) 
    {
        cout << "���� ����\n";
        return 0;
    }

    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

void Stack::print() 
{
    Node* current = top;
    cout << "��������� ����� (������ ����): ";
    while (current) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::clear() 
{
    while (top) 
    {
        pop();
    }
}

void Stack::saveToFile(const char* filename) 
{
    ofstream out(filename);
    if (!out) 
    {
        cout << "�� ������� ������� ���� ��� ������\n";
        return;
    }

    Node* current = top;
    while (current) 
    {
        out << current->data << endl;
        current = current->next;
    }

    out.close();
    cout << "���� �������� � ����.\n";
}

void Stack::loadFromFile(const char* filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "�� ������� ������� ���� ��� ������\n";
        return;
    }

    clear();

    int val;
    Node* values[100];
    int count = 0;

    cout << "���������� �����:\n";

    while (in >> val && count < 100)
    {
        cout << val << " ";
        values[count++] = new Node{ val, nullptr };
    }

    cout << endl;

    for (int i = count - 1; i >= 0; --i)
    {
        push(values[i]->data);
        delete values[i];
    }

    in.close();
    cout << "���� �������� �� �����.\n";
}


void Stack::removeFirstDuplicate() 
{
    unordered_set<int> seen;
    Stack tempStack;
    bool removed = false;

    while (top) 
    {
        int val = pop();
        if (seen.find(val) != seen.end() && !removed) 
        {
            removed = true;
            continue;
        }
        seen.insert(val);
        tempStack.push(val);
    }

    while (tempStack.top) 
    {
        push(tempStack.pop());
    }

    if (removed) 
    {
        cout << "������ �������� ������.\n";
    }
    else 
    {
        cout << "��������� �� �������.\n";
    }
}