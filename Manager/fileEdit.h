#include "Header.h"
namespace fs = std::filesystem;

class FileEdit
{
public:
	FileEdit(const std::string& firstName, const std::string& information, const int totalLineCount);
	~FileEdit();
	void fileCreate(int numberOfLines, const std::string& name);
	void fileUpdate(int numberOfLines, std::string name, const std::string& destination);
	void fileRead(std::string buf, std::string name, const std::string& destination);
	void lineDelete(int lineToDelete, std::string Buf, int currentLine, const std::string& destination);
	int checkFile() const;
	std::string getFirstName() const;
	void setFirstName(const std::string_view& name);
	void friend checkForSimillarity(FileEdit& objectCreate, const std::string& destination, std::string *nameFile);
	void friend deleteSimillarTypeFile(const std::string& destination);
	FileEdit& operator += (const FileEdit& fileToCopy)
	{
		fin.open(fileToCopy.firstName, std::ios::binary);
		fout.open(this->firstName, std::ofstream::app);
		fout << fin.rdbuf();
		fout.close();
		fin.close();
		return *this;
	}

	bool operator ==(const FileEdit &nameOfFile) const
	{
		return this->firstName == nameOfFile.firstName;
	}

	void operator -= (const FileEdit& fileToDelete)
	{
		if (fileToDelete.extension == this->extension && remove(fileToDelete.firstName.c_str()) == 0)
		{
			std::cout << " file is removed" << "\n";
		}
	}

private:
	std::ifstream fin;
	std::ofstream fout;
	int totalLineCount = 0;
	std::string firstName;
	std::string information;
	std::string extension;
};
