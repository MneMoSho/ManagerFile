//
// Created by Gleb on 03.11.2024.
//

#include "BinBucket.h"

void BinBucket::moveByIndex(int index) {
    std::cout<<"\nstarting to delete\n";
    int numberOf = 0;
    std::string nameNew;
    std::string nameOld;
    numberOf = countNumberOfFIles();
    std::cout << "\nfile is deleted " << index;
    Node<std::string> *wayToFile = addToList.getAtPosition(index);
    Node<std::string> *nameOfFile = moveToFolder.getAtPosition(index);
    if(nameOfFile == NULL)
    {
        std::cout<<"Empty";
        return;
    }
    nameNew = nameOfFile->data;
    std::cout << nameNew << "\n";
    std::filesystem::path entry = nameOfFile->data;
    std::filesystem::path pathToFile = wayToFile->data;
    nameOld = pathToFile.parent_path().string() + "\\" + entry.filename().string();
    std::cout << nameOld << "\n";
    MoveFileA(nameNew.c_str(), nameOld.c_str());
    moveToFolder.earse(index);
    addToList.earse(index);
    numberOfFiles = numberOfFiles - 1;
    std::cout << numberOfFiles;
}

void BinBucket::folderClear()
{
    for (const auto& entry : std::filesystem::directory_iterator("I:\\O\\"))
    {
        std::filesystem::remove_all(entry.path());
    }
}

int BinBucket::countNumberOfFIles()
{
    int fileCount = 0;
    for(const auto& entry : std::filesystem::directory_iterator("I:\\O\\"))
    {
        if(std::filesystem::is_regular_file(entry))
        {
            return fileCount;
        }
    }
    fileCount++;
}

int BinBucket::findByName(std::string nameToFind)
{
    std::cout<<"\nadding into list\n";
    Node<std::string>* current = addToList.head;
    std::cout<<nameToFind<<"\n";
    int index = 0;
    while(current != NULL) {
        std::cout << current->data << "\n";
        if (current->data == nameToFind)
        {
           return index;
        }
        current = current->next;
        index++;
    }
}