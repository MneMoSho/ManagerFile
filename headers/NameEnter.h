//
// Created by Gleb on 28.10.2024.
//

#ifndef UNTITLED4_NAMEENTER_H
#define UNTITLED4_NAMEENTER_H

#include <QWidget>
#include "Header.h"
#include <set>

QT_BEGIN_NAMESPACE
namespace Ui { class NameEnter; }
QT_END_NAMESPACE

class NameEnter : public QWidget {
Q_OBJECT

public:
    explicit NameEnter(QWidget *parent = nullptr);

    ~NameEnter() override;

public slots:

    void checkingForExtensions(std::string pathToDirectory);
    void on_buttonToSet_clicked();
    void on_setNumber_clicked();
    void slotToChange();
    void setToDefault();
    void slotToSecondMode();
    void on_setSecondName_clicked();
    void on_comboBox_activated();
    void setComboBox();
    void isDisabled();
    void clearComponents();
    void on_buttonToClose_clicked();

signals:
    void signalToApply(const QString textToApply);
    void signalToSetNumber(const QString textToApply);
    void signalToSetSecond(const QString textToApply);
    void signalToGetExtension(const QString& extension);

private:
    Ui::NameEnter *ui;
    std::set<std::string> extensionSet;
};


#endif //UNTITLED4_NAMEENTER_H
