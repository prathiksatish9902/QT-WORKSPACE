cmake_minimum_required(VERSION 3.16)

project(pointers_file_task LANGUAGES C)

add_executable(pointers_file_task main.c)

include(GNUInstallDirs)
install(TARGETS pointers_file_task
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
