cmake_minimum_required(VERSION 3.16)

project(TableView_example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(appTableView_example
    main.cpp
)

qt_add_qml_module(appTableView_example
    URI TableView_example
    VERSION 1.0
    QML_FILES main.qml
    SOURCES Student.h Student.cpp
    SOURCES StudentModel.h StudentModel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTableView_example PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTableView_example
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTableView_example
    PRIVATE Qt6::Quick)
target_link_libraries(appTableView_example PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appTableView_example
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
