//
// Created by Gleb on 27.11.2024.
//

#include "Filter.h"

void Filter::pushIntoVector(FileComponents objectToPush) {
    filterVector.push_back(objectToPush);
};

void Filter::separateComponents(std::filesystem::path nameOfFile, int size) {
    FileComponents componentOfFile;
    componentOfFile.separeateFiles(nameOfFile.filename().string(), nameOfFile.extension().string());
    componentOfFile.setFileSize(size);
    pushIntoVector(componentOfFile);
}

bool extensionIsCorrect(const FileComponents &component, std::string extension) {
    if (component.extension == extension) {
        return true;
    } else
        return false;
}

bool sizeIsMore(FileComponents &component, int minimumSize) {
    if (component.getFileSize() > minimumSize) {
        return true;
    } else
        return false;
}

void Filter::displayVector() {
    for (auto x: filterVector) {
        std::cout << x.getFileSize();
        std::cout << x.nameOfFile << "\n";
    }
}

void Filter::filtureExtension(std::string path, std::string extensionToCheck) {
    JsonReport extensionReport;
    std::string pathToFile = path + "\\" + "filture.json";
    extensionReport.setJsonPath(pathToFile);
    displayVector();
    auto dataToFilture = filterVector | std::views::filter([&](const FileComponents &component) {
        return extensionIsCorrect(component, extensionToCheck);
    });
    for (auto fileToFilture: dataToFilture) {
        QString nameToSet = QString::fromStdString(fileToFilture.nameOfFile);
        QJsonObject tempObject;
        tempObject["nameOfFile"] = nameToSet;
        tempObject["extension"] = QString::fromStdString(fileToFilture.extension);
        extensionReport.addToJsonFile(tempObject);
    }
    extensionReport.saveToReport();
    filterVector.clear();
}

void Filter::sizeFilter(std::string path, int size) {
    JsonReport sizeReport;
    std::string pathToFile = path + "\\" + "sizeFilture.json";
    QString nameToSet;
    QJsonObject tempObject;
    sizeReport.setJsonPath(pathToFile);
    sizeReport.clearReport();
    displayVector();
    auto sizeFilture = filterVector | std::views::filter([&](FileComponents &component) {
        return sizeIsMore(component, size);
    });
    for (auto fileToFilture: sizeFilture) {
        nameToSet = QString::fromStdString(fileToFilture.nameOfFile);
        tempObject["size"] = fileToFilture.getFileSize();
        tempObject["nameOfFile"] = nameToSet;
        sizeReport.addToJsonFile(tempObject);
    }
    sizeReport.saveToReport();
    filterVector.clear();
}