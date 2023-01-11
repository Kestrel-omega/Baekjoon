#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp, iter, count = 0;
    vector<int> crane;
    vector<int> box;

    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        crane.push_back(temp);
    }

    cin >> M;

    while(M--)
    {
        cin >> temp;
        box.push_back(temp);
    }

    sort(crane.begin(), crane.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());

    if(crane[0] < box[0])
    {
        cout << "-1\n";
        return 0;
    }

    // cout << "crane : ";
    // for(int i : crane) cout << i << " ";

    while (!box.empty())
    {
        count++;

        // cout << endl << count << " ------------\nbox : ";
        // for(int i : box) cout << i << " ";

        for (int i = 0; i < N; i++)
        {
            for(int j = 0; j < box.size(); j++)
            {
                if (crane[i] >= box[j]) 
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout << count;
    return 0;
}