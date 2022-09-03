#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, input;
    map<int, int> sangHave;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>input;

        if(sangHave.find(input) != sangHave.end()){
            sangHave.find(input)->second++;
        }
        else{
            sangHave.insert({input, 1});
        }
    }

    cin>>m;

    for(int i=0; i<m; i++){
        cin>>input;

        if(sangHave.find(input) != sangHave.end()){
            cout<<sangHave.find(input)->second<<" ";
        }
        else{
            cout<<"0 ";
        }
    }
}