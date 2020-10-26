cmake_minimum_required(VERSION 3.10)

project( add_tool )

set(EXECUTABLE_OUTPUT_PATH  ..)

include_directories(${PROJECT_SOURCE_DIR}/../include)

set(SRC add_tool.cpp)

add_executable(add_tool ${SRC})
target_link_libraries(add_tool toynn)
