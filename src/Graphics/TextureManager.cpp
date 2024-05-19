
#include "TextureManager.h"
#include "../Core/Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
   SDL_Surface* surface = IMG_Load(filename.c_str()); // .c_str() convert string to char*
   if(surface == nullptr){
    SDL_Log("Failed to Load texture: %s, %s", filename.c_str(), IMG_GetError());
    return false;
   }

   SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
   if(texture == nullptr){
     SDL_Log("Failed to create texture from surface: %s", IMG_GetError());
     return false;
   }

   m_TextureMap[id] = texture;
   return true;
} 


void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}


void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
    std::map<std::string, SDL_Texture*>::iterator it;  // we can write this part with ranged based for look (write down)
    for (it= m_TextureMap.begin(); it != m_TextureMap.end() ; it++)
    {
        SDL_DestroyTexture(it->second);
    }
    m_TextureMap.clear();
    SDL_Log("Texture map cleaned!");
}






// ranged based lop for Clean function
// for (const auto& pair : m_TextureMap) {
//     SDL_DestroyTexture(pair.second);
// }
