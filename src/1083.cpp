#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    vector<int> elements;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        elements.push_back(temp);
    }

    cin >> S;

    for (int i = 0; i < N; i++)
    {
        int max = elements[i];
        int max_idx = i;
        for (int j = i+1; j < N; j++)
        {
            if(S - j + i < 0) continue;
            if (max < elements[j])
            {
                max = elements[j];
                max_idx = j;
            }
        }
        for(int j = max_idx; j > i; j--) swap(elements[j], elements[j-1]);

        S -= (max_idx - i);

        if (S <= 0) break;
    }

    for (int i = 0; i < N; i++) cout << elements[i] << " ";

    return 0;
}