//
// Created by Gleb on 27.10.2024.
//

#ifndef UNTITLED4_SETNEWNAME_H
#define UNTITLED4_SETNEWNAME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SetNewName; }
QT_END_NAMESPACE

class SetNewName : public QWidget {
Q_OBJECT

public:
    explicit SetNewName(QWidget *parent = nullptr);

    ~SetNewName() override;

    public slots:
    void on_buttonToSet_clicked();

    signals:
    void signalToApply(const QString textToApply);

private:
    Ui::SetNewName *ui;
};


#endif //UNTITLED4_SETNEWNAME_H
