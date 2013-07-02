cmake_minimum_required(VERSION 2.8)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
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
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
SUBDIRLIST(SUBDIRS src)


IF (WIN32)
	
ELSE()
	ADD_DEFINITIONS(-pipe -std=c++0x -O3)
ENDIF()

ADD_LIBRARY(Eternia STATIC ${CC_src})
#ADD_EXECUTABLE(EterniaLib.a ${CC_src})


FOREACH(subdir ${SUBDIRS})
    #ADD_SUBDIRECTORY(${subdir})
	file(GLOB ${subdir}_files
		"*.h"
		"*.c"
		"*.cpp"
		"*.hpp"
	)
	SOURCE_GROUP(${subdir} FILES ${subdir}_files)
ENDFOREACH()
