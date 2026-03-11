#ifndef TITAN_ENTRYPOINT_H
#define TITAN_ENTRYPOINT_H

#ifdef TITAN_PLATFORM_WINDOWS

#endif
#ifdef TITAN_PLATFORM_LINUX

#endif
#ifdef TITAN_PLATFORM_MACOS

#endif

extern Titan::Application* Titan::CreateApplication();

int main(int argc, char** argv)
{
    Titan::Application* app = Titan::CreateApplication();

    app->Run();

    delete app;

    return 0;
}

#endif