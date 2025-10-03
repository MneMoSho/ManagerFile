//
// Created by Gleb on 24.10.2024.
//

#ifndef UNTITLED4_EDITOR_H
#define UNTITLED4_EDITOR_H

#include "Header.h"
#include "FileEdit.h"
#include "FileProperties.h"


class Editor : public FilePropeties, public DirectoryProperties
{
public:
    void setDestinationEdit(std::string_view setDestination);
    std::string getDestinationEdit() const;
    void createNewFile(const std::string& destName);
    void updateAnExisted(int numberOfLines, std::string& destName);
    void deleteFromExisting(std::string destName);
    void readFile(const std::string& destName);
    void deleteFile(const std::string& directory);
    void createDir();
    void readDir();
    void deleteDir();

private:
    std::string destination;
};


#endif //UNTITLED4_EDITOR_H
