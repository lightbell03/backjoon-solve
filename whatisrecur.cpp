#include <iostream>

using namespace std;

void print_under_bar(int under_bar){
    for(int i=0; i<under_bar; i++){
        cout<<"____";
    }
}

void recur(int n, int under_bar){
    print_under_bar(under_bar);
    cout<<"\"����Լ��� ������?\"\n";
    if(n == 0){
        print_under_bar(under_bar);
        cout<<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    else{
        print_under_bar(under_bar);
        cout<<"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        print_under_bar(under_bar);
        cout<<"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        print_under_bar(under_bar);
        cout<<"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        recur(n-1, under_bar+1);
    }

    print_under_bar(under_bar);
    cout<<"��� �亯�Ͽ���.\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;

    cin>>n;

    cout<<"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recur(n, 0);
}