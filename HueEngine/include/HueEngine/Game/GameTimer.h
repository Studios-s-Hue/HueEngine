
#pragma once

class GameTimer
{
public:
    GameTimer();

    void Update();
    double GetDeltaTime() const;

private:
    double previousTime = 0.0;
    double deltaTime = 0.0;
};