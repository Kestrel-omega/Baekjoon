#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N;
    string order;
    deque<int> deq;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> order;
        // push_front
        if (order == "push_front")
        {
            int num;
            cin >> num;
            deq.push_front(num);
        }
        // push_back
        else if (order == "push_back")
        {
            int num;
            cin >> num;
            deq.push_back(num);
        }
        // front
        else if (order == "front")
        {
            if (deq.size() == 0)
                cout << "-1\n";
            else
                cout << deq[0] << "\n";
        }
        // pop_front
        else if (order == "pop_front")
        {
            if (deq.size() == 0)
                cout << "-1\n";
            else
            {
                cout << deq[0] << "\n";
                deq.pop_front();
            }
        }
        // back
        else if (order == "back")
        {
            if (deq.size() == 0)
                cout << "-1\n";
            else
                cout << deq[deq.size() - 1] << "\n";
        }
        // pop_back
        else if (order == "pop_back")
        {
            if (deq.size() == 0)
                cout << "-1\n";
            else
            {
                cout << deq[deq.size() - 1] << "\n";
                deq.pop_back();
            }
        }
        // size
        else if (order == "size")
        {
            cout << deq.size() << "\n";
        }
        // empty
        else if (order == "empty")
        {
            if (deq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}