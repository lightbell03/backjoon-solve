#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Info { 
public:
    int pos;
    int val;
    int cnt;

    Info(int pos, int val){
        this->pos = pos;
        this->val = val;
        this->cnt = 0;
    }
};

bool comparePos(Info info1, Info info2){
    return info1.pos < info2.pos;
}

bool compareVal(Info info1, Info info2){
    return info1.val < info2.val;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N, input, count = 0;
    vector<Info> x;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>input;

        x.push_back(Info(i, input));
    }

    sort(x.begin(), x.end(), compareVal);

    for(int i=1; i<N; i++){
        if(x[i - 1].val != x[i].val)
            count++;

        x[i].cnt = count;
    }

    sort(x.begin(), x.end(), comparePos);

    for(int i=0; i<N; i++){
        cout << x[i].cnt << " ";
    }
}