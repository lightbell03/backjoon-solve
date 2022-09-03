#include <stdio.h>

using namespace std;

long long arr[1000001] = {0, };
int cnt = 0;

int Tile(int n){
    if(n == 0) return 0;
    else if(arr[n] != 0){
        return arr[n];
    }
    else {
        return arr[n] = (Tile(n-1) % 15746 + Tile(n-2) % 15746) % 15746;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    arr[1] = 1;
    arr[2] = 2;

    Tile(n);

    printf("%d\n", arr[n]);
    return 0;
}