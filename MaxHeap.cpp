#include <stdio.h>

using namespace std;

class MaxHeap {
private:
    int n = 1;
    int arr[10];
public:
    bool IsEmpty() {
        return n == -1 ? true : false;
    }

    void Insert(int input){
        arr[n++] = input;
        BubbleUp(n - 1);
    }

    void BubbleUp(int n) {
        if(arr[n] > arr[n/2]){
            int tmp = arr[n];
            arr[n] = arr[n/2];
            arr[n/2] = tmp;
            BubbleUp(n/2);
        }
    }

    void TrickleDown(int n) {
        if(arr[n*2] > arr[n*2 + 1]){
            int tmp = arr[n];
            arr[n] = arr[n*2];
            arr[n*2] = tmp;
            TrickleDown(n*2);
        }
        else {
            int tmp = arr[n];
            arr[n] = arr[n*2 + 1];
            arr[n*2 + 1] = tmp;
            TrickleDown(n*2 + 1);
        }
    }
    
    int Pop(){
        n--;
        int tmp = arr[1];
        arr[1] = arr[n];
        arr[n] = tmp;

        TrickleDown(1);
        return arr[n];
    }
};

int main() {
    int n, input;
    MaxHeap mh;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        mh.Insert(input);
    }

    for(int i=0; i<n; i++){
        printf("%d ", mh.Pop());
    }
    printf("\n");
    
    return 0;
}