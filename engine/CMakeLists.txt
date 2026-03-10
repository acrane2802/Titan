cmake_minimum_required(VERSION 3.31)
project(TitanEngine)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(CMAKE_SHARED_LINKER_FLAGS  "-static-libgcc -static-libstdc++ -static")
    add_definitions(-DPLATFORM_WINDOWS)
endif(WIN32)

if (UNIX AND NOT APPLE)
    add_definitions(-DPLATFORM_LINUX)
endif(UNIX AND NOT APPLE)

if (UNIX AND APPLE)
    add_definitions(-DPLATFORM_MACOS)
endif(UNIX AND APPLE)

add_library(TitanEngine SHARED "src/core/engine.cpp" "src/core/engine.h")

# target_link_libraries(TitanEngine PRIVATE )