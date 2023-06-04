cmake_minimum_required(VERSION 3.22.1)

project("Unix network programming" LANGUAGES C)

add_executable(
    main
    main.c
)

set(INCLUDE_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(cmake/utils.cmake)

add_subdirectory(intro)