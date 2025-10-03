////
//// Created by Gleb on 24.10.2024.
////
//
//#ifndef UNTITLED4_FILEEDIT_H
//#define UNTITLED4_FILEEDIT_H
//
//
//#include "Header.h"
//#include "DirectoryProperties.h"
//#include "SetNewText.h"
//#include "csignal"
//#include <QEventLoop>
//
//namespace fs = std::filesystem;
//
//class FileEdit : public IOperations, public Path
//{
//public:
//    void objectCreate(int numberOfLines, const std::string& name) override;
//    void fileUpdate(int numberOfLines, std::string* destination) override;
//    void fileRead(const std::string& destination) override;
//    void lineDelete(std::string* destination) override;
//    void setLineCount(int numberOfLines);
//    int getLineCount();
//    int checkFile() const;
//    std::string getFirstName() const;
//    void setFirstName(const std::string_view& name);
//    void friend checkForSimillarity(const FileEdit& objectCreate, const std::string& destination, std::string *nameFile);
//    void friend deleteSimillarTypeFile(const std::string& destination);
//    FileEdit& operator += (const FileEdit& fileToCopy)
//    {
//        std::string line;
//        fin.open(fileToCopy.firstName, std::ios::binary);
//        fout.open(this->firstName, std::ofstream::app);
//        while (std::getline(fin, line))
//        {
//            fout << line;
//        }
//        fout.close();
//        fin.close();
//        return *this;
//    }
//
//    bool operator ==(const FileEdit &nameOfFile) const
//    {
//        return this->firstName == nameOfFile.firstName;
//    }
//
//    void operator -= (const FileEdit& fileToDelete)
//    {
//        if (fileToDelete.extension == this->extension && remove(fileToDelete.firstName.c_str()) == 0)
//        {
//            std::cout << " file is removed" << "\n";
//        }
//    }
//signals:
//    void signalToCreate();
//
//private:
//    QEventLoop loop;
//    setNewText *widgetToShow;
//    std::ifstream fin;
//    std::ofstream fout;
//    int totalLineCount = 0;
//    std::string firstName;
//    std::string information;
//    std::string extension;
//    setNewText* textEditor;
//};
//
//
//
//#endif //UNTITLED4_FILEEDIT_H
