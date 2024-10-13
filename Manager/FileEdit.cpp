#include "FileEdit.h"
using namespace std;

FileEdit::FileEdit(const std::string& firstName, const std::string& information, const int totalLineCount = 0) : totalLineCount(totalLineCount), firstName(firstName), information(information)
{

}
FileEdit::~FileEdit() = default;

void FileEdit::fileCreate(int numberOfLines, const std::string& name)
{
	fout.open(name);
	if (int fileOpened = checkFile(); fileOpened != 1)
	{
		std::cout << "Error ";
	}
	else
		for (int i = 0; i < numberOfLines; i++)
		{
			rewind(stdin);
			getline(std::cin, information);
			fout << information << "\n";
		}
	fout.close();
}

 void FileEdit::fileUpdate(int numberOfLines, const std::string& destination)
{
	rewind(stdin);
	std::string name;
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
	appendingPartsOfPath(&name, destination);
	fout.open(name, std::ofstream::app);
	if (int fileOpened = checkFile(); fileOpened != 1)
	{
		std::cout << "Error";
	}
	else
	{
		for (int i = 0; i < numberOfLines; i++)
		{
			rewind(stdin);
			std::getline(std::cin, information);
			fout << information << "\n";
		}
	}
	fout.close();
}

void FileEdit::fileRead(const std::string& destination)
{
	std::string name;
	std::string buf;
	rewind(stdin);
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
	appendingPartsOfPath(&name, destination);
	FileEdit::fin.open(name);
	rewind(stdin);
	if (int fileOpened = checkFile(); fileOpened != 1)
	{
		std::cout << "Error";
	}
	else
	{
		while (!fin.eof())
		{
			std::getline(fin, buf);
			std::cout << buf << "\n";
		}
	}
	fin.close();
}

void FileEdit::lineDelete(const std::string& destination)
{
	int ñurrentLine = 1;
	int lineToDelete = 0;
	string Buf;
	std::string name;
	rewind(stdin);
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
	appendingPartsOfPath(&name, destination);
	rewind(stdin);
	fin.open(name);
	fout.open("test.txt");
	std::cout << "enter number of line to delete \n";
	std::cin >> lineToDelete;
	rewind(stdin);
	while (std::getline(fin, Buf))
	{
		if (ñurrentLine != lineToDelete)
		{
			fout << Buf << std::endl;

		}
		++ñurrentLine;
	}
	fin.close();
	fout.close();
	fout.open(name);
	fin.open("test.txt");
	while (std::getline(fin, Buf))
	{
		fout << Buf << std::endl;
	}
	fout.close();
	fin.close();
}

int FileEdit::checkFile() const
{
	int checkFile = 0;
	if (fout.is_open() || fin.is_open())
	{
		checkFile = 1;
	}
	return checkFile;
}

std::string FileEdit::getFirstName() const
{
	return firstName;
}
void FileEdit::setFirstName(const std::string_view& name)
{
	firstName = name;
}
