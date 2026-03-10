cmake_minimum_required(VERSION 3.31)
project(TitanApplication)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    add_definitions(-DPLATFORM_WINDOWS)
endif(WIN32)

if (UNIX AND NOT APPLE)
    add_definitions(-DPLATFORM_LINUX)
endif(UNIX AND NOT APPLE)

if (UNIX AND APPLE)
    add_definitions(-DPLATFORM_MACOS)
endif(UNIX AND APPLE)

add_executable(TitanApplication "src/core/app.cpp" "src/core/app.h")

target_link_libraries(TitanApplication PRIVATE TitanEngine)

target_include_directories(TitanApplication PRIVATE "../engine/src/core")

#add_custom_command(TARGET TitanApplication PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/ $<TARGET_FILE_DIR:TitanApplication>/)

if(WIN32)
    add_custom_command(TARGET TitanApplication PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE_DIR:TitanApplication>/../engine/libTitanEngine.dll $<TARGET_FILE_DIR:TitanApplication>/)
endif()
