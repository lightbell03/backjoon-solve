#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

class Node
{
public:
    int v;
    int w;

    Node(int v, int w)
    {
        this->v = v;
        this->w = w;
    }

    bool operator<(const Node &n) const
    {
        return w > n.w;
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int V, E, start;
    int u, v, w;

    cin >> V >> E;
    cin>>start;

    priority_queue<Node> pq;
    vector<vector<pair<int, int> > > graph;
    vector<int> dist(V + 1, INF);

    for(int i=0; i<V; i++){
        graph.push_back(vector<pair<int, int> >());
    }

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }

    pq.push(Node(start, 0));
    dist[start] = 0;

    while (!pq.empty())
    {
        int now = pq.top().v;
        int cost = pq.top().w;
        pq.pop();

        if (cost > dist[now])
            continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int nextCost = graph[now][i].second + cost;

            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push(Node(next, nextCost));
            }
        }
    }

    for (int i = 1; i < V + 1; i++)
    {
        if(dist[i] == INF)
            cout<< "INF";
        else
            cout<<dist[i];

        cout<<"\n";
    }
}