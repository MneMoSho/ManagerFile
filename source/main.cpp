#include "mainwindow.h"

#include <QApplication>
#include "Header.h"
#include "FileEdit.h"
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow varWindow;
    w.show();
    return a.exec();
}

