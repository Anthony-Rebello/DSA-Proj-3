#include <iostream>
using namespace std;

struct Tile{
    bool blocked, start, end;
    unsigned int weight;

    Tile(){
        blocked = false, start = false, end = false;
        weight = 0;
    }
    Tile(bool isBlocked, unsigned int w){
        blocked = isBlocked, start = false, end = false;
        weight = w;
    }
    void makeStart(Tile& tile){
        tile.start = true;
    }
    void makeEnd(Tile& tile){
        tile.end = true;
    }
};
class Graph{
    int size = 0;
    Tile* matrix = nullptr;

    Graph(int row, int column){
        Tile arrMatrix[row][column];
        matrix = *arrMatrix;
    }

};

void breadthFirstTrav(){

}

void depthFirstTrav(){

}

void dijkstra(){

}

void bellmanFord(){

}

int main(){

    cout << "this works still" << endl;
    return 0;
}