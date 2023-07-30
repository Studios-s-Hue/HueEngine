#pragma once
#include <HueEngine\CoreMinimal.h>
#include <HueEngine\Window\AppWindow.h>

class GraphicsWindow : public AppWindow
{
public:
    GraphicsWindow(Game *game);

private:
    Game *m_game = nullptr;
};