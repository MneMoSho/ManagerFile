//
// Created by Gleb on 27.11.2024.
//

#ifndef UNTITLED4_FILTER_H
#define UNTITLED4_FILTER_H
#include <vector>
#include "Header.h"
#include "FileComponents.h"
#include "JsonReport.h"

class Filter: public FileComponents  {
public:

    void pushIntoVector(FileComponents objectToPush);
    void separateComponents(std::filesystem::path nameOfFile, int size);
    void filtureExtension(std::string path, std::string extensionToCheck);
    void sizeFilter(std::string path, int size);
    void displayVector();
private:
    std::vector<FileComponents> filterVector;
};


#endif //UNTITLED4_FILTER_H
