#include "Engine.h"
#include <iostream>
#include "../Graphics/TextureManager.h"
#include "../Physics/Transform.h"

Engine* Engine::s_Instance = nullptr; // since this is static object we need initilise it 

bool Engine::Init()
{
    //if this conditions happen something is wrong!
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
    {
        SDL_Log("Failed to initialize SDL_image: %s", IMG_GetError());
        return false;
    }

   m_Window = SDL_CreateWindow("Crystal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, 0);
   if(m_Window == nullptr)
   {
        SDL_Log("Failed to create Window: %s", IMG_GetError());
         return false;
   }

   m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if(m_Renderer == nullptr)
   {
        SDL_Log("Failed to create Renderer: %s", IMG_GetError());
        return false;
   }

    TextureManager::GetInstance()->Load("shroom", "assets/shroom.png");

    Transform tf(8, 4);
    tf.Log("tf: ");
    return m_IsRunning = true;
}

void Engine::Update()
{
    //SDL_Log("SDL initialized successfully333 ");
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw("shroom", 100, 100, 1024, 1024);
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        Quit();
        break;
    
    default:
        break;
    }
}

void Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit()
{
    m_IsRunning = false;
}


