cmake_minimum_required(VERSION 3.30)
project(ChessAttacker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.5)  # Updated to latest stable version as of early 2024
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        FetchContent_MakeAvailable(raylib)
    endif()
endif()

# Our Project
add_executable(${PROJECT_NAME} src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.h
        src/Chess/Chess.cpp
        src/Chess/Chess.h
        src/Map/Map.cpp
        src/Map/Map.h
        src/Board/Board.cpp
        src/Board/Board.h
        src/Sprite/Sprite.cpp
        src/Sprite/Sprite.h
        include/Config.h
        src/Chess/King/King.cpp
        src/Chess/King/King.h
        include/Struct.h
        src/Chess/Rock/Rock.cpp
        src/Chess/Rock/Rock.h
        src/Chess/Bishop/Bishop.cpp
        src/Chess/Bishop/Bishop.h
        src/Chess/Knight/Knight.cpp
        src/Chess/Knight/Knight.h
        src/Chess/Queen/Queen.cpp
        src/Chess/Queen/Queen.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Web Configurations
if (EMSCRIPTEN)  # Better check for web platform
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()