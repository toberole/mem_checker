cmake_minimum_required(VERSION 3.19)
project(mem_checker)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILES)

add_executable(mem_checker ${SRC_FILES})