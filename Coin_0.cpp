#include <stdio.h>

using namespace std;

int GetMinCoin(int *arr, int cost, int size){
    int answer = 0;

    for(int i=size-1; i>=0; i--){
        if(cost == 0)
            break;
        if(arr[i] <= cost){
            answer += cost / arr[i];
            cost = cost % arr[i];
        }
    }

    return answer;
}

int main() {
    int n, k, *coin;
    int answer;

    scanf("%d %d", &n, &k);

    coin = new int[n];

    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    answer = GetMinCoin(coin, k, n);

    printf("%d\n", answer);

    delete []coin;

    return 0;
}