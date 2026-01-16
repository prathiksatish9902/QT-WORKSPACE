# cmake_minimum_required(VERSION 3.16)

# project(QAbstractSocket_isvalid_function_example VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# set(PROJECT_SOURCES
#         main.cpp
#         widget.cpp
#         widget.h
# )

# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(QAbstractSocket_isvalid_function_example
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}

#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET QAbstractSocket_isvalid_function_example APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# else()
#     if(ANDROID)
#         add_library(QAbstractSocket_isvalid_function_example SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(QAbstractSocket_isvalid_function_example
#             ${PROJECT_SOURCES}
#         )
#     endif()
# endif()

# target_link_libraries(QAbstractSocket_isvalid_function_example PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QAbstractSocket_isvalid_function_example)
# endif()
# set_target_properties(QAbstractSocket_isvalid_function_example PROPERTIES
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS QAbstractSocket_isvalid_function_example
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(QAbstractSocket_isvalid_function_example)
# endif()




cmake_minimum_required(VERSION 3.16)

project(QAbstractSocket_isvalid_function_example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🟢 Step 1: Add Core and Network components to find_package
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Network)

set(PROJECT_SOURCES
    main.cpp
    widget.cpp
    widget.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QAbstractSocket_isvalid_function_example
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(QAbstractSocket_isvalid_function_example SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QAbstractSocket_isvalid_function_example
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# 🟢 Step 2: Link against Qt Core, Widgets, and Network modules
target_link_libraries(QAbstractSocket_isvalid_function_example
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
)

# Optional macOS/iOS bundle ID
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QAbstractSocket_isvalid_function_example)
endif()

set_target_properties(QAbstractSocket_isvalid_function_example PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QAbstractSocket_isvalid_function_example
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QAbstractSocket_isvalid_function_example)
endif()
