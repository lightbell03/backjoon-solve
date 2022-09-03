#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[100][100][100];
int visited[100][100][100] = {0, };
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1}; 

int main() {
    int m, n, h, day = 0, total_cnt = 0, cnt = 0;
    queue<tuple<int, int, int>> q;
    queue<tuple<int, int, int>> q2;

    scanf("%d %d %d", &m, &n, &h);

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                scanf("%d", &arr[i][j][k]);
                if(arr[i][j][k] == 1){
                    q.push(make_tuple(i, j, k));
                    //visited[i][j][k] = 1;
                }
                else if(arr[i][j][k] == 0)
                    total_cnt++;
            }
        }
    }

    while(1){
        if(q.empty() && q2.empty()){
            break;
        }
        if(q.empty() && !q2.empty()){
            while(!q2.empty()){
                q.push(make_tuple(get<0>(q2.front()), get<1>(q2.front()), get<2>(q2.front())));
                q2.pop();
            }
            day++;
        }
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int k = get<2>(q.front());

        q.pop();

        for(int idx=0; idx<6; idx++){
            if(dx[idx]+j>=0 && dx[idx]+j<n && dy[idx]+k>=0 && dy[idx]+k<m
                && dz[idx]+i>=0 && dz[idx]+i<h)
                {
                    if(arr[dz[idx]+i][dx[idx]+j][dy[idx]+k] == 1
                        || arr[dz[idx]+i][dx[idx]+j][dy[idx]+k] == -1){
                        continue;
                        }
                    else{
                        q2.push(make_tuple(dz[idx]+i, dx[idx]+j, dy[idx]+k));
                        arr[dz[idx]+i][dx[idx]+j][dy[idx]+k] = 1;
                        cnt++;
                    }
                }
            else
                continue;
        }
    }

    if(cnt == total_cnt){
        printf("%d\n", day);
    }
    else{
        printf("-1\n");
    }
}