#include <iostream>
#include <vector>
using namespace std;

struct Tile{
    bool blocked, start, end;
    unsigned int weight;

    //constructors for the Tile object
    Tile(){
        blocked = false, start = false, end = false;
        weight = 0;
    }
    Tile(bool isBlocked, unsigned int w){
        blocked = isBlocked, start = false, end = false;
        weight = w;
    }
    //functions to block or change the weight of a tile
    void block(){
        blocked = true;
    }
    void changeWeight(unsigned int w){
        weight = w;
    }
    //functions to make tile the start or end of the board
    void makeStart(){
        start = true;
    }
    void makeEnd(){
        end = true;
    }
};
class Graph{

    public:
        int size = 0;
        vector<vector<Tile> > matrix;

        //constructor for the graph object
        Graph(int row, int column){
            matrix.resize(row);
            for(int i = 0; i < row; i++){
                matrix.at(i).resize(column);
            }
        }

};

void breadthFirstTrav(Tile& startTile){
    
}

void depthFirstTrav(Tile& startTile){

}

void dijkstra(Tile& startTile){

}

void bellmanFord(Tile& startTile){

}

int main(){

    //debug statememnt vv
    cout << "this works still" << endl;
    return 0;
}