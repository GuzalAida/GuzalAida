cmake_minimum_required(VERSION 3.1)
project(GuzalAida)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(daemon)

add_executable(${PROJECT_NAME} "Guzal-Aida.c")
target_link_libraries(${PROJECT_NAME} PRIVATE)
