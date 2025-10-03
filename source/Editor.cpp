//
// Created by Gleb on 24.10.2024.
//

#include "Editor.h"

void Editor::setDestinationEdit(std::string_view setDest)
{
    destination = setDest;
}
std::string Editor::getDestinationEdit() const
{
    return destination;
}

void Editor::createNewFile(const std::string& destName)
{
    int numberOfLines = 0;
    auto objectCreate = std::make_unique<FilePropeties>();
    std::string name;
    std::cout << "Enter name of file" << " ";
    std::cin >> name;
    objectCreate->setFirstName(name);
    checkForSimillarity(*objectCreate, destName, &name);
    name = destName + "\\" + name;
    numberOfLines = linesNumber(numberOfLines);
    FilePropeties::objectCreate(numberOfLines, name);
}

void Editor::updateAnExisted(int numberOfLines, std::string& destName)
{
    numberOfLines = linesNumber(numberOfLines);
    FilePropeties::fileUpdate(numberOfLines, &destName);
}

void Editor::deleteFromExisting(std::string destName)
{
    FilePropeties::lineDelete(0,&destName);
}

void Editor::readFile(const std::string& destName)
{
    std::string Buf;
    FilePropeties::fileRead(destName);
}

void Editor::deleteFile(const std::string& directory)
{
    if (remove(directory.c_str()) != 0)
    {
        std::cout << "Error" << " ";
    }
    else
    {
        std::cout << "File is deleted" << "\n";
    }
}

void Editor::createDir()
{
    std::string value = Editor::getDestinationEdit();
    DirectoryProperties::fileUpdate(0, &value);
    Editor::setDestinationEdit(value);
}

void Editor::readDir()
{
    DirectoryProperties::fileRead(Editor::getDestinationEdit());
}

void Editor::deleteDir()
{
    std::string value = Editor::getDestinationEdit();
    DirectoryProperties::lineDelete(0, &value);
    Editor::setDestinationEdit(value);
}