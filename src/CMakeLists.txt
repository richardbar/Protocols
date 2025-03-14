# (c) 2025 Rikarnto Bariampa
# This code is licensed under MIT license (see LICENSE for details)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    include(${CMAKE_CURRENT_LIST_DIR}/linux/CMakeLists.txt)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    include(${CMAKE_CURRENT_LIST_DIR}/macos/CMakeLists.txt)
elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
    include(${CMAKE_CURRENT_LIST_DIR}/freebsd/CMakeLists.txt)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    include(${CMAKE_CURRENT_LIST_DIR}/windows/CMakeLists.txt)
else()
    message(FATAL_ERROR "Unsupported system")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
