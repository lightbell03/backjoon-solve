#include <iostream>
#include <vector>

using namespace std;

int arr[3] = {0};

bool check(vector<vector<int> > &paper, int row, int col, int size){
    int valid = paper[row][col];
    bool check = false;

    for(int i=row; i<row + size; i++){
        for(int j=col; j<col + size; j++){
            if(valid != paper[i][j]){
                check = !check;
                break;
            }
        }
        if(check)
            break;
    }

    if(!check)
        arr[valid+1]++;
    
    return check;
}

void split(vector<vector<int> > &paper, int row, int col, int size){
    if(check(paper, row, col, size)){
        size /= 3;

        for(int i=row; i<=row+size*2; i+=size){
            for(int j=col; j<=col+size*2; j+=size){
                split(paper, i, j, size);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, input;
    cin >> N;

    vector<vector<int> > paper;
    for(int i=0; i<N; i++){
        paper.push_back(vector<int>());
        for(int j=0; j<N; j++){
            cin >> input;
            paper[i].push_back(input);
        }
    }

    split(paper, 0, 0, N);

    for(int i=0; i<3; i++){
        cout<<arr[i]<<"\n";
    }
}