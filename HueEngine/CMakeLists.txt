cmake_minimum_required(VERSION 3.8)

include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_EXTRAS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")

  if(NOT WIN32)
    set(GLAD_LIBRARIES dl)
  endif()
endif()

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)

if(NOT glfw_POPULATED)
  FetchContent_Populate(glfw)

  set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
  set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
  set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
  set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

  add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)

FetchContent_GetProperties(glad)

if(NOT glad_POPULATED)
  FetchContent_Populate(glad)
  set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
  set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
  set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
  add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()

FetchContent_Declare(
  linmath
  GIT_REPOSITORY https://github.com/datenwolf/linmath.h.git
)

FetchContent_GetProperties(linmath)

if(NOT linmath_POPULATED)
  FetchContent_Populate(linmath)
  add_library(linmath INTERFACE)
  target_include_directories(linmath INTERFACE ${linmath_SOURCE_DIR})
endif()

include_directories(include)

add_library(HueEngine
  "include/HueEngine/CoreMinimal.h"
  "include/HueEngine/CurrentPlatform.h"

  "include/HueEngine/Window/AppWindow.h"
  "source/HueEngine/Window/AppWindow.cpp"

  "include/HueEngine/Game/GraphicsWindow.h"
  "source/HueEngine/Game/GraphicsWindow.cpp"
  "include/HueEngine/Game/Game.h"

  "source/HueEngine/Game/Game.cpp"
  "include/HueEngine/Core.h"

  "include/HueEngine/Game/GameTimer.h"
  "source/HueEngine/Game/GameTimer.cpp"

  "include/HueEngine/Input/InputManager.h"

  "include/HueEngine/Input/InputKeysType.h"
  "source/HueEngine/Input/InputManager.cpp"
)

target_link_libraries(HueEngine PUBLIC glfw glad linmath) # public for now

# target_link_libraries(HueEngine PRIVATE glfw glad linmath)
target_include_directories(HueEngine PUBLIC include)

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HueEngine PROPERTY CXX_STANDARD 17)
endif()
