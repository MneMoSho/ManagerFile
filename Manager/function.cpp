#include "Header.h"
#include "fileEdit.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void deleteFile()
{
    auto nameOfFile = std::make_shared < std::string>();
    cout << "Enter destination to the file and name" << "\n";
    rewind(stdin);
    std::getline(std::cin, *nameOfFile);
    if (remove(nameOfFile->c_str()) != 0)
    {
        cout << "Error" << " ";
    }
    else
    {
        cout << "File is deleted" << "\n";
    }
}

void movingDelete()
{
    for (const auto& entry : fs::directory_iterator("H:\\ëôáîðàòîðíûå\\Buf\\"))
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        fs::remove_all(entry.path());
    }
}

void deleteAfterTime()
{
    auto nameOfFile = std::make_shared < std::string>();
    cout << "Enter destination to the file and name" << "\n";
    rewind(stdin);
    std::getline(std::cin, *nameOfFile);
    std::string destination = "H:\\Course\\Manager\\Manager" + *nameOfFile;
    std::string endDestination = "H:\\ëôáîðàòîðíûå\\Buf\\" + *nameOfFile;
    rewind(stdin);
    MoveFileA(destination.c_str(), endDestination.c_str());
}

int linesNumber(int numberOfLines)
{
    numberOfLines = 0;
    cout << "Enter number of Lines";
    cin >> numberOfLines;
    return numberOfLines;
}

void createNewfile(int numberOfLines)
{
    auto objectCreate = std::make_unique<fileEdit>("start", ".txt", "start", 0);
    std::string name;
    cout << "Enter name of file" << " ";
    cin >> name;
    objectCreate->setFirstName(name);
    cout << "Enter type of file" << " ";
    cin >> name;
    objectCreate->setFileType(name);
    objectCreate->setFirstName(objectCreate->getFirstName().append(objectCreate->getFileType()));
    numberOfLines = linesNumber(numberOfLines);
    objectCreate->fileCreate(numberOfLines, objectCreate->getFirstName());
}

void updateAnExisted(int numberOfLines)
{
    auto objectCreate = std::make_unique<fileEdit>("start", ".txt", "start", 0);
    numberOfLines = linesNumber(numberOfLines);
    objectCreate->fileUpdate(numberOfLines, objectCreate->getFirstName());
}

void deleteFromExisting()
{
    string Buf;
    auto objectCreate = std::make_unique<fileEdit>("start", ".txt", "start", 0);
    int ñurrentLine = 1;
    int lineToDelete = 0;
    objectCreate->lineDelete(lineToDelete, Buf, ñurrentLine, objectCreate->getFirstName());
}

void readFile()
{
    string Buf;
    auto objectCreate = std::make_unique<fileEdit>("start", ".txt", "start", 0);
    objectCreate->fileRead(Buf, objectCreate->getFirstName());
}