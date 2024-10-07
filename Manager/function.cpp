#include "Header.h"
#include "FileEdit.h"
#include "Path.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void deleteFile(const std::string& directory)
{
    std::string nameBig;
    auto nameOfFile = std::make_shared < std::string>();
    cout << "Enter destination to the file and name" << "\n";
    rewind(stdin);
    std::getline(std::cin, *nameOfFile);
    nameBig = directory + "\\" + *nameOfFile;
    if (remove(nameBig.c_str()) != 0)
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

void deleteAfterTime(const std::string& directory)
{
    std::string nameOfFile;
    cout << "Enter destination to the file and name" << "\n";
    rewind(stdin);
    std::cin >> nameOfFile;
    rewind(stdin);
    std::string endDestination = "H:\\ëôáîðàòîðíûå\\Buf\\" + nameOfFile;
    appendingPartsOfPath(&nameOfFile, directory);
    std::cout << nameOfFile << "\n";
    std::cout << endDestination << "\n";
    rewind(stdin);
    MoveFileA(nameOfFile.c_str(), endDestination.c_str());
}

int linesNumber(int numberOfLines)
{
    numberOfLines = 0;
    cout << "Enter number of Lines";
    cin >> numberOfLines;
    return numberOfLines;
}

void createNewfile(int numberOfLines, const std::string& destination)
{
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    std::string name;
    cout << "Enter name of file" << " ";
    cin >> name;
    objectCreate->setFirstName(name);
    checkForSimillarity(*objectCreate, destination, &name);
    name = destination + "\\" + name;
    numberOfLines = linesNumber(numberOfLines);
    objectCreate->fileCreate(numberOfLines, name);
}

void updateAnExisted(int numberOfLines, const std::string& destination)
{
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    numberOfLines = linesNumber(numberOfLines);
    objectCreate->fileUpdate(numberOfLines, objectCreate->getFirstName(), destination);
}

void deleteFromExisting(const std::string& destination)
{
    string Buf;
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    int ñurrentLine = 1;
    int lineToDelete = 0;
    objectCreate->lineDelete(lineToDelete, Buf, ñurrentLine, destination);
}

void readFile(const std::string& destination)
{
    string Buf;
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    objectCreate->fileRead(Buf, objectCreate->getFirstName(), destination);
}

void addToAnother(std::string destination)
{
    std::string nameBegin;
    std::string nameToCopy;
    auto fileBegin = std::make_unique<FileEdit>("start.txt", "start", 0);
    auto filetoCopy = std::make_unique<FileEdit>("start.txt", "start", 0);
    cout << "Enter name of file to which you'd like to add" << " ";
    cin >> nameBegin;
    appendingPartsOfPath(&nameBegin, destination);
    fileBegin->setFirstName(nameBegin);
    cout << "Enter name of file to which you'd like to copy" << " ";
    cin >> nameToCopy;
    appendingPartsOfPath(&nameToCopy, destination);
    filetoCopy->setFirstName(nameToCopy);
    if (fs::exists(destination))
    {
        std::cout << "correct";
        *fileBegin += *filetoCopy;
    }
    else
    {
        createNewfile(0, destination);
    }
}

void checkForSimillarity(FileEdit& objectCreate, const std::string& destination, std::string* nameFile)
{
    std::string title;
    auto objectToCheck = std::make_unique<FileEdit>("start.txt", "start", 0);
    fs::directory_iterator iterator(destination);
    for (; iterator != fs::end(iterator); iterator++)
    {
        objectToCheck->firstName = iterator->path().filename().string();
        if (*objectToCheck == objectCreate)
        {
            cout << "This name is already exists ";
            cin >> title;
            rewind(stdin);
            *nameFile = title;
        }
    }
}

void deleteSimillarTypeFile(const std::string& destination)
{
    std::string fullName = destination + "\\";
    auto toDelete = std::make_unique<FileEdit>("start.txt", "start", 0);
    auto typeToDelete = std::make_unique<FileEdit>("start.txt", "start", 0);
    cout << "Enter type of file ypu'd like to add ";
    rewind(stdin);
    cin >> toDelete->extension;
    for (const auto& entry : fs::directory_iterator(fullName))
    {
        typeToDelete->firstName = fullName + entry.path().filename().string();
        typeToDelete->extension = entry.path().extension().string();
        std::cout << typeToDelete->firstName;
        *toDelete -= *typeToDelete;
    }
}

void newDirectory(std::string* destName)
{
    std::string name;
    Path newDir;
    std::cout << "Enter disk ";
    std::cin >> name;
    newDir.setDisk(name);
    newDir.createWay();
    std::cout << "Enter folders, press -1 when to stop\n";
    while (true)
    {
        std::cin >> name;
        if (name == "-1")
        {
            break;
        }
        newDir.createNewPath(name);
    }
    rewind(stdin);
    *destName = newDir.getDestination();
    newDir.createDirectory();
}

void newDirectoryFromFile(std::string* destName)
{
    rewind(stdin);
    std::ifstream pathIn;
    Path newDir;
    pathIn.open("Directory.txt");
    while (!pathIn.eof())
    {
        std::getline(pathIn, *destName);
    }
    newDir.setDestination(*destName);
    newDir.createDirectory();
    pathIn.close();
}

void appendingPartsOfPath(std::string* name, const std::string& destination)
{
    *name = destination + "\\" + *name;
}