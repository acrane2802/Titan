#ifndef TITAN_APPLICATION_H
#define TITAN_APPLICATION_H

#include <chrono>
#include <iostream>

#include "APIDLLExportHandler.h"

#define UPDATE_TIME_IN_FPS 100.0f

namespace Titan
{
    class TITAN_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        bool isRunning = false;
    };

    Application* CreateApplication();
}

#endif