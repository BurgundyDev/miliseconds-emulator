cmake_minimum_required(VERSION 3.31)
project(miliseconds_emulator)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)

add_executable(miliseconds_emulator)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32 TRUE)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
    add_compile_definitions(MS_PLATFORM_WINDOWS)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()


#FetchContent_Declare(fmt
#        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#        GIT_TAG master
#)
#FetchContent_MakeAvailable(fmt)

add_subdirectory(fmt-src)

find_package(Threads REQUIRED)

target_sources(${PROJECT_NAME} PRIVATE
        "src/main.cpp"
        "src/MemTracker.cpp"
        "src/EngineObject.cpp"
    )

target_include_directories(${PROJECT_NAME} PUBLIC include "fmt-src/")

target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt::fmt
    Threads::Threads)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(MS_CONFIG_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    add_compile_definitions(MS_CONFIG_RELEASE)
endif()