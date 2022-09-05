#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Info{
public:
    int pos;
    int val;

    Info(int pos, int val){
        this->pos = pos;
        this->val = val;
    }
};

int main() {
    int N, input;
    stack<Info> s;

    cin >> N;
    vector<int> v(N, -1);

    for(int i=0; i<N; i++){
        cin>>input;

        if(s.empty()){
            s.push(Info(i, input));
        } else {
            while(!s.empty() && s.top().val < input){
                v[s.top().pos] = input;
                s.pop();
            }
            s.push(Info(i, input));
        }
    }

    for(int i=0; i<N; i++){
        cout<<v[i]<<" ";
    }
}