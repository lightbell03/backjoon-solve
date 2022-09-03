#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25];
char carr[25][25];
bool visited[25][25];
int answer[313];
int cnt = 0;

void BFS(int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0 || visited[i][j])
                continue;
            cnt++;

            queue<pair<int, int>> q;

            q.push(make_pair(i, j));
            visited[i][j] = true;

            while(!q.empty()){
                
                answer[cnt - 1]++;
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                arr[row][col] = cnt;

                if(row + 1 < n && !visited[row+1][col])
                    if(arr[row+1][col] != 0){
                        q.push(make_pair(row + 1, col));
                        visited[row+1][col] = true;
                    }
                if(row - 1 >= 0 && !visited[row-1][col])
                    if(arr[row-1][col] != 0){
                        q.push(make_pair(row - 1, col));
                        visited[row-1][col] = true;
                    }
                    
                if(col + 1 < n && !visited[row][col+1])
                    if(arr[row][col+1] != 0){
                        q.push(make_pair(row, col + 1));
                        visited[row][col+1] = true;
                    }
                if(col - 1 >= 0 && !visited[row][col-1])
                    if(arr[row][col-1] != 0){
                        q.push(make_pair(row, col-1));
                        visited[row][col-1] = true;
                    }
            }

        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%s", carr[i]);
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = carr[i][j] - '0';
        }
    }

    BFS(n);

    sort(answer, answer+313);

    printf("%d\n", cnt);
    if(cnt==0)
        printf("0\n");
    else
        for(int i=0; i<313; i++)
            if(answer[i] != 0)
                printf("%d\n", answer[i]);
}