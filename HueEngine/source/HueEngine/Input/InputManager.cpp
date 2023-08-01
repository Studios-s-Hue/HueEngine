#include <HueEngine/Input/InputManager.h>
#include <HueEngine/Game/Game.h>
#include <HueEngine/Game/GraphicsWindow.h>
#include "InputManager.h"

InputManager::InputManager() : m_inputEnable(true) {}

bool InputManager::IsJoystickButtonDown(const EJoystickButton &button) const
{
    if (m_inputEnable)
    {
        return m_joystickButtonState.at(button);
    }
    return false;
}

float InputManager::GetJoystickAxis(ui32 axis) const
{
    if (m_inputEnable)
    {
        return m_joystickAxisCount[axis];
    }

    return 0.0f;
}

bool InputManager::IsKeyDown(const EKey &key) const
{
    if (m_inputEnable)
    {
        return m_keyState.at(key);
    }

    return false;
}

bool InputManager::IsKeyUp(const EKey &key) const
{
    if (m_inputEnable)
    {
        return !m_keyState.at(key);
    }

    return false;
}

bool InputManager::IsMouseDown(const EMouseButton &button) const
{
    if (m_inputEnable)
    {
        return m_mouseButtonState.at(button);
    }

    return false;
}

bool InputManager::IsMouseUp(const EMouseButton &button) const
{
    if (m_inputEnable)
    {
        return !m_mouseButtonState.at(button);
    }

    return false;
}

void InputManager::SetInputEnable(bool enable)
{
    m_inputEnable = enable;
}

void InputManager::SetInputLock(bool lock)
{
    auto window = nullptr;
    // Hide the mouse cursor and  // Lock the mouse cursor to the window
    if (lock)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void InputManager::Update(Game *game)
{
    // TODO maybe this is not the best way to get window handle
    auto window = static_cast<GLFWwindow *>(game->GetGraphicsWindow()->GetHandle());

    if (m_inputEnable)
    {
        m_mouseButtonState[EMouseButton::Left] = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
        m_mouseButtonState[EMouseButton::Right] = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
        m_mouseButtonState[EMouseButton::Middle] = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS;

        int firstKey = static_cast<int>(EKey::A);
        int lastKey = static_cast<int>(EKey::Tab);

        for (int i = firstKey; i <= lastKey; ++i)
        {
            auto key = static_cast<EKey>(i);
            auto pressed = glfwGetKey(window, i) == GLFW_PRESS;
            m_keyState[key] = pressed;
        }

        int buttonCount;
        const unsigned char *buttonStates = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);

        if (buttonStates != nullptr)
        {
            for (int i = 0; i < buttonCount; ++i)
            {
                m_joystickButtonState[static_cast<EJoystickButton>(i)] = buttonStates[i] == GLFW_PRESS;
            }
        }

        int AxesCount;
        const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &AxesCount);

        if (axes != nullptr)
        {
            for (int i = 0; i < AxesCount; ++i)
            {
                m_joystickAxisCount[i] = axes[i];
            }
        }

        glfwGetCursorPos(window, &m_mouseX, &m_mouseY);
    }
}

float InputManager::GetMouseXAxis() const
{
    return static_cast<float>(m_mouseX);
}

float InputManager::GetMouseYAxis() const
{
    return static_cast<float>(m_mouseY);
}