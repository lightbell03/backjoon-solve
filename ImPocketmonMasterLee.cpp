#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, val;
    string str = "";
    map<string, int> strToInt;
    vector<string> intToStr;

    cin>>n>>m;

    intToStr.push_back("");

    for(int i=1; i<=n; i++){
        cin>>str;
        strToInt.insert({str, i});
        intToStr.push_back(str);
    }

    for(int i=0; i<m; i++){
        cin>>str;
        if(str[0] >= '0' && str[0] <= '9'){
            val = stoi(str);
            cout<<intToStr[val]<<"\n";
        }
        else{
            int find = strToInt.find(str)->second;
            cout<<find<<"\n";
        }
    }
}