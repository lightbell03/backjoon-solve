#include <stdio.h>

using namespace std;

void BackTrack(int *arr, int idx, int n, int m, int arr_len){
    arr[arr_len++] = idx;

    if(arr_len == m) {
        for(int i=0; i<arr_len; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

        return;
    }
    else {
        for(int i=idx; i<n + 1; i++){
            BackTrack(arr, i, n, m, arr_len);
        }
    }
}

int main() {
    int n, m;
    int *arr;

    scanf("%d %d", &n, &m);

    arr = new int[m];

    for(int i=1; i<n + 1; i++){
        BackTrack(arr, i, n, m, 0);
    }

    delete arr;

    return 0;
}