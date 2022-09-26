#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, M, input, bottom, top;
    cin >> N;
    vector<int> v(N, 0);

    for(int i=0; i<N; i++){
        cin>>input;
        v[i] = input;
    }
    sort(v.begin(), v.end());

    cin>>M;
    for(int i=0; i<M; i++){
        cin>>input;
        if(input == v[N-1]){
            cout<<"1\n";
            continue;
        }
        bottom = 0;
        top = N - 1;

        int halfIndex = (bottom + top) / 2;

        while(true){
            int half = v[halfIndex];
            if(half == input){
                cout<<"1\n";
                break;
            }
            else if(half > input){
                top = halfIndex;
                int nextHalfIndex = (bottom + top) / 2;
                if(nextHalfIndex == halfIndex){
                    if(v[nextHalfIndex] == input){
                        cout<< "1\n";
                        break;
                    }
                    else{
                        cout<<"0\n";
                        break;
                    }
                }
                halfIndex = nextHalfIndex;
            }
            else{
                bottom = halfIndex;
                int nextHalfIndex = (bottom + top) / 2;
                if(nextHalfIndex == halfIndex){
                    if(v[nextHalfIndex] == input){
                        cout<<"1\n";
                        break;
                    }
                    else{
                        cout<<"0\n";
                        break;
                    }
                }
                halfIndex = nextHalfIndex;
            }
        }
    }
}