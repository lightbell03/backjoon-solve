#include <iostream>

using namespace std;

int arr[100001];
long long save[100001] = {0, };

int main() {
    int n, m, sum = 0;
    int val1, val2;

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d" ,&arr[i]);
        sum += arr[i];
        save[i] = sum;
    }

    for(int i=0; i<m; i++){
        scanf("%d %d", &val1, &val2);
        if(val1 == val2)
            printf("%d\n", arr[val1]);
        else
            printf("%d\n", save[val2] - save[val1 - 1]);
    }
}