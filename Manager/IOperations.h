#include "Header.h"

class IOperations
{
public:
	virtual void fileCreate(int numberOfLines, const std::string& name) = 0;
	virtual void fileUpdate(int numberOfLines, std::string* destination) = 0;
	virtual void fileRead(const std::string& destination) = 0;
	virtual void lineDelete(std::string* destination) = 0;
};
