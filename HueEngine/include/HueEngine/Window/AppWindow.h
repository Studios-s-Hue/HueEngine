#pragma once
#include <HueEngine\CoreMinimal.h>
#include <HueEngine\CurrentPlatform.h>
#include <set>

struct WindowProperties
{
	const char *title = "My Game";
	i32 width = 1920;
	i32 height = 1080;
	bool vsync;
	bool fullscreen;
	bool maximized = true;
};

enum class WindowState
{
	Normal,
	Minimized,
	Maximized
};

class AppWindow
{
public:
	struct WindowSize
	{
		float width;
		float height;
	};

public:
	AppWindow();
	~AppWindow();

public:
	bool s_minimized = false;
	bool s_isFocused = true;

public:
	bool Init(WindowProperties properties);

public:
	void *GetHandle();
	void SetTitle(const char *title);
	bool IsFocused() const;
	WindowState GetWindowState() const;
	bool ShouldClose() const;

public:
	// EVENTs
	virtual void onCreate() {}
	virtual void onUpdate() {}
	virtual void onDestroy() {}
	virtual void onFocus() {}
	virtual void onKillFocus() {}

protected:
	struct GLFWwindow *m_glfwWindow;

private:
	friend class Game;
};