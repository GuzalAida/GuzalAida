cmake_minimum_required(VERSION 3.1)
project(mqtt.bin)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/bin)

add_executable(${PROJECT_NAME} "src/server.c" "src/config.h" "src/content_type.h")
target_link_libraries(${PROJECT_NAME} PRIVATE)
