set(WIN32 1)
set(CMAKE_C_COMPILER_WORKS 1) #Temporary hack for compiling error
set(CMAKE_CXX_COMPILER_WORKS 1)
SET(CMAKE_SYSTEM_NAME Windows)
# the name of the target operating system
add_definitions(-D_HAS_STD_BYTE=0)


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
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,rdynamic \
    -static-libgcc \
    -static-libstdc++ \
    -Wl,--strip-all \
    -Wl,--build-id=none \
    -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive \
    -Wl,--no-insert-timestamp \
    -Wl,--gc-sections \
")

# force workaround for -rdynamic being added even though it shouldn't for mingw windows builds'
string(REPLACE "-rdynamic" "" CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
string(REPLACE "-rdynamic" "" CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
