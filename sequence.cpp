#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, val = 0;
    cin >> N >> K;
   
    vector<int> list(N);
    vector<int> v;
    
    for(int i=0; i<N; i++){
        cin >> list[i];
    }
    for(int i=0; i<K; i++){
        val += list[i];
    }
    v.push_back(val);

    for(int i=K; i<N; i++){
        val -= list[i - K];
        val += list[i];
        v.push_back(val);
    }

    int max = *max_element(v.begin(), v.end());

    cout << max << "\n";
}