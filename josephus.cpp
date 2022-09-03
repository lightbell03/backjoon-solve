#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
int arr[1001] = {0, };

int main() {
    int n, k, cnt = 0, idx = 1, inner_idx = 1;
    vector<int> v;

    scanf("%d %d", &n, &k);

    while(1){
        if(cnt == n)
            break;
        if(idx == n + 1)
            idx = 1;
        if(arr[idx] == 1){
            idx++;
            continue;
        }
        if(inner_idx == k){
            v.push_back(idx);
            arr[idx] = 1;
            cnt++;
            inner_idx = 0;
        }
        inner_idx++;
        idx++;
    }

    printf("<");
    for(int i=0; i<v.size(); i++){
        if(i == v.size() - 1)
            printf("%d", v[i]);
        else
            printf("%d, ", v[i]);
    }
    printf(">\n");

    return 0;
}
*/

int main () {

    int n, k, idx = 1;
    vector<int> v;
    queue<int> q;

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        q.push(i + 1);
    }
    
    while(1){
        if(q.empty())
            break;
        
        if(idx == k){
            v.push_back(q.front());
            q.pop();
            idx = 1;
        }

        q.push(q.front());
        q.pop();
        idx++;
    }

    printf("<");
    for(int i=0; i<v.size(); i++){
        if(i == v.size() - 1)
            printf("%d", v[i]);
        else
            printf("%d, ", v[i]);
    }
    printf(">\n");

    return 0;
}

