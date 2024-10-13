#include "Header.h"
#include "FileEdit.h"
using namespace std;
namespace fs = std::filesystem;

int main()
{
	int modeSelect = 0;
	int fileEditType = 0;
	int numberOfLines = 0;
	int directoryOperations = 0;
	std::string destName;
	auto createDir = std::make_unique<FileEdit>("start.txt", "start", 0);
	int start = 0;
	std::cout << "set mode of editing file ";
	std::cin >> modeSelect;
	if (destName[0] == '\0' && modeSelect == 2 || modeSelect == 1)
	{
		std::cout << "You haven't chosen any folders, switching to the menu to chose\n";
		modeSelect = 3;
	}

	while (modeSelect != '0')
	{
		if (!fs::exists("H:\\Course\\Buf "))
		{
			fs::create_directory("H:\\Course\\Buf ");

		}
		jthread parallelreal(movingDelete);
		switch (modeSelect)
		{
		case 3:
		{
			cout << "would you like to create a directory by yourself(1), read from file(2), switch to an existing(3) ";
			cin >> start;
			switch (start)
			{
			case 1:
				newDirectory(&destName);
				break;
			case 2:
				newDirectoryFromFile(&destName);
				break;
			case 3:
				chooseDirectory(&destName);
				break;
			default:
				cout << "Enter 1 or 2";
			}
			break;
		}
		case 1:
		{
			rewind(stdin);
			cout << "select mode\n 1 to create new file\n 2 to add to an existing\n 3 to delete a particular line\n 4 to display whole document\n 5 to delete text file\n 7 to put into buffer\n 8 to copy full one file to another\n 9 to delete types with simillar extension \n 6 to exit ";
			cin >> fileEditType;
			selectorforFile(fileEditType, destName);
			break;
		}
		case 2:
		{
			cout << "\nEnter mode 1 to change name of your directory 2 to display all files that is in the current folder ";
			selectorForDirectories(destName);
			break;
		}
		parallelreal.join();
		}
		modeSelect = 0;
		std::cout << "set mode of editing file ";
		std::cin >> modeSelect;
	}
}

