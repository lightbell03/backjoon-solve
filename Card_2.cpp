#include <stdio.h>

using namespace std;

int arr[500001] = {0, };

void Solve(int n){
    int idx = 0;

    while(idx++ != n) {
        
        if(idx == 500001)
            idx = 1;
        n++;
        if(n == 500001)
            n = 1;
        idx++;
        arr[n] = arr[idx]; 
    }

    printf("%d\n", arr[n -1]);
}

int main() {
    int n;

    scanf("%d", &n);
    
    for(int i=1; i<n + 1; i++){
        arr[i] = i;
    }

    Solve(n);
}