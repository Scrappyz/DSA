cmake_minimum_required(VERSION 3.14)

# Declare unit testing framework
FetchContent_Declare(
    GTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# Make the framework available for the project
FetchContent_MakeAvailable(GTest)

# Enable unit testing and include the framework
enable_testing()
include(GoogleTest)

# Set unit testing binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Add the unit testing target executable
add_executable(list_test ${CMAKE_CURRENT_SOURCE_DIR}/src/list_test.cpp)
target_include_directories(list_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(list_test PUBLIC gtest_main)

add_executable(insertion_sort_test ${CMAKE_CURRENT_SOURCE_DIR}/src/insertion_sort_test.cpp)
target_include_directories(insertion_sort_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(insertion_sort_test PUBLIC gtest_main)

# Add tests
add_test(
    NAME ListTest
    COMMAND list_test
)

add_test(
    NAME InsertionSortTest
    COMMAND insertion_sort_test
)
