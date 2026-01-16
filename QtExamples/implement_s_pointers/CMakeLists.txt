cmake_minimum_required(VERSION 3.16)

project(implement_s_pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(implement_s_pointers main.cpp
    MyClass.h MyClass.cpp
    Button.h Button.cpp)

include(GNUInstallDirs)
install(TARGETS implement_s_pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
