//
// Created by Gleb on 22.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingDir.h" resolved

#include "settingdir.h"
#include "ui_SettingDir.h"

SettingDirectoryMode::SettingDirectoryMode(QWidget *parent) :
        QWidget(parent), ui(new Ui::SettingDirectoryMode) {
    ui->setupUi(this);
    if(ui->directoryLine->text().isEmpty())
    {
        ui->buttonToApply->setDisabled(true);
    }
    connect(ui->directoryLine, &QLineEdit::textChanged, this, &SettingDirectoryMode::checkForLine);
    connect(ui->buttonToApply, SIGNAL(buttonToApply), this, SLOT(on_buttonToApply_clicked));
    ui->directoryLine->clear();
}

SettingDirectoryMode::~SettingDirectoryMode() {
    delete ui;
}

void SettingDirectoryMode::settingDiskName(std::string diskNameToSet)
{
    diskName=diskNameToSet;
    ui->directoryLine->setText(QString::fromStdString(diskName));
}

void SettingDirectoryMode::checkForLine() {
    if(ui->directoryLine->text().isEmpty() || ui->directoryLine->text() == diskName)
    {
        ui->buttonToApply->setDisabled(true);
    }
    else
    {
        ui->buttonToApply->setDisabled(false);
    }
}

void SettingDirectoryMode::on_buttonToApply_clicked() {
    qDebug()<<"CHECKED";
    emit signalToApply(ui->directoryLine->text());
   emit signalToDisplay(ui->directoryLine->text());
    QWidget::close();
}