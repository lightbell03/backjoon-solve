#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, cnt = 0;
    string str;
    set<string> s;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        cin>>str;
        s.insert(str);
    }

    for(int i=0; i<m; i++){
        cin>>str;
        if(s.find(str) != s.end())
            cnt++;
    }

    cout<<cnt<<endl;
}