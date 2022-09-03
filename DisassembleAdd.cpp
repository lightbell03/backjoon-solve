#include <stdio.h>

using namespace std;

int main() {
    int n, div, mod, sum;
    int answer = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        div = i;
        mod = 0;
        sum = 0;

        while(div != 0){
            mod = div % 10;
            div /= 10;
            sum += mod;
        }

        if((sum + i) == n){
            answer = i;
            break;
        }
    }

    printf("%d\n", answer);
        
    return 0;
}
