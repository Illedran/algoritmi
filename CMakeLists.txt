cmake_minimum_required(VERSION 3.5)
project(sysop)

set(CMAKE_CXX_FLAGS "-O3 ${CMAKE_CXX_FLAGS}")

file(GLOB SOURCE_FILES graph/*.cpp)
foreach (source_file ${SOURCE_FILES})
    get_filename_component(executable_name ${source_file} NAME_WE)
    add_executable(${executable_name} ${source_file} graph/graph.h graph/graph.h)
endforeach (source_file ${SOURCE_FILES})