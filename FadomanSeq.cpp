#include <iostream>

using namespace std;

long long arr[101] = {0, };

long long solve(int i){
    if(i == 1 || i == 2 || i == 3) return 1;
    else if(i < 1) return 0;
    else if (arr[i] != 0) return arr[i];
    else {
        return arr[i] = solve(i-2) + solve(i-3);
    }
}

int main() {
    int t, n;

    cin>>t;

    while(t-- > 0){
        cin >> n;
        cout<<solve(n)<<"\n";
    }
}