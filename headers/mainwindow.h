//
// Created by Gleb on 20.10.2024.
//

#ifndef UNTITLED4_MAINWINDOW_H
#define UNTITLED4_MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTreeView>
#include <QMenu>
#include <QFileSystemModel>
#include "settingdir.h"
#include <QFileDialog>
#include "setnewname.h"
#include "DirectoryProperties.h"
#include "FileEdit.h"
#include "NameEnter.h"
#include "Editor.h"
#include "BinBucket.h"
#include "DisplayBucketFiles.h"
#include "Exception.h"
#include "Filter.h"
#include "PathContainerFile.h"
#include <QListView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    friend class DirectoryProperties;
explicit MainWindow(QWidget *parent = nullptr);

~MainWindow() override;

    void renameDir();
    void onMenuHoveredDirectories(QAction *action);
    void findLastName(std::string *nameToApply);
    void returnNewName(QString *nameToChange, MainWindow *windowToSet);
    void displayContentOfFolder();
    void deleteFolder();
    void refreshView();
    void createNewFile();
    void setNameOfFile(QString nameOfFile);
    void onMenuHoveredFiles(QAction *action);
    QString getNameOfFile();
    void updateFile();
    void readFile();
    void deleteFile();
    void enterInfo();
    void deleteFullFile();
    void copyingContent();
    void deleteSimillarType();
    void onDirectoryClicked(const QModelIndex &index);
    void addIntoList();
    void moveBack();
    void getNameByClick(const QModelIndex &index);
    int numberOfFiles(int numberOfFiles);
    void checkForEmptiness();
    void folderToClear();
    void textToFile();
    void checkForEmptyName(std::string nameOfFile);
    void moveByQueue();
    void moveByIndex();
    void startFromDirectory();
    void filtureBySize();
    void setTreeView();
    void stackIsEmptyOnBottom(int indexToCheck);
    void stackIsEmptyOnTop(int indexToCheck);
    void closeEvent(QCloseEvent *event);

public slots:

    void slotToApply(QString text);
    void slotToNewFile(QString newName);
    void setNewName(QString text);
    QString getNewName();

private slots:

    void nameForDirChanged(QString text);
    void on_buttonToApply_clicked();
    void on_backButton_clicked();
    void on_aheadButton_clicked();
    void onMenuHovered(QAction *action);
    void openFromFile();
    void setName(QString name);
    void createAnExisting();
    void slotToSetNumber(QString numberOfLine);
    void slotToSetSecond(QString nameOfSecond);
    void slotToSetExtension(const QString& typeOfExtension);
    void onTextChanged();
    void slotToSetIndex(std::string nameToSet);
    void slotToExit(int code);
    void filterByExtension();
    void doubleClickOnFolder(const QModelIndex &index);

signals:

    void signalToSetDiskDirectory(std::string diskName);
    void signalToSetSecondMode();
    void signalToSetDefault();
    void nameChangedBig();
    void signalToChange();
    void signalToSetExtension();
    void signalToShow();

private:

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    Ui::MainWindow *ui;
    int numberOfMovement = 0;
    int index = 0;
    int currentIndex = 0;
    int numberOfLines;
    int indexOfComboBox = 0;
    QFileSystemModel *dirmodel;
    QTreeView *viewTree;
    QMenu fileMenu;
    QMenu leftMenu;
    QMenu mMenu;
    QMenu editDir;
    QMenu editFile;
    QString fileToCheck;
    QString pName;
    QString nameChanged;
    QString nameToFile;
    QString nameToSecond;
    QString extension;
    SettingDirectoryMode *setDir;
    SetNewName *setNew;
    NameEnter *enterNewName;
  QEventLoop loop;
    QTreeView* rootViewer;
    QFileSystemModel* modelRoot;
    BinBucket tempFiles;
    DisplayBinFiles* displayBinFiles;
    Filter filture;
    FileComponents componetOfFiles;
    PathContainerFile containerPath;
};


#endif //UNTITLED4_MAINWINDOW_H
