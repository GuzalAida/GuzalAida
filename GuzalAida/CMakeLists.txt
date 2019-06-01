cmake_minimum_required(VERSION 3.1)
project(GuzalAida)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/bin)


add_executable(${PROJECT_NAME} "GuzalAida.c")
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
