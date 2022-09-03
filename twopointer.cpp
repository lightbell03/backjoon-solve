#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, input, x;
    int answer = 0;
    vector<int> v;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        v.push_back(input);
    }

    scanf("%d", &x);

    sort(v.begin(), v.end());

    int i=0, j=v.size()-1;

    while(i < j){
        if(v[i] + v[j] > x)
            j--;
        else if(v[i] + v[j] < x){
            i++;
        }
        else if(v[i] + v[j] == x){
            i++;
            j--;
            answer++;
        }
    }

    printf("%d", answer);
}