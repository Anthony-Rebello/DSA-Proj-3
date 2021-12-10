#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
//Inspired by Professor Fox from programming 2 project code
using std::unordered_map;
using std::string;

class TextureManager {
    static unordered_map<string, sf::Texture>textures;
    static void LoadTexture(string textureName);
public:
    static sf::Texture& GetTexture(string textureName);
    static void Clear();

};

