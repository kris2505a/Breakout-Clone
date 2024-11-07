# CMakeList.txt : CMake project for Breakout-Clone, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Breakout-Clone")

include_directories(Breakout-Clone ${CMAKE_SOURCE_DIR}/Dependencies/include)


# Add source to this project's executable.
add_executable (Breakout-Clone "src/main.cpp" "src/Game.cpp" "src/Headers/Game.h" "src/Headers/Log.h" "src/Headers/Ball.h" "src/Ball.cpp" "src/Headers/Paddle.h" "src/Paddle.cpp")

target_link_libraries(Breakout-Clone ${CMAKE_SOURCE_DIR}/Dependencies/lib/sfml-graphics.lib)
target_link_libraries(Breakout-Clone ${CMAKE_SOURCE_DIR}/Dependencies/lib/sfml-main.lib)
target_link_libraries(Breakout-Clone ${CMAKE_SOURCE_DIR}/Dependencies/lib/sfml-window.lib)
target_link_libraries(Breakout-Clone ${CMAKE_SOURCE_DIR}/Dependencies/lib/sfml-system.lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Breakout-Clone PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
