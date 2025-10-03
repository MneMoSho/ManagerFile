//
// Created by Gleb on 17.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Exceptions.h" resolved

#include "Exception.h"
#include "ui_Exception.h"


Exception::Exception(QWidget *parent) :
        QWidget(parent), ui(new Ui::Exception) {
    ui->setupUi(this);
}

Exception::~Exception() {
    delete ui;
}

void Exception::pathExists(std::string nameOfFile) {
    std::filesystem::path pathToFile(nameOfFile);
    if (!exists(pathToFile)) {
        throw;
    }
}

void Exception::fileNotExists(std::filesystem::path name) {
    if (!exists(name)) {
        throw;
    }
}

void Exception::lineToSetEmpty(std::string lineToCheck) {
        if(lineToCheck.empty())
        {
            throw;
        }
}