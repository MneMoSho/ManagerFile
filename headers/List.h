//
// Created by Gleb on 03.11.2024.
//

#ifndef UNTITLED4_FileToBin_H
#define UNTITLED4_FileToBin_H
#include "Node.h"
#include "DisplayBucketFiles.h"

template<typename T>
class List {
public:
    List() {
        head = tail = NULL;
    }

    Node<T> *pushFront(T data) {
        Node<T>* ptr = new Node<T>(data);
        ptr->next = head;
        if (head != NULL)  {
            head->prev = ptr;
        }
        if (tail == NULL) {
            tail = ptr;
        }
        head =ptr;
        std::cout<<"\ndata\n";
        std::cout<<ptr->data;
        return ptr;
    }

    Node<T> *pushBack(T data) {
        Node<T>* ptr = new Node<T>(data);
        ptr->next = tail;
        if (tail != NULL)  {
            tail->next = ptr;
        }
        if (head == NULL) {
            head = ptr;
        }
        tail =ptr;
        return ptr;
    }

    Node<T> *getAtPosition(int index) {
        Node<T> *ptr = head;
        int n = 0;
        while (n != index) {
            if (ptr == NULL) {
                return ptr;
            }
            ptr = ptr->next;
            n++;
        }
        if(head == NULL || tail == NULL)
        {
            std::cout<<"Hello";
        }
        return ptr;
    }

    void popFront()
    {
        if (head == NULL)
        {
            return;
        }
        Node<T>* ptr = head->next;
        if(ptr != NULL)
        {
            ptr->prev = NULL;
        }
        else
            tail = NULL;
        delete head;
        head = ptr;
    }

    void popBack()
    {
        if (tail == NULL)
        {
            return;
        }
        Node<T>* ptr = tail->prev;
        if(ptr != NULL)
        {
            ptr->next = NULL;
        }
        else
            head = NULL;
        delete tail;
        tail = ptr;
    }

    void earse(int index)
    {
        Node<T>* ptr = getAtPosition(index);
        if(ptr == NULL)
        {
            return;
        }
        if(ptr->prev==NULL)
        {
            popFront();
            return;
        }
        if(ptr->next == NULL)
        {
            popBack();
            return;
        }
        Node<T>* left = ptr->prev;
        Node<T>* right = ptr->next;
        left->next=right;
        right->prev = left;
        delete ptr;
    }
    Node<T> *operator[](int index) {
        return getAtPosition(index);
    }

    Node<T>* head;
    Node<T>* tail;

};


#endif //UNTITLED4_FileToBin_H
