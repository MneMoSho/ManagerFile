//
// Created by Gleb on 24.10.2024.
//

#ifndef UNTITLED4_DIRECTORYPROPERTIES_H
#define UNTITLED4_DIRECTORYPROPERTIES_H


#include "Path.h"
#include "IOperations.h"
#include <QEventLoop>


class DirectoryProperties: public IOperations, public Path
{
public:
    void objectCreate(int numberOfLines, const std::string& name)  override;
    void fileUpdate(int numberOfLines, std::string* destination) override;
    void fileRead(const std::string& destination) override;
    void lineDelete(int numberToDelete, std::string* destination) override;
    void setDestination(std::string destination);
    std::string getDestination();
    std::string check;
private:
    std::string destinationOfDirectory;
};


#endif //UNTITLED4_DIRECTORYPROPERTIES_H
