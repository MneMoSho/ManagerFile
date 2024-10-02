#include "fileEdit.h"
using namespace std;

fileEdit::fileEdit(const std::string& firstName, const std::string& fileType, const std::string& information, const int totalLineCount = 0) : totalLineCount(totalLineCount), firstName(firstName), fileType(fileType), information(information)
{

}
fileEdit::~fileEdit() = default;

void fileEdit::fileCreate(int numberOfLines, const std::string& name)
{
	fout.open(name);
	if (int fileOpened = checkFile(); fileOpened != 1)
	{
		std::cout << "Error";
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

void fileEdit::fileUpdate(int numberOfLines, std::string name)
{
	rewind(stdin);
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
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

void fileEdit::fileRead(std::string buf, std::string name)
{
	rewind(stdin);
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
	fin.open(name);
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

void fileEdit::lineDelete(int lineToDelete, std::string Buf, int currentLine, std::string name)
{
	rewind(stdin);
	std::cout << "Enter name of file you'd like to open ";
	std::cin >> name;
	rewind(stdin);
	fin.open(name);
	fout.open("test.txt");
	std::cout << "enter number of line to delete \n";
	std::cin >> lineToDelete;
	rewind(stdin);
	while (std::getline(fin, Buf))
	{
		if (currentLine != lineToDelete)
		{
			fout << Buf << std::endl;

		}
		++currentLine;
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

int fileEdit::checkFile() const
{
	int checkFile = 0;
	if (fout.is_open() || fin.is_open())
	{
		checkFile = 1;
	}
	return checkFile;
}

std::string fileEdit::getFirstName() const
{
	return firstName;
}
std::string fileEdit::getFileType() const
{
	return fileType;
}
void fileEdit::setFirstName(std::string_view name)
{
	firstName = name;
}
void fileEdit::setFileType(std::string_view type)
{
	fileType = type;
}

