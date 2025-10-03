//
// Created by Gleb on 03.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DisplayAllFolders.h" resolved

#include "DisplayBucketFiles.h"
#include "ui_DisplayBucketFiles.h"


DisplayBinFiles::DisplayBinFiles(QWidget *parent) :
        QWidget(parent), ui(new Ui::DisplayBucketFiles) {
    ui->setupUi(this);
    connect(ui->displayFolders, &QTreeView::clicked, this, &DisplayBinFiles::checkForClicked);
    connect(ui->buttonToReturn, SIGNAL(buttonToReturn), this, SLOT(on_buttonToReturn_clicked()));
}

DisplayBinFiles::~DisplayBinFiles() {
    delete ui;
}

void DisplayBinFiles::slotToDisplay() {
    QString path = "I:\\O\\";//поменять под ноутбук
    dirmodel = new QFileSystemModel(this);
    viewTree = new QTreeView(this);
    std::cout << path.toStdString();
    dirmodel->setRootPath(path);
    viewTree->setModel(dirmodel);
    viewTree->setRootIndex(dirmodel->index(path));
    ui->displayFolders->setModel(dirmodel);
    ui->displayFolders->setRootIndex(dirmodel->index(path));
    viewTree->setSortingEnabled(false);
    dirmodel->sort(1, Qt::AscendingOrder);
}

void DisplayBinFiles::checkForClicked(const QModelIndex &index) {
    indexToSet = index;
    QString nameToFile = dirmodel->fileName(index);
    std::cout << "\n" << indexToSet.row() << " ";
    emit signalToSetIndex(nameToFile.toStdString());
    indexToSet = QModelIndex();
    emit signalIsExited(1);
    QWidget::close();
}

void DisplayBinFiles::on_buttonToReturn_clicked() {

    if (!indexToSet.isValid()) {
        indexToSet = QModelIndex();
        std::cout << "Entered wrong index\n";
        QWidget::close();
        emit signalIsExited(-1);
        return;
    }
    else
    {
        QWidget::close();
        emit signalIsExited(1);
        return;
    }
}