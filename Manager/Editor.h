#include "Header.h"
#include "FileEdit.h"


class Editor : public FileEdit, public DirectoryEdit
{
public:
	void setDestination(const std::string& setDestination);
	std::string getDestination() const;
	void createNewFile(const std::string& destination);
	void updateAnExisted(int numberOfLines, std::string& destination);
	void deleteFromExisting(std::string destination);
	void readFile(const std::string& destination);
	void deleteFile(const std::string& directory);
	void createDir();
	void readDir();
	void deleteDir();

private:
	std::string destination;
};