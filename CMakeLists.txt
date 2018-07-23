cmake_minimum_required(VERSION 2.8)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
PROJECT(EterniaLibrary)


# determine "Bitness" for 32-bit or 64-bit compiling.
#get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)#if (${LIB64} STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "32")
endif()


#build for windows under linux
############################set(WIN32 1)
IF(WIN32)
    message("NOTE: Building for Windows!")
	# the name of the target operating system
	SET(CMAKE_SYSTEM_NAME Windows)

	# which compilers to use for C and C++
	SET(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
	SET(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
	SET(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

	# here is the target environment located
	SET(CMAKE_FIND_ROOT_PATH  /usr/x86_64-w64-mingw32 )

	# adjust the default behaviour of the FIND_XXX() commands:
	# search headers and libraries in the target environment, search
	# programs in the host environment
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

ENDIF()


# Extra options to GCC when compiling to help enforce memory security
# -fPIC
# -fstack-protector-all
set( CMAKE_CXX_FLAGS "-pipe -std=c++11 -fPIC -w -DDEBUG -s -pie -fPIE -fno-stack-protector -Wstack-protector --param ssp-buffer-size=4" )
set( CMAKE_C_FLAGS "-fPIC" )

#add ALL files. (If you don't want a file to compile, just change the extension)
file(GLOB_RECURSE CC_src2
    "main.cpp"
    "src/*.h"
    "src/*.c"
    "src/*.cpp"
    "src/*.hpp"
)

include_directories(src/)


FIND_PACKAGE(Threads REQUIRED)

set(${PROJECT_NAME}_DEFINITIONS
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)


# STATIC SHARED
ADD_LIBRARY("Eternia" STATIC ${CC_src2})
ADD_EXECUTABLE("EterniaExec" ${CC_src2})

TARGET_LINK_LIBRARIES(Eternia ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(EterniaExec ${CMAKE_THREAD_LIBS_INIT})

add_custom_command(TARGET Eternia
                PRE_BUILD
                WORKING_DIRECTORY ./
                COMMAND bash version.sh
                COMMENT "version up"
)


#add_custom_command(TARGET Eternia
#                PRE_BUILD
#                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#                COMMAND bash copyincludes.sh
#                COMMENT "EterniaLibrary - Copying includes over"
#)

