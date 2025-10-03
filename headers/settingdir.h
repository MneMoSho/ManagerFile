//
// Created by Gleb on 22.10.2024.

#ifndef UNTITLED4_SETTINGDIRECTORYMODE_H
#define UNTITLED4_SETTINGDIRECTORYMODE_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingDirectoryMode; }
QT_END_NAMESPACE

class SettingDirectoryMode : public QWidget {
Q_OBJECT

public:
    explicit SettingDirectoryMode(QWidget *parent = nullptr);

    ~SettingDirectoryMode() override;

public slots:
    void settingDiskName(std::string diskNameToSet);
    void on_buttonToApply_clicked();
    void checkForLine();
    signals:
    void signalToApply(const QString textToApply);
    void signalToDisplay(const QString display);

private:
    Ui::SettingDirectoryMode *ui;
    std::string diskName;
};

#endif //UNTITLED4_SettingDirectoryMode_H