#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, input;
    set<int> s;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        s.insert(input);
    }

    scanf("%d", &m);

    for(int i=0; i<m; i++){
        scanf("%d", &input);
        if(s.find(input) != s.end())
            printf("1 ");
        else
            printf("0 ");
    }
}