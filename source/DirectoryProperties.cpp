//
// Created by Gleb on 24.10.2024.
//

#include "DirectoryProperties.h"
#include "MainWindow.h"
#include "displaytext.h"

namespace fs = std::filesystem;

void DirectoryProperties::objectCreate(int numberOfLines, const std::string &name) {
    fs::path dirPath = name;
    if (!fs::exists(dirPath)) {
        fs::create_directories(dirPath);
    }
}

void DirectoryProperties::setDestination(std::string destination)
{
    destinationOfDirectory = destination;
}

std::string DirectoryProperties::getDestination()
{
    return destinationOfDirectory;
}

void DirectoryProperties::fileUpdate(int numberOfLines, std::string *destination) {
    QString nameChanged;
    MainWindow *windowToSet;
    windowToSet = new MainWindow;
    std::string newName;
    windowToSet->returnNewName(&nameChanged, windowToSet);
    newName = nameChanged.toStdString();
    std::cout<<newName<<" ";
    std::cout<<*destination<<" ";
    auto oldPath = fs::path(*destination);
    fs::path newPath = oldPath.parent_path() / newName;
    std::string name = oldPath.filename().string();
    fs::rename(oldPath, newPath);
    *destination = newPath.string();
    setDestination(*destination);
}

void DirectoryProperties::fileRead(const std::string &destination) {
    QString convertedString;
    DisplayText* textToDisplay;
    textToDisplay = new DisplayText;
    textToDisplay->show();
    fs::path dirPath(destination);
    fs::path parentPath = dirPath;
    int count = 0;
    rewind(stdin);
    textToDisplay->displayBrowser();
  std::string diskName = dirPath.root_name().string() + "\\";
  int numberOfParents = 0;
  std::cout << diskName;
  countingDirectories(diskName, parentPath, &count);
  std::cout << "There is: " << count << " directories " << "from which would you like to start? ";
    numberOfParents = 3;
    for (int i = 0; i < numberOfParents; i++) {
        rewind(stdin);
        parentPath = parentPath.parent_path();
    }
  rewind(stdin);
  int modeSelect = 0;
  if (parentPath.string() == diskName) {
      fs::recursive_directory_iterator iter(dirPath);
      parentPath = dirPath;
      count = 0;
      rewind(stdin);
      std::cout << "You are in the root folder. Switching to the first parent path. ";
      countingDirectories(diskName, parentPath, &count);
      parentPath = dirPath;
      for (int i = 0; i < count - 1; i++) {
          parentPath = parentPath.parent_path().string();
      }
  }
   std::cout << "Right now you are in the: " << parentPath.parent_path().string() << "\n";
   std::cout << "Listing all current directories\n";
    fs::path previousPath;
   if (fs::exists(dirPath) && fs::is_directory(parentPath)) {
       for (const auto &p: fs::recursive_directory_iterator(parentPath)) {
           fs::path currentPath = p.path().parent_path();
           if (currentPath != previousPath) {
               textToDisplay->enterIntoBox("In folder");
               convertedString = QString::fromStdString(currentPath.filename().string());
               textToDisplay->enterIntoBox(convertedString);
               previousPath = currentPath;
           }
           convertedString = QString::fromStdString(p.path().filename().string());
           textToDisplay->enterIntoBox(convertedString);
       }
       std::cout << "\n";
   } else {
       std::cerr << "The specified path does not exist or is not a directory. " << std::endl;
   }
}

void DirectoryProperties::lineDelete(int numberToDelete, std::string *destination) {
    qDebug()<<*destination;
    fs::path bigPath;
    fs::path pathToDelete = fs::path(*destination);
    if (fs::exists(*destination)) {
        qDebug()<<"Works";
        fs::remove_all(pathToDelete);
    }
    bigPath = *destination;
    *destination = bigPath.parent_path().string();
    std::cout << "now you are in" << *destination << "\n";
}
