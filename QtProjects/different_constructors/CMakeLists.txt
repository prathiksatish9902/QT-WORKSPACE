cmake_minimum_required(VERSION 3.16)

project(different_constructors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(different_constructors main.cpp
    a.h a.cpp)

include(GNUInstallDirs)
install(TARGETS different_constructors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
