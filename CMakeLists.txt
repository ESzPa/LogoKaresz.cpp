cmake_minimum_required(VERSION 3.10)
project(LogoKaresz++ VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(raylib REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(logokaresz ${SOURCES})
target_include_directories(logokaresz PRIVATE ${INCLUDE_DIR})
target_link_libraries(logokaresz PRIVATE raylib)