# MinGW and nasm are required

# Set compilers
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc-posix)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++-posix)
set(CMAKE_ASM_NASM_COMPILER nasm)

# Set compile flags
set(CMAKE_C_FLAGS "-std=c99 -O3 -s -static -Wall -Wextra -Werror -Wpedantic -Wshadow -DNDEBUG -fno-ident -funroll-loops -fvisibility=hidden")
set(CMAKE_CXX_FLAGS "-std=c++2a -O3 -s -static -Wall -Wextra -Werror -Wpedantic -Wshadow -DNDEBUG -fno-ident -fno-exceptions -fno-rtti -funroll-loops -fvisibility=hidden")
set(CMAKE_ASM_NASM_FLAGS "-f win32")
