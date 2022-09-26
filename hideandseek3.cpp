#include <iostream>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

int dist[100001];

class Edge {
public:
    int u;
    int w;

    Edge(int u, int w){
        this->u = u;
        this->w = w;
    }

    bool operator<(const Edge &edge) const {
        return this->w > edge.w;
    }
};

int main() {
    for(int i=0; i<100001; i++){
        dist[i] = INF;
    }
    int N, K;
    priority_queue<Edge> q;

    cin >> N >> K;

    if(N == K){
        cout<<"0\n";
        return 0;
    }
    if(K < N){
        cout<<N - K<<"\n";
        return 0;
    }

    q.push(Edge(N, 0));
    dist[N] = 0;

    while(!q.empty()){
        int now = q.top().u;
        int cost = q.top().w;
        q.pop();

        if(now + 1 < 100001 && cost + 1 < dist[now + 1]){
            dist[now + 1] = cost + 1;
            q.push(Edge(now + 1, cost + 1));
        }
        if(now - 1 > 0 && cost + 1 < dist[now - 1]){
            dist[now - 1] = cost + 1;
            q.push(Edge(now - 1, cost + 1));
        }
        if((now << 2) < 100001 && cost < dist[now*2]){
            dist[now * 2] = cost;
            q.push(Edge(now * 2, cost));
        }
    }

    cout << dist[K];

    return 0;
}