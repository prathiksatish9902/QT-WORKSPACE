cmake_minimum_required(VERSION 3.16)

project(pointers_tutorial LANGUAGES C)

add_executable(pointers_tutorial main.c)

include(GNUInstallDirs)
install(TARGETS pointers_tutorial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
