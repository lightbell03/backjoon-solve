#include <iostream>
#include <vector>

using namespace std;

int maxVal = -1000000001;
int minVal = 1000000001;

void compareVal(int result)
{
    if (result > maxVal)
        maxVal = result;

    if (result < minVal)
        minVal = result;
}

void find(vector<int> v, int plus, int minus, int multi, int divide, int i, int result)
{
    i += 1;

    if (i == v.size()) {
        compareVal(result);
        return;
    }

    if (plus > 0)
    {
        find(v, plus - 1, minus, multi, divide, i, result + v[i]);
    }
    if (minus > 0)
    {
        find(v, plus, minus - 1, multi, divide, i, result - v[i]);
    }
    if (multi > 0)
    {
        find(v, plus, minus, multi - 1, divide, i, result * v[i]);
    }
    if (divide > 0)
    {
        
        find(v, plus, minus, multi, divide - 1, i, result / v[i]);
    }
}

int main()
{
    int N, plus, minus, multi, divide, input;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        A.push_back(input);
    }
    cin >> plus >> minus >> multi >> divide;

    find(A, plus, minus, multi, divide, 0, A[0]);

    cout<<maxVal<<"\n"<<minVal<<"\n";
}