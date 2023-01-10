#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct cmp
{
    bool operator() (int num_1, int num_2)
    {
        if(abs(num_1) > abs(num_2)) return true;
        else if(abs(num_1) == abs(num_2))
        {
            if (num_1 > num_2) return true;
            else return false;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, cmp> pq;
    int N;
    cin >> N;
    
    while(N--)
    {
        int x, abs_x;
        cin >> x;
        if(x == 0)
        {
            if(pq.empty()) cout << "0\n";
            else 
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }

    return 0;
}

// 출처 : https://travelbeeee.tistory.com/126 (우선순위 큐)