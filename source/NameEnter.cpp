//
// Created by Gleb on 28.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NameEnter.h" resolved

#include "NameEnter.h"
#include "ui_NameEnter.h"


NameEnter::NameEnter(QWidget *parent) :
        QWidget(parent), ui(new Ui::NameEnter) {
    ui->setupUi(this);
    if(ui->lineToSet->text().isEmpty())
    {
        ui->setNumber->setDisabled(true);
        ui->setIndex->setDisabled(true);
        ui->setSecondName->setDisabled(true);
        ui->setNumber->setDisabled(true);
        ui->setSecondName->setDisabled(true);
        ui->buttonToSet->setDisabled(true);
    }
    connect(ui->buttonToSet, SIGNAL(buttonToSet), this, SLOT(on_buttonToSet_clicked));
    connect(ui->setNumber, SIGNAL(setNumber), this, SLOT(on_setNumber_clicked));
    connect(ui->setSecondName, SIGNAL(setSecondName), this, SLOT(on_setSecondName_clicked));
    connect(ui->comboBox, SIGNAL(comboBox), this, SLOT(on_comboBox_activated));
    connect(ui->setIndex, SIGNAL(setIndex), this, SLOT(on_setIndex_clicked));
    connect(ui->lineToSet, &QLineEdit::textChanged, this, &NameEnter::isDisabled);
    connect(ui->buttonToClose, SIGNAL(buttonToClose), this, SLOT(on_buttonToClose_clicked()));
}

NameEnter::~NameEnter() {
    delete ui;
}

void NameEnter::isDisabled() {
    if(ui->lineToSet->text().isEmpty())
    {
        ui->setNumber->setDisabled(true);
        ui->setIndex->setDisabled(true);
        ui->setSecondName->setDisabled(true);
        ui->setNumber->setDisabled(true);
        ui->setSecondName->setDisabled(true);
        ui->buttonToSet->setDisabled(true);
    }
    else
    {
        ui->setNumber->setDisabled(false);
        ui->setIndex->setDisabled(false);
        ui->setSecondName->setDisabled(false);
        ui->setNumber->setDisabled(false);
        ui->setSecondName->setDisabled(false);
        ui->buttonToSet->setDisabled(false);
    }
}

void NameEnter::setToDefault()
{
    ui->lineToSet->clear();
    ui->lineToSet->setText(".txt");
    ui->lineToSet->setCursorPosition(0);
    ui->lineToSet->setVisible(true);
    ui->comboBox->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->setSecondName->setVisible(false);
    ui->secondName->setVisible(false);
    ui->setNumber->setVisible(false);
    ui->buttonToSet->setVisible(true);
    ui->numberOfLines->setVisible(false);
    ui->label->setVisible(true);
    ui->indexToSet->setVisible(false);
    ui->setIndex->setVisible(false);
    ui->Extension->setVisible(false);
}

void NameEnter::on_buttonToSet_clicked() {
    emit signalToApply(ui->lineToSet->text());
    QWidget::close();
}

void NameEnter::slotToChange()
{
    ui->Extension->setVisible(false);
    ui->lineToSet->clear();
    ui->comboBox->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->setSecondName->setVisible(false);
    ui->secondName->setVisible(false);
    ui->setNumber->setVisible(true);
    ui->buttonToSet->setVisible(false);
    ui->numberOfLines->setVisible(true);
    ui->label->setVisible(false);
    ui->indexToSet->setVisible(false);
    ui->setIndex->setVisible(false);
}

void NameEnter::on_setNumber_clicked()
{
    qDebug()<<"number is setting";
    emit signalToSetNumber(ui->lineToSet->text());
    QWidget::close();
}

void NameEnter::slotToSecondMode()
{
    ui->Extension->setVisible(false);
    ui->lineToSet->clear();
    ui->lineToSet->setVisible(true);
    ui->comboBox->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->setSecondName->setVisible(true);
    ui->secondName->setVisible(true);
    ui->setNumber->setVisible(false);
    ui->buttonToSet->setVisible(false);
    ui->numberOfLines->setVisible(false);
    ui->label->setVisible(false);
    ui->indexToSet->setVisible(false);
    ui->setIndex->setVisible(false);
}

void NameEnter::on_setSecondName_clicked()
{
    emit signalToSetSecond(ui->lineToSet->text());
    QWidget::close();
}

void NameEnter::setComboBox() {
    ui->indexToSet->setVisible(false);
    ui->Extension->setVisible(true);
    ui->setIndex->setVisible(false);
    ui->comboBox->setVisible(true);
    ui->lineToSet->clear();
    ui->label->setVisible(false);
    ui->numberOfLines->setVisible(false);
    ui->setNumber->setVisible(false);
    ui->buttonToSet->setVisible(false);
    ui->setSecondName->setVisible(false);
    ui->secondName->setVisible(false);
    ui->lineToSet->setVisible(false);
}

void NameEnter::checkingForExtensions(std::string pathToDirectory)
{
    for(const auto &entry : std::filesystem::directory_iterator(pathToDirectory))
    {
      if(std::filesystem::is_regular_file(entry.status()))
      {
          std::string extension = entry.path().extension().string();
          if(!extension.empty())
          {
              extensionSet.insert(extension);
          }
      }
    }
    for(const auto& extensionIterator : extensionSet)
    {
        ui->comboBox->addItem(QString::fromStdString(extensionIterator));
    }
}

void NameEnter::on_comboBox_activated() {
    emit signalToGetExtension(ui->comboBox->currentText());
    clearComponents();
    QWidget::close();
}

void NameEnter::clearComponents() {
    ui->comboBox->clear();
    extensionSet.clear();
}

void NameEnter::on_buttonToClose_clicked() {
    QWidget::close();
}