#pragma once
#include <HueEngine\CoreMinimal.h>

class Game
{
public:
    Game();
    virtual ~Game();

public:
    GraphicsWindow *GetGraphicsWindow();

public:
    void Run();
    void Quit();
    void SetTitle(const char *title);
    void Init(const WindowProperties &properties);

public:
    bool IsGamePaused() const;
    void SetGamePaused(bool paused);

protected: // Events
    virtual void onQuit() {}
    virtual void onCreate() {}
    virtual void onUpdate(float delta_time) {}

private:
    void onUpdateInternal();

private:
    bool m_isRunning = true;
    bool m_bReady = false;
    bool m_bIsGamePaused = false;
    float m_delta_time = 0.0f;

private:
    std::unique_ptr<GraphicsWindow> m_graphics_window;

private:
    friend class GraphicsWindow;
};