//
// Created by Gleb on 27.11.2024.
//

#include "FileComponents.h"

void FileComponents::separeateFiles(std::string fileName, std::string extensionOfFile ) {
    extension = extensionOfFile;
    nameOfFile = fileName;
}

void FileComponents::setFileSize(int sizeOfFile)
{
    size = sizeOfFile;
}

void FileComponents::setPathOfFile(std::string filePath) {
pathOfFile = filePath;
}

std::string FileComponents::getPathOfFile() {
    return pathOfFile;
}

int FileComponents::getFileSize() {
    return size;
}