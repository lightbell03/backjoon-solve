#include <stdio.h>

using namespace std;

void Conquer(int **arr, int start_row, int start_col, int size){
    bool check = false;
    if(size == 1){
        printf("%d", arr[start_row][start_col]);
    }
    else {
        for(int i=start_row; i<start_row + size; i++){
            for(int j=start_col; j<start_col + size; j++){
                if(arr[start_row][start_col] != arr[i][j]){
                    check = true;
                    break;
                }
            }
            if(check)
                break;
        }
        if(check){
            //left up
            printf("(");
            Conquer(arr, start_row, start_col, size/2);

            //right up
            Conquer(arr, start_row, start_col + size/2, size/2);
            
            //left bottom
            Conquer(arr, start_row + size/2, start_col, size/2);

            //right bottom
            Conquer(arr, start_row + size/2, start_col + size/2, size/2);
            printf(")");
        }
        else{
            printf("%d", arr[start_row][start_col]);
            return;
        }
    }
}

int main(){
    int n, **arr;
    char **str;

    scanf("%d", &n);

    str = new char*[n + 1];
    arr = new int*[n];

    for(int i=0; i<n; i++){
        str[i] = new char[n + 1];
        arr[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = str[i][j] - 48;
        }
    }

    Conquer(arr, 0, 0, n);

    for(int i=0; i<n; i++){
        delete []str[i];
        delete []arr[i];
    }

    delete []str;
    delete []arr;

    return 0;
}