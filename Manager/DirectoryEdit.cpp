#include "DirectoryEdit.h"
namespace fs = std::filesystem;

void DirectoryEdit::fileCreate(int numberOfLines, const std::string& name)
{
	fs::path dirPath = name;
	if (!fs::exists(dirPath))
	{
		fs::create_directories(dirPath);
	}
}

void DirectoryEdit::fileUpdate(int numberOfLines, std::string* destination)
{
	std::string newName;
	std::cout << "Enter new name ";
	std::cin >> newName;
	auto oldPath = fs::path(*destination);
	fs::path newPath = oldPath.parent_path() / newName;
	std::string name = oldPath.filename().string();
	fs::rename(oldPath, newPath);
	std::cout << "File is successfully renamed to " << newPath<<"\n";
	*destination = newPath.string();
}


void DirectoryEdit::fileRead(const std::string& destination)
{

    fs::path dirPath(destination);
	fs::path parentPath = dirPath;
	int count = 0;
	rewind(stdin);
	std::string diskName = dirPath.root_name().string()+"\\";
	int numberOfParents = 0;
	std::cout << diskName;
	countingDirectories(diskName, parentPath, &count);
	std::cout << "There is: " << count << " directories " << "from which would you like to start? ";
	std::cin >> numberOfParents;
	for (int i = 0; i < numberOfParents; i++)
	{
		rewind(stdin);
		parentPath = parentPath.parent_path();
	}
	rewind(stdin);
	int modeSelect = 0;
	if (parentPath.string() == diskName)
	{
		fs::recursive_directory_iterator iter(destination);
		parentPath = dirPath;
		count = 0;
		rewind(stdin);
		std::cout << "You are in the root folder. Switching to the first parent path. ";
		countingDirectories(diskName, parentPath, &count);
		parentPath = dirPath;
		for (int i = 0; i < count - 1; i++)
		{
			parentPath = parentPath.parent_path().string();
		}
	}
	std::cout << "Right now you are in the: " << parentPath.parent_path().string() << "\n";
	std::cout << "Listing all current directories\n";
	fs::path previousPath;
	if (fs::exists(dirPath) && fs::is_directory(parentPath))
	{
		for (const auto& p : fs::recursive_directory_iterator(parentPath))
		{
			fs::path currentPath = p.path().parent_path();
			if (currentPath != previousPath)
			{
				std::cout << "\nIn Folder " << currentPath.filename().string() << "\n";
				previousPath = currentPath;
			}
			std::cout << p.path().filename().string() << " ";
		}
		std::cout << "\n";
	}
	else
	{
		std::cerr << "The specified path does not exist or is not a directory. " << std::endl;
	}
}
void DirectoryEdit::lineDelete(std::string* destination)
{
	fs::path bigPath;
	if (fs::exists(*destination))
	{
		fs::remove_all(*destination);
		std::cout << "directory removed\n";
	}
	bigPath = *destination;
	*destination = bigPath.parent_path().string();
	std::cout <<"now you are in" << * destination << "\n";
}
