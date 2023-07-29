#pragma once
#include <memory>
#include <iostream>
#include <stdexcept>

//typedefs
typedef unsigned int  ui32;
typedef int           i32;
typedef float         f32;
typedef double        d64;
typedef unsigned char byte; 

//Window
class AppWindow;
class GraphicsWindow;
enum class WindowState;
struct WindowProperties;
// Game
class Game;