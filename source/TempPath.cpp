//
// Created by Gleb on 30.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TempPath.h" resolved

#include "TempPath.h"
#include "ui_TempPath.h"


TempPath::TempPath(QWidget *parent) :
        QWidget(parent), ui(new Ui::TempPath) {
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    connect(ui->treeView, &QTreeView::clicked, this, &TempPath::setIndexOfSelected);
}

TempPath::~TempPath() {
    delete ui;
}

void TempPath::appendingItem(std::string textToAppend)
{
QStandardItem *item = new QStandardItem(QString::fromStdString(textToAppend));
model->appendRow(item);
}

void TempPath::setIndexOfSelected() {
    qDebug()<<"in treee\n";
    QModelIndex indexOfElement = ui->treeView->currentIndex();
    item = model->itemFromIndex(indexOfElement);
    indexOfSelected = item->row();
    qDebug()<<item->text()<<" \n";
    qDebug()<<item->index()<<"\n";
    model->removeRow(indexOfElement.row(), indexOfElement.parent());
    emit signalToCloseWidget();
    widgetClosing();
}

void TempPath::widgetClosing()
{
    QWidget::close();
}

int TempPath::getIndexOfSelected() {
    return indexOfSelected;
}