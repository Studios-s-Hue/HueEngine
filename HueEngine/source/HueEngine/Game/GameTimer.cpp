#include <HueEngine/Game/GameTimer.h>

#include <GLFW/glfw3.h>

GameTimer::GameTimer() : previousTime(glfwGetTime()), deltaTime(0.0)
{
}

void GameTimer::Update()
{
    double currentTime = glfwGetTime();
    deltaTime = currentTime - previousTime;
    previousTime = currentTime;
}

double GameTimer::GetDeltaTime() const
{
    return deltaTime;
}