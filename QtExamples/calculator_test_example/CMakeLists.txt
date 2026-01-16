cmake_minimum_required(VERSION 3.16)

project(calculator_test_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

set(CMAKE_AUTOMOC ON)  # <--- Ensure this line is present

add_executable(calculator_test_example
    main.cpp
    calculator.cpp
)

target_link_libraries(calculator_test_example PRIVATE Qt6::Core)

add_executable(calculator_tests
    testcalculator.cpp
    calculator.cpp
)

target_link_libraries(calculator_tests PRIVATE Qt6::Test Qt6::Core)

enable_testing()
add_test(NAME CalculatorTests COMMAND calculator_tests)

include(GNUInstallDirs)
install(TARGETS calculator_test_example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
