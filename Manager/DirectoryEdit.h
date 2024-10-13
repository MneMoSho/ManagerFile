#include "Path.h"
#include "FileCRUDOperations.h"

class DirectoryEdit: public FileCRUDOperations, public Path
{
public:
	void FileCRUDOperations::fileCreate(int numberOfLines, const std::string& name)  override;
	void FileCRUDOperations::fileUpdate(int numberOfLines, const std::string& destination) override;
	void FileCRUDOperations::fileRead(const std::string& destination) override;
	void FileCRUDOperations::lineDelete(const std::string& destination) override;
};
