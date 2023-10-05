cmake_minimum_required(VERSION 3.5)

project(Main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main main.h main.cpp)

install(TARGETS Main
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

