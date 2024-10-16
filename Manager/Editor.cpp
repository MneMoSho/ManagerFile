#include "Editor.h"

void Editor::setDestination(const std::string& setDest)
{
	destination = setDest;
}
std::string Editor::getDestination() const
{
	return destination;
}

void Editor::createNewFile(const std::string& destination)
{
	int numberOfLines = 0;
	auto objectCreate = std::make_unique<FileEdit>();
	std::string name;
	std::cout << "Enter name of file" << " ";
	std::cin >> name;
	objectCreate->setFirstName(name);
	checkForSimillarity(*objectCreate, destination, &name);
	name = destination + "\\" + name;
	numberOfLines = linesNumber(numberOfLines);
	FileEdit::fileCreate(numberOfLines, name);
}

void Editor::updateAnExisted(int numberOfLines, std::string& destination)
{
	numberOfLines = linesNumber(numberOfLines);
	FileEdit::fileUpdate(numberOfLines, &destination);
}

void Editor::deleteFromExisting(std::string destination)
{
	FileEdit::lineDelete(&destination);
}

void Editor::readFile(const std::string& destination)
{
	std::string Buf;
	FileEdit::fileRead(destination);
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
	std::string value = Editor::getDestination();
	DirectoryEdit::fileUpdate(0, &value);
	Editor::setDestination(value);
}

void Editor::readDir()
{
	DirectoryEdit::fileRead(Editor::getDestination());
}

void Editor::deleteDir()
{
	std::string value = Editor::getDestination();
	DirectoryEdit::lineDelete(&value);
	Editor::setDestination(value);
}