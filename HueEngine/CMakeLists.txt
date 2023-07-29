cmake_minimum_required(VERSION 3.8)

include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_library(HueEngine
  "include/HueEngine/CoreMinimal.h"
  "include/HueEngine/CurrentPlatform.h"

  "include/HueEngine/Window/AppWindow.h"
  "source/HueEngine/Window/AppWindow.cpp"

  "include/HueEngine/Game/GraphicsWindow.h" 
  "source/HueEngine/Game/GraphicsWindow.cpp" 
 "include/HueEngine/Game/Game.h" "source/HueEngine/Game/Game.cpp" "include/HueEngine/Core.h")

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HueEngine PROPERTY CXX_STANDARD 17)
endif()
