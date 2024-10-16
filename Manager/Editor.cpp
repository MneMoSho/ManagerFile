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
	auto objectCreate = std::make_unique<FileEdit>();
	std::string name;
	std::cout << "Enter name of file" << " ";
	std::cin >> name;
	objectCreate->setFirstName(name);
	checkForSimillarity(*objectCreate, destName, &name);
	name = destName + "\\" + name;
	numberOfLines = linesNumber(numberOfLines);
	FileEdit::fileCreate(numberOfLines, name);
}

void Editor::updateAnExisted(int numberOfLines, std::string& destName)
{
	numberOfLines = linesNumber(numberOfLines);
	FileEdit::fileUpdate(numberOfLines, &destName);
}

void Editor::deleteFromExisting(std::string destName)
{
	FileEdit::lineDelete(&destName);
}

void Editor::readFile(const std::string& destName)
{
	std::string Buf;
	FileEdit::fileRead(destName);
}

void Editor::deleteFile(const std::string& directory)
{
	std::string nameBig;
	auto nameOfFile = std::make_shared < std::string>();
	std::cout << "Enter destination to the file and name " << "\n";
	rewind(stdin);
	std::getline(std::cin, *nameOfFile);
	nameBig = directory + "\\" + *nameOfFile;
	if (remove(nameBig.c_str()) != 0)
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
	DirectoryEdit::fileUpdate(0, &value);
	Editor::setDestinationEdit(value);
}

void Editor::readDir()
{
	DirectoryEdit::fileRead(Editor::getDestinationEdit());
}

void Editor::deleteDir()
{
	std::string value = Editor::getDestinationEdit();
	DirectoryEdit::lineDelete(&value);
	Editor::setDestinationEdit(value);
}