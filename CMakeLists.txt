cmake_minimum_required(VERSION 2.8)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
PROJECT(EterniaLibrary)

set(CMAKE_VERBOSE_MAKEFILE:BOOL OFF)

# determine "Bitness" for 32-bit or 64-bit compiling.
#get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)#if (${LIB64} STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "32")
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
set( CMAKE_CXX_FLAGS "-pipe -std=c++17 -fPIC -w -DDEBUG -s -pie -fPIE -fno-stack-protector -Wstack-protector --param ssp-buffer-size=4" )
set( CMAKE_C_FLAGS "-fPIC" )

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

# Remove main and test cpp so that libraries can be produced.
list(REMOVE_ITEM CC_LibraryFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp"
)

include_directories(src/)


FIND_PACKAGE(Threads REQUIRED)

set(${PROJECT_NAME}_DEFINITIONS
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)


SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

# temporary STATIC files, usually not directly copied to OS
ADD_LIBRARY("EterniaS" STATIC ${CC_LibraryFiles})
TARGET_LINK_LIBRARIES(Eternia ${CMAKE_THREAD_LIBS_INIT})
ADD_LIBRARY("EterniaS32" STATIC ${CC_LibraryFiles})
TARGET_LINK_LIBRARIES("EterniaS32" ${CMAKE_THREAD_LIBS_INIT})
set_target_properties("EterniaS32" PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
ADD_LIBRARY("EterniaTestLib" STATIC ${CC_LibraryFiles} ${CC_TestFiles})
TARGET_LINK_LIBRARIES(EterniaTestLib ${CMAKE_THREAD_LIBS_INIT})

ADD_EXECUTABLE("EterniaExec" "src/main.cpp")
TARGET_LINK_LIBRARIES(EterniaExec "EterniaTestLib")

# Link .dll, .so, or .dylib files based on OS. To be copied to OS in install.
ADD_LIBRARY("Eternia" SHARED "src/Eternia.h")
TARGET_LINK_LIBRARIES(Eternia PRIVATE "$<LINK_LIBRARY:WHOLE_ARCHIVE,EterniaS>")
ADD_LIBRARY("Eternia32" SHARED "src/Eternia.h")
TARGET_LINK_LIBRARIES(Eternia32 PRIVATE "$<LINK_LIBRARY:WHOLE_ARCHIVE,EterniaS32>")
set_target_properties("Eternia32" PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

# Test executable
ADD_EXECUTABLE("EterniaTest" "test/test.cpp")
TARGET_LINK_LIBRARIES(EterniaTest "EterniaTestLib")

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

#add_custom_command(TARGET EterniaS
#                POST_BUILD
#                WORKING_DIRECTORY /
#                COMMAND cp build/lib/libEterniaS.so build/lib/libEternia.so
#                COMMENT "{EterniaLib} copy shared libEterniaS.so to libEternia.so"
#)

add_custom_target(runtest
                COMMAND EterniaExec
                DEPENDS Eternia
                DEPENDS EterniaExec
                WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)

add_custom_target(windows
                COMMAND cmake -c ./Windows.cmake
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


#installing headers/source and binaries

# Targets
install (TARGETS EterniaExec DESTINATION build/bin)
install (TARGETS EterniaTest DESTINATION build/bin)
install (TARGETS Eternia Eternia32 DESTINATION build/lib)

# includes sent for packaging
install (DIRECTORY include/ DESTINATION build/include)
install (DIRECTORY doc/man DESTINATION build/share/doc/man)


# for EterniaS, *.so files for Linux
install (FILES lib/libEternia.so DESTINATION build/lib)



# Packaging
if(WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
else()
    set(CPACK_GENERATOR "TGZ;RPM;DEB")
endif()
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "EterniaLogic") #required
set(CPACK_DEBIAN_PACKAGE_NAME "libEternia")
set(CPACK_ROM_PACKAGE_NAME "libEternia")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Low-end support library, which includes basic algorithms and data structures.")
set(CPACK_RPM_PACKAGE_DESCRIPTION "Low-end support library, which includes basic algorithms and data structures.")
INCLUDE(CPack)
