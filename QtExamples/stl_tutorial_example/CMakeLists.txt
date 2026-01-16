cmake_minimum_required(VERSION 3.16)

project(stl_tutorial_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stl_tutorial_example main.cpp
    student.h student.cpp)

include(GNUInstallDirs)
install(TARGETS stl_tutorial_example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
