cmake_minimum_required(VERSION 3.22.1)
project(testproj CXX)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    candle.cpp
)

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

enable_testing()
add_test(NAME AllTests COMMAND testproj)