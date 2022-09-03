#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _ConfInfo {
    int conf_start, conf_end;
    
    bool operator < (_ConfInfo &ref){
        if(this->conf_end == ref.conf_end)
            return this->conf_start < ref.conf_start;
            
        return this->conf_end < ref.conf_end;
    }
} ConfInfo;

int MaxConfTotal(ConfInfo *c, int size){
    int answer = 0, endtime = 0;
    int i = 0;

    while(i < size) {

        if(c[i].conf_start >= endtime || (c[i].conf_start >= endtime && c[i].conf_start == c[i].conf_end)){
            answer++;
            endtime = c[i].conf_end;
        }

        i++;
    }

    return answer;
}

int main(){
    int answer, conf_num;
    ConfInfo *c;

    scanf("%d", &conf_num);

    c = new ConfInfo[conf_num];

    for(int i=0; i<conf_num; i++){
        scanf("%d %d", &c[i].conf_start, &c[i].conf_end);
    }

    sort(c, c + conf_num);
    
    answer = MaxConfTotal(c, conf_num);

    printf("%d\n", answer);

    delete []c;

    return 0;
}