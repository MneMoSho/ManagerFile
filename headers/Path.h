//
// Created by Gleb on 24.10.2024.
//

#ifndef UNTITLED4_PATH_H
#define UNTITLED4_PATH_H

#include "Header.h"

class Path
{
public:
    void createWay();
    void createNewPath(const std::string& name);
    std::string getDisk() const;
    void setDisk(std::string_view disk);
    std::string getDestination() const;
    void setDestination(std::string_view disk);
private:
    std::string disk;
    std::string destination;
};


#endif //UNTITLED4_PATH_H
