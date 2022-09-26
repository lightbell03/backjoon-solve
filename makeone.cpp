#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> v(x + 1, 0);

    for (int i = 2; i <= x; i++)
    {
        int next;
        if (i % 3 == 0)
        {
            next = v[i / 3] + 1;
            if (v[i] != 0)
                v[i] = min(v[i], next);
            else
                v[i] = next;
        }
        else if (i % 2 == 0)
        {
            next = v[i / 2] + 1;
            if (v[i] != 0)
                v[i] = min(v[i], next);
            else
                v[i] = next;
        }
        else
        {
            next = v[i - 1] + 1;
            if (v[i] != 0)
                v[i] = min(v[i], next);
            else
                v[i] = next;
        }

        cout<<v[i] <<endl;
        
    }

    cout << v[x];
}