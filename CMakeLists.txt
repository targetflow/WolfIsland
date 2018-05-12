cmake_minimum_required(VERSION 3.8)
project(WolfIsland)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp controller/Controller.cpp model/source/Field.cpp model/source/Cell.cpp
        model/source/Rabbit.cpp model/source/Wolf_M.cpp model/source/Wolf_W.cpp view/ConsoleView.cpp
        view/GUIView.cpp utils/utils.cpp view/menu.h view/menu.cpp)
add_executable(WolfIsland ${SOURCE_FILES} main.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(TGUI 0.7 REQUIRED)

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(WolfIsland ${TGUI_LIBRARY} ${SFML_LIBRARIES})
endif()