cmake_minimum_required(VERSION 3.31)
project(TitanApplication)

set(CMAKE_CXX_STANDARD 20)

add_executable(TitanApplication "src/core/TitanApp.cpp"
                                "src/core/TitanApp.h")

target_link_libraries(TitanApplication PRIVATE TitanEngine)

target_include_directories(TitanApplication PRIVATE "../engine/src")

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    target_compile_definitions(TitanApplication PRIVATE -DTITAN_PLATFORM_WINDOWS)
endif(WIN32)

if (UNIX AND NOT APPLE)
    target_compile_definitions(TitanApplication PRIVATE -DTITAN_PLATFORM_LINUX)
endif(UNIX AND NOT APPLE)

if (UNIX AND APPLE)
    target_compile_definitions(TitanApplication PRIVATE -DTITAN_PLATFORM_MACOS)
endif(UNIX AND APPLE)

# function to copy directories for things like assets or config files. Anything outside the scope of the engine but necessary for it to run
#add_custom_command(TARGET TitanApplication PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/ $<TARGET_FILE_DIR:TitanApplication>/)

if(WIN32)
    add_custom_command(TARGET TitanApplication PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE_DIR:TitanApplication>/../engine/libTitanEngine.dll
            $<TARGET_FILE_DIR:TitanApplication>/)
endif()
