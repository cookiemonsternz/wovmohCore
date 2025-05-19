cmake_minimum_required(VERSION 3.16)

project(wovmohCore LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(wovmohCore
  main.cpp
  types/datatypes.h
  core/pin.h core/pin.cpp
  core/node.h core/node.cpp
  core/patchgraph.h core/patchgraph.cpp
  graph/patchdata.h graph/patchdata.cpp
  graph/nodedata.h graph/nodedata.cpp
  graph/pindata.h graph/pindata.cpp
  Nodes/corenodes.h Nodes/corenodes.cpp
  lib/json.hpp
)

qt_add_qml_module(wovmohCore
    URI wovmohCore
    VERSION 1.0
    QML_FILES
        ui/Main.qml
        ui/test.qml
        QML_FILES
        SOURCES graph/patchmanager.h graph/patchmanager.cpp
)

target_link_libraries(wovmohCore
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
  PRIVATE Qt${QT_VERSION_MAJOR}::Quick
)

include(GNUInstallDirs)
install(TARGETS wovmohCore
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
