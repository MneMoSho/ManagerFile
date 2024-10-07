#include "Header.h"

class Path
{
public:
	void createWay();
	void createDirectory();
	void createNewPath(std::string name);
	std::string getDisk();
	void setDisk(std::string_view disk);
	std::string getDestination();
	void setDestination(std::string_view disk);
private:
	std::string disk;
	std::string destination;
};