#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include "AMateria.hpp"


struct Node
{
    AMateria *data;
    Node *next;
    Node(AMateria *value) : data(value), next(NULL) {}
};

struct LinkedList
{
    Node *head;
    LinkedList();
    void push_back(AMateria *value);
    bool find(AMateria *value);
    void clear();
    ~LinkedList();

};
#endif