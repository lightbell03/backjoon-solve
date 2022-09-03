#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct _StringLen {
    char str[50];
    int len;

    bool operator < (_StringLen &ref){
        if(this->len == ref.len) 
            return strcmp(this->str, ref.str) < 0 ? true : false;

        return this->len < ref.len;
    }
} StringLen;

void SetStrLen(StringLen *s, int size){
    for(int i=0; i<size; i++){
        s[i].len = strlen(s[i].str);
    }
}

int main() {
    int n;
    StringLen *s;

    scanf("%d", &n);

    s = new StringLen[n];

    for(int i=0; i<n; i++) {
        scanf("%s", s[i].str);
    }

    SetStrLen(s, n);

    sort(s, s+n);

    for(int i=0; i<n; i++) {
        if(i > 0 && strcmp(s[i - 1].str, s[i].str) == 0)
            continue;
        printf("%s\n", s[i].str);
    }

    delete []s;
    return 0;
}