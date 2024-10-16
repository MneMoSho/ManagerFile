#include "Header.h"
#include "Editor.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

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
	std::cout << nameOfFile << "\n";
	std::cout << endDestination << "\n";
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

void addToAnother(const std::string& destination)
{
	std::string nameBegin;
	std::string nameToCopy;
	Editor newFile;
	auto fileBegin = std::make_unique<FileEdit>();
	auto filetoCopy = std::make_unique<FileEdit>();
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
		newFile.createNewFile(destination);
	}
}

void checkForSimillarity(const FileEdit& objectCreate, const std::string& destination, std::string* nameFile)
{
	std::string title;
	auto objectToCheck = std::make_unique<FileEdit>();
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

void deleteSimillarTypeFile(const std::string& destination)
{
	std::string fullName = destination + "\\";
	auto toDelete = std::make_unique<FileEdit>();
	auto typeToDelete = std::make_unique<FileEdit>();
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

void newDirectory(std::string* destName)
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

void newDirectoryFromFile(std::string* destName)
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

void countingDirectories(std::string_view diskName, std::filesystem::path parentPath, int* count)
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

void selectorforFile(int mode, std::string& destName)
{
	Editor testVar;
	int numberOfLines = 0;
	while (mode != 0)
	{
		switch (mode)
		{
		case 1:
			testVar.createNewFile(destName);
			break;
		case 2:
			testVar.updateAnExisted(numberOfLines, destName);
			break;
		case 3:
			testVar.deleteFromExisting(destName);
			break;
		case 4:
			testVar.readFile(destName);
			break;
		case 5:
			testVar.deleteFile(destName);
			break;
		case 7:
		{
			deleteAfterTime(destName);
			break;
		}
		case 8:
		{
			addToAnother(destName);
			break;
		}
		case 9:
		{
			deleteSimillarTypeFile(destName);
			break;
		}
		case 0:
		{
			break;
		}
		default:
			cout << "Enter number from 0 to 9" << "\n";
		}
		cout << "select mode\n 1 to create new file\n 2 to add to an existing\n 3 to delete a particular line\n 4 to display whole document\n 5 to delete text file\n 7 to put into buffer\n 8 to copy full one file to another\n 9 to delete types with simillar extension \n 6 to exit ";
		mode = 0;
		cin >> mode;
	}
}

void selectorForDirectories(std::string* destName)
{
	int directoryOperations = 0;
	Editor directoryEdition;
	directoryEdition.setDestinationEdit(*destName);
	cout << "Enter mode 1 to change name of your directory 2 to display all files that is in the current folder 3 to delete current directory 0 to exit\n ";
	std::cin >> directoryOperations;
	while (directoryOperations != 0)
	{
		switch (directoryOperations)
		{
		case 1:
			directoryEdition.createDir();
			*destName = directoryEdition.getDestinationEdit();
			break;
		case 2:
			directoryEdition.readDir();
			break;
		case 3:
			directoryEdition.deleteDir();
			*destName = directoryEdition.getDestinationEdit();
			break;
		case 0:
			break;
		}
		directoryOperations = 0;
		cout << "Enter mode 1 to change name of your directory 2 to display all files that is in the current folder, 3 to delete current directory 0 to exit\n";
		std::cin >> directoryOperations;
	}
}