//
// Created by Gleb on 30.11.2024.
//

#include "PathIteratorFile.h"

PathIteratorFile::PathIteratorFile(const PathContainerFile& container) : container(container){}

FileComponents PathIteratorFile::getAtVector(std::vector<FileComponents> vectorToGetPath, int index) {
    return vectorToGetPath.at(index);
}

FileComponents PathIteratorFile::getByIndex(int index, std::vector<FileComponents> vectorToGetPath) {
    std::cout<<index;
    FileComponents containerToSet = getAtVector(vectorToGetPath, index);
    std::cout<<containerToSet.getPathOfFile();
    return containerToSet;
}
