//
// Created by Gleb on 27.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FilturesToJson.h" resolved

#include "JsonReport.h"
#include "ui_JsonReport.h"

JsonReport::JsonReport(QWidget *parent) :
        QWidget(parent), ui(new Ui::JsonReport) {
    ui->setupUi(this);
    jSonObject = QJsonObject();
}

JsonReport::~JsonReport() {
    delete ui;
}

void JsonReport::setJsonPath(std::string path) {
    pathToFile = path;
    jSonFile.setFileName(QString::fromStdString(pathToFile));
    createNewReport();
}

void JsonReport::saveToReport()
{
    jsonDoc.setObject(jSonObject);
    if (!jSonFile.open(QIODevice::WriteOnly)) {
        qWarning("Error opening");
        return;
    }
    jSonFile.write(jsonDoc.toJson(QJsonDocument::Indented));
    jSonFile.close();
}

void JsonReport::createNewReport() {
    qDebug() << pathToFile;
    if (!QFile::exists(QString::fromStdString(pathToFile))) {
        qDebug() << "file is created";
        QFile file(QString::fromStdString(pathToFile));
        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }
        file.close();
    } else
    {
        return;
    }
    return;
}

void JsonReport::clearReport() {
std::ofstream reportName;
    reportName.open(pathToFile);
    reportName.close();
}