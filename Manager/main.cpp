#include "Header.h"
#include "FileEdit.h"
#include "Path.h"
using namespace std;
namespace fs = std::filesystem;

int main()
{
	int modeSelect = 0;
	int numberOfLines = 0;
	std::string destName;
	Path createDir;
	int start = 0;
	cout << "would you like to create a directory by yourself(1) or read from file(2) ";
	cin >> start;
	switch (start)
	{
	case 1:
		newDirectory(&destName);
		break;
	case 2:
		newDirectoryFromFile(&destName);
		break;
	default:
		cout << "Enter 1 or 2";
	}

	cout << destName << "\n";

	while (modeSelect != '0')
	{
		if (!fs::exists("D:\\учёба\\git\\Buf"))
		{
			fs::create_directory("D:\\учёба\\git\\Buf");
		}
		jthread parallelreal(movingDelete);
		rewind(stdin);
		cout << "select mode\n 1 to create new file\n 2 to add to an existing\n 3 to delete a particular line\n 4 to display whole document\n 5 to delete text file\n 7 to put into buffer\n 8 to copy full one file to another\n 9 to delete types with simillar extension \n 6 to exit ";
		cin >> modeSelect;
		switch (modeSelect)
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
		parallelreal.join();
	}

}

