#include <iostream>

using namespace std;

typedef struct _Info {
    int weight;
    int height;
} Info;

Info info[51];

int main() {
    int n, x, y, rate = 1;
    
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &info[i].weight, &info[i].height);
    }

    for(int i=0; i<n; i++){
        int rate = 1;
        int curWeight = info[i].weight;
        int curHeight = info[i].height;

        for(int j=0; j<n; j++){
            if(curWeight < info[j].weight && curHeight < info[j].height)
                rate++;
        }

        printf("%d ", rate);
    }
    printf("\n");

    return 0;
}