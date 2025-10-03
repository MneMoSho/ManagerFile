//
// Created by Gleb on 27.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DisplayText.h" resolved

#include "displaytext.h"
#include "ui_DisplayText.h"


DisplayText::DisplayText(QWidget *parent) :
        QWidget(parent), ui(new Ui::DisplayText) {
    ui->setupUi(this);
}

void DisplayText::displayBrowser()
{
    ui->textToDisplay->show();
}

void DisplayText::enterIntoBox(QString text) {
    ui->textToDisplay->append(text);
}

DisplayText::~DisplayText() {
    delete ui;
}
