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

void deleteFile();
int linesNumber(int numberOfLines);
void createNewfile(int numberOfLines);
void updateAnExisted(int numberOfLines);
void deleteFromExisting();
void readFile();
void deleteAfterTime();
void movingDelete();
