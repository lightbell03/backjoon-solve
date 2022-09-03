#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct _RegisterInfo {
    int age, rank;
    char name[101];

    bool operator < (const _RegisterInfo &ref) const {
        if(this -> age == ref.age){
            return this -> rank < ref.rank;
        }

        return this -> age < ref.age;
    }
} RegisterInfo;

RegisterInfo r_arr[1000000];

int main() {
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %s", &r_arr[i].age, &r_arr[i].name);
        r_arr[i].rank = i;
    }

    sort(r_arr, r_arr+n);

    for(int i=0; i<n; i++){
        printf("%d %s\n", r_arr[i].age, r_arr[i].name);
    }

    return 0;
}