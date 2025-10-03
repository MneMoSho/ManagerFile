//
// Created by Gleb on 27.11.2024.
//

#ifndef UNTITLED4_JSONREPORT_H
#define UNTITLED4_JSONREPORT_H

#include <QWidget>
#include <QtCore>
#include <QtGUI>
#include "header.h"

QT_BEGIN_NAMESPACE
namespace Ui { class JsonReport; }
QT_END_NAMESPACE

class JsonReport : public QWidget {
Q_OBJECT

public:
    explicit JsonReport(QWidget *parent = nullptr);
    ~JsonReport() override;
    void setJsonPath(std::string path);
    void addToJsonFile(QJsonObject jsonObject)
    {
        qDebug()<<"\nworking\n";
        if (!jSonObject.contains("files")) {
            jSonObject["files"] = QJsonArray(); // Создаем массив, если его еще нет
        }
        QJsonArray jsonArray = jSonObject["files"].toArray();
        jsonArray.append(jsonObject);
        jSonObject["files"] = jsonArray;
    }
    void saveToReport();
    void createNewReport();
    void clearReport();

private:
    Ui::JsonReport *ui;
    std::string pathToFile;
    QJsonObject jSonObject;
    QFile jSonFile;
    QJsonDocument jsonDoc;
};


#endif //UNTITLED4_JSONREPORT_H
