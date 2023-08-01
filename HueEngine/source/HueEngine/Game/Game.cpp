#include <HueEngine/Game/Game.h>
#include <HueEngine/Game/GraphicsWindow.h>
#include <HueEngine/Game/GameTimer.h>
#include <HueEngine/Input/InputManager.h>

#include <HueEngine/CurrentPlatform.h>

Game::Game()
{
    // TODO on platform windows initialize CoInitializeEx
    m_graphics_window = std::make_unique<GraphicsWindow>(this);
    m_game_timer = std::make_unique<GameTimer>();
    m_input_manager = std::make_unique<InputManager>();
}

Game::~Game()
{
    // TODO on platform windows call CoUninitialize
    m_graphics_window = nullptr;
    m_game_timer = nullptr;
    m_input_manager = nullptr;
}

GraphicsWindow *Game::GetGraphicsWindow()
{
    return m_graphics_window.get();
}

void Game::Run()
{
    assert(m_bReady);
    assert(m_graphics_window);
    assert(m_game_timer);
    assert(m_input_manager);

    m_isRunning = true;

    onCreate();

    while (m_isRunning && !m_graphics_window->ShouldClose())
    {
        m_graphics_window->onUpdateInternal();
        onUpdateInternal();
    }

    m_isRunning = false;

    onQuit();
}

void Game::Quit()
{
    m_isRunning = false;
    m_graphics_window->Quit();
    m_graphics_window->onDestroy();
}

void Game::SetTitle(const char *title)
{
    m_graphics_window->SetTitle(title);
}

void Game::Init(const WindowProperties &properties)
{
    // create window
    assert(m_graphics_window->Init(properties));
    // set game ready
    m_bReady = true;
}

bool Game::IsGamePaused() const
{
    return m_bIsGamePaused;
}

void Game::SetGamePaused(bool paused)
{
    m_bIsGamePaused = paused;
}

float Game::GetDeltaTime()
{
    // Maybe we can return double instead of float
    return static_cast<float>(m_game_timer->GetDeltaTime());
}

void Game::onUpdateInternal()
{

    WindowState windowState = m_graphics_window->GetWindowState();

    bool isMinimized = windowState == WindowState::Minimized;
    bool isFocused = m_graphics_window->IsFocused();

    if (isMinimized)
    {
        return;
    }

    if (!isFocused)
    {
        return;
    }

    // update delta time
    m_game_timer->Update();

    float delta_time = GetDeltaTime();

    // update input
    m_input_manager->Update(this);

    // update game
    onUpdate(delta_time);

    // Update all game components like input, physics,audio, etc.
}

InputManager *Game::GetInputManager()
{
    return m_input_manager.get();
}

GraphicsWindow *Game::GetWindow()
{
    return m_graphics_window.get();
}