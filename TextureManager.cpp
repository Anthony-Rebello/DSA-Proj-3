#include "TextureManager.h"
//Inspired by Professor Fox from programming 2 project code
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string filename) {

    string path = "assets/";
    path += filename + ".png";

    textures[filename].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName){
    if(textures.find(textureName) == textures.end())
        LoadTexture(textureName);

    return textures[textureName];
}


void TextureManager::Clear(){
    textures.clear();
}
