//
// Created by Gleb on 20.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <QWidgetAction>
#include "Path.h"
#include "Header.h"
#include "DirectoryProperties.h"
#include "FileProperties.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    if (ui->lineEdit->text().isEmpty()) {
        ui->buttonToApply->setDisabled(true);
    }
    ui->backButton->setDisabled(true);
    ui->aheadButton->setDisabled(true);
    startFromDirectory();
    setDir = new SettingDirectoryMode;
    setNew = new SetNewName;
    enterNewName = new NameEnter;
    displayBinFiles = new DisplayBinFiles;
    QLabel *nameOfMenu = new QLabel("Name", &fileMenu);
    QLabel *label = new QLabel("Menu", &mMenu);
    label->setAlignment(Qt::AlignCenter);
    label->setMinimumHeight(30);
    QWidgetAction *action = new QWidgetAction(&mMenu);
    action->setDefaultWidget(label);
    QWidgetAction *fileMenuToSet = new QWidgetAction(&fileMenu);
    fileMenuToSet->setDefaultWidget(nameOfMenu);
    qDebug() << QDir::rootPath();
    QString sPath;
    modelRoot = new QFileSystemModel(this);
    rootViewer = new QTreeView();
    modelRoot->setRootPath(sPath);
    ui->rootDirectories->setModel(modelRoot);
    QAction *editFolder = new QAction("edit folder", &mMenu);
    QAction *editFiles = new QAction("edit files", &mMenu);
    QAction *changeFolder = new QAction("change folder", &mMenu);
    QAction *setDirectory = new QAction("Create new folder", &leftMenu);
    QAction *chooseFromFile = new QAction("Set from file", &leftMenu);
    QAction *renameDir = new QAction("rename", &editDir);
    QAction *deleteDir = new QAction("delete current", &editDir);
    QAction *showDir = new QAction("show content", &editDir);
    QAction *createFile = new QAction("create new file", &editFile);
    QAction *updateFile = new QAction("update an existing file", &editFile);
    QAction *readFile = new QAction("read file", &editFile);
    QAction *deleteLine = new QAction("delete line", &editFile);
    QAction *deleteFile = new QAction("delete file", &editFile);
    QAction *copyToAnother = new QAction("copy content of another file", &editFile);
    QAction *deleteWithSimillarExtension = new QAction("delete with simillar extension", &editFile);
    QAction *allInBucket = new QAction("bin", &editFile);
    QAction *moveFileBack = new QAction("move back", &editFile);
    QAction *moveByHand = new QAction("move into bin", &fileMenu);
    QAction *inputText = new QAction("writeText", &fileMenu);
    QAction *filterByExtension = new QAction("filter by extension", &editFile);
    QAction *sizeFilture = new QAction("filter by size", &editFile);
    QAction *containerRandom = new QAction("history of visiting", &mMenu);

    mMenu.addAction(action);
    mMenu.addAction(editFolder);
    mMenu.addAction(editFiles);
    mMenu.addAction(changeFolder);
    mMenu.addAction(containerRandom);
    leftMenu.addAction(setDirectory);
    leftMenu.addAction(chooseFromFile);
    editDir.addAction(renameDir);
    editDir.addAction(deleteDir);
    editDir.addAction(showDir);
    editFile.addAction(createFile);
    editFile.addAction(updateFile);
    editFile.addAction(readFile);
    editFile.addAction(deleteLine);
    editFile.addAction(deleteFile);
    editFile.addAction(copyToAnother);
    editFile.addAction(deleteWithSimillarExtension);
    editFile.addAction(moveFileBack);
    editFile.addAction(filterByExtension);
    editFile.addAction(sizeFilture);
    fileMenu.addAction(inputText);
    fileMenu.addAction(moveByHand);
    connect(&mMenu, &QMenu::hovered, this, &MainWindow::onMenuHovered);
    connect(&mMenu, &QMenu::hovered, this, &MainWindow::onMenuHoveredDirectories);
    connect(&mMenu, &QMenu::hovered, this, &MainWindow::onMenuHoveredFiles);

    connect(chooseFromFile, &QAction::triggered, this, &MainWindow::openFromFile);
    connect(setDirectory, &QAction::triggered, this, &MainWindow::createAnExisting);

    connect(renameDir, &QAction::triggered, this, &MainWindow::renameDir);
    connect(showDir, &QAction::triggered, this, &MainWindow::displayContentOfFolder);
    connect(deleteDir, &QAction::triggered, this, &MainWindow::deleteFolder);

    connect(createFile, &QAction::triggered, this, &MainWindow::createNewFile);
    connect(enterNewName, &NameEnter::signalToApply, this, &MainWindow::slotToNewFile);
    connect(updateFile, &QAction::triggered, this, &MainWindow::updateFile);
    connect(readFile, &QAction::triggered, this, &MainWindow::readFile);
    connect(deleteLine, &QAction::triggered, this, &MainWindow::deleteFile);
    connect(deleteFile, &QAction::triggered, this, &MainWindow::deleteFullFile);
    connect(copyToAnother, &QAction::triggered, this, &MainWindow::copyingContent);
    connect(deleteWithSimillarExtension, &QAction::triggered, this, &MainWindow::deleteSimillarType);
    connect(moveFileBack, &QAction::triggered, this, &MainWindow::moveBack);
    connect(moveByHand, &QAction::triggered, this, &MainWindow::addIntoList);
    connect(inputText, &QAction::triggered, this, &MainWindow::textToFile);

    connect(this, &MainWindow::signalToChange, enterNewName, &NameEnter::slotToChange);
    connect(this, &MainWindow::signalToSetDefault, enterNewName, &NameEnter::setToDefault);
    connect(this, &MainWindow::signalToSetSecondMode, enterNewName, &NameEnter::slotToSecondMode);
    connect(this, &MainWindow::signalToSetExtension, enterNewName, &NameEnter::setComboBox);
    connect(this, &MainWindow::signalToShow, displayBinFiles, &DisplayBinFiles::slotToDisplay);

    connect(enterNewName, &NameEnter::signalToSetNumber, this, &MainWindow::slotToSetNumber);
    connect(enterNewName, &NameEnter::signalToSetSecond, this, &MainWindow::slotToSetSecond);
    connect(enterNewName, &NameEnter::signalToGetExtension, this, &MainWindow::slotToSetExtension);
    connect(displayBinFiles, &DisplayBinFiles::signalToSetIndex, this, &MainWindow::slotToSetIndex);

    connect(ui->buttonToApply, SIGNAL(buttonToApply), this, SLOT(on_buttonToApply_clicked));
    connect(setNew, &SetNewName::signalToApply, this, &MainWindow::nameForDirChanged);
    connect(setDir, &SettingDirectoryMode::signalToApply, this, &MainWindow::slotToApply);
    connect(setDir, &SettingDirectoryMode::signalToDisplay, this, &MainWindow::on_buttonToApply_clicked);

    connect(enterNewName, &NameEnter::signalToApply, &loop, &QEventLoop::quit);
    connect(enterNewName, &NameEnter::signalToSetNumber, &loop, &QEventLoop::quit);
    connect(enterNewName, &NameEnter::signalToSetSecond, &loop, &QEventLoop::quit);
    connect(enterNewName, &NameEnter::signalToGetExtension, &loop, &QEventLoop::quit);
    connect(displayBinFiles, &DisplayBinFiles::signalIsExited, &loop, &QEventLoop::quit);

    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::onDirectoryClicked);
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::getNameByClick);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onTextChanged);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::checkForEmptiness);

    connect(displayBinFiles, &DisplayBinFiles::signalIsExited, this, &MainWindow::slotToExit);
    connect(filterByExtension, &QAction::triggered, this, &MainWindow::filterByExtension);
    connect(sizeFilture, &QAction::triggered, this, &MainWindow::filtureBySize);
    connect(containerRandom, &QAction::triggered, this, &MainWindow::moveByIndex);
    connect(ui->aheadButton, SIGNAL(aheadButton), this, SLOT(on_aheadButton_clicked()));
    connect(ui->backButton, SIGNAL(backButton), this, SLOT(on_backButton_clicked()));
    connect(this, &MainWindow::signalToSetDiskDirectory, setDir, &SettingDirectoryMode::settingDiskName);
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClickOnFolder);

}

void MainWindow::doubleClickOnFolder(const QModelIndex &index) {
    QString path = dirmodel->filePath(index);
    QFileInfo fileInfo(path);
    if (!fileInfo.isFile()) {
        pName = path;
        on_buttonToApply_clicked();
    }
}

void MainWindow::checkForEmptiness() {
    if (!ui->lineEdit->text().isEmpty()) {
        ui->buttonToApply->setDisabled(false);
    } else
        ui->buttonToApply->setDisabled(true);
}

void MainWindow::stackIsEmptyOnBottom(int indexToCheck) {
    try {
        containerPath.checkForMeasures(indexToCheck);
        ui->backButton->setDisabled(false);
    }
    catch (const std::runtime_error &e) {
        ui->backButton->setDisabled(true);
    }
}

void MainWindow::stackIsEmptyOnTop(int indexToCheck) {
    try {
        containerPath.checkForMeasuresTop(indexToCheck, numberOfMovement);
        ui->aheadButton->setDisabled(false);
    }
    catch (const std::runtime_error &e) {
        ui->aheadButton->setDisabled(true);
    }
}

void MainWindow::checkForEmptyName(std::string nameOfFile) {
    if (nameOfFile.empty()) {
        enterInfo();
    }
}

MainWindow::~MainWindow() {
    folderToClear();
    delete ui;
}

void MainWindow::folderToClear() {
    tempFiles.folderClear();
}

void MainWindow::setName(QString name) {
    pName = name;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    std::ofstream readFromFile("openFromStart.txt");
    readFromFile<<pName.toStdString();
    readFromFile.close();
    event->accept();
}

void MainWindow::startFromDirectory() {
    std::filesystem::path pathToFile;
    std::string fileToStart;
    std::ifstream readFromFile("openFromStart.txt");
    if(readFromFile.peek() == EOF)
    {
        std::cout<<"file is empty";
    }
    else
    {
        std::cout<<"file is opened from folder";
        std::string line;
        std::getline(readFromFile, line);
        pName = QString::fromStdString(line);
    }
    dirmodel = new QFileSystemModel(this);
    ui->lineEdit->setText(pName);
    componetOfFiles.setPathOfFile(pName.toStdString());
    containerPath.addPath(componetOfFiles);
    dirmodel->setRootPath(pName);
    ui->treeView->setModel(dirmodel);
    ui->treeView->setRootIndex(dirmodel->index(pName));
}

void MainWindow::textToFile() {
    auto objectCreate = std::make_unique<FilePropeties>();
    objectCreate->fileTextAdd(nameToFile.toStdString());
    std::cout << nameToFile.toStdString();
    on_buttonToApply_clicked();
}

void MainWindow::findLastName(std::string *nameToApply) {
    QString folderPath = pName;
    QString folderName = QFileInfo(folderPath).fileName();
    *nameToApply = folderPath.toStdString();
}

void MainWindow::enterInfo() {
    enterNewName->show();
    emit signalToSetDefault();
    loop.exec();
    nameToFile = pName + "\\" + nameToFile;
}

int checkingForEmptiness(QString checked) {
    std::filesystem::path fileToCheck = checked.toStdString();
    if (!exists(fileToCheck)) {
        throw 2;
    } else {
        return 1;
    }
}

void MainWindow::on_buttonToApply_clicked() {
    int numberToCheck = 0;
    try {
        numberToCheck = checkingForEmptiness(pName);
        componetOfFiles.setPathOfFile(pName.toStdString());
        containerPath.addPath(componetOfFiles);
        numberOfMovement = numberOfMovement + 1;
        currentIndex = numberOfMovement;
        setTreeView();
        stackIsEmptyOnBottom(currentIndex + 1);
        stackIsEmptyOnTop(currentIndex);
    }
    catch (int e) {
        QMessageBox::critical(this, tr("error"), tr("directory is not entered or entered wrong"));
        std::cout << "Error";
    }
}

void MainWindow::setTreeView() {
    dirmodel = new QFileSystemModel(this);
    viewTree = new QTreeView(this);
    ui->lineEdit->setText(pName);
    dirmodel->setRootPath(pName);
    viewTree->setModel(dirmodel);
    viewTree->setRootIndex(dirmodel->index(pName));
    ui->treeView->setModel(dirmodel);
    ui->treeView->setRootIndex(dirmodel->index(pName));
    stackIsEmptyOnTop(currentIndex);
    stackIsEmptyOnTop(currentIndex);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        QPoint pt;
        pt = event->globalPosition().toPoint();
        mMenu.popup(pt);
    }
}

void MainWindow::onMenuHovered(QAction *action) {
    QPoint pt;
    if (action->text() == "edit folder") {
        QRect actionGeometry = mMenu.actionGeometry(action);
        QPoint globalPos = mMenu.mapToGlobal(actionGeometry.topRight());
        leftMenu.popup(globalPos);
    }
}

void MainWindow::onMenuHoveredDirectories(QAction *action) {
    QPoint pt;
    if (action->text() == "change folder") {
        QRect actionGeometry = mMenu.actionGeometry(action);
        QPoint globalPos = mMenu.mapToGlobal(actionGeometry.topRight());
        editDir.popup(globalPos);
    }
}

void MainWindow::onMenuHoveredFiles(QAction *action) {
    QPoint pt;
    if (action->text() == "edit files") {
        QRect actionGeometry = mMenu.actionGeometry(action);
        QPoint globalPos = mMenu.mapToGlobal(actionGeometry.topRight());
        editFile.popup(globalPos);
    }
}

void MainWindow::openFromFile() {
    std::string destName;
    std::ifstream pathIn;
    Path newDir;
    DirectoryProperties dirCreation;
    pathIn.open("h:\\Course\\Manager\\Manager\\Directory.txt");
    while (!pathIn.eof()) {
        std::getline(pathIn, destName);
    }
    newDir.setDestination(destName);
    dirCreation.objectCreate(0, destName);
    setName(QString::fromStdString(destName));
    on_buttonToApply_clicked();
    pathIn.close();
}

void MainWindow::createAnExisting() {
    setDir->show();
    emit signalToSetDiskDirectory(pName.toStdString());
}

void MainWindow::slotToApply(QString text) {
    Exception pathToFile;
    try {
        std::cout << text.toStdString();
        pName = text;
        componetOfFiles.setPathOfFile(pName.toStdString());
        indexOfComboBox++;
        setName(text);
        std::string name;
        name = pName.toStdString();
        std::cout << name;
        DirectoryProperties dirCreation;
        dirCreation.objectCreate(0, name);
        QMessageBox::information(this, tr("warining"), tr("directory is created"));
    }
    catch (int e) {}
}

void MainWindow::nameForDirChanged(QString text) {
    nameChanged = text;
    std::string newName;
    setNewName(text);
    qDebug() << nameChanged;
    emit nameChangedBig();
}

void MainWindow::returnNewName(QString *nameToChange, MainWindow *windowToSet) {
    windowToSet->setNew->show();
    connect(this, &MainWindow::nameChangedBig, &loop, &QEventLoop::quit);
    loop.exec();
    *nameToChange = getNewName();
}

void MainWindow::renameDir() {
    std::cout << "index of file " << index << "\n";
    DirectoryProperties testExample;
    std::string newName;
    QString folderPath = pName;
    std::cout << pName.toStdString() << "\n";
    QString folderName = QFileInfo(folderPath).fileName();
    newName = folderPath.toStdString();
    testExample.fileUpdate(0, &newName);
    pName = QString::fromStdString(testExample.getDestination());
    ui->lineEdit->setText(pName);
    on_buttonToApply_clicked();
}

void MainWindow::setNewName(QString text) {
    nameChanged = text;
}

QString MainWindow::getNewName() {
    return nameChanged;
}

void MainWindow::displayContentOfFolder() {
    std::string nameOfFolder;
    DirectoryProperties displayContent;
    findLastName(&nameOfFolder);
    displayContent.fileRead(nameOfFolder);
}

void MainWindow::deleteFolder() {
    std::cout << "index " << index << "\n";
    DirectoryProperties deleteFolder;
    std::string nameOfFolder;
    findLastName(&nameOfFolder);
    containerPath.deleteFromStack();
    numberOfMovement -= 1;
    currentIndex = numberOfMovement;
    deleteFolder.lineDelete(0, &nameOfFolder);
    pName = QString::fromStdString(nameOfFolder);
    refreshView();
}

void MainWindow::refreshView() {
    dirmodel->setRootPath(pName);
    ui->treeView->setRootIndex(dirmodel->index(pName));
    ui->lineEdit->setText(pName);
}

void MainWindow::setNameOfFile(QString nameOfFile) {
    nameToFile = nameOfFile;
    // nameToFile = pName+nameToFile;
    loop.exec();
}

QString MainWindow::getNameOfFile() {
    return nameToFile;
}

void MainWindow::slotToNewFile(QString newName) {
    setNameOfFile(newName);
}

void MainWindow::slotToSetNumber(QString numberOfLine) {
    int totalLineCount = 0;
    totalLineCount = numberOfLine.toInt();
    std::cout << totalLineCount;
    numberOfLines = totalLineCount;
}

void MainWindow::createNewFile() {
    auto objectCreate = std::make_unique<FilePropeties>();
    int numberToCheck = 0;
    int lineNumb = 0;
    Exception checkForLine;
    try {
        checkForLine.lineToSetEmpty(ui->lineEdit->text().toStdString());
        enterInfo();
        objectCreate->objectCreate(1, nameToFile.toStdString());
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("file doesn't exsist or entered wrong"));
        return;
    }
}

void MainWindow::updateFile() {
    Exception checkForExsistence;
    std::filesystem::path name;
    int lineNumb = 0;
    auto objectCreate = std::make_unique<FilePropeties>();
    checkForEmptyName(nameToFile.toStdString());
    name = nameToFile.toStdString();
    try {
        checkForExsistence.fileNotExists(name);
        objectCreate->setLineCount(numberOfLines);
        lineNumb = objectCreate->getLineCount();
        QString nameOfFile = getNameOfFile();
        std::string nameOf = nameOfFile.toStdString();
        objectCreate->fileUpdate(lineNumb, &nameOf);
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("file doesn't exsist or entered wrong"));
        return;
    }
    setTreeView();
}

void MainWindow::readFile() {
    Exception checkForExsistence;
    try {
        checkForExsistence.fileNotExists(nameToFile.toStdString());
        auto objectCreate = std::make_unique<FilePropeties>();
        checkForEmptyName(nameToFile.toStdString());
        QString nameOfFile = getNameOfFile();
        std::string readFrom = nameOfFile.toStdString();
        objectCreate->fileRead(readFrom);
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("file doesn't exsist or entered wrong"));
    }
}

void MainWindow::deleteFile() {
    int maxNumber = 0;
    int lineNumb = 0;
    QFileInfo fileToCheck(nameToFile);
    std::cout << "\n" << nameToFile.toStdString() << "\n";
    if (fileToCheck.isFile()) {
        std::cout << "file\n";
    } else if (fileToCheck.isDir()) {
        std::cout << "directory\n";
        // nameToFile = pName;
        QMessageBox::critical(this, tr("warining"), tr("selected is not file"));
        return;
    }
    if (nameToFile.isEmpty()) {
        QMessageBox::critical(this, tr("warining"), tr("file is not selected"));
        return;
    }
    Exception checkFile;
    try {
        checkFile.lineToSetEmpty(ui->lineEdit->text().toStdString());
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("line to set is empty"));
    }
    auto objectCreate = std::make_unique<FilePropeties>();
    try {
        checkFile.fileNotExists(nameToFile.toStdString());
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("file enterd wrong"));
        return;
    }
    maxNumber = objectCreate->checkNumberOfLines(nameToFile.toStdString());
    if (maxNumber == 0) {
        QMessageBox::information(this, tr("warining"), tr("selected file is empty"));
        return;
    }
    enterNewName->show();
    emit signalToChange();
    loop.exec();
    std::cout << numberOfLines;
    if (numberOfLines > maxNumber) {
        QMessageBox::information(this, tr("warining"), tr("number is to big"));
        return;
    }
    objectCreate->setLineCount(numberOfLines);
    lineNumb = objectCreate->getLineCount();
    QString nameOfFile = getNameOfFile();
    std::string nameOf = nameOfFile.toStdString();
    objectCreate->lineDelete(lineNumb, &nameOf);
    refreshView();
}

void MainWindow::deleteFullFile() {
    Editor fileToDelete;
    checkForEmptyName(nameToFile.toStdString());
    std::string nameOfFile;
    nameOfFile = nameToFile.toStdString();
    fileToDelete.deleteFile(nameOfFile);
}

void MainWindow::slotToSetSecond(QString nameOfSecond) {
    nameToSecond = nameOfSecond;
}

void MainWindow::copyingContent() {
    checkForEmptyName(nameToFile.toStdString());
    enterNewName->show();
    emit signalToSetSecondMode();
    loop.exec();
    nameToSecond = pName + "\\" + nameToSecond;
    addToAnother(nameToFile.toStdString(), nameToSecond.toStdString(), pName.toStdString());
    setTreeView();
}

void MainWindow::slotToSetExtension(const QString &typeOfExtension) {
    extension = typeOfExtension;
}

void MainWindow::deleteSimillarType() {
    enterNewName->checkingForExtensions(pName.toStdString());
    enterNewName->show();
    emit signalToSetExtension();
    loop.exec();
    deleteSimillarTypeFile(pName.toStdString(), extension.toStdString());
    refreshView();
}

void MainWindow::onDirectoryClicked(const QModelIndex &index) {
    QString path = dirmodel->filePath(index);
    path.replace("/", "\\");
    // std::cout << path.toStdString();
    QFileInfo fileInfo(path);
    if (fileInfo.isFile()) {
        nameToFile = path;
        if (fileInfo.isFile()) {
            QPoint pt = QCursor::pos();
            fileMenu.popup(pt);
        }
        return;
    } else if (fileInfo.isDir()) {
        nameToFile = path;
        componetOfFiles.setPathOfFile(pName.toStdString());
    }
}

void MainWindow::onTextChanged() {
    pName = ui->lineEdit->text();
    on_buttonToApply_clicked();
}

void MainWindow::addIntoList() {
    if (nameToFile.isEmpty()) {
        enterNewName->show();
        emit signalToSetDefault();
        loop.exec();
        nameToFile = pName + "\\" + nameToFile;
    }
    FilePropeties objectCreate;

    std::cout<<"\n"<<nameToFile.toStdString()<<"\n";

    objectCreate.setFirstName(nameToFile.toStdString());
    tempFiles.addToList.pushFront(nameToFile.toStdString());
    tempFiles.moveToAnother<std::string>(nameToFile.toStdString());
    tempFiles.countNumberOfFIles();
}

void MainWindow::moveBack() {
    displayBinFiles->show();
    emit signalToShow();
    loop.exec();
    std::cout << index;
    if (index != -1) {
        index = tempFiles.findByName(fileToCheck.toStdString());
        std::cout << " " << index << " ";
        tempFiles.moveByIndex(index);
    } else
        return;
}

void MainWindow::slotToSetIndex(std::string nameToSet) {
    std::cout << pName.toStdString();
    fileToCheck = pName + "\\" + QString::fromStdString(nameToSet);
}

void MainWindow::slotToExit(int code) {
    index = code;
}

void MainWindow::getNameByClick(const QModelIndex &index) {
}

void MainWindow::filterByExtension() {
    Exception checkForLine;
    enterNewName->checkingForExtensions(pName.toStdString());
    enterNewName->show();
    emit signalToSetExtension();
    loop.exec();
    emit signalToSetDefault();
    try {
        checkForLine.lineToSetEmpty(ui->lineEdit->text().toStdString());
        std::filesystem::path pathToFile = pName.toStdString();
        for (const auto &entry: std::filesystem::directory_iterator(pathToFile)) {
            if (entry.is_regular_file()) {
                filture.separateComponents(entry.path(), entry.file_size());
            }
        }
        filture.filtureExtension(pName.toStdString(), extension.toStdString());
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("file doesn't exsist or entered wrong"));
    }
}

void MainWindow::moveByIndex() {
    componetOfFiles = containerPath.selectByIndex();
    pName = QString::fromStdString(componetOfFiles.getPathOfFile());
    on_buttonToApply_clicked();
}

void MainWindow::filtureBySize() {
    Exception checkForName;
    std::string nameToSet;
    int minimumSize = 30;
    try {
        checkForName.lineToSetEmpty(ui->lineEdit->text().toStdString());
        std::filesystem::path pathToFile = pName.toStdString();
        for (const auto &entry: std::filesystem::directory_iterator(pathToFile)) {
            if (entry.is_regular_file()) {
                filture.separateComponents(entry.path(), entry.file_size());
            }
        }
        filture.sizeFilter(pName.toStdString(), minimumSize);
    }
    catch (int e) {
        QMessageBox::critical(this, tr("warining"), tr("line is empty"));
    }
}

void MainWindow::on_backButton_clicked() {
    std::filesystem::path checkForExistence = pName.toStdString();
    int numberToSet = 0;
    numberToSet = numberOfMovement - currentIndex + 1;
    componetOfFiles = containerPath.moveBack(numberToSet);
    pName = QString::fromStdString(componetOfFiles.getPathOfFile());
    setTreeView();
    currentIndex = currentIndex - 1;
    stackIsEmptyOnBottom(currentIndex);
    stackIsEmptyOnTop(currentIndex);
}

void MainWindow::on_aheadButton_clicked() {
    int numberToSet = 0;
    numberToSet = numberOfMovement - currentIndex - 1;
    componetOfFiles = containerPath.moveBack(numberToSet);
    pName = QString::fromStdString(componetOfFiles.getPathOfFile());
    setTreeView();
    currentIndex = currentIndex + 1;
    stackIsEmptyOnTop(currentIndex);
    stackIsEmptyOnBottom(currentIndex);
}
