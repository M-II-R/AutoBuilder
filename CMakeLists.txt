cmake_minimum_required(VERSION 3.10)
  set(CMAKE_C_COMPILER "clang")
  set(CMAKE_CXX_COMPILER "clang++")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -lwx_gtk3u_core-3.2 -lwx_baseu-3.2")
#-lwx_gtk3u_qa-3.2 -lwx_baseu_xml-3.2 -lwx_baseu_net-3.2 
# Now I can't compile for windows properly, but this worked: /usr/bin/x86_64-w64-mingw32-g++ $(ls | grep cpp) -I/usr/x86_64-w64-mingw32/lib/wx/include/msw-unicode-static-3.3 -I/usr/x86_64-w64-mingw32    /include/wx-3.3 -D__WXMSW__ -L/usr/x86_64-w64-mingw32/lib  /usr/x86_64-w64-mingw32/lib/libwx_mswu_xrc-3.3-Windows.a /    usr/x86_64-w64-mingw32/lib/libwx_mswu_qa-3.3-Windows.a /usr/x86_64-w64-mingw32/lib/libwx_    baseu_net-3.3-Windows.a /usr/x86_64-w64-mingw32/lib/libwx_mswu_html-3.3-Windows.a /usr/x8    6_64-w64-mingw32/lib/libwx_mswu_core-3.3-Windows.a /usr/x86_64-w64-mingw32/lib/libwx_base    u_xml-3.3-Windows.a /usr/x86_64-w64-mingw32/lib/libwx_baseu-3.3-Windows.a -lwx_mswu_core-    3.3-Windows /usr/x86_64-w64-mingw32/lib/libjpeg.a /usr/x86_64-w64-mingw32/lib/libpng16.a     /usr/x86_64-w64-mingw32/lib/libz.a /usr/x86_64-w64-mingw32/lib/libtiff.a -lwxwebp -lwxweb    pdemux -lwxsharpyuv -lwx_baseu-3.3-Windows /usr/x86_64-w64-mingw32/lib/libexpat.a -lkerne    l32 -luser32 -lgdi32 -lgdiplus -lmsimg32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lshlwap    i -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lversion -lws2_32 -lwininet -    loleacc -luxtheme /usr/x86_64-w64-mingw32/lib/libz.a -lwxregexu-3.3 -static -static-libgcc -static-libstdc++ -o app.exe
project(autobuilder)

#execute_process(COMMAND "wx-config --cppflags --libs" OUTPUT_VARIABLE WX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)

add_executable(autobuilder main.cpp ui.cpp command.cpp frameBase.cpp loc.cpp ui.cpp frame.cpp ui-interface.cpp global.cpp env.cpp)
