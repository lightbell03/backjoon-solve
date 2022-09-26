// #include <iostream>
// #include <vector>

// #define DUMMY 0

// using namespace std;

// int v[100001] = {0, };

// void insert(int now)
// {
//     if (now == 1)
//         return;

//     int parent = now / 2;

//     if (v[parent] < v[now])
//     {
//         int tmp = v[parent];
//         v[parent] = v[now];
//         v[now] = tmp;

//         insert(parent);
//     }
// }

// void down(int now, int top)
// {
//     if (now * 2 == top)
//     {
//         if (v[now * 2] > v[now])
//         {
//             int tmp = v[now];
//             v[now] = v[now * 2];
//             v[now * 2] = tmp;
//         }
//         return;
//     }
//     else if (now * 2 + 1 <= top)
//     {
//         int left = now * 2;
//         int right = now * 2 + 1;

//         if (v[left] > v[right])
//         {
//             int tmp = v[left];
//             v[left] = v[now];
//             v[now] = tmp;
//             down(left, top);
//         }
//         else
//         {
//             int tmp = v[right];
//             v[right] = v[now];
//             v[now] = tmp;
//             down(right, top);
//         }
//     }
//     else
//         return;
// }

// int pop(int &top)
// {
//     if (top == 0)
//         return 0;

//     int result = v[1];
//     v[1] = v[top];

//     down(1, --top);
//     return result;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);
//     cout.tie(NULL);
    
//     int N, input, top = 0;

//     cin >> N;

//     for (int i = 0; i < N; i++)
//     {
//         cin >> input;

//         if (input == 0)
//         {
//             cout << pop(top) << "\n";
//         }
//         else
//         {
//             v[++top] = input;
//             insert(top);
//         }
//     }
// }

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N, input;
    priority_queue<int> pq;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>input;
        if(input == 0){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(input);
        }
    }
}