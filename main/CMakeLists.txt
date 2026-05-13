# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

# FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)
# 
# idf_component_register(SRCS ${app_sources})

# cmake_minimum_required(VERSION 3.16)
# 
# include($ENV{IDF_PATH}/tools/cmake/project.cmake)
# 
# project(IIOT_GATEWAY)

FILE(GLOB_RECURSE app_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS "." "../lib"
)
