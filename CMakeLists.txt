cmake_minimum_required(VERSION 3.14)
project(MergeSortProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)


set(CMAKE_TLS_VERIFY OFF)

# Wyłączamy zbędne elementy Google Testa
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_build_samples OFF CACHE BOOL "" FORCE)
set(gtest_build_tests OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE 
)
FetchContent_MakeAvailable(googletest)

# program główny
add_executable(MergeSortApp main.cpp)

# testy
enable_testing()
add_executable(MergeSortTests test.cpp)
target_link_libraries(MergeSortTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(MergeSortTests)