#include "Path.h"
#include "IOperations.h"

class DirectoryEdit: public IOperations, public Path
{
public:
	void IOperations::fileCreate(int numberOfLines, const std::string& name)  override;
	void IOperations::fileUpdate(int numberOfLines, const std::string& destination) override;
	void IOperations::fileRead(const std::string& destination) override;
	void IOperations::lineDelete(const std::string& destination) override;
};
