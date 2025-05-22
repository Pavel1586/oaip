#pragma once

struct Node {
    int key;
    char owner[50];
    Node* next;

    Node(int k, const char* name);
};

class HashTable {
private:
    Node** table;
    int size;

    int hash(const char* owner);

public:
    HashTable(int s);
    ~HashTable();

    void insert(int key, const char* owner);
    const char* search(int key);
    void remove(int key);
    void print();
};
