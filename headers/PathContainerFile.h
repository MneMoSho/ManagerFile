//
// Created by Gleb on 30.11.2024.
//

#ifndef UNTITLED4_PATHCONTAINERFILE_H
#define UNTITLED4_PATHCONTAINERFILE_H
#include "FileComponents.h"
#include <stack>
#include "TempPath.h"
#include <QEventLoop>
#include <QWidget>
#include "Header.h"

class PathContainerFile : public FileComponents {
public:

    void addPath(FileComponents filePath);
    FileComponents selectByIndex();
    void displayStackAndVector(std::stack<FileComponents> stackToDisplay);
    FileComponents moveBack(int index);
    FileComponents moveAhead(int index);
    void checkForMeasures(int index);
    void checkForMeasuresTop(int index, int maxValue);
   void deleteFromStack();

private:
    std::vector<FileComponents> vectorPath;
    std::stack<FileComponents> stackPath;
    TempPath* addIntoModel = new TempPath;
    QEventLoop loop;
};


#endif //UNTITLED4_PATHCONTAINERFILE_H
