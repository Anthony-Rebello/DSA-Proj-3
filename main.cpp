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
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered && graph.can_customize_weight) {

                    if (event.text.unicode == '\b' && !graph.c_weight.empty()) {
                        graph.c_weight.pop_back();
                    } else if (graph.c_weight.size() < 2 && event.text.unicode >= 48 && event.text.unicode <= 57) {
                        graph.c_weight += event.text.unicode;
                    }
                if (graph.c_weight.size() == 2)
                    graph.can_customize_weight = false;

                if (graph.c_weight.size() == 2)
                    graph.can_customize_weight = false;
            }



            //0 = Empty; 1 = Start; 2 = End; 3 = Positive; 4 = Negative; 5 = Inaccessible 6 = Visited;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 0;i < graph._matrix[0].size(); i++) { //should get number of rows and below should be number of col 21x30
                for (int j = 0; j < graph._matrix.size(); j++) {
                    sf::FloatRect tile_rect = graph._matrix[j][i].sprite.getGlobalBounds();
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Start_Tile" && graph.getStart() == -1) {
                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Start_Tile"));
                        graph._matrix[j][i].tile_type = 1;
                        graph._matrix[j][i].weight = 0;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "End_Tile" && graph.getEnd() == -1) {
                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("End_Tile"));
                        graph._matrix[j][i].tile_type = 2;
                        graph._matrix[j][i].weight = 0;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Empty_Tile") {
                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Empty_Tile"));
                        graph._matrix[j][i].tile_type = 0;
                        graph._matrix[j][i].weight = 0;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Positive_Cost_Tile") {
                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Positive_Cost_Tile"));
                        graph._matrix[j][i].tile_type = 3;
                        if (!graph.c_weight.empty())
                            graph._matrix[j][i].weight = stoi(graph.c_weight);

                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Negative_Cost_Tile") {

                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Negative_Cost_Tile"));
                        graph._matrix[j][i].tile_type = 4;
                        graph._matrix[j][i].weight = 0;
                    }
                    if (tile_rect.contains(mousePos) && graph.c_current_tile == "Inaccessible_Tile") {
                        graph._matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Inaccessible_Tile"));
                        graph._matrix[j][i].tile_type = 5;
                        graph._matrix[j][i].weight = -1;

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
                graph.can_customize_weight = true;
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
            rect = graph.algorithms_hitbox_1.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.selected_algorithm = 1;
                graph.algorithm_text = "Algorithm: Depth First Search";
            }
            rect = graph.algorithms_hitbox_2.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.selected_algorithm = 2;
                graph.algorithm_text = "Algorithm: Breadth First Search";
            }
             rect = graph.run_btn.getGlobalBounds();
            if (rect.contains(mousePos)) {
                graph.transferData();
                if (graph.selected_algorithm == 1){
                    graph.depthFirstTrav(window, graph,graph.getStart(), graph.getEnd());
                }
                else if (graph.selected_algorithm == 2){
                    graph.breadthFirstTrav(window, graph,graph.getStart(), graph.getEnd());
                }
            }


        }
        }
            graph.UpdateGraph(window);
            window.display();
    }
}
