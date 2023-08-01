#pragma once
#include <HueEngine\CoreMinimal.h>
#include <HueEngine\Input\InputKeysType.h>
#include <array>
#include <unordered_map>

class InputManager {
public:
    InputManager();

    bool IsKeyDown(const EKey& key) const;
    bool IsKeyUp(const EKey& key) const;

    bool IsMouseDown(const EMouseButton& button) const;
    bool IsMouseUp(const EMouseButton& button) const;

    bool IsJoystickButtonDown(const EJoystickButton& button) const;
    float GetJoystickAxis(ui32 axis) const;

    float GetMouseXAxis() const;
    float GetMouseYAxis() const;

    void SetInputEnable(bool enable);
    void SetInputLock(bool lock);

    // void SetScreenArea(const Rect& area);

    bool IsInputEnable() const { return m_inputEnable; }

public:
    void Update(Game *game);

private:
    std::unordered_map<EKey, bool> m_keyState;
    std::unordered_map<EMouseButton, bool> m_mouseButtonState;
    std::unordered_map<EJoystickButton, bool> m_joystickButtonState;
    float m_joystickAxisCount[2];
    
    double m_mouseX;
    double m_mouseY;
    // Rect m_screenArea;
    bool m_inputEnable;
};
