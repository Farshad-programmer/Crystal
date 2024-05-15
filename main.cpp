#include <iostream>
#include "SDL.h"


#undef main
 // g++ -Llib main.cpp -lSDL2

int main(int argc, char **argv)
{

   if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
      std::cout<< "STL WORKING!" << std::endl;
   return 0 ;
}





