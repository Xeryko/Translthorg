cmake_minimum_required(VERSION 3.10)
project(Translathorg)

add_executable("${PROJECT_NAME}"
    src/StringPuller.cpp
    src/Test.cpp
)

target_include_directories("${PROJECT_NAME}" PUBLIC include/ externals/)
