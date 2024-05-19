#ifndef ENGINE_H
#include "SDL.h"
//#include "SDL_image.h"


#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640
class Engine // we make this class singleton class, so we dont want anyone make a sample of this class thefore we make GetInstance() function
{
public:
   bool Init();
   void Clean();
   void Quit();
   void Update();
   void Render();
   void Events();

private:
    Engine(){} // because it is singleton!
    static Engine* s_Instance;
    bool m_IsRunning;

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
public:

    static Engine* GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }
    inline bool Isrunning() const {return m_IsRunning;}
    inline SDL_Renderer* GetRenderer() const {return m_Renderer;}
};






#endif // !ENGINE_H

