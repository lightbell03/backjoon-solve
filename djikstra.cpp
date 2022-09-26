#include <iostream>
#include <vector>

#define INF 11

using namespace std;

int main() {
    int V, E;
    int u, v, w;

    cin>>V>>E;

    vector<vector<int>> list;
    vector<int> total(V, INF);

    for(int i=0; i<V; i++){
        list.push_back(vector<int>(E, 0));
    }


    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        list[u][v] = w;
    }

    
}