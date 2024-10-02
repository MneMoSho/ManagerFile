#include "Header.h"
#include "fileEdit.h"
using namespace std;
namespace fs = std::filesystem;

int main()
{
	int modeSelect = 0;
	int numberOfLines = 0;

	while (modeSelect != '0')
	{
		if (!fs::exists("H:\\лфбораторные\\Buf "))
		{
			fs::create_directory("H:\\лфбораторные\\Buf ");
		}
		jthread parallelreal(movingDelete);
		rewind(stdin);
		cout << "select mode\n 1 to create new file\n 2 to add to an existing\n 3 to delete a particular line\n 4 to display whole document\n 5 to delete text file\n 7 to put into buffer \n 6 to exit ";
		cin >> modeSelect;
		switch (modeSelect)
		{
		case 1:
			createNewfile(numberOfLines);
			break;
		case 2:
			updateAnExisted(numberOfLines);
			break;
		case 3:
			deleteFromExisting();
			break;
		case 4:
			readFile();
			break;
		case 5:
			deleteFile();
			break;
		case 7:
		{
			deleteAfterTime();
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

