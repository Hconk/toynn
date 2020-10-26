cmake_minimum_required(VERSION 3.0.0)
project(toynn VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(3rdparty/gtest)
add_subdirectory(3rdparty/benchmark)

add_subdirectory(src)
add_subdirectory(benchmarks)
add_subdirectory(tests)
add_subdirectory(tools)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
