#include "Header.h"

class fileEdit
{
public:
    fileEdit(const std::string& firstName, const std::string& fileType, const std::string& information, const int totalLineCount);
    ~fileEdit();
    void fileCreate(int numberOfLines, const std::string& name);
    void fileUpdate(int numberOfLines, std::string name);
    void fileRead(std::string buf, std::string name);
    void lineDelete(int lineToDelete, std::string Buf, int currentLine, std::string name);
    int checkFile() const;
    std::string getFirstName() const;
    std::string getFileType() const;
    void setFirstName(std::string_view name);
    void setFileType(std::string_view type);

private:

    std::ifstream fin;
    std::ofstream fout;
    int totalLineCount = 0;
    std::string firstName;
    std::string fileType;
    std::string information;

};
