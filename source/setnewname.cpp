//
// Created by Gleb on 27.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SetNewName.h" resolved

#include "setnewname.h"
#include "ui_SetNewName.h"


SetNewName::SetNewName(QWidget *parent) :
        QWidget(parent), ui(new Ui::SetNewName) {
    ui->setupUi(this);

    connect(ui->buttonToSet, SIGNAL(buttonToSet), this, SLOT(on_buttonToSet_clicked));
}

SetNewName::~SetNewName() {
    delete ui;
}

void SetNewName::on_buttonToSet_clicked() {

    emit signalToApply(ui->lineToSet->text());
    QWidget::close();
}