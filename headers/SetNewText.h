//
// Created by Gleb on 29.10.2024.
//

#ifndef UNTITLED4_SETNEWTEXT_H
#define UNTITLED4_SETNEWTEXT_H

#include <QWidget>
#include "Header.h"


QT_BEGIN_NAMESPACE
namespace Ui { class setNewText; }
QT_END_NAMESPACE

class setNewText : public QWidget {
Q_OBJECT

public:
    explicit setNewText(QWidget *parent = nullptr);
    ~setNewText() override;
    void createNewText(std::string name);
    public slots:
    void on_buttonToSubmit_clicked();
    void textToRead(const QString& line);
    void updatingFile(std::string lineToSet);
    QString getFromTextBrowser();

    signals:
    void signalToQuit();
private:

    Ui::setNewText *ui;
};


#endif //UNTITLED4_SETNEWTEXT_H
