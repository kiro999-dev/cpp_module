#include "Linked_list.hpp"

void LinkedList::push_back(AMateria *value)
{
    if (value == NULL)
        return;
        
    Node *newNode = new Node(value);
    
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::clear()
{
    while (head != NULL)
    {
        Node *temp = head;
        if(temp->data)
            delete temp->data;
        head = head->next;
        delete temp;
    }
}
bool LinkedList::find(AMateria *value)
{
    Node *curr;
    curr = head;
    while (curr != NULL)
    {
        if(value == curr->data)
            return(1);
        curr = curr->next;
    }
    return (0);
}
LinkedList::LinkedList(): head(NULL)
{
   
}
LinkedList::~LinkedList()
    {
        clear();
    }