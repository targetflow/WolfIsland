cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp testing/hello_world.cpp testing/hello_world.h controller/Controller.cpp controller/Controller.h
        model/include/Field.h model/source/Field.cpp)
add_executable(cpp ${SOURCE_FILES} main.cpp)