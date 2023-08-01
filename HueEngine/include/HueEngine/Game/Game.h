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

public:
	float GetDeltaTime();

public: //Modules Get
    InputManager *GetInputManager();
    GraphicsWindow *GetWindow();

protected: // Events
    virtual void onQuit() {}
    virtual void onCreate() {}
    virtual void onUpdate(f32 delta_time) {}

private:
    void onUpdateInternal();

private:
    bool m_isRunning = false;
    bool m_bReady = false;
    bool m_bIsGamePaused = false; 

private:
    std::unique_ptr<GraphicsWindow> m_graphics_window;
    std::unique_ptr<GameTimer> m_game_timer;
    std::unique_ptr<InputManager> m_input_manager;

private:
    friend class GraphicsWindow;
};