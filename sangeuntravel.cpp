#include <iostream>

using namespace std;

int main() {
    int T, N, M;

    cin >> T;

    while(T-- > 0){
        cin >> N >> M;

        for(int i=0; i<M; i++){
            int u, v;
            cin >> u >> v;
        }

        cout << N - 1 <<"\n";
    }
}