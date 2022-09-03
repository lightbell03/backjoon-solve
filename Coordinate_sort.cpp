#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct _Coord {
    int xpos, ypos;

    bool operator < (_Coord &ref){
        if(this->ypos == ref.ypos)
            return this->xpos < ref.xpos;

        return this->ypos < ref.ypos;
    }
} Coord;

int main() {
    int n;
    Coord *c;

    scanf("%d", &n);

    c = new Coord[n];

    for(int i=0; i<n; i++){
        scanf("%d %d", &c[i].xpos, &c[i].ypos);
    }
    sort(c, c+n);

    for(int i=0; i<n; i++){
        printf("%d %d\n", c[i].xpos, c[i].ypos);
    }

    delete []c;

    return 0;
}