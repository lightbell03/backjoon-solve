#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &graph, vector<int> &visited, int now, int &cnt){
    visited[now] = cnt;

    for(int i=0; i<graph[now].size(); i++){
        int next = graph[now][i];

        if(visited[next] != 0) continue;

        dfs(graph, visited, next, ++cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M, R;
    int u, v, cnt=1;
    cin>>N>>M>>R;
    vector<vector<int> > graph;
    vector<int> visited(N + 1, 0);

    for(int i=0; i<N + 1; i++){
        graph.push_back(vector<int>());
    }

    for(int i=0; i<M; i++){
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<N + 1; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited, R, cnt);

    for(int i=1; i<N+1; i++){
        cout<<visited[i]<<"\n";
    }
}