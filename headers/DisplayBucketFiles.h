//
// Created by Gleb on 03.11.2024.
//

#ifndef UNTITLED4_DISPLAYBUCKETFILES_H
#define UNTITLED4_DISPLAYBUCKETFILES_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QDebug>
#include <iostream>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayBucketFiles; }
QT_END_NAMESPACE

class DisplayBinFiles : public QWidget {
Q_OBJECT

public:
    explicit DisplayBinFiles(QWidget *parent = nullptr);

    ~DisplayBinFiles() override;
   QString path;

   void checkForClicked(const QModelIndex &index);

signals:

    void signalToSetIndex(std::string nameToSet);
    void signalIsExited(int code);

public slots:

    void slotToDisplay();

    void on_buttonToReturn_clicked();
private:
    QModelIndex indexToSet;
    Ui::DisplayBucketFiles *ui;
    QFileSystemModel *dirmodel;
    QTreeView *viewTree;
};


#endif //UNTITLED4_DISPLAYBUCKETFILES_H
