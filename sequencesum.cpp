#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[100000];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, preVal = 0;

    cin>>n;
    vector<int> list(n, 0);
    vector<int> v(n, 0);

    for(int i=0; i<n; i++){
        cin>>list[i];
    }

    for(int i=0; i<n; i++){

        if(list[i] + preVal >= list[i])
            v[i] = list[i] + preVal;
        else
            v[i] = list[i];
        
        preVal = v[i];
    }

    int max = *max_element(v.begin(), v.end());
    cout<<max<<"\n";
}