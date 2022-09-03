#include <iostream>

using namespace std;

void print_under_bar(int under_bar){
    for(int i=0; i<under_bar; i++){
        cout<<"____";
    }
}

void recur(int n, int under_bar){
    print_under_bar(under_bar);
    cout<<"\"재귀함수가 뭔가요?\"\n";
    if(n == 0){
        print_under_bar(under_bar);
        cout<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    else{
        print_under_bar(under_bar);
        cout<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        print_under_bar(under_bar);
        cout<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        print_under_bar(under_bar);
        cout<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        recur(n-1, under_bar+1);
    }

    print_under_bar(under_bar);
    cout<<"라고 답변하였지.\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;

    cin>>n;

    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    recur(n, 0);
}