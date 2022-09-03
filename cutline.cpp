#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int val1, int val2){
    return val1 > val2;
}

int main() {
    int N, k, input;
    vector<int> x;

    cin >> N >> k;

    for(int i=0; i<N; i++) {
        cin >> input;
        x.push_back(input);
    }

    sort(x.begin(), x.end(), compare);

    cout << x[k - 1];
}