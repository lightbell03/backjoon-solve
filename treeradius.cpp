#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int max = 0;
    int V, u, v, w;
    cin >> V;

    vector<vector<pair<int, int> > > graphU;

    for(int i=0; i < V + 1; i++){
        graphU.push_back(vector<pair<int, int> >());
    }

    for(int i=0; i<V; i++){
        cin >> u;
        while(true){
            cin >> v;
            if(v == -1)
                break;
            cin >> w;

            graphU[u].push_back(make_pair(v, w));
        }
    }

    queue<pair<int, int> > q;

    for(int i=1; i<V + 1; i++){
        vector<int> visited(V + 1, 0); 

        q.push(make_pair(i, 0));
        visited[i] = 1;

        while(!q.empty()){
            int now = q.front().first;
            int cost = q.front().second;
            q.pop();

            for(int j=0; j<graphU[now].size(); j++){
                int next = graphU[now][j].first;
                if(visited[next] != 0) continue;
                
                int nextCost = cost + graphU[now][j].second;

                q.push(make_pair(next, nextCost));
                visited[next] = 1;

                if(nextCost > max)
                    max = nextCost;
            }
        }
    }
    cout<< max << "\n";
}