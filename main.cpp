#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "extrafile.h"



using namespace std;
int main() {

    Graph graph(21, 30);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pathfinder");
    window.clear(sf::Color::White);
    sf::Event event{};
    graph.LoadInitialGui(window);
//    -----------------------------------------------------------------------
    sf::Font font;
    sf::Text text;
    font.loadFromFile("Assets/font.ttf");
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(21);
    text.setFillColor(sf::Color::Black);
    text.setPosition(290,71);
//    -----------------------------------------------------------------------
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::Closed)
                window.close();
            //0 = Empty; 1 = Start; 2 = End; 3 = Positive; 4 = Negative; 5 = Inaccessible 6 = Visited;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 0;
                 i < graph.matrix[0].size(); i++) { //should get number of rows and below should be number of col 21x30
                for (int j = 0; j < graph.matrix.size(); j++) {
                    sf::FloatRect tile_rect = graph.matrix[j][i].sprite.getGlobalBounds();
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Start_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Start_Tile"));
                        graph.matrix[j][i].tile_type = 1;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "End_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("End_Tile"));
                        graph.matrix[j][i].tile_type = 2;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Empty_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Empty_Tile"));
                        graph.matrix[j][i].tile_type = 0;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Positive_Cost_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Positive_Cost_Tile"));
                        graph.matrix[j][i].tile_type = 3;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Negative_Cost_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Negative_Cost_Tile"));
                        graph.matrix[j][i].tile_type = 4;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Inaccessible_Tile") {
                        graph.matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Inaccessible_Tile"));
                        graph.matrix[j][i].tile_type = 5;
                    }
                }
            }
            sf::FloatRect rect = graph.customize_2_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "Start_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("Start_Tile"));
            }
            rect = graph.customize_3_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "End_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("End_Tile"));
            }
            rect = graph.customize_4_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "Empty_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("Empty_Tile"));
            }
            rect = graph.customize_5_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "Positive_Cost_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("Positive_Cost_Tile"));
            }
            rect = graph.customize_6_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "Negative_Cost_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("Negative_Cost_Tile"));
            }
            rect = graph.customize_7_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.c_current_tile = "Inaccessible_Tile";
                graph.customize_1_1.setTexture(TextureManager::GetTexture("Inaccessible_Tile"));
            }
            rect = graph.reset_btn.getGlobalBounds();
            if (rect.contains(mousePos)) {
                window.clear(sf::Color::White);
                graph.LoadInitialGui(window);
            }
        }
        }
            graph.UpdateGraph(window);
            window.draw(text);
            window.display();
    }
}
