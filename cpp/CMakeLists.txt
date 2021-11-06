cmake_minimum_required(VERSION 3.17)
project(uptime)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE INCLUDES "include/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})
add_library(${PROJECT_NAME}_lib SHARED ${SOURCES} ${INCLUDES})
file(COPY ../uptime_file DESTINATION "${CMAKE_BINARY_DIR}")

enable_testing()
add_library(test_main OBJECT test/testMain.cpp)
add_executable(${PROJECT_NAME}_test test/uptimeTest.cpp $<TARGET_OBJECTS:test_main>)
target_link_libraries(
    ${PROJECT_NAME}_test PUBLIC
    uptime_lib
)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)