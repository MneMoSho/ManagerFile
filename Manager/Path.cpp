#include "Path.h"
namespace fs = std::filesystem;

void Path::createWay()
{
	destination = disk + ":";
}
void Path::createNewPath(std::string name)
{
	if (name != "-1")
	{
		destination += "\\" + name;
	}
}
void Path::createDirectory()
{
	if (!fs::exists(destination))
	{
		fs::create_directories(destination);
	}
}

std::string Path::getDisk()
{
	return disk;
}
std::string Path::getDestination()
{
	return destination;
}
void Path::setDisk(std::string_view name)
{
	disk = name;
}
void Path::setDestination(std::string_view name)
{
	destination = name;
}