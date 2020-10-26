cmake_minimum_required (VERSION 3.10.0)

project(benchmarks)

find_package(Threads REQUIRED)

set(BENCHMARK_ENABLE_TESTING 
    OFF 
    CACHE BOOL "Suppressing benchmark's tests" FORCE
)

set(SOURCE_FILES 
    main_benchmarks.cpp
)

add_executable(
    benchmarks 
    ${SOURCE_FILES}
)


target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/../include
)

#${CMAKE_THREAD_LIBS_INIT}
target_link_libraries(${PROJECT_NAME} benchmark toynn)
