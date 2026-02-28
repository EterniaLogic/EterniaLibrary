cmake_minimum_required(VERSION 2.9..3.1)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
PROJECT(EterniaLibrary)

set(CMAKE_VERBOSE_MAKEFILE:BOOL OFF)

# determine "Bitness" for 32-bit or 64-bit compiling.
#get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)#if (${LIB64} STREQUAL "TRUE")
    set(LIBSUFFIX "64bit")
else()
    set(LIBSUFFIX "32bit")
endif()

set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
#set(PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}")
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # fixes some .so shared library copying issues

message("${PROJECT_SOURCE_DIR} == ${PROJECT_BINARY_DIR}")
message("${CMAKE_CURRENT_LIST_DIR}")

#if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
#   message(SEND_ERROR "In-source builds are not allowed.")
#endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")


#build for windows under linux
# set(WIN32 1)
# cmake . -DWIN32=1 -DCMAKE_TOOLCHAIN_FILE=CMake_MingW64.cmake
# Common flags for both platforms
set(COMMON_LINKER_FLAGS "-s -static-libgcc -static-libstdc++")
set(EXTRA_LINKER_LIBRARIES_SET "")

if(MINGW OR WIN32 OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("NOTE: Building for Windows!")
    #include("CMake_MingW64.cmake")
    set(EXTRA_LINKER_LIBRARIES_SET "ws2_32")
	set(CMAKE_EXE_LINKER_FLAGS "${COMMON_LINKER_FLAGS} -lwinpthread" CACHE STRING "" FORCE)
else()
    set( CMAKE_CXX_FLAGS "-pipe -std=c++17 -fPIC -w -DDEBUG -s -pie -fPIE -fno-stack-protector -Wstack-protector --param ssp-buffer-size=4" )
    set( CMAKE_C_FLAGS "-fPIC" )
    #set(CMAKE_EXE_LINKER_FLAGS "${COMMON_LINKER_FLAGS} -rdynamic" CACHE STRING "" FORCE)
endif()


# Extra options to GCC when compiling to help enforce memory security
# -fPIC
# -fstack-protector-all
# -DDEBUG    <-- debug symbols


#add ALL files. (If you don't want a file to compile, just change the extension)
file(GLOB_RECURSE CC_LibraryFiles
    "src/*.h"
    "src/*.c"
    "src/*.cpp"
    "src/*.hpp"
)
file(GLOB_RECURSE CC_TestFiles
    "test/*.h"
    "test/*.c"
    "test/*.cpp"
    "test/*.hpp"
)

# Remove main and test cpp so that libraries can be produced without 'main' conflicts
list(REMOVE_ITEM CC_LibraryFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

include_directories(src/)


FIND_PACKAGE(Threads REQUIRED)

set(${PROJECT_NAME}_DEFINITIONS
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)


SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

# temporary STATIC files, usually not directly copied to OS
ADD_LIBRARY("EterniaS" STATIC ${CC_LibraryFiles})
TARGET_LINK_LIBRARIES(EterniaS ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LINKER_LIBRARIES_SET})
ADD_LIBRARY("EterniaS32" STATIC ${CC_LibraryFiles})
TARGET_LINK_LIBRARIES("EterniaS32" ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LINKER_LIBRARIES_SET})
set_target_properties("EterniaS32" PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
ADD_LIBRARY("EterniaTestLib" STATIC ${CC_LibraryFiles} ${CC_TestFiles})
TARGET_LINK_LIBRARIES(EterniaTestLib ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LINKER_LIBRARIES_SET})

ADD_EXECUTABLE("EterniaExec" "src/main.cpp")
TARGET_LINK_LIBRARIES(EterniaExec "EterniaTestLib" ${EXTRA_LINKER_LIBRARIES_SET})
set_target_properties(EterniaExec PROPERTIES ENABLE_EXPORTS FALSE) #Fix for MingW64 -rdynamic error


# Link .dll, .so, or .dylib files based on OS. To be copied to OS in install.
ADD_LIBRARY("Eternia" SHARED "src/Eternia.h")
TARGET_LINK_LIBRARIES(Eternia PRIVATE "$<LINK_LIBRARY:WHOLE_ARCHIVE,EterniaS>" ${EXTRA_LINKER_LIBRARIES_SET})
ADD_LIBRARY("Eternia32" SHARED "src/Eternia.h")
TARGET_LINK_LIBRARIES(Eternia32 PRIVATE "$<LINK_LIBRARY:WHOLE_ARCHIVE,EterniaS32>" ${EXTRA_LINKER_LIBRARIES_SET})

set_target_properties("Eternia32" PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

# Test executable
ADD_EXECUTABLE("EterniaTest" "test/test.cpp")
TARGET_LINK_LIBRARIES(EterniaTest "EterniaTestLib" ${EXTRA_LINKER_LIBRARIES_SET})



# increase the version
add_custom_command(TARGET Eternia
                POST_BUILD
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/
                COMMAND bash "build/Scripts/version.sh"
                COMMENT "{EterniaLib} version up"
)

# after-build reminder where to find the executable to test functions directly
add_custom_command(TARGET EterniaExec
                POST_BUILD
                WORKING_DIRECTORY /
                COMMENT "{EterniaLib} use cd build, then ./bin/EterniaExec to run basic tests"
)

# Move include header files
add_custom_command(TARGET Eternia
                PRE_BUILD
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/
                COMMAND bash build/Scripts/copyincludes.sh
                COMMENT "{EterniaLib} copy headers to includes"
)

add_custom_target(runtest
                COMMAND EterniaExec
                DEPENDS Eternia
                DEPENDS EterniaExec
                WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)

add_custom_target(windows
                COMMAND cmake . -DWIN32=1 -DCMAKE_TOOLCHAIN_FILE=CMake_MingW64.cmake
                DEPENDS Eternia
                DEPENDS EterniaExec
                WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)

add_custom_target(run
                DEPENDS EterniaExec
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/
                COMMAND bin/EterniaExec
)


enable_testing()
set(CTEST_OUTPUT_ON_FAILURE 1)
add_test(Math build/bin/EterniaTest "Math")
add_test(DataStructureMemoryLeaks build/bin/EterniaTest "DataStruMemLeaks")
#add_subdirectory(test)


#### Pre-packaging

# Determine the architecture suffix
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LIB_DIR "lib/x86_64-linux-gnu")
    set(PKG_ARCH "amd64")
else()
    set(LIB_DIR "lib/i386-linux-gnu")
    set(PKG_ARCH "i386")
endif()

#installing headers/source and binaries

# Targets

# dont send exec and tests to deb library file
install (TARGETS EterniaExec DESTINATION bin COMPONENT Test64)
install (TARGETS EterniaTest DESTINATION bin COMPONENT Test64)
install(DIRECTORY doc/man DESTINATION share/ COMPONENT Test64) # man documents for tests
#install(DIRECTORY build/bin/www) DESTINATION

# Primary packaged libraries
install(TARGETS Eternia32 DESTINATION ${LIB_DIR} COMPONENT Library32)
install(TARGETS Eternia   DESTINATION ${LIB_DIR} COMPONENT Library64)

INSTALL(DIRECTORY build/include DESTINATION . COMPONENT Library32)
INSTALL(DIRECTORY build/include DESTINATION . COMPONENT Library64)


if(NOT(MINGW OR WIN32 OR CMAKE_SYSTEM_NAME STREQUAL "Windows"))
    include("CMake_DebianPackaging.cmake")
endif()
