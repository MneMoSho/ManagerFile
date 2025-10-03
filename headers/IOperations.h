//
// Created by Gleb on 24.10.2024.
//

#ifndef UNTITLED4_IOPERATIONS_H
#define UNTITLED4_IOPERATIONS_H
#include "Header.h"

class IOperations
{
public:
    virtual void objectCreate(int numberOfLines, const std::string& name) = 0;
    virtual void fileUpdate(int numberOfLines, std::string* destination) = 0;
    virtual void fileRead(const std::string& destination) = 0;
    virtual void lineDelete(int numberToDelete, std::string* destination) = 0;
};


#endif //UNTITLED4_IOPERATIONS_H
