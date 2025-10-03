//
// Created by Gleb on 27.10.2024.
//

#ifndef UNTITLED4_DISPLAYTEXT_H
#define UNTITLED4_DISPLAYTEXT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class DisplayText; }
QT_END_NAMESPACE

class DisplayText : public QWidget {
Q_OBJECT

public:
    friend class DirectoryProperties;

    explicit DisplayText(QWidget *parent = nullptr);

    void enterIntoBox(QString text);
    void displayBrowser();

    ~DisplayText() override;

signals:

    void signalToShow();

private:
    Ui::DisplayText *ui;
};


#endif //UNTITLED4_DISPLAYTEXT_H
