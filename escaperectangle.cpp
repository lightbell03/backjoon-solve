#include <iostream>

using namespace std;

int main() {
    int x, y, w, h;
    int xmin, ymin;

    cin >> x >> y >> w >> h;

    if(x - 0 >= w - x){
        xmin = w - x;
    } else {
        xmin = x - 0;
    }

    if(y - 0 >= h - y){
        ymin = h - y;
    } else {
        ymin = y - 0;
    }

    cout << (xmin < ymin ? xmin : ymin);
}