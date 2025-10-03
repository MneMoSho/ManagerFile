//
// Created by Gleb on 30.11.2024.
//

#include "PathContainerFile.h"
#include "PathIteratorFile.h"

void PathContainerFile::addPath(FileComponents filePath) {
    vectorPath.push_back(filePath);
    stackPath.push(filePath);
    addIntoModel->appendingItem(filePath.getPathOfFile());
}

void PathContainerFile::displayStackAndVector(std::stack<FileComponents> stackToDisplay) {
    std::stack<FileComponents> stackToCopy = stackToDisplay;
    if (!stackToCopy.empty()) {
        while (!stackToCopy.empty()) {
            std::cout << stackToCopy.top().getPathOfFile() << "\n";
            stackToCopy.pop();
        }
    }
}

FileComponents PathContainerFile::moveBack(int index) {
    std::stack<FileComponents> stackToCopy = stackPath;
    if (!stackPath.empty()) {
        for (int i = 0; i < index; i++) {
            stackToCopy.pop();
        }
    }
    std::cout << "\n" << stackToCopy.top().getPathOfFile();
    return stackToCopy.top();
}

FileComponents PathContainerFile::moveAhead(int index) {
}

FileComponents PathContainerFile::selectByIndex() {
    PathIteratorFile iterator(*this);
    FileComponents getElementByIndex;
    addIntoModel->show();
    QObject::connect(addIntoModel, &TempPath::signalToCloseWidget, &loop, &QEventLoop::quit);
    loop.exec();
    int numberToGet = 0;
    numberToGet = addIntoModel->getIndexOfSelected();
    getElementByIndex = iterator.getByIndex(numberToGet, vectorPath);
    vectorPath.erase(vectorPath.begin() + numberToGet);
    return getElementByIndex;
}

void PathContainerFile::checkForMeasures(int index) {
    if (index - 1 < 0) {
        throw std::runtime_error("No more elements in stack");;
    }
}

void PathContainerFile::checkForMeasuresTop(int index, int maxValue) {
    if (index + 1 > maxValue) {
        throw std::runtime_error("No more elements in stack");;
    }
}

void PathContainerFile::deleteFromStack() {
stackPath.pop();
std::cout<<"stack\n"<<stackPath.top().getPathOfFile();
}
