#include "Header.h"

class Path
{
public:
	void createWay();
	void createDirectory(const std::string& name) const;
	void createNewPath(const std::string& name);
	std::string getDisk() const;
	void setDisk(std::string_view disk);
	std::string getDestination() const;
	void setDestination(std::string_view disk);
private:
	std::string disk;
	std::string destination;
};