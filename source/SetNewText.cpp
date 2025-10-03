//
// Created by Gleb on 29.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_setNewText.h" resolved

#include "SetNewText.h"
#include "ui_setNewText.h"


setNewText::setNewText(QWidget *parent) :
        QWidget(parent), ui(new Ui::setNewText) {
    ui->setupUi(this);
    connect(ui->buttonToSubmit, SIGNAL(buttonToSubmit), this, SLOT(on_buttonToSubmit_clicked));
    ui->browsingText->setVisible(false);
    ui->textInFile->setVisible(false);
}

setNewText::~setNewText() {
    delete ui;
}

void setNewText::on_buttonToSubmit_clicked() {
    emit signalToQuit();
    QWidget::close();
}

void setNewText::createNewText(std::string name) {
    ui->browsingText->setVisible(false);
    ui->textInFile->setVisible(false);
    std::ofstream fout;
    fout.open(name, std::ofstream::app);
    std::cout<<name;
    if(!fout.is_open())
    {
        std::cout<<"Error";
    }
    QStringList lines = ui->textEditor->toPlainText().split("\n");
    for (const QString &line: lines) {
        fout << line.toStdString()<<"\n";
    }
    fout.close();
}

void setNewText::textToRead(const QString &line)
{
    ui->label->setVisible(false);
    ui->textInFile->setVisible(true);
    ui->textEditor->setVisible(false);
    ui->browsingText->setVisible(true);
    qDebug()<<line;
ui->browsingText->append(line);
}

void setNewText::updatingFile(std::string lineToSet)
{
    ui->label->setVisible(false);
    ui->textInFile->setVisible(false);
    ui->textEditor->setVisible(true);
    ui->browsingText->setVisible(false);
    ui->textEditor->append(QString::fromStdString(lineToSet));
}

QString setNewText::getFromTextBrowser() {
QString text = ui->textEditor->toPlainText();
return text;
}