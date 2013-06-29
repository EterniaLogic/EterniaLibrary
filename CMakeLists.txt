cmake_minimum_required(VERSION 2.8)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

PROJECT(EterniaLibrary) 



#add ALL files. (If you don't want a file to compile, just change the extension)
file(GLOB CC_src
    "*.h"
    "*.c"
    "*.cpp"
    "*.hpp"
    "src/*.h"
    "src/*.c"
    "src/*.cpp"
    "src/*.hpp"
    "src/*/*.h"
    "src/*/*.c"
    "src/*/*.cpp"
    "src/*/*.hpp"
    "src/*/*/*.h"
    "src/*/*/*.c"
    "src/*/*/*.cpp"
    "src/*/*/*.hpp"
    "src/*/*/*/*.h"
    "src/*/*/*/*.c"
    "src/*/*/*/*.cpp"
    "src/*/*/*/*.hpp"
    "src/*/*/*/*/*.h"
    "src/*/*/*/*/*.c"
    "src/*/*/*/*/*.cpp"
    "src/*/*/*/*/*.hpp"
)

ADD_DEFINITIONS(-pipe -std=c++0x -g3 -O3 -DDEBUG)
ADD_LIBRARY(Eternia STATIC ${CC_src})
#ADD_EXECUTABLE(EterniaLib.a ${CC_src})


