#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int counter = 0;

class Info
{
public:
    int val;
    int pos;

    Info(int val, int pos)
    {
        this->val = val;
        this->pos = pos;
    }
};

int findMax(deque<Info> q)
{
    int max = 0;

    for (deque<Info>::iterator it = q.begin(); it != q.end(); it++)
    {
        if (it->val >= max)
        {
            if (it->val == max)
                counter++;
            else
                counter = 1;
            max = it->val;
        }
    }
    return max;
}

int main()
{
    int t, N, p, input;
    deque<Info> q;

    cin >> t;

    while (t--)
    {
        int answer = 0;
        bool check = false;

        cin >> N >> p;
        for (int i = 0; i < N; i++)
        {
            cin >> input;
            q.push_back(Info(input, i));
        }
        while (!q.empty())
        {
            if(check){
                deque<Info>().swap(q);
                break;
            }

            int maxVal = findMax(q);

            while (counter > 0)
            {
                if (q.front().val == maxVal)
                {
                    if (q.front().pos == p)
                    {
                        answer++;
                        check = true;
                        break;
                    }
                    q.pop_front();
                    answer++;
                }
                else if (q.front().val < maxVal)
                {
                    q.push_back(q.front());
                    q.pop_front();
                }
                counter--;
            }
        }

        std::cout << answer << "\n";
    }
}