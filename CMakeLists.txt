cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -lwx_gtk3u_core-3.2 -lwx_baseu-3.2 -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2")

project(autobuilder)

add_executable(autobuilder main.cpp ui.cpp command.cpp commandHelper.cpp frameBase.cpp loc.cpp ui.cpp frame.cpp ui-interface.cpp global.cpp env.cpp)
