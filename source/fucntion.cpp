//
// Created by Gleb on 24.10.2024.
//
#include "Header.h"
#include "Editor.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int linesNumber(int numberOfLines)
{
    numberOfLines = 0;
    cout << "Enter number of Lines ";
    cin >> numberOfLines;
    return numberOfLines;
}

void addToAnother(const std::string& nameBegin, const std::string& nameToCopy, const std::string& destination)
{
    Editor newFile;
   auto fileBegin = std::make_unique<FilePropeties>();
auto filetoCopy = std::make_unique<FilePropeties>();
    cout << "Enter name of file to which you'd like to add " << " ";
    fileBegin->setFirstName(nameBegin);
    filetoCopy->setFirstName(nameToCopy);
    if (fs::exists(destination))
    {
        std::cout << "File is copied successfully" << "\n";
        *fileBegin += *filetoCopy;
    }
}

void checkForSimillarity(const FilePropeties& objectCreate, const std::string& destination, std::string* nameFile)
{
    std::string title;
    auto objectToCheck = std::make_unique<FilePropeties>();
    fs::directory_iterator iterator(destination);
    for (; iterator != fs::end(iterator); iterator++)
    {
        objectToCheck->firstName = iterator->path().filename().string();
        while (objectToCheck->firstName == objectCreate.firstName)
        {
            cout << "This name is already exists enter another one ";
            cin >> title;
            rewind(stdin);
            *nameFile = title;
            objectToCheck->setFirstName(title);
        }
    }
}

void deleteSimillarTypeFile(const std::string& destination, const std::string& extensionToSet)
{
    auto toDelete = std::make_unique<FilePropeties>();
    auto typeToDelete = std::make_unique<FilePropeties>();
    toDelete->extension = extensionToSet;
    for (const auto& entry : fs::directory_iterator(destination))
    {
        typeToDelete->firstName = destination+ "\\" + entry.path().filename().string();
        typeToDelete->extension = entry.path().extension().string();
        *toDelete -= *typeToDelete;
    }
}

void countingDirectories(std::string_view diskName, std::filesystem::path parentPath, int* count)
{
    while (diskName != parentPath.string())
    {
        *count = *count + 1;
        rewind(stdin);
        parentPath = parentPath.parent_path().string();
    }
}
