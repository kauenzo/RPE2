cmake_minimum_required(VERSION 3.27)
project(coral)

set(CMAKE_CXX_STANDARD 17)

add_executable(coral main.cpp
        funcoes.cpp
        funcoes.h)
