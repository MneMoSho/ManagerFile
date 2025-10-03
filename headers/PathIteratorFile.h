//
// Created by Gleb on 30.11.2024.
//

#ifndef UNTITLED4_PATHITERATORFILE_H
#define UNTITLED4_PATHITERATORFILE_H
#include "PathContainerFile.h"
#include "FileComponents.h"

class PathIteratorFile {

public:

    PathIteratorFile(PathContainerFile const& container);
    FileComponents getByIndex(int index, std::vector<FileComponents> vectorToGetPath);
    FileComponents getAtVector(std::vector<FileComponents> vectorToGetPath, int index);

private:
    int index = 0;
    const PathContainerFile& container;
};


#endif //UNTITLED4_PATHITERATORFILE_H
