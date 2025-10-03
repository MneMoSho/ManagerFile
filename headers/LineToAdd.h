//
// Created by Gleb on 28.10.2024.
//

#ifndef UNTITLED4_LINETOADD_H
#define UNTITLED4_LINETOADD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class lineToAdd; }
QT_END_NAMESPACE

class lineToAdd : public QWidget {
Q_OBJECT

public:
    explicit lineToAdd(QWidget *parent = nullptr);

    ~lineToAdd() override;

private:
    Ui::lineToAdd *ui;
};


#endif //UNTITLED4_LINETOADD_H
