//
// Created by Gleb on 17.11.2024.
//

#ifndef UNTITLED4_EXCEPTION_H
#define UNTITLED4_EXCEPTION_H

#include <QWidget>
#include "Header.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Exception; }
QT_END_NAMESPACE

class Exception : public QWidget {
Q_OBJECT

public:
    explicit Exception(QWidget *parent = nullptr);

    ~Exception() override;

    void pathExists(std::string nameOfFile);
    void fileNotExists(std::filesystem::path name);
    void lineToSetEmpty(std::string lineToCheck);

private:
    Ui::Exception *ui;
};


#endif //UNTITLED4_EXCEPTION_H
