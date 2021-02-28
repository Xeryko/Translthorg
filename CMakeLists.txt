cmake_minimum_required(VERSION 3.10)
project(Translahorg)

add_executable("${PROJECT_NAME}"
    src/Test.cpp
)

target_include_directories("${PROJECT_NAME}" PUBLIC include/ externals/)
