//
// Created by Gleb on 24.10.2024.
//

#ifndef UNTITLED4_HEADER_H
#define UNTITLED4_HEADER_H
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
#include <ranges>

int linesNumber(int numberOfLines);
void addToAnother(const std::string& nameBegin, const std::string& nameToCopy, const std::string& destination);
void deleteSimillarTypeFile(const std::string& destination, const std::string& extensionToSet);
void countingDirectories(std::string_view diskName, std::filesystem::path parentPath, int *count);

#endif //UNTITLED4_HEADER_H
