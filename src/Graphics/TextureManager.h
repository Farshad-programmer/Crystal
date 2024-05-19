#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <map>


class TextureManager
{

public:
    
    static TextureManager* GetInstance(){return s_Instance = (s_Instance != nullptr ? s_Instance : new TextureManager());}


    bool Load(std::string id, std::string filename);
    void Drop(std::string id);
    void Clean(); // to avoid memory leak since we use raw pointers for now 

    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    TextureManager(){}
    static TextureManager* s_Instance;
    std::map<std::string, SDL_Texture*> m_TextureMap;

public:


};







#endif // !TEXTUREMANAGER_H