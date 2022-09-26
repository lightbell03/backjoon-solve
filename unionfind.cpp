#include <iostream>

using namespace std;

int parent[1000001];
int rankArr[1000001];

int find(int u){
    if(u == parent[u]) return u;

    return find(parent[u]);
}

void merge(int u, int v){
    int a = find(u);
    int b = find(v);

    if(a == b) return;

    if(rankArr[a] == rankArr[b]){
        rankArr[a]++;
    }
    
    if(rankArr[a] > rankArr[b])
        parent[b] = a;
    else
        parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int op, u, v;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        cin >> op >> u >> v;

        if(op == 0){
            merge(u, v);
        }
        else {
            if(find(u) == find(v)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}