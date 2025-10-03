//
// Created by Gleb on 30.11.2024.
//

#ifndef UNTITLED4_TEMPPATH_H
#define UNTITLED4_TEMPPATH_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QEventLoop>


QT_BEGIN_NAMESPACE
namespace Ui { class TempPath; }
QT_END_NAMESPACE

class TempPath : public QWidget {
Q_OBJECT

public:
    explicit TempPath(QWidget *parent = nullptr);
    ~TempPath() override;
   void appendingItem(std::string textToAppend);
   void setIndexOfSelected();
   int getIndexOfSelected();
   void widgetClosing();

   signals:
    void signalToCloseWidget();

private:

    int indexOfSelected = 0;
    QStandardItem *item = new QStandardItem();
    QTreeView treView;
    QStandardItemModel* model;
    Ui::TempPath *ui;
    QEventLoop loop;
};


#endif //UNTITLED4_TEMPPATH_H
