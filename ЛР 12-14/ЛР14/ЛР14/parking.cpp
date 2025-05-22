#include "parking.h"
#include <iostream>
#include <cstring>

using namespace std;

Node::Node(int k, const char* name) {
    key = k;
    strcpy_s(owner, name);
    next = nullptr;
}

HashTable::HashTable(int s) {
    size = s;
    table = new Node * [size];
    for (int i = 0; i < size; ++i)
        table[i] = nullptr;
}

HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] table;
}

int HashTable::hash(const char* owner) {
    int hashValue = 0;
    for (int i = 0; owner[i] != '\0'; ++i) {
        hashValue ^= owner[i];
    }
    return hashValue % size;
}

void HashTable::insert(int key, const char* owner) {
    int index = hash(owner);
    Node* newNode = new Node(key, owner);
    newNode->next = table[index];
    table[index] = newNode;
}

const char* HashTable::search(int key) {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current) {
            if (current->key == key)
                return current->owner;
            current = current->next;
        }
    }
    return nullptr;
}

void HashTable::remove(int key) {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        Node* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev == nullptr)
                    table[i] = current->next;
                else
                    prev->next = current->next;

                delete current;
                cout << "Удалено.\n";
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    cout << "Элемент не найден.\n";
}

void HashTable::print() {
    for (int i = 0; i < size; ++i) {
        cout << "[" << i << "]: ";
        Node* current = table[i];
        if (!current) {
            cout << "пусто\n";
        }
        else {
            while (current) {
                cout << "(Место " << current->key << " - " << current->owner << ") -> ";
                current = current->next;
            }
            cout << "null\n";
        }
    }
}
