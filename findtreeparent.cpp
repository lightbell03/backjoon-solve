#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, u, v;
    cin >> N;

    vector<vector<int> > graph;
    queue<int> q;
    vector<int> visited(N + 1, 0);
    vector<int> parent(N + 1, 0);

    for(int i=0; i<N + 1; i++){
        graph.push_back(vector<int>());
    }

    for(int i=0; i<N - 1; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=0; i<graph[now].size(); i++){
            int next = graph[now][i];

            if(visited[next] == 1) continue;
            parent[next] = now;
            q.push(graph[now][i]);
            visited[next] = 1;
        }
    }

    for(int i=2; i<N+1; i++){
        cout<<parent[i]<<"\n";
    }
}