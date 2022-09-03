#include <iostream>

using namespace std;

void Solve(int h, int w, int n){
    int room_num = n / h + 1;
    int floor_num = (n % h == 0) ? h : n % h;

    if(n % h == 0)
        room_num--;

    printf("%d", floor_num);
    if(room_num < 10)
        printf("0%d\n", room_num);
    else
        printf("%d\n", room_num);
}

int main() {
    int t, h, w, n;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d %d %d", &h, &w, &n);
        Solve(h, w, n);
    }

    return 0;
}