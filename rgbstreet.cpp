#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000][3];

int main() {
    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i=1; i<N; i++){
        int next_1 = arr[i][0] + arr[i-1][1];
        int next_2 = arr[i][0] + arr[i-1][2];
        
        arr[i][0] = next_1 < next_2 ? next_1 : next_2;

        int next_3 = arr[i][1] + arr[i-1][0];
        int next_4 = arr[i][1] + arr[i-1][2];

        arr[i][1] = next_3 < next_4 ? next_3 : next_4;

        int next_5 = arr[i][2] + arr[i-1][0];
        int next_6 = arr[i][2] + arr[i-1][1];

        arr[i][2] = next_5 < next_6 ? next_5 : next_6;
    }

    int min = *min_element(arr[N-1], arr[N-1]+3);

    cout<<min<<"\n";
}