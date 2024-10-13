#include "Header.h"
#include "FileEdit.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void deleteFile(const std::string& directory)
{
    std::string nameBig;
    auto nameOfFile = std::make_shared < std::string>();
    cout << "Enter destination to the file and name " << "\n";
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
    for (const auto& entry : fs::directory_iterator("H:\\Course\\Buf"))
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
    std::string endDestination = "H:\\labs\\Buf\\" + nameOfFile;
    appendingPartsOfPath(&nameOfFile, directory);
    std::cout << nameOfFile<<"\n";
    std::cout << endDestination <<"\n";
    rewind(stdin);
    MoveFileA(nameOfFile.c_str(), endDestination.c_str());
}

int linesNumber(int numberOfLines)
{
    numberOfLines = 0;
    cout << "Enter number of Lines ";
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
    objectCreate->fileUpdate(numberOfLines, destination);
}

void deleteFromExisting(const std::string& destination)
{
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    objectCreate->lineDelete(destination);
}

void readFile(const std::string& destination)
{
    string Buf;
    auto objectCreate = std::make_unique<FileEdit>("start.txt", "start", 0);
    objectCreate->fileRead(destination);
}

void addToAnother(const std::string& destination)
{
    std::string nameBegin;
    std::string nameToCopy;
    auto fileBegin = std::make_unique<FileEdit>("start.txt", "start", 0);
    auto filetoCopy = std::make_unique<FileEdit>("start.txt", "start", 0);
    cout << "Enter name of file to which you'd like to add " << " ";
    cin >> nameBegin;
    appendingPartsOfPath(&nameBegin, destination);
    fileBegin->setFirstName(nameBegin);
    cout << "Enter name of file from which you'd like to copy " << " ";
    cin >> nameToCopy;
    appendingPartsOfPath(&nameToCopy, destination);
    filetoCopy->setFirstName(nameToCopy);
    if (fs::exists(destination))
    {
        std::cout << "File is copied successfully" << "\n";
        *fileBegin += *filetoCopy;
    }
    else
    {
        createNewfile(0, destination);
    }
}

void checkForSimillarity(const FileEdit& objectCreate, const std::string& destination, std::string* nameFile)
{
    std::string title;
    auto objectToCheck = std::make_unique<FileEdit>("start.txt","start", 0);
    fs::directory_iterator iterator(destination);
    for (; iterator != fs::end(iterator); iterator++)
    {
        objectToCheck->firstName = iterator->path().filename().string();
        if (*objectToCheck == objectCreate)
        {
            cout << "This name is already exists enter another one ";
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
    cout << "Enter type of file ypu'd like to remove ";
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

void newDirectory(std::string *destName)
{
	std::string name;
    DirectoryEdit dirCreation;
	std::cout << "Enter disk ";
	std::cin >> name;
    dirCreation.setDisk(name);
    dirCreation.createWay();
    std::cout << dirCreation.getDestination();
	std::cout << "Enter folders, press -1 when to stop\n";
	while (true)
	{
        rewind(stdin);
		std::cin >> name;
        if (name == "-1")
        {
            break;
        }
        dirCreation.createNewPath(name);
	}
    rewind(stdin);
   *destName = dirCreation.getDestination();
   dirCreation.fileCreate(0, *destName);
}

void newDirectoryFromFile(std::string *destName)
{
	std::ifstream pathIn;
	Path newDir;
    DirectoryEdit dirCreation;
	pathIn.open("Directory.txt");
	while (!pathIn.eof())
	{
		std::getline(pathIn, *destName);
	}
    rewind(stdin);
	newDir.setDestination(*destName);
    std::cout << newDir.getDestination() << "\n";
    dirCreation.fileCreate(0, *destName);
    pathIn.close();
}

void appendingPartsOfPath(std::string* name, const std::string& destination)
{
    *name = destination + "\\" + *name;
}

void countingDirectories(const std::string& diskName, std::filesystem::path parentPath, int *count)
{
    while (diskName != parentPath.string())
    {
        *count = *count + 1;
        rewind(stdin);
        parentPath = parentPath.parent_path().string();
    }
}

void chooseDirectory(std::string* destName)
{
    std::string name;
    DirectoryEdit dirCreation;
    std::cout << "Enter disk ";
    std::cin >> name;
    dirCreation.setDisk(name);
    dirCreation.createWay();
    std::cout << "Enter folders, press -1 when to stop\n";
    while (true)
    {
        rewind(stdin);
        std::cin >> name;
        if (name == "-1")
        {
            break;
        }
        dirCreation.createNewPath(name);
    }
    *destName = dirCreation.getDestination();
    std::cout << *destName << "\n";
    if (!fs::exists(*destName))
    {
        dirCreation.fileCreate(0, *destName);
    }
    else
    {
        std::cout << "You are in the directory ";
    }
}
