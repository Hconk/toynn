cmake_minimum_required (VERSION 3.0.0)

include(GoogleTest)

aux_source_directory(. SOURCE_FILES)

#set(SOURCE_FILES 
#    main_tests.cpp
#)

#set(EXECUTABLE_OUTPUT_PATH  ..)

add_executable(tests
    ${SOURCE_FILES}
)

target_include_directories(tests 
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include/
    ../lib/benchmark/googletest/googletest/include/
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

target_link_libraries(tests PUBLIC gtest gtest_main toynn)

gtest_discover_tests(tests)
