cmake_minimum_required(VERSION 3.1)
project(guzald)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/bin)

add_executable(${PROJECT_NAME} "guzald.c")
target_link_libraries(${PROJECT_NAME} PRIVATE)
