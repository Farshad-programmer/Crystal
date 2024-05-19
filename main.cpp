//#include "SDL.h"
#include "src/Core/Engine.h"
#include <iostream>

#undef main
 // g++ -Llib main.cpp -lSDL2

int main(int argc, char **argv)
{
   Engine::GetInstance()->Init();
   while(Engine::GetInstance()->Isrunning())
   {
      Engine::GetInstance()->Events();
      Engine::GetInstance()->Update();
      Engine::GetInstance()->Render();
   }
   Engine::GetInstance()->Clean();
   Engine::GetInstance()->Quit();
   return 0 ;
}





