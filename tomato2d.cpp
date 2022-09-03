#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001] = {0, };

typedef struct _Point {
    int x, y;
    _Point(int x, int y){
        this->x = x;
        this->y = y;
    }
} Point;

class BFS {
private:
    int day = 0, cnt = 0;
    int row, col, totalCnt;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    queue<Point> q;

public:
    BFS(int row, int col, int totalCnt){
        this->row = row;
        this->col = col;
        this->totalCnt = totalCnt;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == 1){
                    q.push(Point(i, j));
                }
            }
        }
    }

    void ExcuteBFS(){
        queue<Point> nq;

        while(1){

            if(q.empty() && !nq.empty()){
                while(!nq.empty()){
                    q.push(Point(nq.front().x, nq.front().y));
                    nq.pop();
                }
                day++;
            }
            else if(q.empty() && nq.empty()){
                if(cnt == totalCnt)
                    printf("%d\n", day);
                else
                    printf("-1\n");

                break;
            }
            
            int x = q.front().x;
            int y = q.front().y;

            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < row && ny >= 0 && ny < col){
                    if(arr[nx][ny] == 0 && arr[nx][ny] != -1){
                        arr[nx][ny] = 1;
                        nq.push(Point(nx, ny));
                        cnt++;
                    }
                }
            }
        }
    }
};

int main(){
    int n, m;
    int totalCnt = 0;

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0)
                totalCnt++;
        }
    }

    BFS bfs(m, n, totalCnt);
    bfs.ExcuteBFS();

    return 0;
}