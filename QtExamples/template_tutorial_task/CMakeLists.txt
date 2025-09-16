cmake_minimum_required(VERSION 3.16)

project(template_tutorial_task LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(template_tutorial_task main.cpp
    linkedlist.h linkedlist.cpp)

include(GNUInstallDirs)
install(TARGETS template_tutorial_task
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
