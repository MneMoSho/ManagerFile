//
// Created by Gleb on 29.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FileProperties.h" resolved

#include "FileProperties.h"
#include "ui_FileProperties.h"

FilePropeties::FilePropeties(QWidget *parent) :
        QWidget(parent), ui(new Ui::FilePropeties) {
    ui->setupUi(this);
    widgetToShow = new setNewText;
    connect(this, &FilePropeties::signalToSet, widgetToShow, &setNewText::textToRead);
}

FilePropeties::~FilePropeties() {
    delete ui;
}

void FilePropeties::objectCreate(int numberOfLines, const std::string &name) {
    std::cout<<"file is created ";
    std::cout<< name;
    fout.open(name);
    fout.close();
}

void FilePropeties::fileTextAdd(std::string nameOfIle) {
    widgetToShow = new setNewText;
    connect(widgetToShow, &setNewText::signalToQuit, &loop, &QEventLoop::quit);
    widgetToShow->show();
    loop.exec();
    widgetToShow->createNewText(nameOfIle);
}

void FilePropeties::fileUpdate(int numberOfLines, std::string *destination) {
    QString textToGet;
    std::string buf;
    widgetToShow = new setNewText;
    fin.open(*destination);
    while(!fin.eof())
    {
        std::getline(fin, buf);
        widgetToShow->updatingFile(buf);
    }
    fin.close();
    connect(widgetToShow, &setNewText::signalToQuit, &loop, &QEventLoop::quit);
    fout.open(*destination);
    widgetToShow->show();
    loop.exec();
    textToGet = widgetToShow->getFromTextBrowser();
    QStringList  lines = textToGet.split("\n");
    if (int fileOpened = checkFile(); fileOpened != 1) {
        QMessageBox::critical(this, tr("error"), tr("directory is not entered or entered wrong"));
    }
   else
   {
       for(const QString &line: lines)
       {
           fout<<line.toStdString()<<"\n";
       }
       fout.close();
   }
    fout.close();
}

void FilePropeties::fileRead(const std::string &destination) {
    std::string buf;
    setNewText lineToSet;
    QString lineToRead;
    FilePropeties::fin.open(destination);
    widgetToShow = new setNewText;
    widgetToShow->show();
    if (int fileOpened = checkFile(); fileOpened != 1) {
        std::cout << "Error";
    } else {
        while (!fin.eof()) {
            std::getline(fin, buf);
            widgetToShow->textToRead(lineToRead.fromStdString(buf));
            emit signalToSet(lineToRead.fromStdString(buf));
        }
    }
    fin.close();
}

void FilePropeties::lineDelete(int numberToDelete, std::string *destination) {
    int currentLine = 1;
    std::string Buf;
    fin.open(*destination);
    fout.open("test.txt");
    while (std::getline(fin, Buf)) {
        if (currentLine != numberToDelete) {
            fout << Buf << std::endl;
        }
        ++currentLine;
    }
    fin.close();
    fout.close();
    fout.open(*destination);
    fin.open("test.txt");
    while (std::getline(fin, Buf)) {
        fout << Buf << std::endl;
    }
    fout.close();
    fin.close();
}

int FilePropeties::checkFile() const {
    int checkFile = 0;
    if (fout.is_open() || fin.is_open()) {
        checkFile = 1;
    }
    return checkFile;
}

std::string FilePropeties::getFirstName() const {
    return firstName;
}

void FilePropeties::setFirstName(const std::string_view &name) {
    firstName = name;
}

void FilePropeties::setLineCount(int numberOfLines) {
    totalLineCount = numberOfLines;
}

int FilePropeties::getLineCount() {
    return totalLineCount;
}

int FilePropeties::checkNumberOfLines(std::string filename)
{
    int lineCount = 0;
    std::string line;
    std::ifstream of(filename);
    while(std::getline(of, line))
    {
        lineCount++;
    }
    return lineCount;
}