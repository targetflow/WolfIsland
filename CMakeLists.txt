cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp controller/Controller.cpp model/source/Field.cpp)
add_executable(cpp ${SOURCE_FILES} main.cpp)