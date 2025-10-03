//
// Created by Gleb on 28.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_lineToAdd.h" resolved

#include "LineToAdd.h"
#include "ui_lineToAdd.h"


lineToAdd::lineToAdd(QWidget *parent) :
        QWidget(parent), ui(new Ui::lineToAdd) {
    ui->setupUi(this);
}

lineToAdd::~lineToAdd() {
    delete ui;
}
