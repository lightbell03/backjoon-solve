#include <iostream>

using namespace std;

void print_star(){
    cout<<"***\n";
    cout<<"* *\n";
    cout<<"***";
}

void recur(int n){
    if(n == 1){
        
    }
    else{
        recur(n/3);
    }
}

int main(){
    int N;

    cin>>N;

    recur(N);
}