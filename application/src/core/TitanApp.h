#ifndef TITAN_APP_H
#define TITAN_APP_H

#include <iostream>

#include "Titan.h"

class TitanApp : public Titan::Application
{
public:
    TitanApp();
    ~TitanApp();
};

Titan::Application* Titan::CreateApplication()
{
    return new TitanApp();
}

#endif
