#include "Header.h"
#include "DirectoryEdit.h"

namespace fs = std::filesystem;

class FileEdit : public IOperations, public Path
{
public:
	FileEdit(const std::string& firstName, const std::string& information, const int totalLineCount);
	~FileEdit();
	void IOperations::fileCreate(int numberOfLines, const std::string& name) override;
	void IOperations::fileUpdate(int numberOfLines, const std::string& destination) override;
	void IOperations::fileRead(const std::string& destination) override;
	void IOperations::lineDelete(const std::string& destination) override;
	int checkFile() const;
	std::string getFirstName() const;
	void setFirstName(const std::string_view& name);
	void friend checkForSimillarity(const FileEdit& objectCreate, const std::string& destination, std::string *nameFile);
	void friend deleteSimillarTypeFile(const std::string& destination);
	FileEdit& operator += (const FileEdit& fileToCopy)
	{
		std::string line;
		fin.open(fileToCopy.firstName, std::ios::binary);
		fout.open(this->firstName, std::ofstream::app);
		while (std::getline(fin, line))
		{
			fout << line;
		}
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
