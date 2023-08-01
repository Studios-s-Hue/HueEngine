
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
    }
    glfwTerminate();
}

bool AppWindow::Init(WindowProperties properties)
{
    if (!glfwInit())
    {
        return false;
    }

    // https://www.glfw.org/docs/latest/window.html#window_hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core profile, ignore deprecated functions
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For Mac OS X

    m_glfwWindow = glfwCreateWindow(properties.width, properties.height, properties.title, NULL, NULL);
    if (!m_glfwWindow)
    {
        glfwTerminate();
        return false;
    }

    // Set the user pointer to the class instance
    glfwSetWindowUserPointer(m_glfwWindow, this);

    // Set the window callbacks
    glfwSetFramebufferSizeCallback(m_glfwWindow, framebuffer_size_callback);

    // Set up the OpenGL context
    glfwMakeContextCurrent(m_glfwWindow);

    // Load OpenGL functions using glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return false;
    }

    return true;
}

void AppWindow::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    AppWindow *appWindow = static_cast<AppWindow *>(glfwGetWindowUserPointer(window));

    glViewport(0, 0, width, height);
    appWindow->onResize();
}

void AppWindow::onUpdateInternal()
{
    glfwPollEvents();
    onUpdate();
    glfwSwapBuffers(m_glfwWindow);
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

void AppWindow::Quit()
{
    glfwSetWindowShouldClose(m_glfwWindow, true);
}
