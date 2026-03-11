#include "Application.h"

namespace Titan
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        std::chrono::duration<double, std::milli> frameTime{};
        std::chrono::duration<double, std::milli> fixedTimestep(1000.0f / UPDATE_TIME_IN_FPS);
        std::chrono::duration<double, std::nano> frameLag(0);

        std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

        std::chrono::time_point<std::chrono::high_resolution_clock> previousTimePointForFPS = std::chrono::high_resolution_clock::now();
        std::chrono::time_point<std::chrono::high_resolution_clock> currentTimePointForFPS {};

        isRunning = true;

        int fps = 0;
        double deltaTime = 0;
        int totalFramesSinceASecondElapses = 0;
        double totalDeltaTimePerSecond = 0.0f;

        while(isRunning)
        {
            frameTime = std::chrono::high_resolution_clock::now() - currentTime;
            currentTime = std::chrono::high_resolution_clock::now();
            frameLag += std::chrono::duration_cast<std::chrono::nanoseconds>(frameTime);

            deltaTime = frameTime.count();

            while (frameLag >= fixedTimestep)
            {
                // fixed update
                frameLag -= fixedTimestep;
                // std::cout << "Fixed Update" << std::endl;
            }

            totalDeltaTimePerSecond += deltaTime;

            currentTimePointForFPS = std::chrono::high_resolution_clock::now();

            if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePointForFPS - previousTimePointForFPS) >= std::chrono::seconds{1})
            {
                fps = static_cast<int>(static_cast<double>(totalFramesSinceASecondElapses) / totalDeltaTimePerSecond * std::chrono::duration<double, std::milli>(1000).count());

                totalFramesSinceASecondElapses = 0;
                totalDeltaTimePerSecond = 0.0f;

                previousTimePointForFPS = std::chrono::high_resolution_clock::now();
            }
            ++totalFramesSinceASecondElapses;
        }
    }
}
