cmake_minimum_required(VERSION 3.7)

project(main)

add_compile_options(-Wall -g -pedantic)

include_directories(
"Libraries"
"Sources"
)


add_executable(
main
Sources/main.cpp
Sources/students.cpp
Libraries/students.h
)

