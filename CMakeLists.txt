cmake_minimum_required(VERSION 3.25)

project(Breakout LANGUAGES CXX)

# enforce g++
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "Use g++ only. Clang is not allowed.")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# generate compile_commands.json for nvim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# auto collect sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(Breakout ${SOURCES})

# defines
target_compile_definitions(Breakout PRIVATE
    SDL_MAIN_HANDLED
)

target_compile_definitions(Breakout PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
)

# glad include
target_include_directories(Breakout PRIVATE
    deps/glad/include
)

# SDL via pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

target_include_directories(Breakout PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Breakout PRIVATE ${SDL2_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(Breakout PRIVATE OpenGL::GL)

# glad static
target_link_libraries(Breakout PRIVATE
    ${CMAKE_SOURCE_DIR}/deps/glad/lib/libglad.a
)

# warnings
target_compile_options(Breakout PRIVATE
    -Wall -Wextra -Wpedantic
)
