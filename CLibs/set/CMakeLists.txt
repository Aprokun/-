cmake_minimum_required(VERSION 3.17)
project(set C)

set(CMAKE_C_STANDARD 11)

add_library(set SHARED library.c library.h)