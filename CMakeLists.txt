cmake_minimum_required(VERSION 3.1)
project(GuzalAida)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${CMAKE_BUILD_TYPE})

add_subdirectory(daemon)
add_subdirectory(GuzalAida)

target_link_libraries(${PROJECT_NAME} PRIVATE)
