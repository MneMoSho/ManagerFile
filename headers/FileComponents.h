//
// Created by Gleb on 27.11.2024.
//

#ifndef UNTITLED4_FILECOMPONENTS_H
#define UNTITLED4_FILECOMPONENTS_H
#include "Header.h"

class FileComponents {
public:
    std::string extension;
    std::string nameOfFile;
    std::string getPathOfFile();
    void separeateFiles(std::string fileName, std::string extensionOfFile);
    void setFileSize(int sizeOfFile);
    void setPathOfFile(std::string filePath);
    int getFileSize();

private:
    int size;
    std::string pathOfFile;
};


#endif //UNTITLED4_FILECOMPONENTS_H
