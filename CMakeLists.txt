cmake_minimum_required(VERSION 3.29)
project(untitled4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(headers)

file(GLOB SOURCES "source/*.cpp")
file(GLOB SOURCES "interface/*.ui")

add_executable(untitled4 source/main.cpp

        source/mainwindow.cpp
        headers/mainwindow.h
        source/mainwindow.ui
        source/settingdir.cpp
        headers/settingdir.h
        source/settingdir.ui
        source/DirectoryProperties.cpp
        headers/DirectoryProperties.h
        source/Editor.cpp
        headers/Editor.h
        source/FileEdit.cpp
        headers/FileEdit.h
        source/Path.cpp
        headers/Path.h
        headers/Header.h
        source/IOperations.cpp
        headers/IOperations.h
        source/fucntion.cpp
        source/DirectoryProperties.cpp
        source/Editor.cpp
       headers/Editor.h
        source/FileEdit.cpp
        source/fucntion.cpp
        source/IOperations.cpp
        source/mainwindow.cpp
        source/Path.cpp
        source/settingdir.cpp
        source/setnewname.cpp
        headers/setnewname.h
        source/setnewname.ui
        source/displaytext.cpp
        headers/displaytext.h
        source/displaytext.ui
        source/NameEnter.cpp
        headers/NameEnter.h
        source/NameEnter.ui
        source/LineToAdd.cpp
        headers/LineToAdd.h
        source/LineToAdd.ui
        source/SetNewText.cpp
        headers/SetNewText.h
        source/SetNewText.ui
        source/FileProperties.cpp
        headers/FileProperties.h
        source/FileProperties.ui
        source/Node.cpp
        source/List.cpp
        headers/List.h
        headers/Node.h
        source/BinBucket.cpp
        headers/BinBucket.h
        source/DisplayBucketFiles.cpp
        headers/DisplayBucketFiles.h
        source/DisplayBucketFiles.ui
        headers/List.h
        source/List.cpp
        source/Exception.cpp
        headers/Exception.h
        source/Exception.cpp
        headers/Exception.h
        source/Exception.ui
        source/Filter.cpp
        headers/Filter.h
        source/FileComponents.cpp
        headers/FileComponents.h
        source/FileComponents.cpp
        headers/FileComponents.h
        source/Filter.cpp
        headers/Filter.h
        source/FileComponents.cpp
        source/FileComponents.cpp
        source/JsonReport.cpp
        headers/JsonReport.h
        source/JsonReport.ui
        source/PathContainerFile.cpp
        headers/PathContainerFile.h
        source/TempPath.cpp
        headers/TempPath.h
        source/TempPath.ui
        source/PathIteratorFile.cpp
        headers/PathIteratorFile.h
)

set(SOURCES source/main.cpp

        source/mainwindow.cpp
        headers/mainwindow.h
        source/mainwindow.ui
        source/settingdir.cpp
        headers/settingdir.h
        source/settingdir.ui
        source/DirectoryProperties.cpp
        headers/DirectoryProperties.h
        source/Editor.cpp
        headers/Editor.h
        source/FileEdit.cpp
        headers/FileEdit.h
        source/Path.cpp
        headers/Path.h
        headers/Header.h
        source/IOperations.cpp
        headers/IOperations.h
        source/fucntion.cpp
        source/DirectoryProperties.cpp
        source/Editor.cpp
        headers/Editor.h
        source/FileEdit.cpp
        source/fucntion.cpp
        source/IOperations.cpp
        source/mainwindow.cpp
        source/Path.cpp
        source/settingdir.cpp
        source/setnewname.cpp
        headers/setnewname.h
        source/setnewname.ui
        source/displaytext.cpp
        headers/displaytext.h
        source/displaytext.ui
        source/NameEnter.cpp
        headers/NameEnter.h
        source/NameEnter.ui
        source/LineToAdd.cpp
        headers/LineToAdd.h
        source/LineToAdd.ui
        source/SetNewText.cpp
        headers/SetNewText.h
        source/SetNewText.ui
        source/FileProperties.cpp
        headers/FileProperties.h
        source/FileProperties.ui
        source/ListToDelete.cpp
        ListToDelete.h)

target_link_libraries(untitled4
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

target_include_directories(untitled4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_include_directories(untitled4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source")
target_include_directories(untitled4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/interface")

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
