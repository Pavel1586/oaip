#include "List.h"

bool Object::Insert(void* data) 
{
    bool rc = false;
    if (Head == nullptr) 
    {
        Head = new Element(nullptr, data, nullptr);
        rc = true;
    }
    else 
    {
        Head = (Head->Prev = new Element(nullptr, data, Head));
        rc = true;
    }
    return rc;
}

Element* Object::Search(void* data) 
{
    Element* rc = Head;
    while ((rc != nullptr) && (rc->Data != data))
        rc = rc->Next;
    return rc;
}

void Object::PrintList(void(*f)(void*)) 
{
    Element* e = Head;
    while (e != nullptr) 
    {
        f(e->Data);
        e = e->GetNext();
    }
}

void Object::PrintList(void(*f)(void*), Element* e) 
{
    f(e->Data);
}

bool Object::Delete(Element* e) 
{
    bool rc = false;
    if (e != nullptr) {
        if (e->Next != nullptr)
            e->Next->Prev = e->Prev;
        if (e->Prev != nullptr)
            e->Prev->Next = e->Next;
        else
            Head = e->Next;
        delete e;
        rc = true;
    }
    return rc;
}

bool Object::Delete(void* data) 
{
    return Delete(Search(data));
}

bool Object::DeleteList() 
{
    Element* current = Head;
    while (current != nullptr) 
    {
        Element* next = current->Next;
        delete current;
        current = next;
    }
    Head = nullptr;
    return true;
}

int Object::CountList() 
{
    int count = 0;
    Element* current = Head;
    while (current != nullptr) 
    {
        count++;
        current = current->Next;
    }
    return count;
}

Element* Object::GetLast() 
{
    Element* e = Head;
    Element* rc = e;
    while (e != nullptr) 
    {
        rc = e;
        e = e->GetNext();
    }
    return rc;
}

Object Create() 
{
    return *(new Object());
}