#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

int search(vector<vector<pair<int, int> > > graph, int start, int startVal, int end){
    queue<int> q;
    vector<int> dist(graph.size() + 1, INF);

    dist[start] = startVal;

    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextCost = dist[now] + graph[now][i].second;
            
            if(nextCost < dist[next]){
                dist[next] = nextCost;
                q.push(next);
            }
        }
    }

    return dist[end];
}

/**
 * start = 1
 * */
int main() {
    int N, E;
    int u, v, w;
    int first, second;

    cin>>N>>E;

    vector<vector<pair<int, int> > > graph(N);
    vector<int> firstDist(N + 1, INF);
    vector<int> secondDist(N + 1, INF);

    for(int i=0; i<N; i++){
        graph.push_back(vector<pair<int, int> >());
    }

    for(int i=0; i<E; i++){
        cin>>u>>v>>w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    cin>>first>>second;

    int firstPathVal = search(graph, 1, 0, first);
    int secondPathVal = search(graph, first, firstPathVal, second);
    int lastPathVal = search(graph, second, secondPathVal, N);

    int firstPathVal_2 = search(graph, 1, 0, second);
    int secondPathVal_2 = search(graph, second, firstPathVal_2, first);
    int lastPathVal_2 = search(graph, first, secondPathVal_2, N);

    if(lastPathVal == INF || lastPathVal_2 == INF)
        cout<<-1;
    else if(lastPathVal < lastPathVal_2)
        cout<<lastPathVal;
    else
        cout<<lastPathVal_2;

    cout<<endl;
}