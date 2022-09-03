#include <stdio.h>

using namespace std;

int arr[50][50] = {0, };
int visited[50][50];
int cnt = 0;

void DFS(int cur_row, int cur_col, int row_len, int col_len) {
    visited[cur_row][cur_col] = 1;

    if(cur_row + 1 < row_len){
        if(arr[cur_row + 1][cur_col] && !visited[cur_row + 1][cur_col])
            DFS(cur_row + 1, cur_col, row_len, col_len);
    }

    if(cur_row - 1 >= 0){
        if(arr[cur_row - 1][cur_col] && !visited[cur_row - 1][cur_col])
            DFS(cur_row - 1, cur_col, row_len, col_len);
    }

    if(cur_col + 1 < col_len){
        if(arr[cur_row][cur_col + 1] && !visited[cur_row][cur_col + 1])
            DFS(cur_row, cur_col + 1, row_len, col_len);
    }

    if(cur_col - 1 >= 0){
        if(arr[cur_row][cur_col - 1] && !visited[cur_row][cur_col - 1])
            DFS(cur_row, cur_col - 1, row_len, col_len);
    }

}

int main() {
    int t, row, col, cab_num;
    int input_row, input_col;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        cnt = 0;
        scanf("%d %d %d", &row, &col, &cab_num);

        for(int j=0; j<cab_num; j++){
            scanf("%d %d", &input_row, &input_col);
            arr[input_row][input_col] = 1;
            visited[input_row][input_col] = 0;
        }

        for(int j=0; j<row; j++){
            for(int k=0; k<col; k++){
                if(arr[j][k] == 0 || visited[j][k])
                    continue;
                cnt++;
                DFS(j, k, row, col);
            }
        }
        printf("%d\n", cnt);
    }
}