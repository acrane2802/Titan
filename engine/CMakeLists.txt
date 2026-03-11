cmake_minimum_required(VERSION 3.31)
project(TitanEngine)

set(CMAKE_CXX_STANDARD 20)

add_library(TitanEngine SHARED "src/core/APIDLLExportHandler.h"
                               "src/core/Application.cpp"
                               "src/core/Application.h"
                               "src/Titan.h"
                               "src/core/Entrypoint.h")

# target_link_libraries(TitanEngine PUBLIC )

# target_include_directories(TitanEngine PUBLIC )

if (WIN32)
    set(CMAKE_SHARED_LINKER_FLAGS  "-static-libgcc -static-libstdc++ -static")
    target_compile_definitions(TitanEngine PRIVATE -DTITAN_PLATFORM_WINDOWS PRIVATE -DTITAN_BUILD_DLL)
endif(WIN32)

if (UNIX AND NOT APPLE)
    target_compile_definitions(TitanApplication PRIVATE -DTITAN_PLATFORM_LINUX)
endif(UNIX AND NOT APPLE)

if (UNIX AND APPLE)
    target_compile_definitions(TitanApplication PRIVATE -DTITAN_PLATFORM_MACOS)
endif(UNIX AND APPLE)