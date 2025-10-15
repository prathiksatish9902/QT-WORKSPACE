cmake_minimum_required(VERSION 3.16)

project(CustomRadioButton_example1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)

qt_add_executable(${PROJECT_NAME}
    main.cpp
)

# Use qml.qrc file (Qt resource system)
qt_add_resources(${PROJECT_NAME} "qml_resources"
    PREFIX "/"
    FILES qml.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
)

# Optional deployment rules
if(QNX)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY /tmp/${PROJECT_NAME}/bin
    )
elseif(UNIX AND NOT ANDROID)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY /opt/${PROJECT_NAME}/bin
    )
endif()
