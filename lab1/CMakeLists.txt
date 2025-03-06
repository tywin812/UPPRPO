cmake_minimum_required(VERSION 3.22.1)
project(testproj CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
    main.cpp
    candle.cpp
)

target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND testproj)