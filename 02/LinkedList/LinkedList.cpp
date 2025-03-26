#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::LinkedList(int data)
{
    head = new Node(data);
}

LinkedList::LinkedList(const LinkedList &other)
{
    copy(other);
}

LinkedList &LinkedList::operator=(const LinkedList &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

LinkedList::~LinkedList()
{
    free();
}

void LinkedList::print()
{
    Node* it = head;
    while(it)
    {
        std::cout<<it->data<<" ";
        it = it->next;
    }
}

void LinkedList::copy(const LinkedList &other)
{
    if (!other.head)
    {
        head = nullptr;
        return;
    }

    head = new Node(other.head->data);
    Node *lastCreated = head;
    Node *currentOther = other.head->next;

    while (currentOther)
    {
        lastCreated->next = new Node(currentOther->data);
        lastCreated = lastCreated->next;
        currentOther = currentOther->next;
    }
}

void LinkedList::free()
{
    while (head)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    head = nullptr;
}
