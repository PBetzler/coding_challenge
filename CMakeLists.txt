cmake_minimum_required(VERSION 3.16)
project(c_cpp_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(cifuzz)
enable_fuzz_testing()

add_library(base64 lib/base64.cpp)

add_library(coding_challenge src/coding_challenge.cpp)
target_include_directories(coding_challenge PRIVATE lib)
target_link_libraries(coding_challenge PUBLIC base64)

add_fuzz_test(coding_challenge_test src/coding_challenge_test.cpp)
target_link_libraries(coding_challenge_test PRIVATE coding_challenge)