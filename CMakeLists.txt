#/**
#* WolfIsland environment modeling project.
#*
#* Copyright 2018 by Kateryna Pereverzeva <katya.pereverzeva2109@gmail.com>
#* Copyright 2018 by Oleksandr Orlovskyi <orlovskyi.alex@gmail.com>
#*
#* This program is free software: you can redistribute it and/or modify
#* it under the terms of the GNU General Public License as published by
#* the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#*
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#*
#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.
#=========================================================================== */

cmake_minimum_required(VERSION 3.8)
project(WolfIsland)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp src/controller/Controller.cpp src/model/source/Field.cpp src/model/source/Cell.cpp
        src/model/source/Rabbit.cpp src/model/source/Wolf_M.cpp src/model/source/Wolf_W.cpp src/view/ConsoleView.cpp
        src/view/GUIView.cpp src/utils/utils.cpp)
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

set(RAPIDJSON_INCLUDEDIR "/usr/include/rapidjson")
find_package(rapidjson REQUIRED)
include_directories("${RAPIDJSON_INCLUDE_DIRS}")