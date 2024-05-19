#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr; // since this is static object we need initilise it 

bool Engine::Init()
{
    m_IsRunning = true;
    return m_IsRunning;
}

void Engine::Update()
{
    std::cout << "Updating ...." << std::endl;
}

void Engine::Render()
{

}

void Engine::Events()
{

}

void Engine::Clean()
{

}

void Engine::Quit()
{

}


