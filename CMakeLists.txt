cmake_minimum_required(VERSION 4.3.0)

# Project set up

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(Lab1 VERSION 0.1.0 LANGUAGES CXX)

# Executable

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(Lab1
  ./resources.qrc

  ./src/main.cpp
  ./src/ui/windows/mainWindow.cpp
  ./src/ui/components/shapesCanvas.cpp
)

target_link_libraries(Lab1 PRIVATE Qt6::Widgets)

qt_finalize_target(Lab1)

