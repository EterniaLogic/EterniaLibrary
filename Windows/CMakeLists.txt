cmake_minimum_required(VERSION 2.8)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
#set(CMAKE_LEGACY_CYGWIN_WIN32 0)
PROJECT(EterniaLibrary)

# assuming 
#   sudo apt install g++-mingw-w64 g++-mingw-w64-i686 mingw-w64
include (GenerateExportHeader)


set(CMAKE_TOOLCHAIN_FILE "./Toolchain-Mingw32.cmake")



#set( CMAKE_CXX_FLAGS "-pipe -std=c++11 -fPIC -w -DDEBUG -s -pie -fPIE -fno-stack-protector -Wstack-protector --param ssp-buffer-size=4" )
#set( CMAKE_C_FLAGS "-fPIC" )

set( CMAKE_CXX_FLAGS "-w" )

file(GLOB_RECURSE CC_src2
    "../src/*.h"
    "../src/*.c"
    "../src/*.cpp"
    "../src/*.hpp"
)

include_directories(src/)

FIND_PACKAGE(Threads REQUIRED)

# STATIC SHARED
ADD_LIBRARY("Eternia" STATIC ${CC_src2} "../Eternia.h")
TARGET_LINK_LIBRARIES(Eternia ${CMAKE_THREAD_LIBS_INIT})
#ADD_LIBRARY("EterniaS" SHARED ${CC_src2} "../Eternia.h")
#TARGET_LINK_LIBRARIES(EterniaS ${CMAKE_THREAD_LIBS_INIT})
ADD_EXECUTABLE("Eternia.exe" "../main.cpp" ${CC_src2} "../Eternia.h")
TARGET_LINK_LIBRARIES("Eternia.exe" ${CMAKE_THREAD_LIBS_INIT})


#GENERATE_EXPORT_HEADER( "EterniaS"
#             BASE_NAME EterniaS
#             EXPORT_MACRO_NAME EterniaS_EXPORT
#             EXPORT_FILE_NAME EterniaS_Export.h
#             STATIC_DEFINE EterniaS_BUILT_AS_STATIC
#)

#SET_TARGET_PROPERTIES (EterniaS PROPERTIES DEFINE_SYMBOL  "COMPILING_DLL" )


add_custom_target("Eternia.dll"
                DEPENDS Eternia
                WORKING_DIRECTORY ./
                #COMMAND x86_64-w64-mingw32-g++ -shared -Wl,--out-implib,libEternia.a -o libEternia.dll
                COMMAND i686-w64-mingw32-g++ -shared -Wl,--out-implib,libEternia.a -o libEternia.dll
                COMMENT "{EterniaLib} Generating 64-bit DLL from .a"
)

add_custom_command(TARGET "Eternia.exe"
                PRE_BUILD
                DEPENDS "Eternia.dll" Eternia
                WORKING_DIRECTORY ./
                COMMENT "{EterniaLib} Eternia.exe for tests generated"
)

