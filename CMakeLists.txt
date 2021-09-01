cmake_minimum_required(VERSION 3.16)
project(30_2_cpr)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9) # the commit hash for 1.5.0
FetchContent_MakeAvailable(cpr)

add_executable(30_2_cpr main.cpp)
target_link_libraries(30_2_cpr PRIVATE cpr::cpr)
