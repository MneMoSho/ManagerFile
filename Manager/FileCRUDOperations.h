#include "Header.h"

class FileCRUDOperations
{
public:
	virtual void fileCreate(int numberOfLines, const std::string& name) = 0;
	virtual void fileUpdate(int numberOfLines, const std::string& destination) = 0;
	virtual void fileRead(const std::string& destination) = 0;
	virtual void lineDelete( const std::string& destination) = 0;
};
