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
	DirectoryEdit directoryEdition;
	auto createDir = std::make_unique<FileEdit>("start.txt", "start", 0);
	int start = 0;
	while (modeSelect != '0')
	{
		std::cout << "set mode of editing file ";
		if (!fs::exists("H:\\labs\\Buf "))
		{
			fs::create_directory("H:\\labs\\Buf ");

		}
		jthread parallelreal(movingDelete);
		modeSelect = 0;
		std::cin >> modeSelect;

		if (destName[0] == '\0' && modeSelect == 2 || modeSelect == 1)
		{
			std::cout << "You haven't chosen any folders, switching to the menu to chose\n";
			modeSelect = 3;
		}
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
			while (fileEditType != 0)
			{
				switch (fileEditType)
				{
				case 1:
					createNewfile(numberOfLines, destName);
					break;
				case 2:
					updateAnExisted(numberOfLines, destName);
					break;
				case 3:
					deleteFromExisting(destName);
					break;
				case 4:
					readFile(destName);
					break;
				case 5:
					deleteFile(destName);
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
				case 6:
					return 0;
				default:
					cout << "Enter number from 1 to 6" << "\n";
				}
				cin >> fileEditType;
				cout << "select mode\n 1 to create new file\n 2 to add to an existing\n 3 to delete a particular line\n 4 to display whole document\n 5 to delete text file\n 7 to put into buffer\n 8 to copy full one file to another\n 9 to delete types with simillar extension \n 6 to exit ";
			}
			break;
		}
		case 2:
		{
			cout << "\nEnter mode 1 to change name of your directory 2 to display all files that is in the current folder ";
			cin >> directoryOperations;
			while (directoryOperations != '0')
			{
				switch (directoryOperations)
				{
				case 1:
					directoryEdition.fileUpdate(0, destName);
					break;
				case 2:
					directoryEdition.fileRead(destName);
					break;
				case 3:
				{
					directoryEdition.lineDelete(destName);
				}
				}
				break;
			}
		}
		parallelreal.join();
		}
	}
}

