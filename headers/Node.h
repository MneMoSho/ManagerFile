//
// Created by Gleb on 03.11.2024.
//

#ifndef UNTITLED4_NODE_H
#define UNTITLED4_NODE_H
#include "Header.h"

template<typename T>
class Node
{
public:
    Node(T data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
    T data;
    Node* prev;
    Node* next;
};


#endif //UNTITLED4_NODE_H
