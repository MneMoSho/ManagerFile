#include "Header.h"
#include "FileEdit.h"


class Editor : public FileEdit, public DirectoryEdit
{
public:
	void setDestinationEdit(std::string_view setDestination);
	std::string getDestinationEdit() const;
	void createNewFile(const std::string& destName);
	void updateAnExisted(int numberOfLines, std::string& destName);
	void deleteFromExisting(std::string destName);
	void readFile(const std::string& destName);
	void deleteFile(const std::string& directory);
	void createDir();
	void readDir();
	void deleteDir();

private:
	std::string destination;
};