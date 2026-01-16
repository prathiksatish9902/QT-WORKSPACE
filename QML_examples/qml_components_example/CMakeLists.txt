cmake_minimum_required(VERSION 3.16)

project(qml_components_example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appqml_components_example
    main.cpp
)

qt_add_qml_module(appqml_components_example
    URI qml_components_example
    VERSION 1.0
    QML_FILES main.qml
    RESOURCES Images/view-3d-car.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqml_components_example PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqml_components_example
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqml_components_example
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appqml_components_example
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
