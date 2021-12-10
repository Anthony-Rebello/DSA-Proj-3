#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

/*
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
*/
class Graph{

    public:
        int size = 0;
        vector<Tile> nodes;
        vector<vector<int> > matrix;

        //constructor for the graph object
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

};

bool breadthFirstTrav(Graph& myGraph, int start, int end){
    queue<int> q;
    vector<int> used;
    q.push(start);
    used.push_back(start);
    while(!q.empty()){
        for(int i = 0; i < myGraph.matrix.at(q.front()).size(); i++){
            if((myGraph.matrix[q.front()][i] != -1) &&(count(used.begin(), used.end(), i) == 0)){
                if(i == end)
                    return true;
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

bool depthFirstTrav(Graph& myGraph, int start, int end){
    stack<int> s;
    vector<int> used;
    s.push(start);
    used.push_back(start);
    while(!s.empty()){
        for(int i = 0; i < myGraph.matrix[s.top()].size(); i++){
            if((myGraph.matrix[s.top()][i] != -1) && (count(used.begin(), used.end(), i) == 0)){
                if(i == end)
                    return true;
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

vector<pair<int, int>> dijkstra(Graph& myGraph, int start, int end){
  vector<pair<int, int>> resultPath;
  vector<int> distances(size, 20000);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  distances[start] = 0;

  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    
  }
}

/*int main(){

    //debug statememnt vv
    Graph g(4, 4);
    g.matrix[0][1] = 1;
    g.matrix[1][5] = 1;
    g.matrix[5][6] = 1;
    g.matrix[6][10] = 1;
    g.matrix[10][11] = 1;
    cout << breadthFirstTrav(g, 0, 11) << endl;
    cout << depthFirstTrav(g, 0, 11) << endl;
    cout << depthFirstTrav(g, 0, 12) << endl;
    cout << "this works still" << endl;
    return 0;
}*/
