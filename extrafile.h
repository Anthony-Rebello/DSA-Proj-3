#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Tile{
    unsigned int tile_type;
    unsigned int col,row;
    unsigned int weight;
    sf::Sprite sprite;
    Tile();
    Tile(unsigned int tile_type, unsigned int w);
    void block();
    void changeWeight(unsigned int w);
    void makeStart();
    void makeEnd();
    void setSprite(string texture);
    void setSpritePosition(float x, float y);

};
    //constructors for the Tile object


    Tile::Tile(){
        //0 = Empty; 1 = Start; 2 = End; 3 = Positive; 4 = Negative; 5 = Inaccessible 6 = Visited;
        unsigned int tile_type = 0;
        weight = 0;
    }
    Tile::Tile(unsigned int tile_type, unsigned int w){
        tile_type = tile_type;
        weight = w;
    }
    //functions to block or change the weight of a tile
    void Tile::block(){
        tile_type = 5;
    }
    void Tile::changeWeight(unsigned int w){
        weight = w;
    }
    //functions to make tile the start or end of the board
    void Tile::makeStart(){
        tile_type = 1;
    }
    void Tile::makeEnd(){
        tile_type = 2;
    }
    void Tile::setSprite(string texture){
        sprite.setTexture(TextureManager::GetTexture(texture));
    }
    void Tile::setSpritePosition(float x, float y) {
        sprite.setPosition(x,y);
    }



class Graph{

public:
//    int size = 0;
//    Tile* matrix = nullptr;
    //constructor for the graph object
    Graph(int row, int column){
//        Tile arrMatrix[row][column];
//        size = row * column;
//        matrix = *arrMatrix;
    }
    vector<vector<Tile>> matrix;
    string c_current_tile; //current tile to customize graph
    sf::Sprite customize_1;
    sf::Sprite customize_1_1;
    sf::Sprite customize_2;
    sf::Sprite customize_2_1; //2_1 - 7_1 are hitboxes for custom tile selection
    sf::Sprite customize_3;
    sf::Sprite customize_3_1;
    sf::Sprite customize_4;
    sf::Sprite customize_4_1;
    sf::Sprite customize_5;
    sf::Sprite customize_5_1;
    sf::Sprite customize_6;
    sf::Sprite customize_6_1;
    sf::Sprite customize_7;
    sf::Sprite customize_7_1;
    sf::Sprite algorithms;
    sf::Sprite run_btn;
    sf::Sprite reset_btn;

    void LoadInitialGui(sf::RenderWindow& window);
    void LoadTileData();
    void UpdateGraph(sf::RenderWindow& window);

};


void Graph::LoadInitialGui(sf::RenderWindow& window) {
    matrix.clear();
    c_current_tile = "";
    static bool once = false;
    vector<Tile> rows;
    Tile a;
    a.setSprite("Empty_Tile");
    for(int i = 0; i < 21; i++) {
        a.row = i;
        rows.push_back(a);
    }
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 21; j++) {
            rows[j].col = i;
        }
        matrix.push_back(rows);
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 30; j++){
            matrix[j][i].setSpritePosition((32*j) + 288,(32*i) + 68);
        }
    }


    customize_1.setTexture(TextureManager::GetTexture(("Customize")));
    customize_1.setPosition(1349,68);
    customize_1_1.setTexture(TextureManager::GetTexture(("Empty_Tile")));
    customize_1_1.setPosition(1787,68);
    if (!once) {
        customize_1_1.scale(3, 3);
        once = true;
    }
    customize_2.setTexture(TextureManager::GetTexture(("Customize_Start")));
    customize_2.setPosition(1349,164);
    customize_2_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_2_1.setPosition(1368,164);

    customize_3.setTexture(TextureManager::GetTexture(("Customize_End")));
    customize_3.setPosition(1349,260);
    customize_3_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_3_1.setPosition(1368,260);

    customize_4.setTexture(TextureManager::GetTexture(("Customize_Empty")));
    customize_4.setPosition(1349,356);
    customize_4_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_4_1.setPosition(1368,356);

    customize_5.setTexture(TextureManager::GetTexture(("Customize_Positive")));
    customize_5.setPosition(1349,452);
    customize_5_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_5_1.setPosition(1368,452);

    customize_6.setTexture(TextureManager::GetTexture(("Customize_Negative")));
    customize_6.setPosition(1349,548);
    customize_6_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_6_1.setPosition(1368,548);

    customize_7.setTexture(TextureManager::GetTexture(("Customize_Inaccessible")));
    customize_7.setPosition(1349,644);
    customize_7_1.setTexture(TextureManager::GetTexture(("Customize_HitBox")));
    customize_7_1.setPosition(1368,644);

    algorithms.setTexture(TextureManager::GetTexture("Algorithms"));
    algorithms.setPosition(0,810);
    run_btn.setTexture(TextureManager::GetTexture("Run"));
    run_btn.setPosition(1536,810);
    reset_btn.setTexture(TextureManager::GetTexture("Reset"));
    reset_btn.setPosition(1536,950);

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 30; j++) {
            window.draw(matrix[j][i].sprite);
        }
    }
    window.draw(algorithms);
    window.draw(run_btn);
    window.draw(reset_btn);
    window.draw(customize_1);
    window.draw(customize_1_1);
    window.draw(customize_2);
    window.draw(customize_3);
    window.draw(customize_4);
    window.draw(customize_5);
    window.draw(customize_6);
    window.draw(customize_7);
}

void  Graph::LoadTileData() {

    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 30; j++){
            //0 = Empty; 1 = Start; 2 = End; 3 = Positive; 4 = Negative; 5 = Inaccessible 6 = Visited;
            if (matrix[j][i].tile_type = 1)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Start_Tile"));

            else if (matrix[j][i].tile_type == 2)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("End_Tile"));

            else if (matrix[j][i].tile_type == 0)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Empty_Tile"));

            else if (matrix[j][i].tile_type == 3)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Positive_Cost_Tile"));

            else if (matrix[j][i].tile_type == 4)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Negative_Cost_Tile"));

            else if (matrix[j][i].tile_type == 5)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Inaccessible_Tile"));

            else if (matrix[j][i].tile_type == 6)
                matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Visited_Tile"));

        }
    }
}

void Graph::UpdateGraph(sf::RenderWindow& window){
    window.draw(algorithms);
    window.draw(run_btn);
    window.draw(reset_btn);
    window.draw(customize_1);
    window.draw(customize_1_1);
    window.draw(customize_2);
    window.draw(customize_3);
    window.draw(customize_4);
    window.draw(customize_5);
    window.draw(customize_6);
    window.draw(customize_7);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 30; j++) {
            window.draw(matrix[j][i].sprite);
        }
    }
    sf::Font font;
    font.loadFromFile("Assets/font.ttf");
    vector<sf::Text> tile_text_row;
    vector<vector<sf::Text>> tile_text;
    //[col][row]
    sf::Text text;
    for(int i = 0; i < 21; i++) {
        text.setFont(font);
        text.setCharacterSize(21);
        text.setFillColor(sf::Color::Black);
        tile_text_row.push_back(text);
    }
    for(int i = 0; i < 30; i++) {
        for (int j = 0; j < 21; j++) {
            if (matrix[i][j].weight != 0){
                tile_text_row[j].setString(to_string(matrix[i][j].weight));
                }
        }
        tile_text.push_back(tile_text_row);
    }
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 30; ++j) {
            tile_text[j][i].setPosition(290 + (j*32),71 + (i*32));
            window.draw(tile_text[j][i]);
        }
    }
}



void breadthFirstTrav(Tile& startTile){

}

void depthFirstTrav(Tile& startTile){

}

void dijkstra(Tile& startTile) {
  vector<int> result(630, 20000);
  priority_queue<pair<Tile, int>, vector<pair<Tile, int>>, greater<pair<Tile, int>>> pq;
  pq.push(make_pair(startTile.weight, startTile));

  result[startTile.col + startTile.row * 21] = 0;

  while (!pq.empty()) {
    int oldV = pq.top().second;
    pq.pop();
    for (int i = 0; i < 4; i++) {
      int v, weight;

      // Cycle through all adjacent neighbors & check if it's accessing an invalid index.
      // Not added here, since I don't know how you want to phrase it, but this does
      // **NOT** check if the tile is a void/blocked tile!

      if (i == 0 && oldV.row - 1 != -1) {
        v = matrix[oldV.col][oldV.row - 1];
        weight = matrix[oldV.col][oldV.row - 1].weight;
      } else if (i == 1 && oldV.row + 1 != 30) {
        v = matrix[oldV.col][oldV.row + 1];
        weight = matrix[oldV.col][oldV.row + 1].weight;
      } else if (i == 2 && oldV.col - 1 != -1) {
        v = matrix[oldV.col - 1][oldV.row];
        weight = matrix[oldV.col][oldV.row - 1].weight;
      } else if (i == 3 && oldV.col + 1 != 21) {
        v = matrix[oldV.col + 1][oldV.row];
        weight = matrix[oldV.col][oldV.row + 1].weight;
      }

         //  If there is shorted path to v through u.
         if (result[v.col + v.row * 21] > result[oldV.col + oldV.row * 21] + weight) {
             result[v.col + v.row * 21] = result[oldV.col + oldV.row * 21] + weight
             pq.push(make_pair(matrix[v.col][v.row].weight, matrix[v.col][v.row]));
         }
         }
 }
}

void bellmanFord(Tile& startTile){
  vector<int> result(630, 20000);
  result[startTile.col + startTile.row * 21] = 0;
}
