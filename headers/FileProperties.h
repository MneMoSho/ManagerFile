//
// Created by Gleb on 29.10.2024.
//

#ifndef UNTITLED4_FILEPROPERTIES_H
#define UNTITLED4_FILEPROPERTIES_H

//#include <QWidget>
#include "Header.h"
#include "DirectoryProperties.h"
#include "SetNewText.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class FilePropeties; }
QT_END_NAMESPACE

class FilePropeties : public QWidget, public IOperations, public Path{
Q_OBJECT

public:
    explicit FilePropeties(QWidget *parent = nullptr);

    ~FilePropeties() override;

    void objectCreate(int numberOfLines, const std::string& name) override;
    void fileUpdate(int numberOfLines, std::string* destination) override;
    void fileRead(const std::string& destination) override;
    void lineDelete(int numberToDelete, std::string* destination) override;
    void fileTextAdd(std::string nameOfIle);
    int checkNumberOfLines(std::string filename);
    void setLineCount(int numberOfLines);
    int getLineCount();
    int checkFile() const;
    std::string getFirstName() const;
    void setFirstName(const std::string_view& name);
    void friend checkForSimillarity(const FilePropeties& objectCreate, const std::string& destination, std::string *nameFile);
    void friend deleteSimillarTypeFile(const std::string& destination, const std::string& extension);
    FilePropeties& operator += (const FilePropeties& fileToCopy)
    {
        std::string line;
        fin.open(fileToCopy.firstName, std::ios::binary);
        fout.open(this->firstName, std::ofstream::app);
        while (std::getline(fin, line))
        {
            fout << line;
        }
        fout.close();
        fin.close();
        return *this;
    }

    bool operator ==(const FilePropeties &nameOfFile) const
    {
        return this->firstName == nameOfFile.firstName;
    }

    void operator -= (const FilePropeties& fileToDelete)
    {
        if (fileToDelete.extension == this->extension && remove(fileToDelete.firstName.c_str()) == 0)
        {
            std::cout << " file is removed" << "\n";
        }
    }

    signals:
    void signalToSet(QString line);
   // void signalToReadAndWrite();

private:
    QEventLoop loop;
    setNewText *widgetToShow;
    std::ifstream fin;
    std::ofstream fout;
    int totalLineCount = 0;
    std::string firstName;
    std::string information;
    std::string extension;
    Ui::FilePropeties *ui;
};


#endif //UNTITLED4_FILEPROPERTIES_H
