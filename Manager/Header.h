#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <direct.h>
#include <winbase.h>
#include <filesystem>

void deleteFile(const std::string& directory);
int linesNumber(int numberOfLines);
void createNewfile(int numberOfLines, const std::string& destination);
void updateAnExisted(int numberOfLines, const std::string& destination);
void deleteFromExisting(const std::string& destination);
void readFile(const std::string& destination);
void deleteAfterTime(const std::string& directory);
void movingDelete();
void addToAnother(const std::string& destination);
void deleteSimillarTypeFile(const std::string& destination);
void newDirectory(std::string* destName);
void newDirectoryFromFile(std::string* destName);
void chooseDirectory(std::string* destName);
void appendingPartsOfPath(std::string* name, const std::string& destination);
void countingDirectories(const std::string& diskName, std::filesystem::path parentPath, int *count);
