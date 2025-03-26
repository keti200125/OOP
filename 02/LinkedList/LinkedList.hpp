#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include<iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
    };

    Node *head;

public:
    LinkedList();
    LinkedList(int data);
    LinkedList(const LinkedList &other);
    LinkedList &operator=(const LinkedList &other);
    ~LinkedList();

    void print();

private:
    void copy(const LinkedList &other);
    void free();
};

#endif // LINKEDLIST_HPP
