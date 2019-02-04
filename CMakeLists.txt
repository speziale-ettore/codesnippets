########################################################################
# CMake build script for Code Snippets.
#

cmake_minimum_required(VERSION 3.12)

project(gtest CXX)

set(GOOGLETEST_VERSION 1.8.1)
add_subdirectory(googletest)

add_subdirectory(helloworld)
