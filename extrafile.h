#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

struct Tile{
    //0 = Empty; 1 = Start; 2 = End; 3 = Positive; 4 = Negative; 5 = Inaccessible 6 = Visited;
    unsigned int tile_type;
    unsigned int col,row, tile_num;
    int weight;
    sf::Sprite sprite;
    Tile();
    Tile(unsigned int tile_type, unsigned int w);
    void block();
    void changeWeight(unsigned int w);
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

void Tile::setSprite(string texture){
    sprite.setTexture(TextureManager::GetTexture(texture));
}
void Tile::setSpritePosition(float x, float y) {
    sprite.setPosition(x,y);
}



class Graph{

public:

        int size = 0;
        vector<Tile> nodes;
        vector<vector<int> > matrix;
        //constructor for the graph object
        //Adjacency Matrix
        Graph(int row, int column){
            matrix.resize(row * column);
            nodes.resize(row * column);
            size = row * column;
            for(int i = 0; i < size; i++){
                matrix.at(i).resize(row * column);
            }
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(i == j){
                        matrix[i][j] = 0;
                    }
                    else{
                        matrix[i][j] = -1;
                    }
                }
            }
        }
        // 0 = none; 1 = DFS; 2 = BFS; 3 = Dijkstra's; 4 = Bellman-Ford
    int selected_algorithm = 0;
    string algorithm_text = "Algorithm: ";
    string algorithm_duration = "Time: ";
    string c_weight;
    bool can_customize_weight = false;
    vector<vector<Tile>> _matrix;
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
    sf::Sprite algorithms_hitbox_1;
    sf::Sprite algorithms_hitbox_2;
    sf::Sprite algorithms_hitbox_3;
    sf::Sprite algorithms_hitbox_4;
    sf::Sprite run_btn;
    sf::Sprite reset_btn;

    void LoadInitialGui(sf::RenderWindow& window);
    void LoadTileData();
    void UpdateGraph(sf::RenderWindow& window);
    void dijkstra(Tile& startTile);
    bool depthFirstTrav(sf::RenderWindow& window, Graph& myGraph, int start, int end);
    bool testDepthFirstTrav(Graph& myGraph, int start, int end);
    bool testBreadthFirstTrav(Graph& myGraph, int start, int end);
    bool breadthFirstTrav(sf::RenderWindow& window,Graph& myGraph, int start, int end);
    void transferData();
    int getStart();
    int getEnd();
    void test();

};


void Graph::LoadInitialGui(sf::RenderWindow& window) {
    _matrix.clear();
    int tile_num = 0;
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
        _matrix.push_back(rows);
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 30; j++){
            _matrix[j][i].setSpritePosition((32 * j) + 288, (32 * i) + 68);
            _matrix[j][i].tile_num = (j + (i*30));
            _matrix[j][i].tile_type = 0;
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
    algorithms_hitbox_1.setTexture(TextureManager::GetTexture("Algorithms_Hitbox"));
    algorithms_hitbox_1.setPosition(66,909);
    algorithms_hitbox_2.setTexture(TextureManager::GetTexture("Algorithms_Hitbox"));
    algorithms_hitbox_2.setPosition(286,909);
    run_btn.setTexture(TextureManager::GetTexture("Run"));
    run_btn.setPosition(1536,810);
    reset_btn.setTexture(TextureManager::GetTexture("Reset"));
    reset_btn.setPosition(1536,950);

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 30; j++) {
            window.draw(_matrix[j][i].sprite);
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
            if (_matrix[j][i].tile_type == 1)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Start_Tile"));

            else if (_matrix[j][i].tile_type == 2)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("End_Tile"));

            else if (_matrix[j][i].tile_type == 0)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Empty_Tile"));

            else if (_matrix[j][i].tile_type == 3)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Positive_Cost_Tile"));

            else if (_matrix[j][i].tile_type == 4)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Negative_Cost_Tile"));

            else if (_matrix[j][i].tile_type == 5)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Inaccessible_Tile"));

            else if (_matrix[j][i].tile_type == 6)
                _matrix[j][i].sprite.setTexture(TextureManager::GetTexture("Visited_Tile"));

        }
    }
}

void Graph::UpdateGraph(sf::RenderWindow& window){
    window.clear(sf::Color::White);
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
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 29; j++) {

            window.draw(_matrix[j][i].sprite);
        }
    }
    //updates tile weights on GUI
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

        }
        tile_text.push_back(tile_text_row);
    }
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (_matrix[j][i].weight != 0 && _matrix[j][i].weight != -1 ){
                tile_text[j][i].setString(to_string(_matrix[j][i].weight));
            }
            tile_text[j][i].setPosition(290 + (j*32),71 + (i*32));
            window.draw(tile_text[j][i]);
        }
    }
    //updates customizable tile weight
    sf::Text weight_text;
    weight_text.setFont(font);
    weight_text.setCharacterSize(51);
    weight_text.setFillColor(sf::Color::Black);
    weight_text.setPosition(1370,468);
    weight_text.setString(c_weight);
    window.draw(weight_text);

    sf::Text algorithm;
    sf::Text time;
    algorithm.setFont(font);
    algorithm.setCharacterSize(30);
    algorithm.setFillColor(sf::Color::Red);
    algorithm.setPosition(1000,810);
    algorithm.setString(algorithm_text );
    window.draw(algorithm);

    time.setFont(font);
    time.setCharacterSize(30);
    time.setFillColor(sf::Color::Red);
    time.setPosition(1000,910);
    time.setString(algorithm_duration);
    window.draw(time);



}

void Graph::transferData() {
//    for (int i = 0; i < 21; ++i) {
//        for (int j = 0; j < 30; ++j) {
    //tiles with no edges
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j < 29; ++j) {
            //[from][to]
            //Left
            matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j - 1][i].weight;
            //Right
            matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j + 1][i].weight;
            //Top
            matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i - 1].weight;
            //Bottom
            matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//            [from][to]
//            Left
            matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num] = _matrix[j - 1][i].weight;
            //Right
            matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num] = _matrix[j + 1][i].weight;
            //Top
            matrix[_matrix[j][i].tile_num - 30][_matrix[j][i].tile_num] = _matrix[j][i - 1].weight;
            //Bottom
            matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
        }

    }

//    for (int i = 0; i < 21; i++) {
//        for (int j = 0; j < 30; j++) {
//            if (i == 0 && j > 0 && j < 29) {
//                //left
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j - 1][i].weight;
//                //bottom
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j + 1][i].weight;
//            }
//        else if (i == 20 && j > 0 && j < 29) {
//                //left
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j - 1][i].weight;
//                //top
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i - 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j + 1][i].weight;
//            }
//        else if (i == 20 && j == 0) {
//                //top
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i-1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j+1][i].weight;
//            }
//            else if (i == 20 && j == 29) {
//                //left
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j - 1][i].weight;
//                //top
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i - 1].weight;
//            }
//            else if (i == 0 && j == 0) {
//                //right
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j + 1][i].weight;
//                //bottom
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//            }
//            else if (i == 0 && j == 29) {
//                //bottom
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//                //left
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j-1][i].weight;
//            }
//            else if (j == 0 && i > 0 && i < 20) {
//                //bottom
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//                //top
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i - 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 1] = _matrix[j + 1][i].weight;
//            }
//            else if (j == 29 && i > 0 && i < 20) {
//                //bottom
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num + 30] = _matrix[j][i + 1].weight;
//                //top
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 30] = _matrix[j][i - 1].weight;
//                //left
//                matrix[_matrix[j][i].tile_num][_matrix[j][i].tile_num - 1] = _matrix[j - 1][i].weight;
//            }
//        }
//    }
//    for (int i = 0; i < 21; i++) {
//        for (int j = 0; j < 30; j++) {
//            if (i == 0 && j > 0 && j < 29) {
//                //left
//                matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num] = _matrix[j - 1][i].weight;
//                //bottom
//                matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num] = _matrix[j + 1][i].weight;
//            }
//        else if (i == 20 && j > 0 && j < 29) {
//                //left
//                matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num ] = _matrix[j - 1][i].weight;
//                //top
//                matrix[_matrix[j][i].tile_num - 30][_matrix[j][i].tile_num ] = _matrix[j][i - 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num ] = _matrix[j + 1][i].weight;
//            }
//        else if (i == 20 && j == 0) {
//                //top
//                matrix[_matrix[j][i].tile_num - 30][_matrix[j][i].tile_num] = _matrix[j][i-1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num ] = _matrix[j+1][i].weight;
//            }
//            else if (i == 20 && j == 29) {
//                //left
//                matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num] = _matrix[j - 1][i].weight;
//                //top
//                matrix[_matrix[j][i].tile_num - 30][_matrix[j][i].tile_num] = _matrix[j][i - 1].weight;
//            }
//            else if (i == 0 && j == 0) {
//                //right
//                matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num] = _matrix[j + 1][i].weight;
//                //bottom
//                matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
//            }
//            else if (i == 0 && j == 29) {
//                //bottom
//                matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
//                //left
//                matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num] = _matrix[j-1][i].weight;
//            }
//            else if (j == 0 && i > 0 && i < 20) {
//                //bottom
//                matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
//                //top
//                matrix[_matrix[j][i].tile_num - 30][_matrix[j][i].tile_num] = _matrix[j][i - 1].weight;
//                //right
//                matrix[_matrix[j][i].tile_num + 1][_matrix[j][i].tile_num ] = _matrix[j + 1][i].weight;
//            }
//            else if (j == 29 && i > 0 && i < 20) {
//                //bottom
//                matrix[_matrix[j][i].tile_num + 30][_matrix[j][i].tile_num] = _matrix[j][i + 1].weight;
//                //top
//                matrix[_matrix[j][i].tile_num  - 30][_matrix[j][i].tile_num] = _matrix[j][i - 1].weight;
//                //left
//                matrix[_matrix[j][i].tile_num - 1][_matrix[j][i].tile_num] = _matrix[j - 1][i].weight;
//            }
//        }
//    }
}

int Graph::getStart(){
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (_matrix[j][i].tile_type == 1)
                return _matrix[j][i].tile_num;
        }
    }
    return -1;
}
int Graph::getEnd(){
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (_matrix[j][i].tile_type == 2)
                return _matrix[j][i].tile_num;
        }
    }
    return -1;
}


bool Graph::breadthFirstTrav(sf::RenderWindow& window,Graph &myGraph, int start, int end) {
    // num / 30 = row
    // mum % 30 = col
    auto begin = chrono::high_resolution_clock::now();
    algorithm_duration = "Time: ";
    queue<int> q;
    vector<int> used;
    q.push(start);
    used.push_back(start);
    while(!q.empty()){
        myGraph.LoadTileData();
        window.setFramerateLimit(70);
        myGraph.UpdateGraph(window);
        window.display();
        for(int i = 0; i < myGraph.matrix.at(q.front()).size(); i++){
            if((myGraph.matrix[q.front()][i] != -1) &&(count(used.begin(), used.end(), i) == 0)){
                myGraph.LoadTileData();
                myGraph.UpdateGraph(window);
                window.setFramerateLimit(70);
                window.display();
                if(i == end) {
                    while(!q.empty() && q.front() != myGraph.getEnd() - 1 && q.front() != myGraph.getEnd() + 1
                            && q.front() != myGraph.getEnd() + 30 && q.front() != myGraph.getEnd() - 30){
                        _matrix[q.front() % 30][q.front() / 30].tile_type = 6;
                        myGraph.LoadTileData();
                        myGraph.UpdateGraph(window);
                        window.setFramerateLimit(70);
                        window.display();
                        q.pop();
                    }
                    _matrix[q.front() % 30][q.front() / 30].tile_type = 6;
                    myGraph.LoadTileData();
                    myGraph.UpdateGraph(window);

                    auto end1 = chrono::high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end1 - begin);
                    algorithm_duration = "Time: " + to_string(duration.count()) + "ms";
                    return true;
                }
                else {
                    q.push(i);
                    used.push_back(i);
                    if (_matrix[q.front() % 30][q.front() / 30].tile_type != 1 &&
                        _matrix[q.front() % 30][q.front() / 30].tile_type != 2) {
                            _matrix[q.front() % 30][q.front() / 30].tile_type = 6;
                    }
                }
            }
        }
        q.pop();
    }
    auto end2 = chrono::high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end2 - begin);
    algorithm_duration = "Time: " + to_string(duration.count()) + "ms";
    return false;
}
bool Graph::depthFirstTrav(sf::RenderWindow& window, Graph& myGraph, int start, int end){
    algorithm_duration = "Time: ";
    auto begin = chrono::high_resolution_clock::now();
    stack<int> s;
    vector<int> used;
    s.push(start);
    used.push_back(start);

    while(!s.empty()){
        myGraph.LoadTileData();
        myGraph.UpdateGraph(window);
        window.setFramerateLimit(50);
        window.display();
        for(int i = 0; i < myGraph.matrix[s.top()].size(); i++){
            if((myGraph.matrix[s.top()][i] != -1) && (count(used.begin(), used.end(), i) == 0)){
                if(i == end) {
                    while(!s.empty() && s.top() != myGraph.getEnd() - 1 && s.top() != myGraph.getEnd() + 1
                          && s.top() != myGraph.getEnd() + 30 && s.top() != myGraph.getEnd() - 30){
                        _matrix[s.top() % 30][s.top() / 30].tile_type = 6;
                        myGraph.LoadTileData();
                        myGraph.UpdateGraph(window);
                        window.setFramerateLimit(50);
                        window.display();
                        s.pop();
                    }
                    myGraph.LoadTileData();
                    myGraph.UpdateGraph(window);
                    window.setFramerateLimit(50);
                    window.display();
                    auto end1 = chrono::high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end1 - begin);
                    algorithm_duration = "Time: " + to_string(duration.count()) + "ms";
                    return true;
                }
                else{
                    s.push(i);
                    used.push_back(i);
                    //if not start or end tile
                    if (_matrix[s.top() % 30][s.top() / 30].tile_type != 1 && _matrix[s.top() % 30][s.top() / 30].tile_type != 2) {
                        _matrix[s.top() % 30][s.top() / 30].tile_type = 6;
                    }
                }
            }
        }
        s.pop();
    }
    auto end2 = chrono::high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end2 - begin);
    algorithm_duration = "Time: " + to_string(duration.count())+ "ms";
    return false;
}
bool Graph::testDepthFirstTrav( Graph& myGraph, int start, int end){
    stack<int> s;
    vector<int> used;
    s.push(start);
    used.push_back(start);

    while(!s.empty()){
        for(int i = 0; i < myGraph.matrix[s.top()].size(); i++){
            if((myGraph.matrix[s.top()][i] != -1) && (count(used.begin(), used.end(), i) == 0)){
                if(i == end) {
                    return true;
                }
                else{
                    s.push(i);
                    used.push_back(i);
                }
            }
        }
        s.pop();
    }
    return false;
}
bool Graph::testBreadthFirstTrav(Graph &myGraph, int start, int end) {
    queue<int> q;
    vector<int> used;
    q.push(start);
    used.push_back(start);

    while(!q.empty()){
        for(int i = 0; i < myGraph.matrix[q.front()].size(); i++){
            if((myGraph.matrix[q.front()][i] != -1) && (count(used.begin(), used.end(), i) == 0)){
                if(i == end) {
                    return true;
                }
                else{
                    q.push(i);
                    used.push_back(i);
                }
            }
        }
        q.pop();
    }
    return false;
}

void Graph::test(){
    Graph testGraph(250, 400);
    int count = 0;
    for(int i = 0; i < 100000; i++){
        for(int j = 0; j < 100000; j++){
            testGraph.matrix[i][j] = count % 50;
            count++;
        }
    }
    cout << "Testing BFS... "<< endl;
    auto start = chrono::high_resolution_clock::now();
    testBreadthFirstTrav(testGraph, 0, 99999);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> dur = end - start;
    cout << "BFS took " << dur.count() <<  "seconds" << endl;
    cout << "Testing DFS..." << endl;
    start = chrono::high_resolution_clock::now();
    testDepthFirstTrav(testGraph, 0, 99999);
    end = chrono::high_resolution_clock::now();
    dur = end - start;
    cout << "DFS took " << dur.count() << " seconds" << endl;
}


