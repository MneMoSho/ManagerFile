//
// Created by Gleb on 03.11.2024.
//

#ifndef UNTITLED4_BINBUCKET_H
#define UNTITLED4_BINBUCKET_H
#include "Header.h"
#include "List.h"
#include "Exception.h"

class BinBucket {
public:
    List<std::string> addToList;
    List<std::string> moveToFolder;
    void moveByIndex(int index);
    void folderClear();
    int countNumberOfFIles();
    int findByName(std::string nameToFind);
    template <typename T>
    void moveToAnother(T nameOfFile)
    {
        numberOfFiles++;
        std::string nameNew;
        std::filesystem::path entry = nameOfFile;
        nameNew = entry.filename().string();
        nameNew = "I:\\O\\"+nameNew;//поменять под ноутбук
        moveToFolder.pushFront(nameNew);
        MoveFileA(nameOfFile.c_str(), nameNew.c_str());
    }
private:
    int numberOfFiles;
    DisplayBinFiles displayView;
};


#endif //UNTITLED4_BINBUCKET_H
