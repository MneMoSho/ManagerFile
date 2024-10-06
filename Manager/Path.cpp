#include "Path.h"
namespace fs = std::filesystem;

void Path::createWay()
{
	destination = disk + ":";
}
void Path::createNewPath(const std::string& name)
{
	if (name != "-1")
	{
		destination += "\\" + name;
	}
}
void Path::createDirectory() const
{
	if (!fs::exists(destination))
	{
		fs::create_directories(destination);
	}
}

std::string Path::getDisk() const
{
	return disk;
}
std::string Path::getDestination() const
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