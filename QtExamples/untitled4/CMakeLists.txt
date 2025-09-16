cmake_minimum_required(VERSION 3.16)

project(untitled4 LANGUAGES C)

add_executable(untitled4 main.c)

include(GNUInstallDirs)
install(TARGETS untitled4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
