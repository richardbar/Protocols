# (c) 2025 Rikarnto Bariampa
# This code is licensed under MIT license (see LICENSE for details)

cmake_minimum_required(VERSION 3.20)
project(Protocols
    VERSION 1.0.0
    DESCRIPTION "C/C++ iot library"
    HOMEPAGE_URL "https://github.com/richardbar/Protocols"
    LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_CURRENT_LIST_DIR}/lib/CMakeLists.txt)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

add_library(Protocols STATIC ${Protocols_SRC})
target_include_directories(Protocols PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
