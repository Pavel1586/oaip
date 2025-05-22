#ifndef STACK_H
#define STACK_H

struct Node 
{
    int data;
    Node* next;
};

class Stack 
{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int val);
    int pop();
    void print();
    void clear();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
    void removeFirstDuplicate();
};

#endif