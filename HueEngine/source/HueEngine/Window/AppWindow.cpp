
#include <HueEngine/Window/AppWindow.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

AppWindow::AppWindow()
{
    // TODO
}

AppWindow::~AppWindow()
{
    if (m_glfwWindow)
    {
        glfwDestroyWindow(m_glfwWindow);
        glfwTerminate();
    }
}

bool AppWindow::Init(WindowProperties properties)
{
    if (!glfwInit())
    {
        return false;
    }

    m_glfwWindow = glfwCreateWindow(properties.width, properties.height, properties.title, NULL, NULL);
    if (!m_glfwWindow)
    {
        glfwTerminate();
        return false;
    }

    // Set up the OpenGL context
    glfwMakeContextCurrent(m_glfwWindow);

    // Load OpenGL functions using glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return false;
    }

    return true;
}

void *AppWindow::GetHandle()
{
    return m_glfwWindow;
}

void AppWindow::SetTitle(const char *title)
{
    glfwSetWindowTitle(m_glfwWindow, title);
}

bool AppWindow::IsFocused() const
{
    return glfwGetWindowAttrib(m_glfwWindow, GLFW_FOCUSED);
}

WindowState AppWindow::GetWindowState() const
{
    if (glfwGetWindowAttrib(m_glfwWindow, GLFW_ICONIFIED))
    {
        return WindowState::Minimized;
    }
    else if (glfwGetWindowAttrib(m_glfwWindow, GLFW_MAXIMIZED))
    {
        return WindowState::Maximized;
    }
    else
    {
        return WindowState::Normal;
    }
}

bool AppWindow::ShouldClose() const
{
    return glfwWindowShouldClose(m_glfwWindow);
}
 