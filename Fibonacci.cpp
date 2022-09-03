#include <stdio.h>

using namespace std;

int arr_0[41] = {0, };
int arr_1[41] = {0, };

int main() {
    int t, input_val;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        arr_1[1]++;
        arr_0[0]++;
        
        scanf("%d", &input_val);

        for(int i=2; i<input_val + 1; i++){
            arr_0[i] += arr_0[i-1] + arr_0[i-2];
            arr_1[i] += arr_1[i-1] + arr_1[i-2];
        }

        printf("%d %d\n", arr_0[input_val], arr_1[input_val]);

        for(int i=0; i<42; i++){
            arr_0[i] = 0;
            arr_1[i] = 0;
        }
    }
}